#ifndef INDICATORLAMP_H
#define INDICATORLAMP_H

#define NO_DATA ""
#define GREEN_LAMP ":/greenLamp"
#define YELLOW_LAMP ":/yellowLamp"
#define RED_LAMP ":/redLamp"

#include "qmeter.h"
#include <qpen.h>
#include <qtimer.h>


class IndicatorLamp : public QMeter
{
	Q_OBJECT

public:

    //报警标志位
    enum LIMIT{
        NOLIMIT = 0,
        LOWERWARNING = 1,
        HIGHWARNING = 2,
        LOWERALARM = 3,
        HIGHALARM = 4
    };

	IndicatorLamp(QString name = "IndiactorLamp",QString title = QStringLiteral("指示灯"), QMeter::Type type = QMeter::Lamp, QWidget *parent=0);
	IndicatorLamp(const IndicatorLamp &);
	~IndicatorLamp();
	int  getRadius() const {return m_radius;}
   
    double getValue() const {return m_value;}
    QString getPixmapPath() const {return pixmapPath;}
    bool isShowPixMap() const {return showPixMap;}
    bool getIsDrawLamp() const {return isDrawLamp;}
    bool getIsDigit() const {return isDigit;}
    double getLimitValue(LIMIT) const;

protected:
	virtual void paintEvent(QPaintEvent *);
	virtual void setAxis(QPainter *);
	virtual void drawOutFrame(QPainter *,int , QColor );
	virtual void drawInnerFrame(QPainter *,int , QColor);
	virtual void drawInnerColor(QPainter *,int , QColor);
	virtual void drawContexts(QPainter *painter,QRect r,const QString str,
		int pixsize = 10, int flags = Qt::AlignCenter,QPen pen = QPen(Qt::green));
    virtual void drawPixmap(QPainter *, QRect r, QPixmap pixmap);
    virtual void drawPixmap(QPainter *, QRect r);

	
private:
	double m_value;
    int m_radius;

    double lower_warning;
    double high_warning;
    double lower_alarm;
    double high_alarm;

	QColor m_lampColor;
	QTimer *m_timer;
    QPixmap pixmap;
    QString pixmapPath;
    bool showPixMap;
    bool isDrawLamp;
    bool isDigit;

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
    virtual void setPixmapPath(QString);
    virtual void setLowerWarning(double);
    virtual void setHighWarning(double);
    virtual void setLowerAlarm(double);
    virtual void setHighAlarm(double);
    virtual void setLimitValue(LIMIT, double);
   /* virtual void setValue(int);*/
    virtual void setIsDigit(bool);
    virtual void setDrawPixMap(bool);

private slots:
	void twinkle();	
};

#endif // INDICATORLAMP_H
