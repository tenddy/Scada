#ifndef INDICATORCONFIGDLG_H
#define INDICATORCONFIGDLG_H

#include <QWidget>
#include "ui_indicatorconfigdlg.h"
#include "src/indicatorlamp.h"
class IndicatorConfigDlg : public QWidget
{
	Q_OBJECT

public:
	IndicatorConfigDlg(IndicatorLamp *meter = 0,QWidget *parent = 0);
	~IndicatorConfigDlg();
	void setMeter(IndicatorLamp *);
	void setPageNumRange(int min,int max) {ui.pageSpinBox->setRange(min,max);}
	void setMeterNumRange(int min,int max) {ui.posSpinBox->setRange(min,max);}
private:
	Ui::IndicatorConfigDlg ui;
	void connectUI();
	void initConfig();
	IndicatorLamp *m_meter;
	int m_currentMeterIndex;
	int m_preMeterIndex;
signals:
    void indicatorNameChanged(QString);
	void posNumChanged(int,int);
public slots: 
	
	void setMeterPageNum(int);
	void setMeterPosNum(int);

	void on_titleLineEditChanged();
	void on_titleVisiabled(bool);
	void on_pageChanged(int);
	void on_posChanged();
	void on_centerXChanged(int);
	void on_centerYChanged(int);
	void on_radiusChanged(int);
};

#endif // INDICATORCONFIGDLG_H
