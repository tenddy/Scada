/****************************************
**	File Name:pageconfig.cpp
**  Description:
**	Manager and configure the parameters of pages and meters. 
**  Author:		teddy.tu(tudongdong1989@gmail.com)
**	
**	Remark:		teddy.tu
**  Date:		2014/11/28
**	Version:	1.0.0
**
**  Copyright(C) teddy.tu	
**  All rights reserved.
****************************************/
#include "pageconfig.h"
#include "configure.h"
#include "qbasemeter.h"
#include "thermometer.h"
#include "indicatorlamp.h"
#include "fuelmeter.h"
#include "enginemeter.h"
#include "connectdb.h"
#include <qmessagebox.h>
#include <qsqlquery.h>
#include <qstringlist.h>
#include <qlist.h>
#include "InfoMsg.h"
#include "SettingFiles.h"


PageConfig::PageConfig(QWidget *parent)
	: QWidget(parent)
{
	PageConfigUI.setupUi(this);
	m_currentItem = NULL;					// current selected item of treewidget
	m_stackedPages = new StackedPage;		//stack pages to store the pages generate by configrue file
	m_pageConfigDlg = new PageConfigDlg;	// page configure dialog
	m_meterConfigDlg = new MeterConfigDlg;	// basemeter configure dialog
	m_thermoConfigDlg = new ThermoMeterConfig;	// thermometer configure dialog
	m_lampConfigDlg = new IndicatorConfigDlg;	// lamps configure dialog
	createUI();
}

PageConfig::~PageConfig()
{
	if(m_pageConfigDlg)
		delete m_pageConfigDlg;
	if(m_meterConfigDlg)
		delete m_meterConfigDlg;
	if(m_thermoConfigDlg)
		delete m_thermoConfigDlg;
	if(m_lampConfigDlg)
		delete m_lampConfigDlg;
	if(m_stackedPages)
		delete m_stackedPages;
}
void PageConfig::createUI()
{	
	InfoMsg info;
	PageConfigUI.stackedWidget->addWidget((QWidget*)m_pageConfigDlg);
	PageConfigUI.stackedWidget->addWidget((QWidget*)m_meterConfigDlg);
	PageConfigUI.stackedWidget->addWidget((QWidget*)m_thermoConfigDlg);
	PageConfigUI.stackedWidget->addWidget((QWidget*)m_lampConfigDlg);
	
	ConnectDB db;
	/*
	bool flag = find("default.ini"); 
	
	if(!false)
		SettingFiles::WriteToConfigFile("default.ini",db,"configdb");
	*/
	m_stackedPages = new StackedPage(SettingFiles::ReadFromConfigFile("default.ini"));
	
	initTreeWidget(m_stackedPages);
	PageConfigUI.tabWidget->clear();
	for(int i= 0;i <m_stackedPages->getCounts();i++)
	{
		BasePage *page = m_stackedPages->getPage(i);
		PageConfigUI.tabWidget->insertTab(i,page,page->pageName());
	}
	if(PageConfigUI.tabWidget->count())
		PageConfigUI.tabWidget->setCurrentIndex(0);

   

	connect(PageConfigUI.tabWidget,SIGNAL(tabBarClicked(int)),this,SLOT(on_tabWidgetSelected(int)));
	connect(PageConfigUI.treeWidget,SIGNAL(itemClicked(QTreeWidgetItem *,int)),this,SLOT(on_treeWidgetItemClicked(QTreeWidgetItem *)));
	connect(m_pageConfigDlg,SIGNAL(pageMeterNumChanged(int,int,bool)),this,SLOT(on_pageAdjust(int,int,bool)));
}

/*
**  @description:
**	Initialize the m_treeWidget object.
**  @parameter:
**	@param treeWidget:QTreeWidget object
**  @return value:NULL
**
**  author:teddy.tu
**  date:2014/11/29
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void PageConfig::initTreeWidget(QTreeWidget *treeWidget)
{
	treeWidget->setColumnCount(2);
	QStringList headers;
	headers<<QStringLiteral("ID")<<QStringLiteral("Ãû³Æ");
	treeWidget->setHeaderLabels(headers);

	
	QList<QTreeWidgetItem*> widgetlist;

	Configure config("default.ini");
	int pageNum = config.configureRead("PageNum").toInt();

	for(int i=1;i<=pageNum;i++)
	{	
		QStringList pageNames,meterNames,lampNames;
		QString pageflag = QString("/Page%1/").arg(i);
		pageNames<<QString("page_%1").arg(i)
			<<config.configureRead(pageflag+"pageName").toStringList();
		QTreeWidgetItem *page = new QTreeWidgetItem(treeWidget,pageNames);  //parent tree widget


		int meterNum = config.configureRead(pageflag+"meterNum").toInt();
		meterNames = config.configureRead(pageflag+"meterList").toStringList();
		for(int j = 0;j<meterNum; j++)
		{
			QStringList meteritem;
			meteritem<< config.configureRead(pageflag+meterNames[j]+"/name").toString()
				<<config.configureRead(pageflag+meterNames[j]+"/title").toString();
			widgetlist.append(new QTreeWidgetItem(page,meteritem)); 
		}

		int lampNum = config.configureRead(pageflag+"lampNum").toInt();
		lampNames = config.configureRead(pageflag+"lampList").toStringList();
		for(int j=0;j<lampNum;j++)
		{
			QStringList lampitem;
			lampitem << config.configureRead(pageflag+lampNames[j]+"/name").toString()
				<<config.configureRead(pageflag+lampNames[j]+"/title").toString();
			widgetlist.append(new QTreeWidgetItem(page,lampitem));
		}
		widgetlist.clear();
	}
}

  /*
  **  @description:
  **	Initialize the QTreeWidget by stackedPage.
  **  @parameter:
  **	@stackedPages : StackedPage generate by configure file.
  **  @return value:NULL
  **
  **  author:teddy.tu
  **  date:
  **  Copyright(C) teddy.tu
  **  All rights reserved.
  */ 
void PageConfig::initTreeWidget(StackedPage *stackedPages)
{
	InfoMsg info;
	QTreeWidget *treeWidget = PageConfigUI.treeWidget;
	treeWidget->clear();
	treeWidget->setColumnCount(2);
	QStringList headers;
	headers<<QStringLiteral("ID")<<QStringLiteral("Ãû³Æ");
	treeWidget->setHeaderLabels(headers);
	QList<QTreeWidgetItem*> items;
	for(int i=0; i<m_stackedPages->getCounts();i++)
	{	
		BasePage *page = m_stackedPages->getPage(i);
		if(!page)
			continue;
		int pageId = page->getId();
		QString name = page->pageName();
		QStringList pageNames;
		pageNames << QString("Page_%1").arg(pageId) << name;

		QTreeWidgetItem *pitem = new QTreeWidgetItem(treeWidget,pageNames);  //top level item
		int lastIndex = page->lampLastPos() == -1? page->meterLastPos() : page->lampLastPos();
		for(int j= page->meterFirstPos();j <= lastIndex;j++)
		{	
			QStringList meterNames;
			QMeter *meter = page->getMeter(j);
			if(!meter)
				continue;
			meterNames << meter->getName() << meter->getTitle();
			items.append(new QTreeWidgetItem(pitem,meterNames));
		}
	}
}

/*
**  @description:
**		Update the configure page.
**  @parameter:NULL
**
**  @return value:NULL
**
**  author:teddy.tu
**  date:
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void PageConfig::updatePage()
{
	m_stackedPages->clearStackedPages();
	m_stackedPages = new StackedPage(SettingFiles::ReadFromConfigFile("default.ini"));
	initTreeWidget(m_stackedPages);
	
	PageConfigUI.tabWidget->clear();
	for(int i= 0;i <m_stackedPages->getCounts();i++)
	{
		BasePage *page = m_stackedPages->getPage(i);
		PageConfigUI.tabWidget->insertTab(i,page,page->pageName());
	}
	if(PageConfigUI.tabWidget->count())
		PageConfigUI.tabWidget->setCurrentIndex(0);
}

/*
**  @description:
**	Update the page index of treewidget and page configure dialog(m_pageConfigDlg) when the index
**	of tabWiget changed.
**  @parameter:NULL
**
**  @return value:NULL
**
**  author:teddy.tu
**  date:
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void PageConfig::on_tabWidgetSelected(int index)
{
	//PageConfigUI.treeWidget->setCurrentItem(m_currentItem);
	//PageConfigUI.treeWidget->setCurrentItem(PageConfigUI.treeWidget->topLevelItem(index));
	m_pageConfigDlg->setPage(m_stackedPages->getPage(index));
}

/*
**  @description:
**	event when click on treewidgetitem
**  @parameter:
**		@param item: the QTreeWidgetItem object is clicked.
**  @return value:NULL
**
**  author:teddy.tu
**  date:
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void PageConfig::on_treeWidgetItemClicked(QTreeWidgetItem *item)
{
	InfoMsg info;
	int index = 0;	     //switch configure page flag
	m_currentItem = item;
	QTreeWidgetItem *pitem = item->parent();
		
	if(!pitem)
		pitem = item;
	const int pageindex = PageConfigUI.treeWidget->indexOfTopLevelItem(pitem);	 //parent item index 
	
	BasePage *page = NULL;
	for(int i =0;i<m_stackedPages->getCounts();i++)
	{
		//search page 
		if(m_stackedPages->getPage(i)->getId() == pageindex+1 )
		{
			page = m_stackedPages->getPage(i);
			PageConfigUI.tabWidget->setCurrentIndex(i);
			break;
		}
	}
	if(!page)		// if don't find page (it's id is i) 
	{
		QMessageBox::critical(this,"error","Don't find page");
		return ;
	}

	if(item->parent())  //clicked on meter item
	{
		QMeter *meter= page->getMeter(item->text(0));
		if(meter)
		{
			int meterPos = page->getMeterPos(meter);
			int maxMeter = page->Row()*page->Colomn();
			int type = page->getMeter(item->text(0))->getType();
			switch(type)
			{
			case 1:
				m_meterConfigDlg->setMeter((EngineMeter*)page->getMeter(item->text(0)));
				index = 1;
				break;
			case 2:
				m_meterConfigDlg->setMeter((FuelMeter*)page->getMeter(item->text(0)));
				index = 1;
				break;
			case 3:
				m_meterConfigDlg->setMeter((QBaseMeter*)page->getMeter(item->text(0)));
				index = 1;
				break;
			case 4:
				m_thermoConfigDlg->setMeter((ThermoMeter*)page->getMeter(item->text(0)));
				index = 2;
				break;
			case 5:
				m_lampConfigDlg->setMeter((IndicatorLamp*)page->getMeter(item->text(0)));
				index = 3;
				break;
			}
			if(type != 4 && type != 5)	 //basemeter 
			{
				m_meterConfigDlg->setMeterPageNum(pageindex+1);
				m_meterConfigDlg->setMeterPosNum(meterPos);
				m_meterConfigDlg->setMeterNumRange(1,maxMeter);
                connect(m_meterConfigDlg,SIGNAL(meterNameChanged(QString)),this, SLOT(on_updateMeterName(QString)));
				connect(m_meterConfigDlg,SIGNAL(posNumChanged(int,int)),this,SLOT(on_meterPosAdjust(int,int)));
			}
			else if(type == 4)		//thermometer
			{
				m_thermoConfigDlg->setMeterPageNum(pageindex+1);
				m_thermoConfigDlg->setMeterPosNum(meterPos);
				m_thermoConfigDlg->setMeterNumRange(1,maxMeter);
                connect(m_thermoConfigDlg,SIGNAL(thermometerNameChanged(QString)),this, SLOT(on_updateMeterName(QString)));
				connect(m_thermoConfigDlg,SIGNAL(posNumChanged(int,int)),this,SLOT(on_meterPosAdjust(int,int)));
			}
			else				//indicator 
			{
				m_lampConfigDlg->setMeterPageNum(pageindex+1);
				m_lampConfigDlg->setMeterPosNum(meterPos);
				m_lampConfigDlg->setMeterNumRange(maxMeter+1,maxMeter + page->MaxLamps());
                connect(m_lampConfigDlg,SIGNAL(indicatorNameChanged(QString)),this, SLOT(on_updateMeterName(QString)));
				connect(m_lampConfigDlg,SIGNAL(posNumChanged(int,int)),this,SLOT(on_meterPosAdjust(int,int)));
			}
		}
		
	}
	else	   //clicked page item
	{
		m_pageConfigDlg->setPage(page);
		PageConfigUI.tabWidget->setCurrentIndex(pageindex);
		index = 0;
		connect(m_pageConfigDlg,SIGNAL(pageNameChanged(QString)),this,SLOT(on_updatePageName(QString)));
	}	 
	PageConfigUI.stackedWidget->setCurrentIndex(index);
	
}

/*
**  @description:
**  set page name by page configure dialog(pageconfigdlg.ui)
**  @parameter:
**		@param title: the new page name  
**  @return value:NULL
**
**  author:teddy.tu
**  date:
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void PageConfig::on_updatePageName(QString title)
{
	PageConfigUI.tabWidget->setTabText(PageConfigUI.tabWidget->currentIndex(),title);
	m_currentItem->setText(1,title);
}

void PageConfig::on_updateMeterName(QString title)
{
    m_currentItem->setText(1,title);
}

/*
**  @description:
**	Adjust meters' position. The new position shouldn't be empty, it can place the meter on new position.
**  @parameter:
**		@param current: the new position of meter to place.
**		@param previous: the current position of meter placed.
**  @return value:NULL
**
**  author:teddy.tu
**  date:
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void PageConfig::on_meterPosAdjust(int current, int previous)
{
	if(current < 0 || previous < 0 || current == previous)
		return;
	const int  pageIndex = PageConfigUI.tabWidget->currentIndex(); //current page index
	if(pageIndex<0)
		return;
	bool flag = m_stackedPages->setMeterPos(pageIndex, m_currentItem->text(0), current);
	BasePage *page = m_stackedPages->getPage(pageIndex);
	QTreeWidgetItem *pitem = m_currentItem->parent();  //meter's page item
	if(flag && pitem && page)
	{
		pitem->removeChild(m_currentItem);	//remove the current item from  m_treeWidget
		int pos = -1;
		int i=0;
		for(i = 0; i < pitem->childCount(); i++) //search the new position to insert the item
		{
			QTreeWidgetItem *child = pitem->child(i);
			int pos = page->getMeterPos(page->getMeter(child->text(0)));  
			if(pos >= current)		 
			{
				pos =  i?i-1:i;		
				break;
			}
		}
		if(pos == -1)	// the new position is largest, insert item into the last position 
			pos = i;
		pitem->insertChild(pos,m_currentItem);
		PageConfigUI.treeWidget->setCurrentItem(m_currentItem);
	}
}

/*
**  @description:
**	Adjust page's style.When a page's parameters include row, column or lampEnabled flag changed,
**	it need to invoke this function to adjust the page style.
**  @parameter:
**		@preMeterNum: the previous maximum number of meters (except lamps).
**		@curMeterNum: the current maximum number of meters (except lamps).
**		@lampFlag:   the flag of whether lamps is visible.
**  @return value:NULL
**
**  author:teddy.tu
**  date:
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void PageConfig::on_pageAdjust(int preMeterNum, int curMeterNum, bool lampFlag)
{
	QTreeWidgetItem *item;
	int index = PageConfigUI.tabWidget->currentIndex();
	m_stackedPages->adjustPages(index,preMeterNum,curMeterNum,lampFlag);

	initTreeWidget(m_stackedPages);
	for(int i = index;i<m_stackedPages->getCounts();i++)
	{
		PageConfigUI.tabWidget->removeTab(i);
		BasePage *page = m_stackedPages->getPage(i);
		PageConfigUI.tabWidget->insertTab(i,page,page->pageName());
	}
	if(index != PageConfigUI.tabWidget->currentIndex())
		PageConfigUI.tabWidget->setCurrentIndex(index);
}

/*
**  @description:
**		Saving the configured pages's parameters in configure file (filepath).
**  @parameter:
**		@filepath: the path of configure file.
**  @return value:NULL
**
**  author:teddy.tu
**  date:
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void PageConfig::savePageConfig(QString filepath)
{
	SettingFiles::SaveToConfigFile(m_stackedPages, filepath);
}