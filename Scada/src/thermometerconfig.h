#ifndef THERMOMETERCONFIG_H
#define THERMOMETERCONFIG_H

#include <QWidget>
#include "ui_thermometerconfig.h"
#include "thermometer.h"
class ThermoMeterConfig : public QWidget
{
	Q_OBJECT

public:
	ThermoMeterConfig(ThermoMeter *meter = 0, QWidget *parent = 0);
	~ThermoMeterConfig();
	void setMeter(ThermoMeter *meter);
	void setPageNumRange(int min,int max) {ui.pageSpinBox->setRange(min,max);}
	void setMeterNumRange(int min,int max) {ui.posSpinBox->setRange(min,max);}
private:
	Ui::ThermoMeterConfig ui;
	void connectUI();
	void initConfig();

	int m_currentMeterIndex;
	int m_preMeterIndex;

	ThermoMeter *m_meter;

signals:
    void thermometerNameChanged(QString);
	void posNumChanged(int,int);
public slots: 

	void setMeterPageNum(int);
	void setMeterPosNum(int);

	void on_titleLineEditChanged();
	void on_titleVisiabled(bool);
	//void on_unitsLineEditChanged();
	//void on_unitsVisiabled(bool); 

	void on_minValueChanged(int);
	void on_maxValueChanged(int);
	//void on_rateChecked(bool);
	//void on_rateValueChanged(const QString);

	void on_pageChanged(int);
	void on_posChanged();
	//void on_startAngleChanged(int);
	//void on_endAngleChanged(int);
	//void on_radiusChanged(int);
	void on_centerXChanged(int);
	void on_centerYChanged(int);

	void on_majorStepsChanged(int);
	void on_majorLengthChanged(int);
	void on_majorWidthChanged(int);
	/*void on_middleNumChanged(int);
	void on_middleLengthChanged(int);
	void on_middleWidthChanged(int);*/
	void on_minorStepsChanged(double);
	void on_minorLengthChanged(int);
	void on_minorWidthChanged(int);
	void on_widthChanged(int);
	void on_heightChanged(int);
	//void on_middleVisiable(bool);
};

#endif // THERMOMETERCONFIG_H
