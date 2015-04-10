#include "thermometerconfig.h"
#include <qmessagebox.h>

ThermoMeterConfig::ThermoMeterConfig(ThermoMeter *meter,QWidget *parent)
	: QWidget(parent),m_meter(meter)
{
	ui.setupUi(this);
	m_currentMeterIndex = -1;
	m_preMeterIndex = -1;
	if(meter)
		initConfig();
	connectUI();
}

ThermoMeterConfig::~ThermoMeterConfig()
{

}
void ThermoMeterConfig::initConfig()
{

	ui.channelLineEdit->setText(m_meter->getChannel());
	ui.titleLineEdit->setText(m_meter->getTitle());
	//ui.titleCheckBox->setEnabled(m_meter->getComponents() & ThermoMeter::Title);

	ui.minValueSpinBox->setValue(m_meter->MinValue());
	ui.maxValueSpinBox->setValue(m_meter->MaxValue());

	ui.majorNumSpinBox->setValue((int)m_meter->ScaleSteps(ThermoMeter::Major));
	ui.majorLengthSpinBox->setValue(m_meter->ScaleLength(ThermoMeter::Major));
	ui.majorWidthSpinBox->setValue(m_meter->ScaleWidth(ThermoMeter::Major));
	
	//QMessageBox::about(0,"minor",QString::number(m_meter->MinorScaleSteps()));
	ui.minorNumDoubleSpinBox->setValue(m_meter->ScaleSteps(ThermoMeter::Minor));
	ui.minorLengthSpinBox->setValue(m_meter->ScaleLength(ThermoMeter::Minor));
	ui.minorWidthSpinBox->setValue(m_meter->ScaleWidth(ThermoMeter::Minor));
	
	ui.XSpinBox->setValue(m_meter->getCenter().x());
	ui.YSpinBox->setValue(m_meter->getCenter().y());
	ui.widthSpinBox->setValue(m_meter->getWidth());
	ui.heightSpinBox->setValue(m_meter->getHeight());

}
void ThermoMeterConfig::connectUI()
{
	//connect(ui.titleLineEdit,SIGNAL(editingFinished()),this,SLOT(on_titleLineEditChanged()));
    connect(ui.titleLineEdit,SIGNAL(textEdited(QString)),this,SLOT(on_titleLineEditChanged()));
	connect(ui.titleCheckBox,SIGNAL(clicked(bool)),this,SLOT(on_titleVisiabled(bool)));
	connect(ui.unitsLineEdit,SIGNAL(editingFinished()),this,SLOT(on_unitsLineEditChanged()));
	connect(ui.pageSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_pageChanged(int)));
	connect(ui.posSpinBox,SIGNAL(editingFinished()),this,SLOT(on_posChanged()));

	connect(ui.minValueSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_minValueChanged(int)));
	connect(ui.maxValueSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_maxValueChanged(int)));
	connect(ui.XSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_centerXChanged(int)));
	connect(ui.YSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_centerYChanged(int)));

	connect(ui.majorNumSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_majorStepsChanged(int)));
	connect(ui.majorLengthSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_majorLengthChanged(int)));
	connect(ui.majorWidthSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_majorWidthChanged(int)));
	connect(ui.minorNumDoubleSpinBox,SIGNAL(valueChanged(double)),this,SLOT(on_minorStepsChanged(double)));
	connect(ui.minorLengthSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_minorLengthChanged(int)));
	connect(ui.minorWidthSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_minorWidthChanged(int)));
	connect(ui.widthSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_widthChanged(int)));
	connect(ui.heightSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_heightChanged(int)));
}

void ThermoMeterConfig::setMeter(ThermoMeter *meter)
{
	m_meter = meter;
	if(meter)
		initConfig();
}

//public slots

void ThermoMeterConfig::setMeterPageNum(int index)
{
	ui.pageSpinBox->setValue(index);
}

void ThermoMeterConfig::setMeterPosNum(int index)
{
	ui.posSpinBox->setValue(index);
	m_preMeterIndex = m_currentMeterIndex;
	m_currentMeterIndex = index;
}


void ThermoMeterConfig::on_titleLineEditChanged()
{
    if(m_meter)
    {
	    m_meter->setTitle(ui.titleLineEdit->text());
        emit thermometerNameChanged(ui.titleLineEdit->text());
    }   
}

void ThermoMeterConfig::on_titleVisiabled(bool flags)
{
}

void ThermoMeterConfig::on_minValueChanged(int value)
{
	m_meter->setMinValue(value);
}

void ThermoMeterConfig::on_maxValueChanged(int value)
{
	m_meter->setMaxValue(value);
}




void ThermoMeterConfig::on_pageChanged(int index)
{
}
void ThermoMeterConfig::on_posChanged()
{
	m_preMeterIndex = m_currentMeterIndex;
	m_currentMeterIndex = ui.posSpinBox->value();
	if(m_preMeterIndex != m_currentMeterIndex && m_preMeterIndex >0 && m_currentMeterIndex > 0)
		emit posNumChanged(m_currentMeterIndex,m_preMeterIndex);
}

void ThermoMeterConfig::on_centerXChanged(int x)
{
	
	m_meter->setCenter(x,ui.YSpinBox->value());
}
void ThermoMeterConfig::on_centerYChanged(int y)
{
	m_meter->setCenter(ui.XSpinBox->value(),-y);
}

void ThermoMeterConfig::on_majorStepsChanged(int num)
{
	m_meter->setScaleSteps(ThermoMeter::Major,num);
}

void ThermoMeterConfig::on_majorLengthChanged(int length)
{
	m_meter->setScaleLength(ThermoMeter::Major,length);
}

void ThermoMeterConfig::on_majorWidthChanged(int width)
{
	m_meter->setScaleWidth(ThermoMeter::Major,width);
}



void ThermoMeterConfig::on_minorStepsChanged(double space)
{
	m_meter->setScaleSteps(ThermoMeter::Minor,space);
}
void ThermoMeterConfig::on_minorLengthChanged(int length)
{
	m_meter->setScaleLength(ThermoMeter::Minor,length);
}

void ThermoMeterConfig::on_minorWidthChanged(int width)
{
	m_meter->setScaleWidth(ThermoMeter::Minor,width);
}

void ThermoMeterConfig::on_widthChanged(int w)
{
	m_meter->setWidth(w);
}

void ThermoMeterConfig::on_heightChanged(int h)
{
	m_meter->setHeight(h);
}
