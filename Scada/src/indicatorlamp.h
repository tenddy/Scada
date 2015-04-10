#ifndef INDICATORLAMP_H
#define INDICATORLAMP_H

#include "qmeter.h"
#include <qpen.h>
#include <qtimer.h>

class IndicatorLamp : public QMeter
{
	Q_OBJECT

public:
	IndicatorLamp(QString name = "IndiactorLamp",QString title = QStringLiteral("Ö¸Ê¾µÆ"), QMeter::Type type = QMeter::Lamp, QWidget *parent=0);
	IndicatorLamp(const IndicatorLamp &);
	~IndicatorLamp();
	int  getRadius() const {return m_radius;}

protected:
	virtual void paintEvent(QPaintEvent *);
	virtual void setAxis(QPainter *);
	virtual void drawOutFrame(QPainter *,int , QColor );
	virtual void drawInnerFrame(QPainter *,int , QColor);
	virtual void drawInnerColor(QPainter *,int , QColor);
	virtual void drawContexts(QPainter *painter,QRect r,const QString str,
		int pixsize = 10, int flags = Qt::AlignCenter,QPen pen = QPen(Qt::green));
	
private:
	int m_radius;
	QColor m_lampColor;
	QTimer *timer;
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
	virtual void setLampColor(QColor);
	virtual void stateChanged();
	virtual void setRadius(int);
private slots:
	void twinkle();	
};

#endif // INDICATORLAMP_H
