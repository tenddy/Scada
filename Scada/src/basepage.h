#ifndef BASEPAGE1_H
#define BASEPAGE1_H

#include <QWidget>
#include <qvector.h>
#include <qmap.h>
#include "qmeter.h"
#include "enginemeter.h"
#include "qbasemeter.h"
#include "fuelmeter.h"
#include "indicatorlamp.h"
#include "thermometer.h"

class QGridLayout;
class QHBoxLayout;
class QVBoxLayout;

class BasePage : public QWidget
{
	Q_OBJECT

public:
	BasePage(int id,QString pageName = QStringLiteral("ÐÂÒ³Ãæ"),int row = 2, 
        int column = 3 ,int maxLamps = 10,QWidget *parent = 0);
	//BasePage(const BasePage *);
	~BasePage();
	int getId() const {return m_id;} 
	QString pageName() const {return m_pageName;}
	int Row() const {return m_row;}
	int Colomn() const {return m_column;}
	int MaxLamps() const {return m_maxLamps;}
	int MaxMeters() const {return m_row * m_column;}
	bool EnabledLamps() {return LampEnabled;}
	bool getLampsEnabled() const {return LampEnabled;}
	int MeterCounts() const {return m_meterMap.size();}
	int LampCounts() const {return m_lampMap.size();}
	int Counts() const {return m_meterMap.size() + m_lampMap.size();}
	void insertMeter(QMeter *w,int row, int col);
	void addMeter(QMeter *w,int pos);
	void appendMeter(QMeter *w);
	bool deleteMeter(int pos);
	bool deleterMeter(QMeter *w);
	QMeter* getMeter(const int i);
	QMeter* getMeter(const QString name);
	QMeter::Type getMeterType(const int pos) ;
	int getMeterPos(QMeter *w) const ;
	const int meterFirstPos();
	const int meterLastPos(); 
	const int lampFirstPos();
	const int lampLastPos();
	void setMeterPos(QMeter*, int);
	void setMeterPos(QString meterName, int);
	void moveMeterSeial(int steps = 1);
	void moveLampSerial(int steps = 1);
	//void meterAdjust(int current,int pre);
	
	
signals:
	//void lampNumChange();
	//void meterNumChange();

public Q_SLOTS:
	void setRow(int);
	void setColumn(int);
	void setMaxLamps(int);
	void setLampsEnabled(bool);
	//void lampNumChangeEvent();
	//void meterNumChangeEvent(bool);
	//void setMeterCounts(int flag = 0){};
	void updateLayout();
	void setPageName(QString name) {m_pageName = name;setWindowTitle(name);}

private:
	int m_id;	  
	QMap<QMeter*, int> m_meterMap;	   //store all meters except indicators
	QMap<IndicatorLamp*, int> m_lampMap; //store lamps
	bool LampEnabled;				  //set show lamps or not
	int m_row;						  
	int m_column;
	int m_maxLamps;
	QString m_pageName;
	QGridLayout *m_gridlayout;
	QGridLayout *m_lamplayout;
	QVBoxLayout *m_mainlayout;
	//void resizeEvent(QResizeEvent *);
	
};

#endif // BASEPAGE1_H
