#include "fuelmeter.h"
#include <qmath.h>
#include "InfoMsg.h"

FuelMeter::FuelMeter(QString name, QString title,  QMeter::Type type,QWidget *parent)
	: QBaseMeter(name,title,type,parent)
{
	 m_compoment =0x0f0e ;

	m_value = 0;
	m_minValue = 0;
	m_maxValue = 100;

	m_laValue = 25;
	m_lwValue = 25;	
	m_haValue = 100;
	m_hwValue = 100;

	m_startAngle = 120;
	m_endAngle = 120;

	m_scaleMajor = 4;
	m_scaleMiddle = 2;
	m_scaleMinor = 4;
	//m_title = QStringLiteral("”ÕŒª±Ì");
}

FuelMeter::~FuelMeter()
{

}

void FuelMeter::paintEvent(QPaintEvent *e)
{
	//InfoMsg info;
	if(!m_visible)
		hide();
	else if(isHidden())
		show();

	//info.info_log("r:%d\n",m_radius);
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	setAxis(&painter);

	if(m_compoment & BackGround)
		drawBackground(&painter);
	if(m_compoment & Crown)
		drawCrown(&painter,m_radius);

	drawScale(&painter,m_radius);

	if(m_compoment & DoubleMeter)
	{
		drawInnerScale(&painter,m_center,m_radius-m_strech);
		drawInnerScaleNum(&painter,m_center,m_radius-m_strech);
	}
	if(m_compoment & NumericValue)
		drawNumericValue(&painter);

	//draw units
	if((m_compoment & Units) || (m_compoment & NumericRate))
	{
		if(!(m_compoment & NumericRate))		//rate is invisible
		{
			int haltw = int(1.7*m_radius); 
			QRect r(-haltw,-m_radius/2-8,haltw<<1,16);
			drawContexts(&painter,QRect(r),m_units,16*m_scale,Qt::AlignCenter,QPen(Qt::darkMagenta));
	 	}
		else	 
		{
		   	QRect r(-40,10,80,20);	 
			QString rate = QStringLiteral("°¡") + QString("%1").arg(m_rate);
			if(m_compoment & Units)		   //units is visible
				rate += " "+m_units;
			drawContexts(&painter,QRect(r),rate,12*m_scale,Qt::AlignCenter,QPen(Qt::darkMagenta));
		}
	}
	//draw title
	if(m_compoment & Title)
	{
		QRect rect(-width()/2,m_radius+5,width(),18);
		drawContexts(&painter,rect,m_title,18*m_scale,Qt::AlignCenter,QPen(Qt::yellow));
	}
	drawEF(&painter);
	drawLogo(&painter);
	drawIndicator(&painter);
}

void FuelMeter::drawLogo(QPainter *painter)
{
	painter->save();

	painter->setPen(m_scaleMinorColor);
	if(getValue()>=0.2*maxValue())
		painter->setBrush(Qt::blue);
	else
		painter->setBrush(Qt::red);

	painter->setPen(QPen(Qt::white,2));
	QPainterPath path;
	double x = Radius()/2-20;
	double y = -Radius()/2+40;
	path.moveTo(x,y);
	path.lineTo(x,y-40);
	path.lineTo(x+20,y-40);
	path.lineTo(x+20,y);
	painter->drawPath(path);
	painter->drawLine(x-5,y,x+25,y);
	
	painter->drawLine(x,y-20,x+20,y-20);
	painter->drawArc(x+15,y-20,10,10,0,90*16);
	painter->drawLine(x+25,y-15,x+25,y-8);
	painter->drawArc(x+25,y-11,6,6,180*16,180*16);
	painter->drawLine(x+31,y-8,x+31,y-20);
	painter->drawArc(x+25,y-26,6,12,0,90*16);
	painter->restore();
}

void FuelMeter::drawEF(QPainter *painter)
{
	painter->save();
	int fontsize = 12;
	int rotateAngle;
	QRect rect;
	if(m_startAngle<90 || m_startAngle>270)
	{
		rotateAngle = m_startAngle;
		rect = 	QRect(0,m_radius-fontsize,16,fontsize);
	}
	else
	{
		rotateAngle = m_startAngle+180;
		rect = QRect(-16,-m_radius,16,fontsize);
	}
	painter->rotate(rotateAngle);
	drawContexts(painter,rect,"E",fontsize);
	
	painter->rotate(-rotateAngle);
	if(m_endAngle>90 && m_endAngle<270)
	{
		rotateAngle = 180-m_endAngle;
		rect = QRect(0,-m_radius,16,fontsize);
	}
	else
	{
		rotateAngle = -m_endAngle;
		rect = QRect(-16,m_radius-fontsize,16,fontsize);
	}
	painter->rotate(rotateAngle);
	drawContexts(painter,rect,"F",fontsize);
	painter->restore();
}
