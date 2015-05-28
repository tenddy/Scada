
/*
**  @description:
**	Head file of class QBaseMeter

**  author:teddy.tu
**  date:
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
#ifndef QBASEMETER_H
#define QBASEMETER_H
#include "qmeter.h"
#include <qpen.h>
#include <qpainter.h>
#include <QPixmap>
#include <QPicture>

class QBaseMeter : public QMeter
{
	Q_OBJECT
public:			
	enum Compoment{
		NoComponment	= 0x0,
		Crown			= 0x0001,			/*draw crown*/
		BackGround		= 0x0002,			/*draw background*/
		Units			= 0x0004,			/*draw units*/
		Title			= 0x0008,			/*draw title*/
		Logo			= 0x0010,			/*draw log*/
		DoubleMeter		= 0x0020,			/*draw inner meter*/
		NumericValue	= 0x0040,			/*show numeric value*/
		NumericRate	    = 0x0080,			/*value rate*/
		LowerAlarm		= 0x0100,			/* lower */
		LowerWarning	= 0x0200,
		UpperWarning	= 0x0400,			/*upper*/
		UpperAlarm		= 0x0800
	};
	enum ScaleLine{
		Major = 1,
		Middle = 2,
		Minor	= 3	
	};
	explicit QBaseMeter(QString name = "meter",QString title = QStringLiteral("仪表"),QMeter::Type type = QMeter::Meter,QWidget *parent=0);
	 ~QBaseMeter();

	double Radius() const {return m_radius;}  
	int getComponents() const {return m_compoment;}
	QString getUnits()const {return m_units;}
	int Precision() const {return m_precision;}
	double Rate() const {return m_rate;}
	int startAngle() const {return m_startAngle;}
    int endAngle() const { return m_endAngle;}
	double Factor() const { return m_factor;}
	int InnerScaleSteps() const {return m_innerScaleSteps;}
	int Strech() const {return m_strech;}

    int minValue() const {return m_minValue;}
    int maxValue() const {return m_maxValue;}
	int getWAEnabled() const { return m_WAEnabled;}
	int LAValue() const {return m_laValue;}
	int HAValue() const {return m_haValue;}
	int LWValue() const {return m_lwValue;}
	int HWValue() const {return m_hwValue;}
    
	bool middleVisiable() const {return m_middleVisiable;}
	int ScaleLineNum(ScaleLine);
	int ScaleLineLength(ScaleLine);
	int ScaleLineWidth(ScaleLine);
	QColor ScaleLineColor(ScaleLine);
	
	QColor backgroundColor() const {return m_backgroundColor;}
    QColor crownColor() const {return m_crownColor;}
    QColor IndicatorColor() const {return m_indicatorColor;}
	QColor TextColor() const {return m_textColor;}
    
	
protected:
    /*   QPicture tempPicture;
    QPicture picture;*/

    bool isDrawing;
    QPixmap pixmap;
	int m_radius;							//半径
	int m_compoment;						//显示元素标志位
	QString m_units;						//单位
	int m_precision;						//显示示数精度
	double m_rate;								//数值比例
    int m_startAngle,m_endAngle;
	double m_factor;
	int m_innerScaleSteps;
   	int m_strech;

    int m_maxValue, m_minValue;
	bool m_WAEnabled;
	int m_lwValue,m_hwValue;
	int m_laValue,m_haValue;
    
    int m_scaleMajor;
	int m_scaleMiddle;
    int m_scaleMinor;
	int m_scaleMajorLength;
	bool m_middleVisiable;
	int m_scaleMiddleLength;
	int m_scaleMinorLength;
	int m_scaleMajorWidth;
	int m_scaleMiddleWidth;
    int m_scaleMinorWidth;

	QColor m_scaleMajorColor;
	QColor m_scaleMiddleColor;
	QColor m_scaleMinorColor;
    QColor m_crownColor;
    QColor m_backgroundColor;
	QColor m_textColor;
	QColor m_indicatorColor;
 
	virtual void paintEvent(QPaintEvent *);	
    virtual void setAxis(QPainter *);
	virtual void drawCrown(QPainter *painter,int radius);
    virtual void drawBackground(QPainter *painter);
	virtual void drawScale(QPainter *painter,int radius,QPoint center =QPoint(0,0));
    virtual void drawScale(int radius, QPoint center = QPoint(0,0));
	virtual void drawScaleNum(QPainter *painter,int radius,QPoint center = QPoint(0,0));
	virtual void drawInnerScale(QPainter *painter,QPointF center,double radius);
	virtual void drawInnerScaleNum(QPainter *painter,QPointF center,double radius);
	virtual void drawNumericValue(QPainter *painter,int flags = Qt::AlignCenter, QPen pen = QPen(Qt::gray));
	virtual void drawIndicator(QPainter *painter,QColor color = QColor(150,150,200));

	virtual void drawContexts(QPainter *painter,QRect r,const QString str,int pixsize = 10, int flags = Qt::AlignCenter,QPen pen = QPen(Qt::green));
	virtual void drawContexts(QPainter *painter,QPointF point,const QString str,int pixsize = 10,int flags = Qt::AlignCenter,QPen pen = QPen(Qt::green));
	virtual void drawLogo(QPainter *painter, QRect r); 
    virtual void drawMeterFrame();

    virtual void drawPixMap(QPainter *painter, QRect rect);
//signals:
//    void rePaintMeter();
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

	virtual void ScaleRadius(double);
	virtual void setRadius(double);
	virtual void setCompoment(Compoment ,bool enabled = true); 
	virtual void setUnits(QString);
	virtual void setPrecision(int);
	virtual void setRate(double);
	//void setFactor(double);
	//void setInnerScaleSteps(int);
	//void setStrech(int);
	virtual void setStartAngle(int);
    virtual void setEndAngle(int);
  
    virtual void setMinValue(int);
    virtual void setMaxValue(int);
	virtual void setWAEnabled(int);
	virtual void setlaValue(int);
	virtual void sethaValue(int);
	virtual void setlwValue(int);
	virtual void sethwValue(int);
	
	virtual void setScaleLine(ScaleLine , int );
	virtual void setScaleLineLength(ScaleLine, int);
	virtual void setScaleLineWidth(ScaleLine, int);
	virtual void setScaleLineColor(ScaleLine, QColor);
	virtual void setMiddleVisiable(bool);
    virtual void setCrownColor(QColor);
    virtual void setBackgroundColor(QColor);
	virtual void setTextColor(QColor);
	virtual void setIndicatorColor(QColor);	
	
	virtual void setRuntime(int) {}

    virtual void ChangeValue();
};
#endif //QBASEMETER_H