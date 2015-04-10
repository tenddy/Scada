#ifndef THERMOMETER_H
#define THERMOMETER_H

#include "qmeter.h"
#include <qpen.h>
class ThermoMeter : public QMeter
{
	Q_OBJECT

public:
	enum Scale{
		Major = 1,
		Minor = 2
	};
	ThermoMeter(QString name = "ThermoMeter", QString title = QStringLiteral("温度计"), QMeter::Type type = QMeter::Thermometer, QWidget *parent = 0);
	~ThermoMeter();
	int getWidth() const {return m_width;}
	int getHeight() const { return m_heigth;}
	int MinValue() const {return m_minValue;}
	int MaxValue() const {return m_maxValue;}
	QColor LiquidColor() const {return m_liquidColor;}
	double ScaleSteps(Scale);
	/*double MinorScaleSteps() {return m_minorSteps;}*/
	int ScaleLength(Scale) const;
	int ScaleWidth(Scale) const;
private:
	int m_width;		//绘制仪表的框架宽度
	int m_heigth;		//绘制仪表的框架高度
	int m_minValue;		//最小量程
	int m_maxValue;		//最大量程
	int m_majorSteps;	//大刻度的步长
	double m_minorSteps; //小刻度的步长 (=m_majorSteps/m_minorNum) 
	int m_minorNum;		 //小刻度数
	int m_majorLength;	 //大刻度长度
	int m_minorLength;	 //小刻度长度 
	int m_majorWidth;	 //大刻度宽度
	int m_minorWidth;	 //小刻度宽度
	QColor m_liquidColor; //温度计液体颜色

	void paintEvent(QPaintEvent *);
	void setAxis(QPainter *);
	virtual void drawContexts(QPainter *painter,QRect r,const QString str,
		int pixsize = 10, int flags = Qt::AlignCenter,QPen pen = QPen(Qt::green));
public slots:
	virtual void setType(Type);
	virtual void setState(State) ;
	virtual void setName(QString);
	virtual void setTitle(QString) ;
	virtual void setChannel(QString);
	virtual void setValue(double);
	virtual void setScale(double) ;
	virtual void setCenter(QPoint) ;
	virtual void setCenter(double,double);
	virtual void setMeterVisible(bool);
	void setWidth(int);
	void setHeight(int);
	void setMinValue(int);
	void setMaxValue(int);
	void setScaleSteps(Scale,double);
	void setScaleLength(Scale,int);
	void setScaleWidth(Scale,int);
	void setLiuidColor(QColor);
};


#endif // THERMOMETER_H
