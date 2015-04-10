#include "pageconfigdlg.h"
#include <qmessagebox.h>

PageConfigDlg::PageConfigDlg(BasePage *page,QWidget *parent)
	:QWidget(parent),m_page(page)
{
	ui.setupUi(this);
	if(m_page)
	{
		initPageConfigDlg();
		ui.groupBox->setEnabled(true);
	}
	else
		ui.groupBox->setEnabled(false);
	connectUI();
}

PageConfigDlg::~PageConfigDlg()
{
}

void PageConfigDlg::connectUI()
{
	//connect(ui.pageNameLineEdit,SIGNAL(editingFinished()),this,SLOT(on_pageNameChanged()));
    connect(ui.pageNameLineEdit,SIGNAL(textEdited(const QString)),this,SLOT(on_pageNameChanged()));
	connect(ui.rowSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_pageRowChanged(int)));
	connect(ui.columnSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_pageColumnChanged(int)));
	connect(ui.lampGroupBox,SIGNAL(clicked(bool)),this,SLOT(on_pageLampChecked(bool)));
	connect(ui.lampNumSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_lampNumChanged(int)));
}

void PageConfigDlg::initPageConfigDlg()
{
	ui.pageNameLineEdit->setText(m_page->pageName());
	ui.rowSpinBox->setValue(m_page->Row());
	ui.columnSpinBox->setValue(m_page->Colomn());
	ui.lampNumSpinBox->setValue(m_page->MaxLamps());
	ui.lampGroupBox->setChecked(m_page->getLampsEnabled());
	//ui.lampGroupBox->setEnabled(ui.lampGroupBox->isChecked());
}



void PageConfigDlg::setPage(BasePage *page)
{
	m_page = page;
	if(page)
	{
		initPageConfigDlg();
		ui.groupBox->setEnabled(true);
	}
	else
		ui.groupBox->setEnabled(true);
}

//public slots

void PageConfigDlg::on_pageNameChanged()
{
	m_page->setPageName(ui.pageNameLineEdit->text());
	
	if(ui.pageNameLineEdit->hasFocus())
		emit pageNameChanged(ui.pageNameLineEdit->text()); 
}

void PageConfigDlg::on_pageRowChanged(int row)
{
	int pre = m_page->MaxMeters();
	m_page->setRow(row);
	if(ui.rowSpinBox->hasFocus())
    {
		emit pageMeterNumChanged(pre,m_page->MaxMeters(),m_page->getLampsEnabled());
       // m_page->setRow(row);
    }
}

void PageConfigDlg::on_pageColumnChanged(int column)
{
	int pre = m_page->MaxMeters();
	m_page->setColumn(column);
	if(ui.columnSpinBox->hasFocus())
		emit pageMeterNumChanged(pre,m_page->MaxMeters(),m_page->getLampsEnabled());
}

void PageConfigDlg::on_pageLampChecked(bool flags)
{
	int meterNum  = m_page->MaxMeters();
	m_page->setLampsEnabled(flags);
	if(ui.lampGroupBox->hasFocus())
		emit pageMeterNumChanged(meterNum,meterNum,flags);
}

void PageConfigDlg::on_lampNumChanged(int num)
{
	int meterNum  = m_page->MaxMeters();
	m_page->setMaxLamps(num);
	if(ui.lampNumSpinBox->hasFocus())
		emit pageMeterNumChanged(meterNum,meterNum,m_page->getLampsEnabled());
}