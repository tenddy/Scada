#include "scada.h"
#include <qstring.h>
#include <qmenubar.h>
#include <qmessagebox.h>
#include "ui_datamanager.h"
#include "SettingFiles.h"
#include "settingsdialog.h"

Scada::Scada(QWidget *parent)
	: QMainWindow(parent)
{	
	createUI();
	createAction();
	createMenu();
	createToolBar();
	connectUI();
}

Scada::~Scada()
{
}

void Scada::createUI()
{   
    m_canOpen = new CanOpenTestDlg;
	m_sysconfig = new SysConfig(this);
	m_pageconfig = new PageConfig(this);
	m_dataManager = new DataManager(this);
	m_serialPort = new SerialDialog(this);
    m_serialPortSetting = new SettingsDialog;
    m_stackedwidget = new QStackedWidget(this);
	

    m_stackedwidget->addWidget(m_sysconfig);
	m_stackedwidget->addWidget(m_pageconfig);
	m_stackedwidget->addWidget(m_dataManager);
    m_stackedwidget->setCurrentIndex(0);
	setCentralWidget(m_stackedwidget);	

	setWindowTitle("Scada");
	resize(800,600);
}

void Scada::createAction()
{
	m_sysConfigAction = new QAction(QIcon(":/systemconfigure"),QStringLiteral("系统配置"),this);
	m_sysConfigAction->setShortcut(QKeySequence("ctrl+G"));
	m_sysConfigAction->setStatusTip(QStringLiteral("系统配置"));

    m_serialPortConfigAction = new QAction(QIcon(":/setting"),QStringLiteral("串口配置"),this);
	m_serialPortConfigAction->setShortcut(QKeySequence("ctrl+R"));
	m_serialPortConfigAction->setStatusTip(QStringLiteral("串口配置"));

    m_serialPortAction = new QAction(QIcon(":/serialport"),QStringLiteral("串口调试"),this);
    m_serialPortAction->setShortcut(QKeySequence("ctrl+P"));
    m_serialPortAction->setStatusTip(QStringLiteral("串口调试")); 

    m_canOpenTestAction = new QAction(QIcon(":/canOpen"),QStringLiteral("CanOpen测试"),this);
	m_canOpenTestAction->setShortcut(QKeySequence("ctrl+T"));
	m_canOpenTestAction->setStatusTip(QStringLiteral("CanOpen测试"));

    m_widgetConfigAction = new QAction(QIcon(":/pageedit1"),QStringLiteral("界面配置"),this);
	m_widgetConfigAction->setShortcut(QKeySequence("ctrl+O"));
	m_widgetConfigAction->setStatusTip(QStringLiteral("界面配置"));

	m_sysManagerAction = new QAction(QIcon(":/database"),QStringLiteral("数据查询"),this);
	m_sysManagerAction->setShortcut(QKeySequence());
	m_sysManagerAction->setStatusTip(QStringLiteral(""));

	m_deleteDataBaseAction = new QAction(QIcon(""),QStringLiteral("清空配置表数据"),this);
	m_deleteDataBaseAction->setShortcut(QKeySequence("ctrl + l"));
	m_deleteDataBaseAction->setStatusTip(QStringLiteral("清空配置表数据"));

	m_savePageConfig = new QAction(QIcon(":/pagesave2"),QStringLiteral("保存配置"),this);
	m_savePageConfig->setShortcut(QKeySequence());
	m_savePageConfig->setStatusTip(QStringLiteral("保存页面和仪表设置"));

	m_previewAction = new QAction(QIcon(":/preview"),QStringLiteral("预览"),this);
	m_previewAction->setShortcut(QKeySequence());
	m_previewAction->setStatusTip(QStringLiteral("预览..."));
}

void Scada::createMenu()
{
	m_sysConfigMenu = menuBar()->addMenu(QStringLiteral("基本配置"));
	m_sysConfigMenu->addAction(m_sysConfigAction);
    m_sysConfigMenu->addAction(m_serialPortConfigAction);
    m_sysConfigMenu->addAction(m_serialPortAction);
    m_sysConfigMenu->addAction(m_canOpenTestAction);

	m_widgetConfigMenu = menuBar()->addMenu(QStringLiteral("界面管理"));
	m_widgetConfigMenu->addAction(m_widgetConfigAction);
	m_widgetConfigMenu->addAction(m_previewAction);
	m_widgetConfigMenu->addAction(m_savePageConfig);

	m_sysConfigMenu = menuBar()->addMenu(QStringLiteral("数据管理"));
	m_sysConfigMenu->addAction(m_sysManagerAction);
	m_sysConfigMenu->addAction(m_deleteDataBaseAction);

}

void Scada::createToolBar()
{
	m_sysConfigToolBar = addToolBar("SysConfig");
	m_sysConfigToolBar->addAction(m_sysConfigAction);
	m_sysConfigToolBar->addAction(m_widgetConfigAction);
	m_sysConfigToolBar->addAction(m_sysManagerAction);
    m_sysConfigToolBar->addAction(m_canOpenTestAction);
    m_sysConfigToolBar->addAction(m_serialPortConfigAction);

	m_pageConfigToolBar = addToolBar("pageConfig") ;
	m_pageConfigToolBar->addAction(m_savePageConfig);
	m_pageConfigToolBar->addAction(m_previewAction);

	statusBar();
}

void Scada::connectUI()
{
	connect(m_sysConfigAction,SIGNAL(triggered()),this,SLOT(on_sysConfigAction()));
	connect(m_widgetConfigAction,SIGNAL(triggered()),this,SLOT(on_widgetConfigAction()));
	connect(m_sysManagerAction,SIGNAL(triggered()),this,SLOT(on_sysManagerAction()));
	connect(m_deleteDataBaseAction,SIGNAL(triggered()),this,SLOT(on_deleteDataBaseAction()));
	connect(m_previewAction,SIGNAL(triggered()),this,SLOT(on_runAction()));
	connect(m_sysconfig,SIGNAL(updateData()),m_pageconfig,SLOT(updatePage()));
	connect(m_previewAction,SIGNAL(triggered()),this,SLOT(on_previewAction()));
	connect(m_savePageConfig,SIGNAL(triggered()),this,SLOT(on_savePageConfig()));
    connect(m_canOpenTestAction,SIGNAL(triggered()),m_canOpen,SLOT(show()));
	connect(m_sysconfig,SIGNAL(update()),m_dataManager,SLOT(tableChanged()));
    connect(m_serialPortAction,SIGNAL(triggered()),m_serialPort,SLOT(show()));
    connect(m_serialPortConfigAction,SIGNAL(triggered()),m_serialPortSetting,SLOT(show()));
}

void Scada::on_sysConfigAction()
{
	m_stackedwidget->setCurrentIndex(0);
}
void Scada::on_widgetConfigAction()
{	
	//m_pageconfig->updatePage();
	m_stackedwidget->setCurrentIndex(1);
	
}
void Scada::on_sysManagerAction()
{
	m_dataManager->tableChanged();
	m_stackedwidget->setCurrentIndex(2);
}

void Scada::on_deleteDataBaseAction()
{
	m_sysconfig	->clearAllData("configdb");
}

void Scada::on_previewAction()
{
	QTabWidget *tabwidget = new QTabWidget;
	/*tabwidget->setFixedWidth(800);
	tabwidget->setFixedHeight(800);*/
	m_pageconfig->savePageConfig();
	QVector<BasePage*> pages = SettingFiles::ReadFromConfigFile("default.ini");
	for(int i=0;i<pages.count();i++)
	{
		tabwidget->insertTab(i,(QWidget*)pages[i],QString::number(i));
	}
	tabwidget->show();
}

void Scada::on_savePageConfig()
{
	m_pageconfig->savePageConfig();
}
