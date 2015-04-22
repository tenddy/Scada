
/****************************************
**	File Name:	scada.h
**  Description:
**	The head file of main window
**  Author:		teddy.tu(tudongdong1989@gmail.com)
**	
**	Remark:		teddy.tu
**  Date:
**	Version:	1.0.0
**
**  Copyright(C) teddy.tu
**  All rights reserved.
****************************************/ 
#ifndef SCADA_H
#define SCADA_H

#include <QtWidgets/QMainWindow>
#include <qaction.h>
#include <qmenu.h>
#include <qtoolbar.h>
#include "sysconfig.h"
#include "datamanager.h"
#include <qstackedwidget.h>
#include "pageconfig.h"
#include "canopentestdlg.h"
#include "serialdialog.h"

class Scada : public QMainWindow
{
	Q_OBJECT

public:
	Scada(QWidget *parent = 0);
	~Scada();

private: 
	
	QMenu *m_sysConfigMenu;	         /* menu of system configure*/
	QMenu *m_widgetConfigMenu;		 /* menu of page configure */
	QMenu *m_sysManagerMenu;		 /* menu of data manager*/

	QAction *m_sysConfigAction;		  /*action of system configure*/
	QAction *m_widgetConfigAction;	  /*action of page configure*/
	QAction *m_sysManagerAction;	  /*action of data manager*/
	QAction *m_deleteDataBaseAction;  /*action of clear all data in configure database*/
	QAction *m_previewAction;		  /*action of pre-view page*/
	QAction *m_savePageConfig;		   /*action of save all meters configure data*/
	QAction *m_canOpenTestAction;      /*action of test CanOpen protocol*/
    QAction *m_serialPortConfigAction;       /*action of serial port  setting */
    QAction *m_serialPortAction;        /*action of testing serial port */

	QToolBar *m_sysConfigToolBar;	  /*toolbar of system configure*/
	QToolBar *m_pageConfigToolBar;	  /*toolbar of page configure*/
									   
	QStackedWidget *m_stackedwidget;   /*center widget for show and switch pages*/
	SysConfig *m_sysconfig;			   /*system configure widget*/
	PageConfig *m_pageconfig;		   /*page configure widget*/
	DataManager *m_dataManager;		   /*data manager widget*/
    CanOpenTestDlg *m_canOpen;          /*dialog for testing can open*/
    SettingsDialog *m_serialPortSetting; /*dialog for configure serial port*/
    SerialDialog *m_serialPort;         /*dialog for configure and testing serial port*/

	void createUI();
	void createAction();
	void createMenu();
	void createToolBar();
	void connectUI();

private slots:
	void on_sysConfigAction();
	void on_widgetConfigAction();
	void on_sysManagerAction();
	void on_deleteDataBaseAction();
	void on_previewAction();
	void on_savePageConfig();
    
    void on_statusBar(const QString msg);

};

#endif // SCADA_H
