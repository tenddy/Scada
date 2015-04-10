#include "indicatorlamp.h"
#include <qpainter.h>
#include "InfoMsg.h"
#include <qtimer.h>

IndicatorLamp::IndicatorLamp(QString name,QString title, QMeter::Type type, QWidget *parent)
	: QMeter(name,title,type,parent),m_radius(100)
{
	/*set the background color*/
	QPalette p = palette();
	p.setBrush(QPalette::Background,Qt::black);
	setPalette(p);
	setAutoFillBackground(true);

	m_radius = 30;						    //半径
	//m_title = QStringLiteral("指示灯");	//名称
	m_lampColor = Qt::darkGray;			   //指示灯颜色
	//setMinimumSize(220,220);			   //窗体大小设置
	setMaximumHeight(100);
	//sizeHint();
	//resize(220,220);
	timer = new QTimer;
	connect(timer,SIGNAL(timeout()),this,SLOT(twinkle()));
}

IndicatorLamp::IndicatorLamp(const IndicatorLamp &lamp)
	:QMeter(lamp.m_name,lamp.m_title,lamp.m_type,lamp.parentWidget())
{
	m_radius = lamp.m_radius;
	m_lampColor = lamp.m_lampColor;
	timer = lamp.timer;

}

IndicatorLamp::~IndicatorLamp()
{

}

void IndicatorLamp::paintEvent(QPaintEvent *)
{
	//是否显示仪表
	//if(!m_visible)
	//	hide();
	//else
	//{
	//	//if(isHidden())
	//	showNormal();
	//}
	int w = width();
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	//设置坐标轴
	setAxis(&painter);	
	//设置画笔
	painter.setPen(Qt::NoPen);
	//绘制外边框
	drawOutFrame(&painter,m_radius,QColor(Qt::white));
	//绘制内框
	drawInnerFrame(&painter,m_radius*0.85,QColor(Qt::white));
	//设置指示灯颜色
	drawInnerColor(&painter,m_radius*0.8,m_lampColor);
	//设置仪表名称
	drawContexts(&painter,QRect(-w,m_radius+5,w*2,40),m_title,30,Qt::AlignCenter,QPen(m_lampColor));
	painter.setPen(Qt::red);
	//painter.drawRect(-w,m_radius+5,w*2,25);
	if(!m_visible)
	{
		painter.setBrush(Qt::black);
		painter.drawRect(-m_radius,-m_radius,m_radius<<1,m_radius<<1);
		painter.restore();
	}
}
void IndicatorLamp::setAxis(QPainter *painter)
{
	int w = width();
	int h = height();
	int side = qMin(w,h);
	painter->translate(w/2,h/2);
	painter->scale(side/220.0,side/220.0); 

	/*painter->setPen(Qt::gray);
	painter->drawRect(-110,-110,220,220);*/
	painter->translate(m_center.x(),m_center.y()-10);
	
	/*painter->setPen(Qt::red);
	painter->drawRect(-m_radius,-m_radius,m_radius<<1,m_radius<<1);
	painter->setPen(Qt::green);
	painter->drawLine(-m_radius-5,0,m_radius+5,0);
	painter->drawLine(0,-m_radius-5,0,m_radius+5);*/
	
}
void IndicatorLamp::drawOutFrame(QPainter *painter,int radius,QColor color)
{
	painter->save();
    int red = color. red();
	int green = color.green();
	int blue = color.blue();
	QLinearGradient lg(0, -m_radius, 0, m_radius);
    lg.setColorAt(0, color);
    lg.setColorAt(1, QColor(red*0.65, green*0.65, blue*0.65));
    painter->setBrush(lg);
    painter->drawEllipse(-radius, -radius, radius << 1, radius << 1);

	painter->restore();
}
void IndicatorLamp::drawInnerFrame(QPainter *painter,int radius,QColor color)
{
	painter->save();
	int red = color. red();
	int green = color.green();
	int blue = color.blue();
    QLinearGradient lg2(0, -radius, 0, radius);
    lg2.setColorAt(0, QColor(red*0.65, green*0.65, blue*0.65));
    lg2.setColorAt(1, color);
    painter->setBrush(lg2);
    painter->drawEllipse(-radius, -radius, radius << 1, radius << 1);
	painter->restore();
}

void IndicatorLamp::drawInnerColor(QPainter *painter,int radius, QColor color)
{
	painter->save();
	int red = color. red();
	int green = color.green();
	int blue = color.blue();
	QRadialGradient rg(0,0,radius);
	rg.setColorAt(0,QColor(red,green,blue));
	rg.setColorAt(0.8,QColor(red*0.8,green*0.8,blue*0.8));
	rg.setColorAt(1,QColor(red*0.65,green*0.65,blue*0.65));
	painter->setBrush(rg);
	painter->drawEllipse(-radius,-radius,radius<<1,radius<<1);
	painter->restore();
}
void IndicatorLamp::drawContexts(QPainter *painter,QRect r, const QString str, int pixsize, int flags,QPen pen )
{
	painter->save();
	QFont font;
	font.setPixelSize(pixsize);
	font.setBold(true);
	painter->setFont(font);
	painter->setPen(pen);
	painter->drawText(r,flags, str);
	painter->restore();
}
//plubic slots
void IndicatorLamp::setType(QMeter::Type type)
{
	m_type = type;
	update();
}

void IndicatorLamp::setState(QMeter::State state)
{
	m_state = state;
	stateChanged();
	update();
}

void IndicatorLamp::setName(QString name)
{
	m_name = name;
	update();
}

void IndicatorLamp::setTitle(QString title)
{
	m_title = title;
	update();
}

void IndicatorLamp::setChannel(QString channel)
{
	m_channel = channel;
	update();
}

void IndicatorLamp::setValue(double val)
{

/*	if(val <= m_laValue || val >= m_haValue )
		m_state = Alarm;
	else if(val <= m_lwValue || val >= m_hwValue)
		m_state = Warning;
	else
		m_state = Normal;*/ 
	m_value = val;
	
	update();
}

void IndicatorLamp::setScale(double scale)
{
	m_scale = scale;
	m_radius *= m_scale;
	update();
}

void IndicatorLamp::setCenter(QPoint point)
{
	setCenter((double)point.x(),(double)point.y());
}

void IndicatorLamp::setCenter(double x, double y)
{
	m_center = QPoint(x,y);
	update();
}
void IndicatorLamp::setMeterVisible(bool visible)
{
	m_visible = visible;
	update();
}

void IndicatorLamp::setLampColor(QColor color)
{
	m_lampColor = color;
	update();
}

void IndicatorLamp::setRadius(int r)
{
	m_radius = r;
	update();
}

void IndicatorLamp::stateChanged()
{
	QColor color;
	switch(getState())
	{
	case QMeter::NoData:
		color = QColor(Qt::gray);
		break;
	case QMeter::Normal:
		color = QColor(Qt::green);
		timer->stop();
		break;
	case QMeter::Warning:
		color = QColor(Qt::yellow);
		if(!timer->isActive())
			timer->start(500);
		break;
	case QMeter::Alarm:
		color = QColor(Qt::red);
		if(!timer->isActive())
			timer->start(500);
		break;
	default:
		break;
	}
	setLampColor(color);
	update();
}

void IndicatorLamp::twinkle()
{
	m_visible  = !m_visible;
	update();
}