#include "thermometer.h"
#include <qpainter.h>
#include <qpixmap.h>
#include <qmessagebox.h>

ThermoMeter::ThermoMeter(QString name,QString title, QMeter::Type type, QWidget *parent)
	: QMeter(name,title,type,parent)
{
	m_width = 100;
	m_heigth = 300;
	m_minValue =0;
	m_maxValue = 100;
	m_majorSteps = 10;
	m_minorNum = 5;
	m_minorSteps = 2;
	m_majorLength = 10;
	m_minorLength = 6;
	m_majorWidth = 3;
	m_minorWidth = 1;
	m_liquidColor = QColor(Qt::green);
	//m_title = QStringLiteral("温度计");
	/*set the background color*/
	QPalette p = palette();
	p.setBrush(QPalette::Background,Qt::black);
	setPalette(p);
	setAutoFillBackground(true);
	//setMinimumSize(100,320);
	//resize(200,620);
}

ThermoMeter::~ThermoMeter()
{

}

void ThermoMeter::paintEvent(QPaintEvent *)
{
	QPainter painter(this);	
	painter.setRenderHint(QPainter::Antialiasing); 	/* 使用反锯齿(如果可用) */
	setAxis(&painter);

	int w= m_width>>1;
	int h = (m_heigth>>1)-10;

	/* 绘制液体容器圆 */
	painter.setPen(Qt::NoPen);
	painter.setBrush(Qt::white);
	painter.setBrush(Qt::gray);
	double s = 0.6;		 //液体容器圆占窗体宽度的比例
	painter.drawEllipse(-w*s,h,w*s,-w*s);
		
	/* 绘制液体容器柱(外边框) */
	//painter.setBrush(m_foreground);
	painter.setBrush(Qt::gray);
	painter.drawRect(-0.75*w*s , h-w*s/2 , w*s/2 ,-(m_heigth-20-w*s/2) );

	/*绘制刻度线*/
	int majorNum = (m_maxValue - m_minValue)/m_majorSteps;	//计算大刻度数
	if((m_maxValue-m_minValue)%m_majorSteps)
		majorNum++;
	//计算实际温度计的最大量程
	int scaleMaxValue = majorNum*m_majorSteps+m_minValue;
	//总刻度数
	int steps = m_minorNum * majorNum;
	//每一个小刻度的坐标间隔
	double ystep = (2*h-w*s-5)/steps;
	//最小刻度的y轴坐标
	double y = h-w*s;

	QPen pen;
	for(int i = 0;i<=steps;i++,y-=ystep)
	{
		if(i % m_minorNum == 0) //大刻度
		{
			pen.setWidth(m_majorWidth);
			pen.setColor(Qt::green);
			painter.setPen(pen);
			//绘制刻度线
			painter.drawLine(QPointF(-w*s/3.0+1, y) ,QPointF(-w*s/3.0+m_majorLength, y));
			//绘制刻度值
			double tmpVal = m_minValue+i*m_minorSteps;
			drawContexts(&painter,QRect(-w*s/3.0+m_majorLength+5,y-4,40,12), QString::number((int)tmpVal),10,Qt::AlignLeft,QPen(Qt::white));
		}
		else					  //绘制小刻度线
		{
			pen.setWidth(m_minorWidth);
			pen.setColor(Qt::gray);
			painter.setPen(pen);
			painter.drawLine(QPointF(-w*s/3.0+1 , y) ,QPointF( -w*s/3.0+1+m_minorLength , y) );
		}
	}
	
	/*绘制液体圆*/
	painter.setPen(Qt::NoPen);
	painter.setBrush(m_liquidColor);
	painter.drawEllipse(-0.8*w*s,h-w*s*0.2,w*s*0.6,-w*s*0.6);
	/*绘制液体柱（指示）*/
	double val = (m_value -m_minValue)/m_minorSteps * ystep ;	//示数的高度
	painter.drawRect(-0.6*w*s,h-w*s*0.6,0.2*w*s,-(val+0.4*w*s));

	/*绘制单位*/
	drawContexts(&painter,QRect(0,h-w*s,w*s,w*s),QStringLiteral("℃"),16,Qt::AlignCenter,QPen(Qt::yellow));
	/*绘制仪表名称*/
	drawContexts(&painter,QRect(-width(),h+5,(width()<<1)-w*s,20),m_title,16);

}

void ThermoMeter::setAxis(QPainter *painter)
{
	int w = width();
	int h = height();
	int side = qMin(w,h);
	painter->translate(w/2,h/2);
	painter->scale(side/310.0,side/310.0);
	painter->translate(m_center.x(),m_center.y()-10);
}

void ThermoMeter::drawContexts(QPainter *painter,QRect r, const QString str, int pixsize, int flags,QPen pen )
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
void ThermoMeter::setType(QMeter::Type type)
{
	m_type = type;
	update();
}

void ThermoMeter::setState(QMeter::State state)
{
	m_state = state;
	switch(state)
	{
	case Alarm:
	case Warning:
		setLiuidColor(Qt::red);
		break;
	case Normal:
		setLiuidColor(Qt::green);
		break;
	default:
		setLiuidColor(Qt::gray);
	}
	update();
}

void ThermoMeter::setName(QString name)
{
	m_name = name;
	update();
}

void ThermoMeter::setTitle(QString title)
{
	m_title = title;
	update();
}

void ThermoMeter::setChannel(QString channel)
{
	m_channel = channel;
	update();
}

void ThermoMeter::setValue(double val)
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

void ThermoMeter::setScale(double scale)
{
	m_scale = scale;
	m_width *= scale;
	m_heigth *= scale;
	update();
}

void ThermoMeter::setCenter(QPoint point)
{
	setCenter((double)point.x(),(double)point.y());
}

void ThermoMeter::setCenter(double x, double y)
{
	m_center = QPoint(x,y);
	update();
}
void ThermoMeter::setMeterVisible(bool visible)
{
	m_visible = visible;
	update();
}

void ThermoMeter::setWidth(int w)
{
	m_width = w;
	update();
}

void ThermoMeter::setHeight(int h)
{
	m_heigth = 	h;
	update();
}
void ThermoMeter::setMinValue(int val)
{
	m_minValue = val;
	setValue(val);
	update();
}

void ThermoMeter::setMaxValue(int val)
{
	m_maxValue = val;
	update();
}

void ThermoMeter::setScaleSteps(Scale scale,double steps)
{
	if(scale == Major)
	{
		m_majorSteps = (int) steps;
		m_minorNum = (int)(steps/m_minorSteps);
		
	}
	else
	{
		m_minorSteps = steps;
		m_minorNum = (int)(m_majorSteps / steps);
		//QMessageBox::about(0,"set minor",QString::number(steps));
	}

	m_minorNum =int(m_majorSteps / m_minorSteps);
	if(m_minorNum<1)
	{
		m_minorNum = 1;
		m_minorSteps = m_majorSteps;
	}
	//QMessageBox::about(0,"debug","steps:"+QString::number(steps)+"minor:"+QString::number(m_minorSteps));
	update();
}

void ThermoMeter::setScaleLength(Scale scale, int length)
{
   	if(scale == Major)
	{
		m_majorLength = length;
	}
	else
	{
		m_minorLength = length;
	}
	update();
}

void ThermoMeter::setScaleWidth(Scale scale, int width)
{
	if(scale == Major)
	{
		m_majorWidth = width;
	}
	else
	{
		m_minorWidth = width;
	}
	update();
}

void ThermoMeter::setLiuidColor(QColor color)
{
	m_liquidColor = color;
	update();
}

double ThermoMeter::ScaleSteps(Scale scale)	
{
	setScaleSteps(Minor,m_majorSteps/(m_minorNum*1.0));
	double steps;
	if(scale == Scale::Minor)
		steps = m_minorSteps;
	if(scale == Scale::Major)
		steps = double(m_majorSteps);
	//QMessageBox::about(0,"steps",QString::number(steps));
	return steps;
}

int  ThermoMeter::ScaleLength(Scale scale)	const
{
	if(scale == Major)
		return m_majorLength;
	else
		return m_minorLength;
}

int ThermoMeter::ScaleWidth(Scale scale) const
{
   if(scale == Major)
	   return m_majorWidth;
   else
	   return m_minorWidth;
}