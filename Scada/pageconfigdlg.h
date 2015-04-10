#ifndef PAGECONFIGDLG_H
#define PAGECONFIGDLG_H

#include <QWidget>
#include "ui_pageconfigdlg.h"
#include "src\basepage.h"
class PageConfigDlg : public QWidget
{
	Q_OBJECT

public:
	PageConfigDlg(BasePage* page = NULL ,QWidget *parent = 0);
	~PageConfigDlg();
	void setPage(BasePage *);
private:
	Ui::PageConfigDlg ui;
	BasePage *m_page;
	void initPageConfigDlg();
	void connectUI();
signals:
	void pageNameChanged(QString );
	void pageMeterNumChanged(int preMeterNum, int curMeterNum, bool lampFlag);
private slots:
	void on_pageNameChanged();
	void on_pageRowChanged(int);
	void on_pageColumnChanged(int);
	void on_pageLampChecked(bool);
	void on_lampNumChanged(int);
};

#endif // PAGECONFIGDLG_H
