#ifndef MeterConfigDlg_H
#define MeterConfigDlg_H

#include <QWidget>
#include "qbasemeter.h"
#include "ui_meterconfigdlg.h"

class MeterConfigDlg : public QWidget
{
	Q_OBJECT

public:
	MeterConfigDlg(QBaseMeter *meter = NULL, QWidget *parent = 0);
	~MeterConfigDlg();
	void initConfig(QBaseMeter *);
	void setMeter(QBaseMeter *meter);
	void setPageNumRange(int min,int max) {ui.pageSpinBox->setRange(min,max);}
	void setMeterNumRange(int min,int max) {ui.posSpinBox->setRange(min,max);}
private:
	Ui::MeterConfigDlg ui;
	QBaseMeter *m_meter;
	int m_currentPageIndex;
	int m_prePageIndex;
	int m_currentMeterIndex;
	int m_preMeterIndex;
	bool m_flags;      //首次载入仪表基本参数标志位：true--首次载入或者仪表切换，false -- 设置当前仪表属性
	void connectUI();
	//int getPageNum() {return ui.pageSpinBox->value();}
signals:
    void meterNameChanged(QString);
	void posNumChanged(int current,int previous);
	void pageNumChanged(int current, int previous);

public slots: 
	void setMeterPageNum(int);
	void setMeterPosNum(int);

	void on_titleLineEditChanged();
	void on_titleVisiabled(bool);
	void on_unitsLineEditChanged();
	void on_unitsVisiabled(bool); 

	void on_minValueChanged(int);
	void on_maxValueChanged(int);
	void on_rateChecked(bool);
	void on_rateValueChanged(const QString);

	void on_pageChanged(int);
	void on_posChanged();

	void on_startAngleChanged(int);
	void on_endAngleChanged(int);
	void on_radiusChanged(int);
	void on_centerXChanged(int);
	void on_centerYChanged(int);

	void on_majorNumChanged(int);
	void on_majorLengthChanged(int);
	void on_majorWidthChanged(int);
	void on_middleNumChanged(int);
	void on_middleLengthChanged(int);
	void on_middleWidthChanged(int);
	void on_minorNumChanged(double);
	void on_minorLengthChanged(int);
	void on_minorWidthChanged(int);
	void on_middleVisiable(bool);

	void selectedMeter();
	void selectedMeter(QMeter *);


};

#endif // MeterConfigDlg_H
