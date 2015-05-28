#include "qbasemeter.h"
#include "InfoMsg.h"

#include <QPixmap>
#include <QMessageBox>
#include <QTimer>
#include <QTime>


QBaseMeter::QBaseMeter(QString name, QString title,QBaseMeter::Type type, QWidget *parent):
	QMeter(name,title,type,parent)
{
    pixmap = QPixmap(400,400);
    pixmap.fill(Qt::black);

    isDrawing = false;

    m_radius = 100 * m_scale;
	m_compoment = Title | Units | NumericValue | BackGround;
    m_units = QStringLiteral("N/A");
   /* m_title = QStringLiteral("仪表");*/
    m_precision = 1;
	m_rate = 1;
    m_startAngle = 60;
    m_endAngle = 60;
    m_innerScaleSteps = 20;
    m_factor = 1.6;
    m_strech = 40;

    m_minValue = 0;
    m_maxValue = 100;
	m_value = m_minValue;
	m_WAEnabled = true;
    m_laValue = 10;
    m_lwValue = 20;
    m_hwValue = 80;
	m_haValue = 90;

	m_middleVisiable = false;
	m_scaleMajor = 10;
	m_scaleMiddle = 5;
    m_scaleMinor = 10;
	m_scaleMajorLength = 8;
	m_scaleMiddleLength = 4;
	m_scaleMinorLength = 2;
	m_scaleMajorWidth = 3;
	m_scaleMiddleWidth = 2;
	m_scaleMinorWidth = 2;
	m_scaleMajorColor = QColor(Qt::darkCyan);
	m_scaleMiddleColor = QColor(Qt::cyan);
    m_scaleMinorColor = QColor(Qt::white);

	m_backgroundColor = QColor(Qt::black);
	m_crownColor = QColor(200,200,210);
	m_textColor = QColor(Qt::darkGreen);
	m_indicatorColor = QColor(Qt::darkYellow);

	QPalette palette;
	palette.setColor(QPalette::Window,m_backgroundColor);
	setPalette(palette);
	//setMinimumSize(220,220);
    //drawMeterFrame();
	resize(400,400);
   /* QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(ChangeValue()));
    timer->start(100);*/
}

QBaseMeter::~QBaseMeter()
{

}


/*
**  @description:
**	绘制图形
**  @parameter:NULL
**
**  @return value:NULL
**
**  author:teddy.tu
**  date:
**
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void QBaseMeter::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);
	setAxis(&painter);

    /*
	if(m_compoment & BackGround)
		drawBackground(&painter);
	if(m_compoment & Crown)
		drawCrown(&painter,m_radius);

	drawScale(&painter,m_radius);
	drawScaleNum(&painter,m_radius);

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
			QString rate = QStringLiteral("×") + QString("%1").arg(m_rate);
			if(m_compoment & Units)		   //units is visible
				rate += " "+m_units;
			drawContexts(&painter,QRect(r),rate,12*m_scale,Qt::AlignCenter,QPen(Qt::darkMagenta));
		}
	}
	//draw title
	if(m_compoment & Title)
	{
		QRect rect(-width()/2,m_radius+2,width(),18);
		drawContexts(&painter,rect,m_title,18*m_scale,Qt::AlignCenter,QPen(Qt::yellow));
	}
    */

	painter.drawPixmap(-100,-110,200,200,pixmap);
    //draw title
    if(m_compoment & Title)
    {
        QRect rect(-width()/2,m_radius-20,width(),18);
        drawContexts(&painter,rect,m_title,18*m_scale,Qt::AlignCenter,QPen(Qt::white));
    }
    drawIndicator(&painter);
    

	//hide the meter
    if(!m_visible)
        drawBackground(&painter);

 //   QRect r(20,-10,40,40);
 //   drawPixMap(&painter,r);
}

void QBaseMeter::setAxis(QPainter *painter)
{
	int w = width();
	int h = height();
	int side = qMin(w,h);
	painter->translate(w/2,h/2);
	painter->scale(side/220.0,side/220.0);
	painter->translate(m_center.x(),m_center.y());
}
/*
**  @description:
**
**  @parameter:NULL
**
**  @return value:NULL
**
**  author:teddy.tu
**  date:
**
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void QBaseMeter::drawCrown(QPainter *painter,int radius)
{
	painter->save();
	painter->setBrush(QBrush(m_crownColor));
    painter->drawEllipse(-radius-1, -radius-1, (radius << 1) +2, (radius << 1) +2);
	painter->restore();	
}


/*
**  @description:
**	设置背景颜色
**  @parameter:NULL
**
**  @return value:NULL
**
**  author:teddy.tu
**  date:
**
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void QBaseMeter::drawBackground(QPainter *painter)
{
	painter->save();
	painter->setBrush(m_backgroundColor);
	painter->drawRect(-width(),-height(),2*width(),2*height());
	painter->restore();
	//QPalette palette;
	//palette.setColor(QPalette::Window,m_backgroundColor);
	//setPalette(palette);
}

/*
**  @description:
**	绘制刻度线
**  @parameter:NULL
**
**  @return value:NULL
**
**  author:teddy.tu
**  date:
**
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void QBaseMeter::drawScale(QPainter *painter, int radius,QPoint center)
{
	painter->save();
	if(m_middleVisiable)
		m_scaleMiddle = m_scaleMinor/2;
    painter->rotate(m_startAngle);
	int steps = m_scaleMajor * m_scaleMinor;
    double angleStep = (360.0 - m_startAngle - m_endAngle) / steps;
   
	int scalerange = m_maxValue - m_minValue;
	int lowerwarning = (steps * m_lwValue / scalerange) / m_rate;
	int upperwarning = (steps * m_hwValue / scalerange) / m_rate;
	int loweralarm = (steps * m_laValue / scalerange) / m_rate;
	int upperalarm	= (steps * m_haValue / scalerange) / m_rate;

    QPen pen = painter->pen();
	QColor color = pen.color();
	for (int i = 0; i <= steps; i++)
    {
		if(m_WAEnabled && (m_compoment & 0x0f00))
		{
			if(((m_compoment&0x0100) && (i <= loweralarm)) || ((m_compoment&0x0800) && (i>= upperalarm)) )	 //	 报警值颜色
				color = QColor(Qt::red);
			else if(((m_compoment&0x0200) &&( i <= lowerwarning)) || ((m_compoment&0x0400) && (i>= upperwarning)))	//预警值颜色
				color = QColor(Qt::yellow);
			else
				color = QColor(m_scaleMinorColor);		//正常颜色
		}
		else
		{
			if(i%m_scaleMinor == 0)			  //大刻度颜色
				color = m_scaleMajorColor;
			else if(m_middleVisiable && i%m_scaleMiddle == 0)	  //中刻度颜色
				color = m_scaleMiddleColor;
			else							  //小刻度颜色
				color = m_scaleMinorColor;
		}

		pen.setColor(color);
		if (i % m_scaleMinor == 0)
        {
			pen.setWidth(m_scaleMajorWidth);
            painter->setPen(pen);  
			painter->drawLine(0, radius, 0, radius-m_scaleMajorLength);	
        }
		else if(m_middleVisiable && i%m_scaleMiddle == 0)
		{
			pen.setWidth(m_scaleMiddleWidth);
            painter->setPen(pen);
			painter->drawLine(0, radius, 0, radius-m_scaleMiddleLength);
		}
        else
        {
			pen.setWidth(m_scaleMinorWidth);
            painter->setPen(pen);
			painter->drawLine(0, radius, 0, radius-m_scaleMinorLength);
		}
        painter->rotate(angleStep);
    }
    painter->restore();
}

void QBaseMeter::drawScale(int radius, QPoint center /* = QPoint(0,0) */)
{
    QPainter painter;
    //painter.begin(&pixmap);
    QPicture picture;
    painter.begin(&picture);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(100,100);
    //painter.setPen(Qt::red);
    //painter.scale(100/200.0,100/200.0);
    if(m_middleVisiable)
        m_scaleMiddle = m_scaleMinor/2;
    painter.rotate(m_startAngle);
    int steps = m_scaleMajor * m_scaleMinor;
    double angleStep = (360.0 - m_startAngle - m_endAngle) / steps;

    int scalerange = m_maxValue - m_minValue;
    int lowerwarning = (steps * m_lwValue / scalerange) / m_rate;
    int upperwarning = (steps * m_hwValue / scalerange) / m_rate;
    int loweralarm = (steps * m_laValue / scalerange) / m_rate;
    int upperalarm	= (steps * m_haValue / scalerange) / m_rate;

    QPen pen = painter.pen();
    QColor color = pen.color();
    for (int i = 0; i <= steps; i++)
    {
        if(m_WAEnabled && (m_compoment & 0x0f00))
        {
            if(((m_compoment&0x0100) && (i <= loweralarm)) || ((m_compoment&0x0800) && (i>= upperalarm)) )	 //	 报警值颜色
                color = QColor(Qt::red);
            else if(((m_compoment&0x0200) &&( i <= lowerwarning)) || ((m_compoment&0x0400) && (i>= upperwarning)))	//预警值颜色
                color = QColor(Qt::yellow);
            else
                color = QColor(m_scaleMinorColor);		//正常颜色
        }
        else
        {
            if(i%m_scaleMinor == 0)			  //大刻度颜色
                color = m_scaleMajorColor;
            else if(m_middleVisiable && i%m_scaleMiddle == 0)	  //中刻度颜色
                color = m_scaleMiddleColor;
            else							  //小刻度颜色
                color = m_scaleMinorColor;
        }

        pen.setColor(color);
        if (i % m_scaleMinor == 0)
        {
            pen.setWidth(m_scaleMajorWidth);
            painter.setPen(pen);  
            painter.drawLine(0, radius, 0, radius-m_scaleMajorLength);	
        }
        else if(m_middleVisiable && i%m_scaleMiddle == 0)
        {
            pen.setWidth(m_scaleMiddleWidth);
            painter.setPen(pen);
            painter.drawLine(0, radius, 0, radius-m_scaleMiddleLength);
        }
        else
        {
            pen.setWidth(m_scaleMinorWidth);
            painter.setPen(pen);
            painter.drawLine(0, radius, 0, radius-m_scaleMinorLength);
        }
        painter.rotate(angleStep);
    }

    painter.end();
    picture.save("meter.pic");
}

/*
**  @description:
**	绘制刻度值
**  @parameter:NULL
**
**  @return value:NULL
**
**  author:teddy.tu
**  date:
**
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void QBaseMeter::drawScaleNum(QPainter *painter,int  radius,QPoint center)
{
	//InfoMsg info;
    painter->save();
    double startRad = (360 - m_startAngle - 90) * (3.14 / 180);
	double steps = (m_maxValue - m_minValue)*1.0/m_scaleMajor;
	double deltaRad = (360 - m_startAngle - m_endAngle) * (3.14 / 180) / m_scaleMajor;
    double sina,cosa;
    double x, y;
	
    QFontMetricsF fm(this->font());
  
	double w, h, tmpVal;
    QString str;
	//info.info_log("\n%d,%d,steps:%f,major:%d ",m_minValue,m_maxValue,steps,m_scaleMajor);
	for (int i = 0; i <= m_scaleMajor; i++)
    {
        sina = sin(startRad - i * deltaRad);
        cosa = cos(startRad - i * deltaRad);

        tmpVal = int(i * steps + m_minValue);
		//info.info_log("%4.2f ",tmpVal);
		str = QString(" %1 ").arg(tmpVal);
        w = fm.size(Qt::TextSingleLine,str).width()+16;
        h = fm.size(Qt::TextSingleLine,str).height()+10;
		x = center.x() + (radius-12-m_scaleMajorLength) * cosa - w / 2;
		y = center.y() - (radius-12-m_scaleMajorLength) * sina - h / 2;
		const QRectF r(x,y,w,h);
		QFont font;
		font.setPixelSize(12*m_scale);
		painter->setFont(font);
		painter->setPen(QPen(m_textColor));
		painter->drawText(r,Qt::AlignCenter,str);
	}
    painter->restore();
}

/*
**  @description:
**	绘制双表盘的内部刻度线
**  @parameter:NULL
**
**  @return value:NULL
**
**  author:teddy.tu
**  date:
**
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void QBaseMeter::drawInnerScale(QPainter *painter, QPointF center,double radius)
{
	painter->save();
    painter->rotate(m_startAngle);
	double c_x = center.x();
	double c_y = center.y();
	int steps = (m_maxValue - m_minValue)*m_factor/m_innerScaleSteps *2;
	double angleStep = (360.0 - m_startAngle - m_endAngle) / steps;
    QPen pen = painter->pen();
	pen.setColor(Qt::white);
    for (int i = 0; i <= steps; i++)
    {
        if (i % 2 == 0) //draw major tick
        {
            pen.setWidth(2);
            painter->setPen(pen);  
			painter->drawLine(c_x,radius, c_y, radius-6);	
        }
		else
        {
            pen.setWidth(2);
            painter->setPen(pen);
			painter->drawLine(c_x, radius, c_y, radius-3);
		}
        painter->rotate(angleStep);
    }
	
    painter->restore();
}

/*
**  @description:
**	绘制内部表盘的刻度值
**  @parameter:NULL
**
**  @return value:NULL
**
**  author:teddy.tu
**  date:
**
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void QBaseMeter::drawInnerScaleNum(QPainter *painter,QPointF center,double radius)
{
	painter->save();
    double startRad = (360 - m_startAngle - 90) * (3.14 / 180);
	int steps = (m_maxValue - m_minValue)*m_factor/m_innerScaleSteps;
	double deltaRad = (3.14/180) * (360.0 - m_startAngle - m_endAngle) / steps;
    double sina,cosa;
    int x, y;
	
    QFontMetricsF fm(this->font());
	double w, h, tmpVal;
    QString str;
	painter->setPen(QPen(QColor(120,240,240),2,Qt::SolidLine,Qt::SquareCap));
    for (int i = 0; i <= steps; i++)
    {
        sina = sin(startRad - i * deltaRad);
        cosa = cos(startRad - i * deltaRad);

		tmpVal = i *m_innerScaleSteps +m_minValue*m_scale;
        str = QString( "%1" ).arg(tmpVal);
        w = fm.size(Qt::TextSingleLine,str).width();
        h = fm.size(Qt::TextSingleLine,str).height();
        x = (radius-15) * cosa - w / 2;
        y = -(radius-15) * sina - h / 2;
		const QRectF r(x,y,w,h);
		QFont font;
		font.setPixelSize(8);
		painter->setFont(font);
		painter->drawText(r,Qt::AlignCenter,str);
	}
	QRect rect(-radius-1,-radius-1,2*radius+2,2*radius+2);
	painter->drawArc(rect,(m_endAngle-90)*16,(360-m_startAngle-m_endAngle)*16);
    painter->restore();
}

/*
**  @description:
**	绘制指针
**  @parameter:NULL
**
**  @return value:NULL
**
**  author:teddy.tu
**  date:
**
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void QBaseMeter::drawIndicator(QPainter *painter, QColor color)
{
    painter->save();    
	//画指针
    QPolygon pts;
	int py = m_radius-m_scaleMajorLength-2;
	pts.setPoints(3, -2,0, 2,0, 0,py);	/* (-2,0)/(2,0)/(0,60) */
	double degRotate = (360.0 - m_startAngle - m_endAngle)/(m_maxValue - m_minValue)*(m_value - m_minValue);
	painter->rotate(degRotate+m_startAngle);
    QRadialGradient haloGradient(0, 0, 80, 0, 0);
    haloGradient.setColorAt(0, QColor(255,255,10));
    haloGradient.setColorAt(1, QColor(255,255,0));
    painter->setPen(QColor(255,255,0));
    painter->setBrush(haloGradient);
    painter->drawConvexPolygon(pts);
   
	//画中心点
    QColor niceBlue(color);
    QConicalGradient coneGradient(0, 0, -90.0);
    coneGradient.setColorAt(0.0, Qt::darkGray);
    coneGradient.setColorAt(0.2, niceBlue);
    coneGradient.setColorAt(0.5, Qt::white);
    coneGradient.setColorAt(1.0, Qt::darkGray);
    //painter->setPen(Qt::NoPen);
    painter->setBrush(coneGradient);
    painter->drawEllipse(-5, -5, 10, 10);  
	
	painter->restore();	 
}

/*
**  @description:
**	显示当前指针所指的刻度值
**  @parameter:NULL
**
**  @return value:NULL
**
**  author:teddy.tu
**  date:
**
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void QBaseMeter::drawNumericValue(QPainter *painter,int flags , QPen pen)
{
	//InfoMsg info;
	//info.info_error("Draw\tm_rate:%f,m_value:%f\n",m_rate,m_value);
    QString str  =  QString("%1").arg(m_value, 0, 'f', m_precision);
    QFontMetricsF fm(font());
    double w = fm.size(Qt::TextSingleLine,str).width();
	double h = fm.size(Qt::TextSingleLine,str).height();
	QRect rect(-w/2,-20-h,w,h);
	drawContexts(painter,rect,str,16,flags,pen);
}

/*
**  @description:
**	显示文本
**  @parameter:NULL
**
**  @return value:NULL
**
**  author:teddy.tu
**  date:
**
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void QBaseMeter::drawContexts(QPainter *painter,QRect r, const QString str, int pixsize, int flags,QPen pen )
{
	painter->save();
	QFont font;
	font.setPixelSize(pixsize);
	painter->setFont(font);
	painter->setPen(pen);
	painter->drawText(r,flags, str);
	painter->restore();
}

/*
**  @description:
**	重载函数，显示文本
**  @parameter:NULL
**
**  @return value:NULL
**
**  author:teddy.tu
**  date:
**
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void QBaseMeter::drawContexts(QPainter *painter,QPointF point, const QString str, int pixsize, int flags,QPen pen  )
{
	painter->save();
    QFontMetricsF fm(this->font());
    double w = fm.size(Qt::TextSingleLine,str).width();
	double h = fm.size(Qt::TextSingleLine,str).height();
	QFont font;
	font.setPixelSize(pixsize);
	painter->setFont(font);
	painter->setPen(pen); 
	painter->drawText(QRect(point.x(),point.y(),w,h),flags, str);
	painter->restore();
}

/*
**  @description:
**	绘制logo
**  @parameter:NULL
**
**  @return value:NULL
**
**  author:teddy.tu
**  date:
**
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void QBaseMeter::drawLogo(QPainter *painter, QRect rect)
{

}

void QBaseMeter::drawPixMap(QPainter *painter, QRect rect)
{
    painter->save();
    QPixmap pixmap(":/fuel");
    //painter->setPen(Qt::white);
    //painter->setBrush(Qt::black);
    //painter->drawRect(rect);
    //painter->setPen(Qt::red);
    painter->drawPixmap(rect, pixmap);
    painter->restore();
}

void QBaseMeter::drawMeterFrame()
{
    QPainter painter;
    painter.begin(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.scale(400/200,400/200);
    painter.translate(100,110);
  
    if(m_compoment & BackGround)
        drawBackground(&painter);
    if(m_compoment & Crown)
        drawCrown(&painter,m_radius);

    drawScale(&painter,m_radius);
    drawScaleNum(&painter,m_radius);

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
            QString rate = QStringLiteral("×") + QString("%1").arg(m_rate);
            if(m_compoment & Units)		   //units is visible
                rate += " "+m_units;
            drawContexts(&painter,QRect(r),rate,12*m_scale,Qt::AlignCenter,QPen(Qt::darkMagenta));
        }
    }
    ////draw title
    //if(m_compoment & Title)
    //{
    //    QRect rect(-width()/2,m_radius+2,width(),18);
    //    painter.setPen(Qt::red);
    //    painter.drawRect(rect);
    //    drawContexts(&painter,rect,m_title,18*m_scale,Qt::AlignCenter,QPen(Qt::yellow));
    //}
    painter.end();
}


int QBaseMeter::ScaleLineNum(ScaleLine line)
{
	if(line == Major)
		return m_scaleMajor;
	else if(line == Middle)
		return m_scaleMiddle;
	else
		return m_scaleMinor;
}

int QBaseMeter::ScaleLineLength(ScaleLine line)
{
	if(line == Major)
		return m_scaleMajorLength;
	else if(line == Middle)
		return m_scaleMiddleLength;
	else
		return m_scaleMinorLength;
}

int QBaseMeter::ScaleLineWidth(ScaleLine line)
{
	if(line == Major)
		return m_scaleMajorWidth;
	else if(line == Middle)
		return m_scaleMiddleWidth;
	else
		return m_scaleMinorWidth;
}

QColor QBaseMeter::ScaleLineColor(ScaleLine line)
{
	if(line == Major)
		return m_scaleMajorColor;
	else if(line == Middle)
		return m_scaleMiddleColor;
	else
		return m_scaleMinorColor;
}
//plubic slots
void QBaseMeter::setType(QMeter::Type type)
{
	m_type = type;
    drawMeterFrame();
	update();
}

void QBaseMeter::setState(QMeter::State state)
{
	m_state = state;
    drawMeterFrame();
	update();
}

void QBaseMeter::setName(QString name)
{
	m_name = name;
    drawMeterFrame();
	update();
}

void QBaseMeter::setTitle(QString title)
{
	m_title = title;
    drawMeterFrame();
	update();
}

void QBaseMeter::setChannel(QString channel)
{
	m_channel = channel;
	drawMeterFrame();
    update();
}

void QBaseMeter::setValue(double val)
{
	InfoMsg info;
	val = val/m_rate;
	//info.info_error("rate:%d,val:%f,val/rate:%f",m_rate,val,val/m_rate);
	if(val<m_minValue)
		m_value = m_minValue;
	else if(val > m_maxValue)
		m_value = m_maxValue;
	else
	{
		if(val <= m_laValue || val >= m_haValue )
			m_state = Alarm;
		else if(val <= m_lwValue || val >= m_hwValue)
			m_state = Warning;
		else
			m_state = Normal; 
		m_value = val;
	}
	update();
}
void QBaseMeter::setRate(double rate)
{
	m_rate = rate;
	setCompoment(NumericRate,rate = 1);
    drawMeterFrame();
	update();
}
void QBaseMeter::setScale(double scale)
{
	m_scale = scale;
	m_radius *= m_scale;
    drawMeterFrame();
	update();
}

void QBaseMeter::setCenter(QPoint point)
{
	setCenter((double)point.x(),(double)point.y());
}

void QBaseMeter::setCenter(double x, double y)
{
	/*InfoMsg  info;
	info.infoClearFile("log.txt");
	info.info_log("%d,%d\n",geometry().x(),geometry().y());*/
	m_center = QPoint(x,y);
    drawMeterFrame();
	update();
}
void QBaseMeter::setMeterVisible(bool visible)
{
	m_visible = visible;
    drawMeterFrame();
	update();
}
void QBaseMeter::setRadius(double radius)
{
	m_radius = radius * m_scale;
    drawMeterFrame();
	update();
}

void QBaseMeter::ScaleRadius(double scale)
{
	m_radius *= m_scale;
    drawMeterFrame();
	update();
}

void QBaseMeter::setCompoment(Compoment compoment, bool enabled )
{
	if(enabled)
		m_compoment |= compoment;
	else
		m_compoment &= ~compoment;
    drawMeterFrame();
	update();
}

void QBaseMeter::setUnits(QString units)
{
    m_units = units;
    drawMeterFrame();
    update();
}

void QBaseMeter::setPrecision(int precision)
{
	m_precision = precision;
    drawMeterFrame();
	update();
}

void QBaseMeter::setStartAngle(int value)
{
    m_startAngle = value>=0?value:0;
    drawMeterFrame();
    update();
}

void QBaseMeter::setEndAngle(int value)
{
    m_endAngle = value>=0?value:0;
    drawMeterFrame();
    update();
}

void QBaseMeter::setMinValue(int value)
{
    m_minValue = value;  
	m_value = value;
    drawMeterFrame();
	update();
}

void QBaseMeter::setMaxValue(int value)
{
    m_maxValue = value;
    drawMeterFrame();
	update();
}		  

void QBaseMeter::setWAEnabled(int flags)
{

}

void QBaseMeter::setlaValue(int val)
{
	m_laValue = val;
    drawMeterFrame();
	update();
}
void QBaseMeter::sethaValue(int val)
{
	m_haValue = val;
    drawMeterFrame();
	update();
}
void QBaseMeter::setlwValue(int val)
{
	m_lwValue = val;
    drawMeterFrame();
	update();
}
void QBaseMeter::sethwValue(int val)
{
	m_hwValue = val;
    drawMeterFrame();
	update();
}

void QBaseMeter::setMiddleVisiable(bool falgs)
{
	m_middleVisiable = falgs;
    drawMeterFrame();
	update();
}

void QBaseMeter::setScaleLine(ScaleLine scale, int steps)
{
	if(scale == Major)
		m_scaleMajor  = steps;
	else if(scale == Middle)
		m_scaleMiddle = steps;
	else if(scale == Minor)
		m_scaleMinor = steps;
    drawMeterFrame();
	update();
}

void QBaseMeter::setScaleLineLength(ScaleLine scale, int length)
{
	if(scale == Major)
		m_scaleMajorLength  = length;
	else if(scale == Middle)
		m_scaleMiddleLength = length;
	else if(scale == Minor)
		m_scaleMinorLength = length;
    drawMeterFrame();
	update();
}

void QBaseMeter::setScaleLineWidth(ScaleLine scale,int width)
{
 	if(scale == Major)
		m_scaleMajorWidth  = width;
	else if(scale == Middle)
		m_scaleMiddleWidth = width;
	else if(scale == Minor)
		m_scaleMinorWidth = width;
    drawMeterFrame();
	update();
}

void QBaseMeter::setScaleLineColor(ScaleLine scale, QColor color)
{
	if(scale == Major)
		m_scaleMajorColor  = color;
	else if(scale == Middle)
		m_scaleMiddleColor = color;
	else if(scale == Minor)
		m_scaleMinorColor = color;
    drawMeterFrame();
	update();
}

void QBaseMeter::setBackgroundColor(QColor color)
{
	m_backgroundColor = color;
    drawMeterFrame();
	update();
}

void QBaseMeter::setCrownColor(QColor color)
{
	m_crownColor = color;
	update();
}

void QBaseMeter::setTextColor(QColor color)
{
	QPalette palette;
	palette.setColor(QPalette::WindowText,color);
	setPalette(palette);
	update();
}

void QBaseMeter::setIndicatorColor(QColor color)
{
	m_indicatorColor  = color;  
	update();
}

void QBaseMeter::ChangeValue()
{
 /*   static int mg = 1;
    if(m_value >= m_maxValue)
        mg = -1;
    else if(m_value <= m_minValue)
        mg = 1;
    m_value += mg;
    setValue(m_value);*/
    qsrand(QTime(0,0,0).msecsTo(QTime::currentTime()));

    int value = qrand() % 300;
    setValue(value);
}


//signals
//void QBaseMeter::rePaintMeter()
//{
//    drawMeterFrame();
//    update();
//}

