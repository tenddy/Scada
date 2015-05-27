#include "indicatorconfigdlg.h"
#include <qmessagebox.h>

IndicatorConfigDlg::IndicatorConfigDlg(IndicatorLamp *meter,QWidget *parent)
	: m_meter(meter),QWidget(parent)
{
	ui.setupUi(this);
	m_currentMeterIndex = -1;
	m_preMeterIndex = -1;
	if(meter)
		initConfig();
	connectUI();
}

IndicatorConfigDlg::~IndicatorConfigDlg()
{
	
}

void IndicatorConfigDlg::initConfig()
{
	ui.channelLineEdit->setText(m_meter->getChannel());
	ui.titleLineEdit->setText(m_meter->getTitle());
	//ui.titleCheckBox->setEnabled(m_meter->getComponents() & ThermoMeter::Title);
	ui.XSpinBox->setValue(m_meter->getCenter().x());
	ui.YSpinBox->setValue(m_meter->getCenter().y());
	ui.radiusSpinBox->setValue(m_meter->getRadius());
}

void IndicatorConfigDlg::connectUI()
{
	//connect(ui.titleLineEdit,SIGNAL(editingFinished()),this,SLOT(on_titleLineEditChanged()));
    connect(ui.titleLineEdit,SIGNAL(textEdited(QString)),this,SLOT(on_titleLineEditChanged()));
	connect(ui.titleCheckBox,SIGNAL(clicked(bool)),this,SLOT(on_titleVisiabled(bool)));
	connect(ui.pageSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_pageChanged(int)));
	connect(ui.posSpinBox,SIGNAL(editingFinished()),this,SLOT(on_posChanged()));
	connect(ui.XSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_centerXChanged(int)));
	connect(ui.YSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_centerYChanged(int)));
	connect(ui.radiusSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_radiusChanged(int)));

}

void IndicatorConfigDlg::setMeter(IndicatorLamp *meter)
{
	m_meter = meter;
	if(meter)
	{
		initConfig();
	}
}

void IndicatorConfigDlg::setMeterPageNum(int index)
{
	ui.pageSpinBox->setValue(index);
}

void IndicatorConfigDlg::setMeterPosNum(int index)
{
	ui.posSpinBox->setValue(index);
	m_preMeterIndex = m_currentMeterIndex;
	m_currentMeterIndex = index;
}

void IndicatorConfigDlg::on_titleLineEditChanged()
{
	m_meter->setTitle(ui.titleLineEdit->text());
    emit indicatorNameChanged(ui.titleLineEdit->text());
}

void IndicatorConfigDlg::on_titleVisiabled(bool)
{}

void IndicatorConfigDlg::on_pageChanged(int index)
{}
void IndicatorConfigDlg::on_posChanged()
{
	m_preMeterIndex = m_currentMeterIndex;
	m_currentMeterIndex = ui.posSpinBox->value();
	if(m_preMeterIndex != m_currentMeterIndex && m_preMeterIndex >0 && m_currentMeterIndex > 0)
		emit posNumChanged(m_currentMeterIndex,m_preMeterIndex);
}

void IndicatorConfigDlg::on_centerXChanged(int x)
{
	m_meter->setCenter(x,m_meter->getCenter().y());
}

void IndicatorConfigDlg::on_centerYChanged(int y)
{
	m_meter->setCenter(m_meter->getCenter().x(), y);  //指示灯Y轴移动方向相反
}

void IndicatorConfigDlg::on_radiusChanged(int r)
{
	m_meter->setRadius(r);
}