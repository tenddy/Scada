#include "meterconfigdlg.h"
#include "ui_meterconfigdlg.h"
#include <qlineedit.h>
#include <qmessagebox.h>
#include "qbasemeter.h"
#include "InfoMsg.h"

MeterConfigDlg::MeterConfigDlg(QBaseMeter *meter,QWidget *parent)
	: m_meter(meter),QWidget(parent)
{
	ui.setupUi(this);
	if(m_meter)
	{
		initConfig(m_meter);
   		m_flags = true;		 
	}
	else
		m_flags = false;
	m_currentMeterIndex = -1;
	m_preMeterIndex = -1;
	m_currentPageIndex = -1;
	m_prePageIndex = -1;
	connectUI();
   
}

MeterConfigDlg::~MeterConfigDlg()
{
	
}

void MeterConfigDlg::initConfig(QBaseMeter *meter)
{
	ui.channelLineEdit->setText(meter->getChannel());
	ui.titleLineEdit->setText(meter->getTitle());
	ui.titleCheckBox->setEnabled(meter->getComponents() & QBaseMeter::Title);
	ui.unitsCheckBox->setEnabled(meter->getComponents() & QBaseMeter::Units);
	ui.UnitsLineEdit->setText(meter->getUnits());
	ui.minValueSpinBox->setValue(meter->minValue());
	ui.maxValueSpinBox->setValue(meter->maxValue());
	ui.rateCheckBox->setChecked(meter->getComponents() & QBaseMeter::NumericRate);
	ui.rateComboBox->setCurrentText(QString("%1").arg(meter->Rate()));

	ui.startAngleSpinBox->setValue(meter->startAngle());
	ui.endAngleSpinBox->setValue(meter->endAngle());
	ui.radiusSpinBox->setValue(meter->Radius());
	ui.XSpinBox->setValue(meter->getCenter().x());
	ui.YSpinBox->setValue(meter->getCenter().y());

	int range = meter->maxValue() - meter->minValue();
	int majornum = meter->ScaleLineNum(QBaseMeter::Major);
	ui.majorNumSpinBox->setValue(range/majornum);
	ui.majorLengthSpinBox->setValue(meter->ScaleLineLength(QBaseMeter::Major));
	ui.majorWidthSpinBox->setValue(meter->ScaleLineWidth(QBaseMeter::Major));

	ui.middleNumSpinBox->setValue(range/majornum/2);
	ui.middleLengthSpinBox->setValue(meter->ScaleLineLength(QBaseMeter::Middle));
	ui.middleWidthSpinBox->setValue(meter->ScaleLineWidth(QBaseMeter::Middle));
						      
	int minornum = meter->ScaleLineNum(QBaseMeter::Minor);
	ui.minorNumDoubleSpinBox->setValue((1.0*range/majornum)/minornum);
	ui.minorLengthSpinBox->setValue(meter->ScaleLineLength(QBaseMeter::Minor));
	ui.minorWidthSpinBox->setValue(meter->ScaleLineWidth(QBaseMeter::Minor));
	ui.middleScalegroupBox->setChecked(meter->middleVisiable());
	
	m_flags = false;
}
void MeterConfigDlg::connectUI()
{
	//connect(ui.titleLineEdit,SIGNAL(editingFinished()),this,SLOT(on_titleLineEditChanged()));
    connect(ui.titleLineEdit,SIGNAL(textEdited(QString)),this,SLOT(on_titleLineEditChanged()));	
    connect(ui.titleCheckBox,SIGNAL(clicked(bool)),this,SLOT(on_titleVisiabled(bool)));
	//connect(ui.UnitsLineEdit,SIGNAL(editingFinished()),this,SLOT(on_unitsLineEditChanged()));
    connect(ui.UnitsLineEdit,SIGNAL(textEdited(QString)),this,SLOT(on_unitsLineEditChanged()));
	connect(ui.unitsCheckBox,SIGNAL(clicked(bool)),this,SLOT(on_unitsVisiabled(bool)));
	connect(ui.pageSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_pageChanged(int)));
	//connect(ui.pageSpinBox,SIGNAL(editingFinished()),this,SLOT());
	connect(ui.posSpinBox,SIGNAL(editingFinished()),this,SLOT(on_posChanged()));

	connect(ui.minValueSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_minValueChanged(int)));
	connect(ui.maxValueSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_maxValueChanged(int)));
	connect(ui.rateCheckBox,SIGNAL(clicked(bool)),this,SLOT(on_rateChecked(bool)));
	connect(ui.rateComboBox,SIGNAL(activated(const QString)),this,SLOT(on_rateValueChanged(const QString)));
	connect(ui.rateComboBox,SIGNAL(editTextChanged(const QString)),this,SLOT(on_rateValueChanged(const QString)));

	connect(ui.startAngleSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_startAngleChanged(int)));
	connect(ui.endAngleSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_endAngleChanged(int)));
	connect(ui.radiusSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_radiusChanged(int)));
	connect(ui.XSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_centerXChanged(int)));
	connect(ui.YSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_centerYChanged(int)));

	connect(ui.majorNumSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_majorNumChanged(int)));
	connect(ui.majorLengthSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_majorLengthChanged(int)));
	connect(ui.majorWidthSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_majorWidthChanged(int)));
	connect(ui.middleNumSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_middleNumChanged(int)));
	connect(ui.middleLengthSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_middleLengthChanged(int)));
	connect(ui.middleWidthSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_middleWidthChanged(int)));
	connect(ui.minorNumDoubleSpinBox,SIGNAL(valueChanged(double)),this,SLOT(on_minorNumChanged(double)));
	connect(ui.minorLengthSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_minorLengthChanged(int)));
	connect(ui.minorWidthSpinBox,SIGNAL(valueChanged(int)),this,SLOT(on_minorWidthChanged(int)));
	connect(ui.middleScalegroupBox,SIGNAL(toggled(bool)),this,SLOT(on_middleVisiable(bool)));
}



void MeterConfigDlg::setMeter(QBaseMeter * meter)
{
	m_meter = meter;
	m_flags = true;
	if(meter)
		initConfig(meter);
}



//public slots
void MeterConfigDlg::setMeterPageNum(int index)
{
	ui.pageSpinBox->setValue(index);
	m_prePageIndex = m_currentPageIndex;
	m_currentPageIndex = index;
}

void MeterConfigDlg::setMeterPosNum(int index)
{
	ui.posSpinBox->setValue(index);
	m_preMeterIndex = m_currentMeterIndex;
	m_currentMeterIndex = ui.posSpinBox->value();
}


void MeterConfigDlg::on_titleLineEditChanged()
{
	if(m_meter)
    {
	    m_meter->setTitle(ui.titleLineEdit->text());
        emit meterNameChanged(ui.titleLineEdit->text());
    }
}
void MeterConfigDlg::on_titleVisiabled(bool flags)
{
	if(m_meter)
	    m_meter->setCompoment(QBaseMeter::Title,flags);
}
void MeterConfigDlg::on_unitsLineEditChanged()
{
	if(m_meter)
	    m_meter->setUnits(ui.UnitsLineEdit->text());
}
void MeterConfigDlg::on_unitsVisiabled(bool flags)
{
	if(m_meter)
	m_meter->setCompoment(QBaseMeter::Units,flags);
}

void MeterConfigDlg::on_minValueChanged(int value)
{
	if(m_meter)
		m_meter->setMinValue(value);
	if(!m_flags) //不是首次载入数据
	{
		on_majorNumChanged(ui.majorNumSpinBox->value());
		on_minorNumChanged(ui.minorNumDoubleSpinBox->value());
	}
}

void MeterConfigDlg::on_maxValueChanged(int value)
{
	if(m_meter)
		m_meter->setMaxValue(value);
	if(!m_flags)
	{
		on_majorNumChanged(ui.majorNumSpinBox->value());
		on_minorNumChanged(ui.minorNumDoubleSpinBox->value());
	}
}

void MeterConfigDlg::on_rateChecked(bool flags)
{
	if(m_meter)
	m_meter->setCompoment(QBaseMeter::NumericRate,flags);
}

void MeterConfigDlg::on_rateValueChanged(const QString str)
{
	
	if(m_meter)
		m_meter->setRate(str.toDouble());
	//QMessageBox::about(0,"debug",QString::number(m_meter->Rate()));
}


void MeterConfigDlg::on_pageChanged(int index)
{
	m_prePageIndex = m_currentPageIndex;
	m_currentPageIndex = index;
	if(ui.pageSpinBox->hasFocus() && m_prePageIndex != m_currentPageIndex)
		QMessageBox::about(this,"page"," page changed, pre:" + QString::number(m_prePageIndex)+"cur:"+QString::number(m_currentPageIndex));
}
void MeterConfigDlg::on_posChanged()
{
	m_preMeterIndex = m_currentMeterIndex;
	m_currentMeterIndex = ui.posSpinBox->value();

	if(m_preMeterIndex != m_currentMeterIndex && m_preMeterIndex >0 && m_currentMeterIndex > 0)
		emit posNumChanged(m_currentMeterIndex,m_preMeterIndex);
}
void MeterConfigDlg::on_startAngleChanged(int val)
{
	if(m_meter)
	m_meter->setStartAngle(val);
}
void MeterConfigDlg::on_endAngleChanged(int val)
{
	if(m_meter)
	m_meter->setEndAngle(val);
}
void MeterConfigDlg::on_radiusChanged(int r)
{
	if(m_meter)
	m_meter->setRadius(r);
}
void MeterConfigDlg::on_centerXChanged(int x)
{
	if(m_meter)
	m_meter->setCenter(x,ui.YSpinBox->value());
}
void MeterConfigDlg::on_centerYChanged(int y)
{
	if(m_meter)
	m_meter->setCenter(ui.XSpinBox->value(),-y);
}

void MeterConfigDlg::on_majorNumChanged(int num)
{
	if(m_meter)
	{
		int range = m_meter->maxValue() -  m_meter->minValue();
		//m_meter->setScaleLine(QBaseMeter::Middle,num/2);
		//ui.middleNumSpinBox->setValue(num/2);
		if(num > range)
			num = 1;
		else
			num = range/num;
		m_meter->setScaleLine(QBaseMeter::Major,num);
	}
}

void MeterConfigDlg::on_majorLengthChanged(int length)
{
	if(m_meter)
	m_meter->setScaleLineLength(QBaseMeter::Major,length);
}

void MeterConfigDlg::on_majorWidthChanged(int width)
{
	if(m_meter)
	m_meter->setScaleLineWidth(QBaseMeter::Major,width);
}

void MeterConfigDlg::on_middleNumChanged(int num)
{
	if(m_meter)
	m_meter->setScaleLine(QBaseMeter::Middle,num);
}

void MeterConfigDlg::on_middleLengthChanged(int length)
{
	if(m_meter)
	m_meter->setScaleLineLength(QBaseMeter::Middle,length);
}

void MeterConfigDlg::on_middleWidthChanged(int width)
{
	if(m_meter)
	m_meter->setScaleLineWidth(QBaseMeter::Middle,width);
}

void MeterConfigDlg::on_minorNumChanged(double space)
{
	if(m_meter)
	{
	int range = m_meter->maxValue() - m_meter->minValue();
	int num = range / m_meter->ScaleLineNum(QBaseMeter::Major) / space;
	//QMessageBox::about(this,"minor",QString::number(num));
	if(num<1)
		num = 1;
	//QMessageBox::about(0,"minor",QString("%1").arg(num));
	m_meter->setScaleLine(QBaseMeter::Middle,num/2);
	ui.middleNumSpinBox->setValue(num/2 * space);
	m_meter->setScaleLine(QBaseMeter::Minor,num);
	}
}
void MeterConfigDlg::on_minorLengthChanged(int length)
{
	if(m_meter)
	m_meter->setScaleLineLength(QBaseMeter::Minor,length);
}

void MeterConfigDlg::on_minorWidthChanged(int width)
{
	if(m_meter)
	m_meter->setScaleLineWidth(QBaseMeter::Minor,width);
}


void MeterConfigDlg::on_middleVisiable(bool flags)
{
	if(m_meter)
	//QMessageBox::about(this,"middle","enabled");
	m_meter->setMiddleVisiable(flags);
}
void MeterConfigDlg::selectedMeter()
{

}
void MeterConfigDlg::selectedMeter(QMeter *meter)
{
	
}

