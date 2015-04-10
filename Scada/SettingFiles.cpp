#include "SettingFiles.h"
#include "src\qbasemeter.h"
#include "src\indicatorlamp.h"
#include "src\thermometer.h"
#include "src\configure.h"
#include "src\basepage.h"
#include "settingsdialog.h"
#include "src\InfoMsg.h"

#include <qmessagebox.h>
#include <qstringlist.h>
#include <qstringlist.h>

SettingFiles::SettingFiles(void)
	:m_settingFile("default.ini")
{
}
SettingFiles::SettingFiles(QString filePath)
	:m_settingFile(filePath)
{
}

SettingFiles::SettingFiles(const SettingFiles & file)
{
	m_settingFile = file.m_settingFile;
}

SettingFiles::~SettingFiles(void)
{
}


/*
**  @description:
**	read data form database and generate the configure file(filepath)
**  @parameter:
**		@filepath:the path of configure file which will generate
**		@db: the object of ConnectDB for connect database
**		@tablename:the table name in database for store configure parameters
**  @return value:NULL
**
**  author:teddy.tu
**  date:
**
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void SettingFiles::WriteToConfigFile(QString filepath,ConnectDB db, QString tablename)
{
    
	//connect to database
	db.openDB();
	if(!db.isOpen())
	{
		QMessageBox::critical(0,"open db","connect database failed.");
		return;
	}
	//create setting file
  	Configure config(filepath);
	config.clear();

	saveSerialPortParam(filepath);

	QBaseMeter *meter;
	ThermoMeter *therm;
	IndicatorLamp *lamp;

	BasePage page(-1);
	int maxMeter = page.Row() * page.Colomn();  //页面默认最大仪表个数
	int maxLampNum = page.MaxLamps();			//页面默认最大指示灯个数
	bool lampEnabled = page.EnabledLamps();		//页面默认是否显示指示灯标志
	int pageNum = 1;							//起始页面编号

	
	config.configureWrite(pageNum,"PageNum");  //页面总数

	//读取配置数据库
	QSqlQuery query;
	if(!query.exec("select * from " + tablename))
	{
		QMessageBox::critical(0,"read db","query database failed.");
		return;
	}
	int meterPageId = 1, lampPageId = 1; //当前可放置仪表的页面id，默认有一个主页面
	int meternum=0,lampnum=0;	   //当前页面meter或者lamp的个数
	QStringList meterList, lampList; //当前页面meter和lamp的仪表名列表

	//从数据库中读取数据
	while(query.next())
	{
		//读取仪表类型
		//0或者空 --- 没有设置仪表类型，默认设置为 仪表盘
		// 1 --- 转速表  2 --- 油位表  3 --- 仪表盘
		// 4 --- 温度计  5 --- 指示灯
		QString metername = query.record().value(1).toString();
		if(metername.isEmpty())
			continue;
		QString meterChannel = query.record().value(1).toString();
		QString metertype = query.record().value(4).toString();

		//根据目前所读取的仪表数，来判断是否能在当前页面中放下，
		//如果在当前页面放不下，就会生成下一个页面。
		if(metertype == "5" )
		{	
			lampnum++;
			if(lampnum>maxLampNum)  //判断当前页面中指示灯是否已满，如果指示灯已满则在下一个页面放置，或创建新页面
			{
				lampPageId++;
				lampnum = 1;
				lampList.clear();
			}
			lampEnabled = true;
		}
		else
		{
			if(metertype.isEmpty() || metertype == "0")	//设置默认的显示方式
				metertype = "3";
		
			if((++meternum) > maxMeter)		  //判断当前页面中仪表是否已满，如果仪表放置已满则会创建新的页面
			{
				meterPageId++;
				meternum = 1;
				meterList.clear();
			}
		
		}
		//设置当前页面是否需要显示指示灯，如果要显示指示灯，则b_lampEnabled = true,，否则为false
		if(lampnum && lampEnabled)
			lampEnabled = true;
		else
			lampEnabled = false;
		
		//添加新页面并设置页面基本属性
		if(pageNum==1 || lampPageId>pageNum || meterPageId>pageNum)
		{
			if(lampPageId != 1 || meterPageId != 1) //当lampPageId != 1  || meterPageId != 1，表示增加了新页面
				pageNum++;
			
		    config.configureWrite(pageNum,"PageNum");		                  //
			QString pageflag = QString("/Page%1/").arg(pageNum);
			if(pageNum==1)
				config.configureWrite(QStringLiteral("主页面"),pageflag+"pageName");
			else
				config.configureWrite(QStringLiteral("页面%1").arg(pageNum-1),pageflag+"pageName");
			config.configureWrite(page.Row(),pageflag+"row");
			config.configureWrite(page.Colomn(),pageflag+"column");
			config.configureWrite(page.MaxLamps(),pageflag + "maxLampsNum");
		}

		QString currentMeterPage = QString("/Page%1/").arg(meterPageId);	//放置仪表的当前页面
		QString currentLampPage = QString("/Page%1/").arg(lampPageId);		//放置指示灯的当前页面

		config.configureWrite(meternum,currentMeterPage+"meterNum");
		config.configureWrite("",currentMeterPage+"meterList");
		if(lampEnabled)
			config.configureWrite("true",currentLampPage+"lampEnabled");
		else
			config.configureWrite("false",currentLampPage+"lampEnabled");

		config.configureWrite(lampnum,currentLampPage+"lampNum");
		config.configureWrite("",currentLampPage+"lampList");
		
		//仪表属性设置
		QString widgetflag;
		int pos;
		if(metertype=="5")
		{
			lampList<<metername;
			widgetflag = currentLampPage+metername+"/";
			pos = lampnum + maxMeter;
		}
		else
		{
			meterList<<metername;
			widgetflag = currentMeterPage+metername+"/";
			pos = meternum;
		}
		config.configureWrite(metername,widgetflag+"name");
		config.configureWrite(query.record().value(2).toString(),widgetflag+"title");
		config.configureWrite(meterChannel,widgetflag+"channel");
		config.configureWrite(pos,widgetflag+"pos");

		//不同仪表的属性设置
		switch(metertype.toInt())
		{
		case 1: 
		case 2:
		case 3:
			if(metertype=="1")	//engineMeter
			{
				config.configureWrite(1,widgetflag+"type");
				meter =  new EngineMeter(metername);
				config.configureWrite(0,widgetflag+"runtime");     //运行时间
			}
			else if(metertype=="2") // fuelLevel
			{
				config.configureWrite(2,widgetflag+"type");
				meter = new FuelMeter(metername);
			}
			else				//meter
			{
				config.configureWrite(3,widgetflag+"type");
				meter = new QBaseMeter(metername);
			}
			meter->setChannel(meterChannel);
			config.configureWrite(meter->getUnits(),widgetflag+"unit");	
			config.configureWrite(meter->getComponents(),widgetflag+"component");
			config.configureWrite(meter->Radius(),widgetflag+"radius");
			config.configureWrite(meter->getCenter().x(),widgetflag+"centerX");
			config.configureWrite(meter->getCenter().y(),widgetflag+"centerY");

			config.configureWrite(meter->startAngle(),widgetflag+"startAngle");
			config.configureWrite(meter->endAngle(),widgetflag+"endAngle");	
			config.configureWrite(meter->minValue(),widgetflag+"minValue");
			config.configureWrite(meter->maxValue(),widgetflag+"maxValue");
			config.configureWrite(meter->Rate(),widgetflag+"rate");
			config.configureWrite(meter->HAValue(),widgetflag+"haValue");
			config.configureWrite(meter->HWValue(),widgetflag+"hwValue");
			config.configureWrite(meter->LWValue(),widgetflag+"lwValue");
			config.configureWrite(meter->LAValue(),widgetflag+"laValue");

			config.configureWrite(meter->ScaleLineNum(QBaseMeter::Major),widgetflag+"scaleMajor");
			config.configureWrite(meter->ScaleLineLength(QBaseMeter::Major),widgetflag+"scaleMajorLength");
			config.configureWrite(meter->ScaleLineWidth(QBaseMeter::Major),widgetflag+"scaleMajorWidth");

			if(meter->middleVisiable())
				config.configureWrite("visible",widgetflag+"middleVisible");
			else
				config.configureWrite("invisible",widgetflag+"middleVisible");
			config.configureWrite(meter->ScaleLineNum(QBaseMeter::Middle),widgetflag+"scaleMiddle");
			config.configureWrite(meter->ScaleLineLength(QBaseMeter::Middle),widgetflag+"scaleMiddleLength");
			config.configureWrite(meter->ScaleLineWidth(QBaseMeter::Middle),widgetflag+"scaleMiddleWidth");

			config.configureWrite(meter->ScaleLineNum(QBaseMeter::Minor),widgetflag+"scaleMinor");
			config.configureWrite(meter->ScaleLineLength(QBaseMeter::Minor),widgetflag+"scaleMinorLength");
			config.configureWrite(meter->ScaleLineWidth(QBaseMeter::Minor),widgetflag+"scaleMinorWidth");
			break;
		case 4:
			therm = new ThermoMeter(metername);
			therm->setChannel(meterChannel);
			config.configureWrite(4,widgetflag+"type");
			config.configureWrite(QStringLiteral("℃"),widgetflag+"unit");
			config.configureWrite(therm->getWidth(),widgetflag+"width");
			config.configureWrite(therm->getHeight(),widgetflag+"height");
			config.configureWrite(therm->getCenter().x(),widgetflag+"centerX");
			config.configureWrite(therm->getCenter().y(),widgetflag+"centerY");
			config.configureWrite(therm->MinValue(),widgetflag+"minValue");
			config.configureWrite(therm->MaxValue(),widgetflag+"maxValue");
			config.configureWrite(therm->ScaleSteps(ThermoMeter::Major),widgetflag+"majorSteps");
			config.configureWrite(therm->ScaleLength(ThermoMeter::Major),widgetflag+"majorLength");
			config.configureWrite(therm->ScaleWidth(ThermoMeter::Major),widgetflag+"majorWidth");
			config.configureWrite(therm->ScaleSteps(ThermoMeter::Minor),widgetflag+"minorSteps");
			config.configureWrite(therm->ScaleLength(ThermoMeter::Minor),widgetflag+"minorLength");
			config.configureWrite(therm->ScaleWidth(ThermoMeter::Minor),widgetflag+"minorWidth");
			break;
		case 5:
			lamp = new IndicatorLamp(metername);
			lamp->setChannel(meterChannel);
			config.configureWrite(5,widgetflag+"type");
			config.configureWrite(lamp->getRadius(),widgetflag+"radius");
			config.configureWrite(lamp->getCenter().x(),widgetflag+"centerX");
			config.configureWrite(lamp->getCenter().y(),widgetflag+"centerY");
			break;
		default:
			break;
		}
		config.configureWrite(meterList,currentMeterPage+"meterList");	  //仪表名称列表
		config.configureWrite(lampList,currentLampPage+"lampList");
	}
	db.closeDB();						 //关闭数据库
}

/*
**  @description:
**	Save the configure parameters of meters and pages into configure file.
**  @parameter:
**		@param stackpage: the  stack to store pages
**		@param filepath: the configure file path
**  @return value:NULL
**
**  author:teddy.tu
**  date:
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void SettingFiles::SaveToConfigFile(StackedPage *stackpage, QString filepath)
{
    InfoMsg info;
	Configure config(filepath);
	config.clear();
	saveSerialPortParam(filepath);
	int maxPage = stackpage->getCounts();
	config.configureWrite(maxPage,"PageNum");
	for(int i = 0; i < maxPage; i++)
	{
		BasePage *page = stackpage->getPage(i);
		QString pageflag = QString("Page%1").arg(i+1);
		/* page parameter */
		config.configureWrite(page->pageName(),"pageName", pageflag);
		config.configureWrite(page->Row(),"row", pageflag);
		config.configureWrite(page->Colomn(),"column", pageflag);
		config.configureWrite(page->MaxLamps(), "maxLampsNum", pageflag);
		config.configureWrite(page->MeterCounts(), "meterNum", pageflag);
		config.configureWrite("","meterList", pageflag);
		if(page->getLampsEnabled())
			config.configureWrite("true", "lampEnabled", pageflag);
		else
			config.configureWrite("false", "lampEnabled", pageflag);
		config.configureWrite(page->LampCounts(), "lampNum", pageflag);
		config.configureWrite("","lampList", pageflag);
		
		QStringList meterNamesList, lampNamesList;
		int lastIndex = page->lampLastPos() == -1 ? page->meterLastPos() : page->lampLastPos();
		for(int i = page->meterFirstPos() ; i  <= lastIndex; i++)
		{
			QMeter::Type type = page->getMeterType(i);
			QMeter *meter = page->getMeter(i);
			if(!meter)
				continue;
			QString meterName = meter->getName();
			if(type != QMeter::Lamp)
				meterNamesList<<meterName;
			else
				lampNamesList<<meterName;

			config.configureWrite(meterName,"name",meterName,pageflag);
			config.configureWrite(meter->getTitle(),"title",meterName,pageflag);
			config.configureWrite(meter->getChannel(),"channel",meterName,pageflag);
			config.configureWrite(i,"pos",meterName,pageflag);
			config.configureWrite((int)type,"type",meterName,pageflag);
			if(type == QMeter::EngineMeter)			    //if the meter type is EngineMeter, it should save the runtime.
			{
				EngineMeter *engine = (EngineMeter*) meter;
				config.configureWrite(engine->runtime(),"runtime",meterName, pageflag);
			}
			//QBaseMeter *baseMeter = page->getMeter(i);
			QBaseMeter *baseMeter = NULL;
			ThermoMeter *therm = NULL;
			IndicatorLamp *lamp = NULL;

			switch(type)
			{
			case QMeter::EngineMeter:
			case QMeter::FuelLevel:
			case QMeter::Meter:
				
				if(type == QMeter::EngineMeter)
					baseMeter = (EngineMeter*) meter;
				else if (type == QMeter::FuelLevel)
					baseMeter = (FuelMeter*) meter;
				else
					baseMeter = (QBaseMeter*) meter;
				config.configureWrite(baseMeter->getUnits(),"unit",meterName, pageflag);	
				config.configureWrite(baseMeter->getComponents(),"component",meterName, pageflag);
				config.configureWrite(baseMeter->Radius(),"radius",meterName, pageflag);
				config.configureWrite(baseMeter->getCenter().x(),"centerX",meterName, pageflag);
				config.configureWrite(baseMeter->getCenter().y(),"centerY",meterName, pageflag);
				config.configureWrite(baseMeter->startAngle(),"startAngle",meterName, pageflag);
				config.configureWrite(baseMeter->endAngle(),"endAngle",meterName, pageflag);	
				config.configureWrite(baseMeter->minValue(),"minValue",meterName, pageflag);
				config.configureWrite(baseMeter->maxValue(),"maxValue",meterName, pageflag);
				//double rate = ;
				//QMessageBox::about(0,"rate",QString::number(baseMeter->Rate()));
				config.configureWrite(baseMeter->Rate(),"rate",meterName, pageflag);
				config.configureWrite(baseMeter->HAValue(),"haValue",meterName, pageflag);
				config.configureWrite(baseMeter->HWValue(),"hwValue",meterName, pageflag);
				config.configureWrite(baseMeter->LWValue(),"lwValue",meterName, pageflag);
				config.configureWrite(baseMeter->LAValue(),"laValue",meterName, pageflag);

				config.configureWrite(baseMeter->ScaleLineNum(QBaseMeter::Major),"scaleMajor",meterName, pageflag);
				config.configureWrite(baseMeter->ScaleLineLength(QBaseMeter::Major),"scaleMajorLength",meterName, pageflag);
				config.configureWrite(baseMeter->ScaleLineWidth(QBaseMeter::Major),"scaleMajorWidth",meterName, pageflag);

				if(baseMeter->middleVisiable())
					config.configureWrite("visible","middleVisible",meterName, pageflag);
				else
					config.configureWrite("invisible","middleVisible",meterName, pageflag);
				config.configureWrite(baseMeter->ScaleLineNum(QBaseMeter::Middle),"scaleMiddle",meterName, pageflag);
				config.configureWrite(baseMeter->ScaleLineLength(QBaseMeter::Middle),"scaleMiddleLength",meterName, pageflag);
				config.configureWrite(baseMeter->ScaleLineWidth(QBaseMeter::Middle),"scaleMiddleWidth",meterName, pageflag);
				config.configureWrite(baseMeter->ScaleLineNum(QBaseMeter::Minor),"scaleMinor",meterName, pageflag);
				config.configureWrite(baseMeter->ScaleLineLength(QBaseMeter::Minor),"scaleMinorLength",meterName, pageflag);
				config.configureWrite(baseMeter->ScaleLineWidth(QBaseMeter::Minor),"scaleMinorWidth",meterName, pageflag);
				break;
			case QMeter::Thermometer:
				therm = (ThermoMeter*) meter;
				config.configureWrite(QStringLiteral("℃"),"unit", meterName, pageflag);
				config.configureWrite(therm->getWidth(),"width", meterName, pageflag);
				config.configureWrite(therm->getHeight(),"height", meterName, pageflag);
				config.configureWrite(therm->getCenter().x(),"centerX", meterName, pageflag);
				config.configureWrite(therm->getCenter().y(),"centerY", meterName, pageflag);
                
				config.configureWrite(therm->MinValue(),"minValue", meterName, pageflag);
				config.configureWrite(therm->MaxValue(),"maxValue", meterName, pageflag);
				config.configureWrite(therm->ScaleSteps(ThermoMeter::Major),"majorSteps", meterName, pageflag);
				config.configureWrite(therm->ScaleLength(ThermoMeter::Major),"majorLength", meterName, pageflag);
				config.configureWrite(therm->ScaleWidth(ThermoMeter::Major),"majorWidth", meterName, pageflag);
				config.configureWrite(therm->ScaleSteps(ThermoMeter::Minor),"minorSteps", meterName, pageflag);
				config.configureWrite(therm->ScaleLength(ThermoMeter::Minor),"minorLength", meterName, pageflag);
				config.configureWrite(therm->ScaleWidth(ThermoMeter::Minor),"minorWidth", meterName, pageflag);
				break;
			case QMeter::Lamp:
				lamp = (IndicatorLamp *) meter;
				config.configureWrite(lamp->getRadius(),"radius", meterName, pageflag);
				config.configureWrite(lamp->getCenter().x(),"centerX", meterName, pageflag);
				config.configureWrite(lamp->getCenter().y(),"centerY", meterName, pageflag);
				break;
			}
		}
		config.configureWrite(meterNamesList,"meterList",pageflag);
		config.configureWrite(lampNamesList,"lampList", pageflag);
	}
}


/*
**  @description:
**	read the data form configure file to generate the meters && pages
**  @parameter:
**		@filepath : the configure file path
**  @return value: QVecotor<BasePage*> 
**		the generate pages
**  author:teddy.tu
**  date:
**
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
QVector<BasePage*> SettingFiles::ReadFromConfigFile(QString filepath)
{
	InfoMsg info;
	QVector<BasePage*> pagevect;
	Configure config(filepath);
	int maxPage = config.configureRead("PageNum").toInt();
	for( int i = 1; i <= maxPage; i++)
	{
		BasePage* page = new BasePage(i);
		//setting page parameters 
		QString pageflag = "Page"+QString::number(i);
		page->setPageName(config.configureRead("pageName",pageflag).toString());
		int row =  config.configureRead("row",pageflag).toInt();
		int column =  config.configureRead("column",pageflag).toInt();
		page->setRow(row);
		page->setColumn(column);
		page->setMaxLamps(config.configureRead("maxLampsNum",pageflag).toInt());
		if(config.configureRead("lampEnabled",pageflag).toString() == "true")
			page->setLampsEnabled(true);
		else
			page->setLampsEnabled(false);
		
		//setting meters parameters
		QStringList meterNames = config.configureRead("meterList",pageflag).toStringList();
		for(int i = 0; i< meterNames.count(); i++)
		{
			int type = config.configureRead("type",meterNames[i],pageflag).toInt();
			QString title = config.configureRead("title",meterNames[i],pageflag).toString();
            int pos = config.configureRead("pos",meterNames[i],pageflag).toInt();
	
			if(type == 4)	//thermometer
			{
				ThermoMeter *therm= new ThermoMeter(meterNames[i],title);
				therm->setChannel(config.configureRead("channel",meterNames[i],pageflag).toString());
				therm->setWidth(config.configureRead("width",meterNames[i],pageflag).toInt());
				therm->setHeight(config.configureRead("height",meterNames[i],pageflag).toInt());
				double x = config.configureRead("centerX",meterNames[i],pageflag).toDouble();
				double y = config.configureRead("centerY",meterNames[i],pageflag).toDouble();
				therm->setCenter(x,y);
				therm->setMinValue(config.configureRead("minValue",meterNames[i],pageflag).toInt());
				therm->setMaxValue(config.configureRead("maxValue",meterNames[i],pageflag).toInt());
				therm->setScaleSteps(ThermoMeter::Major,config.configureRead("majorSteps",meterNames[i],pageflag).toInt());
				therm->setScaleLength(ThermoMeter::Major,config.configureRead("majorLength",meterNames[i],pageflag).toInt());
				therm->setScaleWidth(ThermoMeter::Major,config.configureRead("majorWidth",meterNames[i],pageflag).toInt());
				therm->setScaleSteps(ThermoMeter::Minor,config.configureRead("minorSteps",meterNames[i],pageflag).toInt());
				therm->setScaleLength(ThermoMeter::Minor,config.configureRead("minorLength",meterNames[i],pageflag).toInt());
				therm->setScaleWidth(ThermoMeter::Minor,config.configureRead("minorWidth",meterNames[i],pageflag).toInt());
                page->addMeter(therm,pos);
				//info.info_log("insert therm,m:%d,pos:%d,sum:%d\n",page->MeterCounts(),pos,page->Counts());
			}
            else
            {
                QBaseMeter *meter;
             
			    if(type == 1)   //engineMeter
			    {
                    meter = new EngineMeter(meterNames[i],title);
				    meter->setRuntime(config.configureRead("runtime",meterNames[i],pageflag).toInt());    
			    }
			    else if(type == 2) //fuelMeter
				    meter = new FuelMeter(meterNames[i],title);
			    else if(type == 3)	//meter
                    meter = new QBaseMeter(meterNames[i],title);

				meter->setChannel(config.configureRead("channel",meterNames[i],pageflag).toString());
				meter->setUnits(config.configureRead("unit",meterNames[i],pageflag).toString());
				meter->setCompoment((QBaseMeter::Compoment)config.configureRead("component",meterNames[i],pageflag).toInt());
				meter->setRadius(config.configureRead("radius",meterNames[i],pageflag).toDouble());
				double x = config.configureRead("centerX",meterNames[i],pageflag).toDouble();
				double y = config.configureRead("centerY",meterNames[i],pageflag).toDouble();
				meter->setCenter(x,y);
				meter->setStartAngle(config.configureRead("startAngle",meterNames[i],pageflag).toInt());
				meter->setEndAngle(config.configureRead("endAngle",meterNames[i],pageflag).toInt());
				

				meter->setMaxValue(config.configureRead("maxValue",meterNames[i],pageflag).toInt());

				meter->setMinValue(config.configureRead("minValue",meterNames[i],pageflag).toInt());
				
				//int minValue = config.configureRead("minValue",meterNames[i], pageflag).toInt();
				//QMessageBox::about(0,"debug",meter->getChannel()+":"+QString::number(minValue));

				meter->setRate(config.configureRead("rate",meterNames[i],pageflag).toDouble());
				meter->sethaValue(config.configureRead("haValue",meterNames[i],pageflag).toInt());
				meter->sethwValue(config.configureRead("hwValue",meterNames[i],pageflag).toInt());
				meter->setlwValue(config.configureRead("lwValue",meterNames[i],pageflag).toInt());
				meter->setlaValue(config.configureRead("laValue",meterNames[i],pageflag).toInt());
				meter->setScaleLine(QBaseMeter::Major,config.configureRead("scaleMajor",meterNames[i],pageflag).toInt());
				meter->setScaleLineLength(QBaseMeter::Major,config.configureRead("scaleMajorLength",meterNames[i],pageflag).toInt());
				meter->setScaleLineWidth(QBaseMeter::Major,config.configureRead("scaleMajorWidth",meterNames[i],pageflag).toInt());
				meter->setScaleLine(QBaseMeter::Middle,config.configureRead("scaleMiddle",meterNames[i],pageflag).toInt());
				meter->setScaleLineLength(QBaseMeter::Middle,config.configureRead("scaleMiddleLength",meterNames[i],pageflag).toInt());
				meter->setScaleLineWidth(QBaseMeter::Middle,config.configureRead("scaleMiddleWidth",meterNames[i],pageflag).toInt());
				meter->setScaleLine(QBaseMeter::Minor,config.configureRead("scaleMinor",meterNames[i],pageflag).toInt());
				meter->setScaleLineLength(QBaseMeter::Minor,config.configureRead("scaleMinorLength",meterNames[i],pageflag).toInt());
				meter->setScaleLineWidth(QBaseMeter::Minor,config.configureRead("scaleMinorWidth",meterNames[i],pageflag).toInt());
				if(config.configureRead("middleVisible",meterNames[i],pageflag).toString() == "visible")
					meter->setMiddleVisiable(true);
				else
					meter->setMiddleVisiable(false);
				page->addMeter(meter,pos);
				//info.info_log("insert meter,m:%d,l:%d,sum:%d\n",page->MeterCounts(),page->LampCounts(),page->Counts());
			}
		}
		//setting lamps parameters
		QStringList lampNames = config.configureRead("lampList",pageflag).toStringList();
		int maxMeter = row *column;
		for(int i = 0; i < lampNames.count(); i++)
		{
			QString title = config.configureRead("title",lampNames[i],pageflag).toString();
			IndicatorLamp *lamp = new IndicatorLamp(lampNames[i],title);
			lamp->setChannel(config.configureRead("channel",lampNames[i],pageflag).toString());
			double x = config.configureRead("centerX",lampNames[i],pageflag).toDouble();
			double y = config.configureRead("centerY",lampNames[i],pageflag).toDouble();
			lamp->setCenter(x,y);
			lamp->setRadius(config.configureRead("radius",lampNames[i],pageflag).toInt());
            int pos = config.configureRead("pos",lampNames[i],pageflag).toInt(); 
			page->addMeter(lamp,pos);
			//info.info_log("insert lamps,m:%d,l:%d,sum:%d,pos:%d\n",page->MeterCounts(),page->LampCounts(),page->Counts(),pos);
		}
		pagevect.push_back(page);
	}
	return pagevect;
}

void SettingFiles::saveSerialPortParam(QString filepath)
{
    Configure config(filepath);
    SettingsDialog settings;
    SettingsDialog::Settings p = settings.settings();
    
    config.configureWrite(p.name,"serialPortName");
    config.configureWrite(p.baudRate,"baudRate");
    config.configureWrite(p.dataBits,"dataBits");
    config.configureWrite(p.parity,"parity");
    config.configureWrite(p.stopBits,"stopBits");
    config.configureWrite(p.flowControl,"flowControl");  
}

