
/****************************************
**	File Name:sysconfig.cpp
**  Description: 配置界面的相关操作和配置数据库(configdb)的管理
**
**  Author:		teddy.tu(tudongdong1989@gmail.com)
**	
**	Remark:		teddy.tu
**  Date:
**	Version:	1.0.0
**
**  Copyright(C) teddy.tu
**  All rights reserved.
****************************************/ 
#include "sysconfig.h"
#include <qevent.h>
#include <qstringlist.h>
#include <qmessagebox.h>
#include <qsqlquery.h>
#include <qsqlquerymodel.h>
#include <qcombobox.h>
#include "pageconfig.h"
#include "SettingFiles.h"
#include "..\CanOpen\canopenprotocol.h"
#include <QTableView>

SysConfig::SysConfig(QWidget *parent)
	: QWidget(parent)
{
	SysConfigUI.setupUi(this);
	mask =0;			//预警值和报警值标志位                  +
	MaxColumn = 10;		//tableWidget最大列数
	comboRow = -1;
	SelectionRow = -1;
	con = new ConnectDB("scada.db");//建立数据库连接
	createUI();
	connectUI();
}

SysConfig::~SysConfig()
{

}

/*
**  @description:
**	create or initialize all widget 
**  @parameter:NULL
**
**  @return value:NULL
**
**  author:teddy.tu
**  date:2014/11/24
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void SysConfig::createUI()
{
    QVector<unsigned int> chNum = CanOpenProtocol::channelNum;
    int counts = chNum[0] + chNum[2];
    for(int i= 0; i<chNum[0] + chNum[2]; i++)
        SysConfigUI.comboBoxChannel->insertItem(i,QString("Channel_%1").arg(i+1));
   //SysConfigUI.comboBoxMeterType->insertSeparator(5);
   // QMessageBox::about(this,"num",QString::number(chNum[0]+chNum[2]));
	QRegExp regExp("[-]?\\d+\\.\\d{0,2}");
	QRegExp regExp1("[0-9]\\d");
	QRegExpValidator *rxValidator = new QRegExpValidator(regExp,this);
	QRegExpValidator *rxValidator1 = new QRegExpValidator(regExp1,this);
	SysConfigUI.lineEditLWarning->setValidator(rxValidator);
	SysConfigUI.lineEditHWarning->setValidator(rxValidator);
	SysConfigUI.lineEditLAlarm->setValidator(rxValidator);
	SysConfigUI.lineEditHAlarm->setValidator(rxValidator);
	SysConfigUI.comboBoxSensorMax->setValidator(rxValidator);
	SysConfigUI.comboBoxSensorMin->setValidator(rxValidator);
	SysConfigUI.comboBoxInhibitTime->setValidator(rxValidator1);
	initTableWidget();
}

/*
**  @description:  Connect all signals with slots.
**
**  @parameter:NULL
**
**  @return value:NULL
**
**  author:teddy.tu
**  date:2014/11/20
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void SysConfig::connectUI()
{
	connect(SysConfigUI.comboBoxDataName,SIGNAL(activated(QString)),this,SLOT(on_dataNameChanged(QString)));
    connect(SysConfigUI.comboBoxDataName,SIGNAL(editTextChanged(QString)),this,SLOT(on_dataNameChanged(QString)));
	connect(SysConfigUI.comboBoxDataUint,SIGNAL(activated(QString)),this,SLOT(on_DataUintChanged(QString)));
	connect(SysConfigUI.comboBoxMeterType,SIGNAL(activated(int)),this,SLOT(on_MeterTypeChanged(int)));
	connect(SysConfigUI.comboBoxChannel,SIGNAL(activated(QString)),this,SLOT(on_setChannel(QString)));
	
    connect(SysConfigUI.comboBoxSensorType,SIGNAL(activated(QString)),this,SLOT(on_SensorType(QString)));
    connect(SysConfigUI.comboBoxDataType,SIGNAL(activated(int)),this,SLOT(on_InputDataType(int)));
    connect(SysConfigUI.comboBoxSensorMax,SIGNAL(activated(QString)),this,SLOT(on_SensorMax(QString)));
    connect(SysConfigUI.comboBoxSensorMax,SIGNAL(editTextChanged(QString)),this,SLOT(on_SensorMax(QString)));
    connect(SysConfigUI.comboBoxSensorMin,SIGNAL(activated(QString)),this,SLOT(on_SensorMin(QString)));
    connect(SysConfigUI.comboBoxSensorMin,SIGNAL(editTextChanged(QString)),this,SLOT(on_SensorMin(QString)));
    connect(SysConfigUI.comboBoxInhibitTime,SIGNAL(activated(QString)),this,SLOT(on_InhibitTime(QString)));
    connect(SysConfigUI.comboBoxTimeUint,SIGNAL(activated(int)),this,SLOT(on_InhibitTimeUint(int)));

	connect(SysConfigUI.groupBoxWarning,SIGNAL(clicked(bool)),this,SLOT(on_WarningChecked(bool)));
	connect(SysConfigUI.checkBoxLWarning,SIGNAL(clicked(bool)),this,SLOT(on_LowerWarningChecked(bool)));
	connect(SysConfigUI.checkBoxHWarning,SIGNAL(clicked(bool)),this,SLOT(on_HighWarningChecked(bool)));
	connect(SysConfigUI.groupBoxAlarm,SIGNAL(clicked(bool)),this,SLOT(on_AlarmChecked(bool)));
	connect(SysConfigUI.checkBoxLAlarm,SIGNAL(clicked(bool)),this,SLOT(on_LowerAlarmChecked(bool)));
	connect(SysConfigUI.checkBoxHAlarm,SIGNAL(clicked(bool)),this,SLOT(on_HighAlarmChecked(bool)));
	
    
    connect(SysConfigUI.lineEditLWarning,SIGNAL(textEdited(const QString)),this,SLOT(on_LowerWarningChanged(const QString)));
	connect(SysConfigUI.lineEditHWarning,SIGNAL(textEdited(const QString)),this,SLOT(on_HighWarningChanged(const QString)));
	connect(SysConfigUI.lineEditLAlarm,SIGNAL(textChanged(const QString)),this,SLOT(on_LowerAlarmChanged(const QString)));
	connect(SysConfigUI.lineEditHAlarm,SIGNAL(textChanged(const QString)),this,SLOT(on_HighAlarmChanged(const QString)));
	
	connect(SysConfigUI.tableWidget,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(on_tableWidgetCellDoubleClicked(int,int)));
	connect(SysConfigUI.tableWidget,SIGNAL(cellClicked(int,int)),this,SLOT(on_cellClicked(int,int)));
	
	connect(SysConfigUI.pushButtonOK,SIGNAL(clicked()),this,SLOT(on_OkPushButtonClicked()));
	connect(SysConfigUI.pushButtonCancel,SIGNAL(clicked()),this,SLOT(on_CancelPushButtonClicked()));
	connect(SysConfigUI.pushButtonApplied,SIGNAL(clicked()),this,SLOT(on_AppliedPushButtonClicked()));
}


/*
**  @description:  Initialize tableWidget
**
**  @parameter:NULL
**
**  @return value:NULL
**
**  author:teddy.tu
**  date: 2014/11/20
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void SysConfig::initTableWidget()
{
	/*添加TableWidget的列名称*/
	QStringList strlist;
	strlist<<QStringLiteral("是否配置通道")<<QStringLiteral("通道")<<QStringLiteral("名称")<<QStringLiteral("单位")<<QStringLiteral("显示方式")
        <<QStringLiteral("传感器类型")<<QStringLiteral("输入数据类型")<<QStringLiteral("传感器最大值")<<QStringLiteral("传感器最小值")<<QStringLiteral("保存周期")
		<<QStringLiteral("预警下限值")<<QStringLiteral("预警上限值")<<QStringLiteral("报警下限值")<<QStringLiteral("报警上限值")
		<<QStringLiteral("警告标志位");
	//strlist<<QString("a")<<QString("b")<<QString("c")<<QString("d")<<QString("e")<<QString("f")<<QString("g")
		//<<QString("h")<<QString("i")<<QString("j")<<QString("k")<<QString("l")<<QString("m")<<QString("n")<<QString("o");
	MaxColumn = strlist.count();
    int numRows = 0;
   
	SysConfigUI.tableWidget->setHorizontalHeaderItem(numRows,new QTableWidgetItem("strlist"));
	/*从configdb中读取已存储的数据*/
    con->openDB();
    QSqlQuery query("select * from configdb");
    QSqlDatabase db = QSqlDatabase::database();
    if(db.driver()->hasFeature(QSqlDriver::QuerySize))
        numRows = query.size();
    else
    {
        query.last();
        numRows = query.at() + 1;
    }
	

	/*设置tableWiget的列数，从Canopen读取通道数，tableWidget的最大列数为CanOpen中读取的通道数*/
	int channelNum = SysConfigUI.comboBoxChannel->count();
    MaxRow = channelNum > numRows ? channelNum : numRows;
    //QMessageBox::about(0,"row",QString::number(numRows));
	SysConfigUI.tableWidget->setRowCount(MaxRow);
    SysConfigUI.tableWidget->setColumnCount(MaxColumn);
	SysConfigUI.tableWidget->setHorizontalHeaderLabels(strlist);

	for(int i=0;i<MaxRow;i++)
	{
		SysConfigUI.tableWidget->setItem(i,0,new QTableWidgetItem(QStringLiteral("是")));
		SysConfigUI.tableWidget->item(i,0)->setCheckState(Qt::Unchecked);
        if(i<channelNum)
		    m_setChannelList.insert(QString("Channel_%1").arg(i+1));
	}

    ReadData();		        //更新tableWidget
	createConfigureDB();
}

/*
**  @description: 
**	This is an overloaded function(+1)
**	Insert data into tableWidget.
**
**  @parameter:
**  @param row: row of tableWidget,start from 0;
**	@param column: column of tableWidget, start from 0;
**	@param str:Data(string) need insert into tableWidget,postion (row,column).
**
**	@return value:bool
**	Successfully insert data into tablewidget return true, otherwise return false.
**  author:teddy.tu
**  date: 2014/11/20
**
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
bool SysConfig::insertData(int row, int column, QString str)
{
	QTableWidgetItem *item = new QTableWidgetItem(str);
	if(row>=0 && column>=0)
		SysConfigUI.tableWidget->setItem(row,column,item);
	return true;
}

/*
**  @description: 
**	This  is an overloaded function(+1)
**	Insert data into tableWidget.
**  @parameter:
**  @param row: row of tableWidget,start from 0;
**	@param column: column of tableWidget, start from 0;
**	@param str: Data(string) need insert into tableWidget,postion (row,column).
**	@return value:bool
**	Successfully insert data into tablewidget return true, otherwise return false.
**
**  author:teddy.tu
**  date: 2014/11/20
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
bool SysConfig::insertData(int row, int column, int index)
{
	return insertData(row,column,QString("%1").arg(index));
}

//private slots

/*
**  @description:
**	Slot connects to m_channelComboBox signal activated(QString).
**  @parameter:NULL
**
**  @return value:NULL
**
**  author:teddy.tu
**  date:2014/11/24
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void SysConfig::on_setChannel(QString channelName)
{
	int row=-1;
	if(comboRow != -1)   //存在m_channelComboBox
	{
		if(m_setChannelList.find(channelName) == m_setChannelList.end()) //通道channelName 已经被设置了
		{
			for(int i=0;i<MaxRow;i++)
			{
				QTableWidgetItem *item = SysConfigUI.tableWidget->item(i,1);
				if(item && item->text() == channelName)
					row = i;
			}
		}
		else
		{
			if(m_channelComboBox->isEnabled())
				m_channelComboBox->setCurrentText(channelName);	
			else
				m_channelComboBox->setCurrentIndex(0);	
			row = comboRow;
		}
	}
	else		   //不存在m_channelComboBox
	{
		if(m_setChannelList.find(channelName) == m_setChannelList.end())
			for(int i=0;i<MaxRow;i++)
			{
				QTableWidgetItem *item = SysConfigUI.tableWidget->item(i,1);
				if(item && item->text() == channelName)
					row = i;
			}
	}
	//QMessageBox::about(this,"row",QString("select:%1").arg(row));
	SysConfigUI.tableWidget->selectRow(row);
	SelectionRow = row;
	if(row>=0)
		setData(row);	
}
void SysConfig::on_dataNameChanged(QString dataName)
{
	/*int row = SelectionRow; 
	if(row >= 0)*/
    insertData(SelectionRow,2,dataName);
}
void SysConfig::on_DataUintChanged(QString uint)
{
	/*int row = SelectionRow;
	if(row >= 0)*/
	insertData(SelectionRow,3,uint);
}

void SysConfig::on_MeterTypeChanged(int type)
{
	//int row = SelectionRow;
	//if(row >= 0)
	//insertData(SelectionRow,4,type);
    insertData(SelectionRow, 4, SysConfigUI.comboBoxMeterType->currentText());
    if(type >= 5)
    {
        /* SysConfigUI.lineEditLWarning->setText("1");
        SysConfigUI.lineEditHWarning->setText("1");
        SysConfigUI.lineEditLAlarm->setText("1");
        SysConfigUI.lineEditHAlarm->setText("1");*/
    }
}

void SysConfig::on_SensorType(QString type)
{
    insertData(SelectionRow,5,type);
}

void SysConfig::on_InputDataType(int index)
{
    insertData(SelectionRow,6,index);
}

void SysConfig::on_SensorMax(QString val)
{
    insertData(SelectionRow,7,val);
}

void SysConfig::on_SensorMin(QString val)
{
    insertData(SelectionRow,8,val);
}

void SysConfig::on_InhibitTime(QString val)
{
    int time = val.toInt() ;
    if(SysConfigUI.comboBoxTimeUint->currentIndex() == 1)
    {
        time = time*60;
    }
    insertData(SelectionRow,9,time);
}

void SysConfig::on_InhibitTimeUint(int index)
{
    int time = SysConfigUI.comboBoxInhibitTime->currentText().toInt() ;
    if(index == 1)
    {
        time = time*60;
    }
    insertData(SelectionRow,9,time);
}

void SysConfig::on_LowerWarningChanged(QString val)
{
	insertData(SelectionRow,10,val);
}

void SysConfig::on_HighWarningChanged(QString val)
{
	insertData(SelectionRow,11,val);
}

void SysConfig::on_LowerAlarmChanged(QString val)
{
    double lowerAlarmVal = SysConfigUI.lineEditLAlarm->text().toDouble();
    double highAlarmVal = SysConfigUI.lineEditHAlarm->text().toDouble();
    if((lowerAlarmVal > highAlarmVal) && SysConfigUI.checkBoxHAlarm->isChecked())
    {
        //QMessageBox::warning(this, "Error", QString::fromLocal8Bit("报警下限值大于报警上限值，请重新设置报警值！"));
        setStatusTip("status tip:lower");
        SysConfigUI.lineEditLWarning->setText("");
        emit errorMsg(QString::fromLocal8Bit("报警下限值大于报警上限值，请重新设置报警值！"));
    }
    else
    {
        setStatusTip("");
        insertData(SelectionRow,12,SysConfigUI.lineEditLAlarm->text());
        insertData(SelectionRow,13,SysConfigUI.lineEditHAlarm->text());
    }
}	
void SysConfig::on_HighAlarmChanged(QString val)
{
    double lowerAlarmVal = SysConfigUI.lineEditLAlarm->text().toDouble();
    double highAlarmVal =  SysConfigUI.lineEditHAlarm->text().toDouble();     
    if((lowerAlarmVal > highAlarmVal) && SysConfigUI.checkBoxLAlarm->isChecked())
    {
        SysConfigUI.lineEditLWarning->setText("");
        emit errorMsg(QString::fromLocal8Bit("报警上限值小于报警下限值，请重新设置报警值！"));
    }
    else
    {
        //setStatusTip("");
        insertData(SelectionRow,12,SysConfigUI.lineEditLAlarm->text());
        insertData(SelectionRow,13,SysConfigUI.lineEditHAlarm->text());
    }
}

void SysConfig::on_WarningChecked(bool flag)
{
	//QMessageBox::about(this,"item select",QString("warning:"+QString::number(mask,2)));
	if(flag)
	{
		if(SysConfigUI.checkBoxLWarning->isChecked())
			mask |= 0x1;
		else
			mask  &= 0xE;
		if(SysConfigUI.checkBoxHWarning->isChecked())
			mask |= 0x2;
		else
			mask &= 0xD;
	}
	else
		mask &= 0xC;
	//int row = SelectionRow;
	insertData(SelectionRow,14,QString::number(mask,2));
}

void SysConfig::on_LowerWarningChecked(bool flag)
{
	//QMessageBox::about(this,"item select",QString("lwarning"));
	if(SysConfigUI.groupBoxWarning->isChecked() && flag)
		mask |= 0x1;
	else
		mask &= ~0x1;
	//int row = SelectionRow;
	insertData(SelectionRow,14,QString::number(mask,2));
}
void SysConfig::on_HighWarningChecked(bool flag)
{
	//QMessageBox::about(this,"item select",QString("hwarning"));
	if(SysConfigUI.groupBoxWarning->isChecked() && flag)
		mask |= 0x2;
	else
		mask &= ~0x2;

	//int row = SelectionRow;
	insertData(SelectionRow,14,QString::number(mask,2));
}

void SysConfig::on_AlarmChecked(bool flag)
{
	if(flag)
	{
		if(SysConfigUI.checkBoxLAlarm->isChecked())
			mask |= 0x4;   //0100
		else
			mask  &= ~0x4;  //1011
		if(SysConfigUI.checkBoxHAlarm->isChecked())
			mask |= 0x8;
		else
			mask &= ~0x8;
	}
	else
		 mask &= 0x3;

	insertData(SelectionRow,14,QString::number(mask,2));
}

void SysConfig::on_LowerAlarmChecked(bool flag)
{
  if(SysConfigUI.groupBoxAlarm->isChecked() && flag)
		mask |= 0x4;
	else
		mask &= ~0x4;
	insertData(SelectionRow,14,QString::number(mask,2));
}

void SysConfig::on_HighAlarmChecked(bool flag)
{
	if(SysConfigUI.groupBoxAlarm->isChecked() && flag)
		mask |= 0x8;
	else
		mask &= ~0x8;
	insertData(SelectionRow,14,QString::number(mask,2));
}


void SysConfig::setGroupBoxState(int rmask)
{
	SysConfigUI.checkBoxLWarning->setChecked(rmask&0x1);
	SysConfigUI.checkBoxHWarning->setChecked(rmask&0x2);
	SysConfigUI.groupBoxWarning->setChecked((rmask&0x1)||(rmask&0x2));
	SysConfigUI.checkBoxLAlarm->setChecked(rmask&0x4);
	SysConfigUI.checkBoxHAlarm->setChecked(rmask&0x8);
	SysConfigUI.groupBoxAlarm->setChecked((rmask&0x4)||(rmask&0x8));
	emit SysConfigUI.checkBoxLWarning->clicked(rmask&0x1);
	emit SysConfigUI.checkBoxHWarning->clicked(rmask&0x2);
	emit SysConfigUI.checkBoxLAlarm->clicked(rmask&0x4);
	emit SysConfigUI.checkBoxHAlarm->clicked(rmask&0x8);
}

void SysConfig::on_tableWidgetCellDoubleClicked(int row, int column)
{
	QTableWidgetItem *item = SysConfigUI.tableWidget->item(row,column);
    if(!item)
		item = new QTableWidgetItem("");

    if(column == 0)
         SysConfigUI.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	else if(column == 1)
	{
		if(comboRow==-1)
		{
			QTableWidgetItem *comboItem = SysConfigUI.tableWidget->item(row,column);
			if(!comboItem)
				comboItem = new QTableWidgetItem("");
			m_channelComboBox = new QComboBox;
			if(!comboItem->text().isEmpty())
				m_setChannelList.insert(comboItem->text());
			m_channelComboBox->addItem("");
			foreach(const QString &val,m_setChannelList)
			{
				m_channelComboBox->addItem(val);
			}
			SysConfigUI.tableWidget->setCellWidget(row,1,m_channelComboBox);
			m_channelComboBox->setCurrentText(comboItem->text());
			m_channelComboBox->setEnabled(SysConfigUI.tableWidget->item(row,0)->checkState());
			comboRow = row;
		}
	}
    else
         SysConfigUI.tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
}


void SysConfig::on_cellClicked(int row, int column)
{
	//QMessageBox::about(this,"cell","changed");
	SysConfigUI.tableWidget->selectRow(row);
	SelectionRow = row;
	QTableWidgetItem *currentItem = SysConfigUI.tableWidget->item(row,column);
	QTableWidgetItem *comboItem = SysConfigUI.tableWidget->item(row,1);
	if(!comboItem)
		comboItem = new QTableWidgetItem("");
	if(column == 0)
	{
		if(comboRow != -1 && comboRow != row) //Existed comboBox,but not in the same row with my clicked.
		{
		//  qDebug()<<"current text:"<<m_channelComboBox->currentText();
			QTableWidgetItem *item = new QTableWidgetItem(m_channelComboBox->currentText());
			SysConfigUI.tableWidget->removeCellWidget(comboRow,1);
			if(!item->text().isEmpty())
			m_setChannelList.remove(item->text());
			SysConfigUI.tableWidget->setItem(comboRow,1,item);
			comboRow = -1;
		}
		if(comboRow == -1) //Not exist comboBox.
		{
			m_channelComboBox = new QComboBox;
			if(!comboItem->text().isEmpty())
				m_setChannelList.insert(comboItem->text());
			m_channelComboBox->addItem("");
			foreach(const QString &val,m_setChannelList)
				m_channelComboBox->addItem(val);
	
			m_channelComboBox->setCurrentText(comboItem->text());
			SysConfigUI.tableWidget->setCellWidget(row,1,m_channelComboBox);
			connect(m_channelComboBox,SIGNAL(activated(QString)),this,SLOT(on_channelcomboBoxActivated(QString)));
			comboRow = row;
		}
		if(currentItem->checkState())
		{
			if(m_channelComboBox->currentIndex() == 0 && m_setChannelList.count())
				m_channelComboBox->setCurrentIndex(1);
			m_channelComboBox->setEnabled(true);
		}
		else
		{
			if(m_channelComboBox->currentIndex() != 0)
				m_channelComboBox->setCurrentIndex(0);
			m_channelComboBox->setEnabled(false);
		}
	}
	else
	{
		if(comboRow!= -1 && row != comboRow)
		{
			QTableWidgetItem *item = new QTableWidgetItem(m_channelComboBox->currentText());
			SysConfigUI.tableWidget->removeCellWidget(comboRow,1);
			if(!item->text().isEmpty())
			m_setChannelList.remove(item->text());
			SysConfigUI.tableWidget->setItem(comboRow,1,item);
			comboRow = -1; //Not exist comboBox
		}  
        
	}
    setData(row);
}

void SysConfig::on_channelcomboBoxActivated(QString text)
{
	SysConfigUI.comboBoxChannel->setCurrentText(text);
}


/*
**  @description:
**  slot for OK_PushButton
**  @parameter:NULL
**
**  @return value:NULL
**
**  author:teddy.tu
**  date:2014/11/26
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void SysConfig::on_OkPushButtonClicked()
{
	WriteData();
	createHistoryDB();
	SettingFiles ::WriteToConfigFile("default.ini",*con,"configdb");
	emit updateData();
	QMessageBox::about(this,QStringLiteral("设置基本参数"),QStringLiteral("基本参数设置成功"));
}

/*
**  @description:
**	slot for Cancel_pushButton
**  @parameter:NULL
**
**  @return value:NULL
**
**  author:teddy.tu
**  date: 2014/11/26
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void SysConfig::on_CancelPushButtonClicked()
{
	SysConfigUI.tableWidget->clear();
	initTableWidget();
    setData(SelectionRow);
}

/*
**  @description:
**	This slot  is responded when the appliedPushButton is clicked. 
**  @parameter:NULL
**
**  @return value:NULL
**
**  author:teddy.tu
**  date:2014/11/26
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 

void SysConfig::on_AppliedPushButtonClicked()
{
	//WriteData();
}
/*
**  @description:
**	create database  configdb  for storing the channel settings.
**  @parameter:NULL
**
**  @return value:boolean
**	return true if create table successfully, otherwise return false.
**  author:teddy.tu
**  date:2014/11/24
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
bool SysConfig::createConfigureDB()
{
	if(!con->isOpen())
		con->run();

	//create configure database
	bool ctable = con->createTable("CREATE TABLE IF NOT EXISTS configdb(id int not null  primary key,"
        "channel varchar not null,dataName varchar,units varchar,type char(2),"
        "sensorName varchar,inputDataType char(1),max varchar,min varchar, inhibt int,"
        "lowerwarning varchar,highwarning varchar, loweralarm varchar,highalarm varchar,mask varchar)");
	if(!ctable)
	{
		QMessageBox::about(this,"table","create table failed");
		return false;
	}
    //create distance database
    ctable = con->createTable("CREATE TABLE IF NOT EXISTS distance(time char(20) not null,"
        "tagMAC char(10),distance varchar,message varchar)");

	con->closeDB();
	return true;
}


/*
**  @description:
**  Create history database to store all data which detected by CAN-Bus and Distance-tag
**  @parameter:NULL
**
**  @return value: bool
**  Return true when create history database successful, otherwise return false.
**  author:teddy.tu
**  date:2015/4/14
**
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
bool SysConfig::createHistoryDB()
{
	if(!con->isOpen())
        con->openDB();
	QMap<int,QString>::Iterator mapiter;

	/*if(!con->createTable("drop table if exists historydb"))
		return false;*/
	QMap<int,QString>::iterator iter;
	QStringList tables;
	for(iter = m_channelIdMap.begin();iter!= m_channelIdMap.end();iter++)
	{
		if(!iter.value().isEmpty())
			con->createTable(QString("CREATE TABLE IF NOT EXISTS '%1'(time char(20) not null,value varchar default(0))").arg(iter.value()));
		tables << iter.value();
	}  
	
	QStringList tableList = con->getTables();
	for(int i=0; i<tableList.size();i++)
	{
		if(tableList[i] != "configdb" && tableList[i] != "distance" && !tables.contains(tableList[i]))
			con->deleteTable(tableList[i]);
	}

	con->closeDB();
	return true;
}

/*
**  @description:
**  Read configure data from configdb, and initialize m_channelIdMap && tableWidget
**  @parameter:NULL
**
**  @return value:NULL
**
**  author:teddy.tu
**  date:2014/11/24
**
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void SysConfig::ReadData()
{
	con->openDB();
	if(!con->isOpen())
	{
		QMessageBox::about(this,"Read Data","Failed connect with database to read data.");
		return;
	}
	/*else
		QMessageBox::about(this,"connect","failed");*/
	QSqlQuery query("select * from configdb");
	int recordNum = query.record().count();
	if(recordNum != MaxColumn)
	{
		QMessageBox::critical(this,"Read Data",QStringLiteral("数据不匹配，请重新读取配置数据(%1,%2)").arg(recordNum).arg(MaxColumn));
		return;
    }
	int row=0;
	m_channelIdMap.clear();
	while(query.next())
	{
		
		for(int i=1;i<recordNum;i++)
		{
			QString val = query.record().value(i).toString();
			QTableWidgetItem *item= new QTableWidgetItem(val);
            if(i == 4)
                item->setText(SysConfigUI.comboBoxMeterType->itemText(val.toInt()));
			SysConfigUI.tableWidget->setItem(row,i,item);
			if(i==1)
			{
				if(val.isEmpty())
					SysConfigUI.tableWidget->item(row,0)->setCheckState(Qt::Unchecked);
				else
				{
					if(m_setChannelList.size() && m_setChannelList.find(val) != m_setChannelList.end())
						m_setChannelList.remove(val);
					SysConfigUI.tableWidget->item(row,0)->setCheckState(Qt::Checked);
				}
			}	
		}
		//QMessageBox::about(0,"insert map",query.value(1).toString());
		m_channelIdMap.insert(row,query.value(1).toString());
		row++;
	}

	con->closeDB();
}

/*
**  @description:
**	将已设置好的通道参数保存到配置数据库configdb中，其中channel可以选择，
**	如果不设置channel则必须设置dataName;如果设置channel则必须设置dataName。
**  Saving the configure parameters to configure database(configdb), the parameter of Channel 
**  can be set or not. If not to configure the Channel, the dataName of channel doesn't
**  need to configure. If configure the Channel, then it must configure the dataName as well.

**  @parameter:NULL
**
**  @return value:NULL
**
**  author:teddy.tu
**  date:2014/11/24
**
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void SysConfig::WriteData()
{
	//当保存数据是仍然存在m_channelComboBox,则将会删除m_channelComboBox,并设置channel
	if(comboRow != -1)
	{
		QTableWidgetItem *item = new QTableWidgetItem(m_channelComboBox->currentText());
		SysConfigUI.tableWidget->removeCellWidget(comboRow,1);
		if(!item->text().isEmpty())
			m_setChannelList.remove(item->text());
		SysConfigUI.tableWidget->setItem(comboRow,1,item);
		comboRow = -1;										// Set not exist comboBox
	} 
    //clear the old data           
	con->deleteTable("configdb"); 
	createConfigureDB();
	m_channelIdMap.clear();

	//连接数据库
	con->openDB();
	if(!con->isOpen())
	{
		QMessageBox::about(this,"connect","write data failed.Can't connect with database.");
		return;
	}

    QTableWidgetItem *item;
	int id=0;
    for(int i=0;i<MaxRow;i++)
    {
		QTableWidgetItem *channelSelectItem = SysConfigUI.tableWidget->item(i,0);
		QTableWidgetItem *dataTypeItem = SysConfigUI.tableWidget->item(i,2);
		//当不设置通道，并且没有设置数据名称，将跳过不保存到配置数据库中
		if(!channelSelectItem->checkState()&&(!dataTypeItem || dataTypeItem->text().isEmpty()))
			continue;

		QSqlQuery query;
		//if(squery.next())
		if(m_channelIdMap.size() && m_channelIdMap.find(id) != m_channelIdMap.end()) 
			query.prepare(QString("update configdb set channel=?,dataName=?,units=?,type=?,"
            "sersorName=?,inputDataType=?,max=?,min=?,inhibit=?"
            "lowerwarning=?,highwarning=?,loweralarm=?,highalarm=?,mask=? where id=%1").arg(id));
		else
		{
		   query.prepare("insert into configdb values (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)");
		   query.addBindValue(id);
		}
		//QMessageBox::about(this,"mn",QString("%1,%2").arg(MaxRow).arg(MaxColumn));
		for(int j=1;j<MaxColumn;j++)
		{
			item = SysConfigUI.tableWidget->item(i,j);
			if(!item)
			{
				//QMessageBox::about(this,"item",QString("item(%1,%2) is null").arg(i).arg(j));
				query.addBindValue("");
			}
			else
            {
                if( j == 4)
                    query.addBindValue(SysConfigUI.comboBoxMeterType->findText(item->text()));
                else
				    query.addBindValue(item->text());
		
            }
        }
		if(query.exec()) 
		{	
			item = SysConfigUI.tableWidget->item(i,1);
			QString text="";
			if(item)
			   text = item->text();
			m_channelIdMap.insert(id,text);
		}
		id++;
    }
	con->closeDB();
}


/*
**  @description:
**	Clear all data from table tableName of database.
**  @parameter:
**	@param tableName:	table name
**	@param database:	database name
**  @return value:NULL
**
**  author:teddy.tu
**  date:2014/11/24
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void SysConfig::clearAllData(QString tableName, QString database)
{
	ConnectDB *db = new ConnectDB("scada.db");
	db->openDB();
	if(db->isOpen())
		QMessageBox::about(this,"connect DB","connect success");
	else
		QMessageBox::about(this,"connect DB","connect failed");
	QSqlQuery query(QString("select * from %1").arg(tableName));
	if(!query.exec())
	{
		QMessageBox::about(this,"clear data",QString("Database(%1) is not exist").arg(tableName));
		return;
	}
	while(query.next())
	{
		int id = query.record().value(0).toInt();
		QSqlQuery dquery;
		if(!dquery.exec(QString("delete from %1 where id=%2").arg(tableName).arg(id)))
			QMessageBox::about(this,"delete data","clear data failed.");
	}

	ReadData();
}

/*
**  @description:
**	connect the field in tablewidget to the text widgets for setting field. 
**  @parameter:
**	@param row: row number of tablewidget
**  @return value:NULL
**
**  author:teddy.tu
**  date:2014/11/24
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void SysConfig::setData(int row)
{
	int rmask;
	for(int i=0;i<SysConfigUI.tableWidget->columnCount();i++)
	{
		QTableWidgetItem *item = SysConfigUI.tableWidget->item(row,i);
		if(!item)
			item = new QTableWidgetItem(""); 
        switch(i)
		{
		case 1:
			if(comboRow != -1 && comboRow == row)
				SysConfigUI.comboBoxChannel->setCurrentText(m_channelComboBox->currentText());
			else
			    SysConfigUI.comboBoxChannel->setCurrentText(item->text());
			break;
		case 2:
			SysConfigUI.comboBoxDataName->setCurrentText(item->text());
			break;
		case 3:
			SysConfigUI.comboBoxDataUint->setCurrentText(item->text());
			break;
		case 4:
			SysConfigUI.comboBoxMeterType->setCurrentText(item->text());
			break;
        case 5:
            SysConfigUI.comboBoxSensorType->setCurrentText(item->text());
            //SysConfigUI.comboBoxSensorType->setCurrentIndex(item->text().toInt());
            break;
        case 6:
            if(!item->text().isEmpty())
                SysConfigUI.comboBoxDataType->setCurrentIndex(item->text().toInt());
            else
                SysConfigUI.comboBoxDataType->setCurrentIndex(0);
            break;
        case 7:
            SysConfigUI.comboBoxSensorMax->setCurrentText(item->text());
            break;
        case 8:
            SysConfigUI.comboBoxSensorMin->setCurrentText(item->text());
            break;
        case 9:
            SysConfigUI.comboBoxInhibitTime->setCurrentText(item->text());
            SysConfigUI.comboBoxTimeUint->setCurrentIndex(0);
            break;
		case 10:
				SysConfigUI.lineEditLWarning->setText(item->text());
				break;
		case 11:
				SysConfigUI.lineEditHWarning->setText(item->text());
				break;
		case 12:
				SysConfigUI.lineEditLAlarm->setText(item->text());
				break;
		case 13:
				SysConfigUI.lineEditHAlarm->setText(item->text());
				break;
		case 14:
				rmask = item->text().toInt();
				rmask = rmask%10+rmask/10%10*2+rmask/100%10*4+rmask/1000*8;
				setGroupBoxState(rmask);
				break;
		}
	}
}

QMap<int, QString> SysConfig::getChannelMap() 
{
    return m_channelIdMap;
}