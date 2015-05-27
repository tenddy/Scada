#include "enginemeter.h"
#include <qtimer.h>
#include <qmessagebox.h>

EngineMeter::EngineMeter(QString name, QString title, QMeter::Type type,QWidget *parent)
	: QBaseMeter(name,title,type,parent)
{
	m_runtime = 0;
	
    m_minValue = 0;
    m_maxValue = 40; 
	m_value = m_minValue;
	m_laValue = 25;
	m_haValue = 40;
	m_lwValue = 15;
	m_hwValue = 25;

	m_startAngle =60;
	m_endAngle =60;

	m_scaleMajor = 10;
	m_scaleMiddle = 2;
    m_scaleMinor = 4;

	m_units = QStringLiteral("RPM"); 
	//m_title = QStringLiteral("×ªËÙ±í");
	m_compoment =0x0C0E;
	m_precision = 2;
	QTimer *timer = new QTimer(this);
	//timer->connect(timer,SIGNAL(timeout()),this,SLOT(changeValue()));
	timer->connect(timer,SIGNAL(timeout()),this,SLOT(setRuntime()));
	timer->start(1000);
}

EngineMeter::~EngineMeter()
{

}

void EngineMeter::paintEvent(QPaintEvent *)
{
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
	drawScaleNum(&painter,m_radius);
	
	drawNumericValue(&painter);

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
			int haltw1 = int(1.7*m_radius); 
			QRect r(-haltw1,-m_radius/2,haltw1<<1,16);
		   	//QRect r(-40,15,80,20);	 
			QString rate = QStringLiteral("¡Á") + QString("%1").arg(m_rate);
			if(m_compoment & Units)		   //units is visible
				rate += " "+m_units;
			drawContexts(&painter,QRect(r),rate,16*m_scale,Qt::AlignCenter,QPen(Qt::darkMagenta));
		}
	}
	//draw title
	if(m_compoment & Title)
	{
		QRect rect(-width()/2,m_radius+2,width(),18);
		drawContexts(&painter,rect,m_title,18*m_scale,Qt::AlignCenter,QPen(Qt::yellow));
	}

	drawRuntime(&painter);
	drawIndicator(&painter);
}

void EngineMeter::drawRuntime(QPainter *painter)
{
	painter->save();
	int number[4];
	int t = m_runtime/60;
	int N=1000;
	for(int i=0;i<4;i++)//number[0]=0;number[1]=0;number[2]=0;number[3]=0;t0=0;t1=0;t2=0;t3=0;N1=100;N2=10;N3=1;N4=0;
	{
		number[i] = t/N;
		t%=N;
		N/=10;
	}
	int side = m_radius/5;
	QRect r[4];
	for(int i=0;i<4;i++)
		r[i].setRect(-2*side+i*side,m_radius/3,0.8*side,side);
	painter->setBrush(QBrush(Qt::blue,Qt::SolidPattern));
	for(int i=0;i<4;i++)
		painter->drawRect(r[i]);
	painter->setPen(QPen(Qt::white,16));
	for(int i=0;i<4;i++)
		painter->drawText(r[i],Qt::AlignCenter,QString("%1").arg(number[i]));
	drawContexts(painter,QRect(2*side,m_radius/3,side/2,side),"h",side); 

	painter->restore();
}


void EngineMeter::drawNumericValue(QPainter *painter,int flags , QPen pen)
{
    QString str  =  QString("%1").arg(m_value, 0, 'f', m_precision);
    QFontMetricsF fm(font());
    double w = fm.size(Qt::TextSingleLine,str).width();
	double h = fm.size(Qt::TextSingleLine,str).height();
	QRect rect(-w/2,-20-h,w,h);
	drawContexts(painter,rect,str,12,flags,pen);
}
void EngineMeter::setRuntime(int time)
{
	m_runtime = time;  
	update();
}
void EngineMeter::setRuntime()
{
	m_runtime++ ;    //sec
	update();
}
void EngineMeter::changeValue()
{

}
