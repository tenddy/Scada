
/****************************************
**	File Name:	 basepage.cpp
**  Description:
**	Manage the style of meter in the page
**  Author:		teddy.tu(tudongdong1989@gmail.com)
**	
**	Remark:		teddy.tu
**  Date:
**	Version:	1.0.0
**
**  Copyright(C) teddy.tu
**  All rights reserved.
****************************************/ 
#include "basepage.h"
#include "qlayout.h"
#include "qpalette.h"
#include "qframe.h"
#include "InfoMsg.h"
#include <qmessagebox.h>
#include "enginemeter.h"
#include "qbasemeter.h"
#include "fuelmeter.h"
#include "indicatorlamp.h"
#include "thermometer.h"

BasePage::BasePage(int id,QString name,int row,int column,int num,QWidget *parent)
	: m_id(id),m_pageName(name),m_row(row),m_column(column),m_maxLamps(num)/*,m_MeterCounts(0)*/,QWidget(parent)
{
	QPalette p = palette();
	p.setBrush(QPalette::Background,Qt::black);
	setPalette(p);
	setAutoFillBackground(true);
	QFrame(this,Qt::FramelessWindowHint);
	
    m_mainlayout = new QVBoxLayout(this);
    m_gridlayout = new QGridLayout;
	m_lamplayout = new QGridLayout;
	m_mainlayout->addLayout(m_gridlayout);
	m_mainlayout->addLayout(m_lamplayout);
	LampEnabled = true;			/* show lamps default */
	setLayout(m_mainlayout);
	setWindowTitle(m_pageName);
    showNormal();
	/*connect(this,SIGNAL(lampNumChange()),this,SLOT(updateLayout()));
	connect(this,SIGNAL(meterNumChange()),this,SLOT(updateLayout()));*/
}

BasePage::~BasePage()
{

}

/*
**  @description:
**  Add a new meter into a page with position(pos).
**  @parameter:NULL
**		@pos: the position of meter,begin from 1 
**  @return value:NULL
**
**  author:teddy.tu
**  date:
**  Copyright(C) teddy.tu
**  All rights reserved.
*/
void BasePage::addMeter(QMeter *w, int pos)
{
	if(pos <= 0 || !w)
		return;
	if(w->getType() == QMeter::Lamp)
	{
		m_lampMap.insert((IndicatorLamp*)w,pos);
		//emit lampNumChange();
	}
    else if(w->getType() == QMeter::Thermometer)
	{
        m_meterMap.insert((ThermoMeter*)w,pos);  
		//emit meterNumChange();
	}
    else
        m_meterMap.insert((QBaseMeter*)w,pos);
	updateLayout();
}

void BasePage::insertMeter(QMeter *w , int row, int column)
{
	addMeter(w,row * column);
}

void BasePage::appendMeter(QMeter *w )
{
	int maxMeterNum = m_row * m_column;
	if(w->getType() == QMeter::Lamp)
		addMeter(w,maxMeterNum + m_lampMap.size() + 1);
	else
		addMeter(w,meterLastPos()+1);
}


/*
**  @description:
**
**  @parameter:
**	 @pos: the position of the meter
**  @return value:bool
**		if m_meterMap contains the meter on positon pos and delete it successfully return true;
**		else return false.
**  author:teddy.tu
**  date:
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
bool BasePage::deleteMeter( int pos)
{
	QMeter *meter = getMeter(pos);
	QMeter::Type type = meter->getType();
	if(type == QMeter::Lamp && m_lampMap.contains((IndicatorLamp*)meter))
	{
		m_lampMap.remove((IndicatorLamp*)meter);
		updateLayout();
		return true;
	}
	else if(type != -1 && m_meterMap.contains(meter))
	{
		m_meterMap.remove(meter);
		updateLayout();
		return true;	
	}
	else
		return false;
}

bool BasePage::deleterMeter(QMeter *w)
{  
	QMeter::Type type = w->getType();
	if(type == QMeter::Lamp && m_lampMap.contains((IndicatorLamp*)w))
	{
		m_lampMap.remove((IndicatorLamp*)w);
		updateLayout();
		return true;
	}
	else if(type != -1 && m_meterMap.contains(w))
	{
		m_meterMap.remove(w);
		updateLayout();
		return true;	
	}
	else
		return false;
}

QMeter* BasePage::getMeter(const int i)
{
	//InfoMsg info;
	QMap<QMeter*,int>::iterator iter;
	for(iter = m_meterMap.begin(); iter != m_meterMap.end(); iter++)
	{
		if(iter.value() == i)
			return iter.key();
	}

	QMap<IndicatorLamp*,int>::iterator iter1;
	for(iter1 = m_lampMap.begin(); iter1 != m_lampMap.end(); iter1++)
	{
		if(iter1.value() == i)
			return iter1.key();
	}

	return NULL;
}

QMeter *BasePage::getMeter(const QString name)
{
	QMap<QMeter*,int>::iterator iter;
	for(iter = m_meterMap.begin();iter != m_meterMap.end();iter++)
	{
		if(iter.key()->getName() == name )
		{
			QMeter::Type type =iter.key()->getType();
			switch(type)
			{
			case QMeter::EngineMeter:
				return	(EngineMeter*)iter.key();
				break;
			case QMeter::FuelLevel:
				return (FuelMeter*)iter.key();
				break;
			case QMeter::Meter :
				return (QBaseMeter*)iter.key();
				break;
			case QMeter::Thermometer:
				return (ThermoMeter*)iter.key();
				break;
			}
		}
	}

	QMap<IndicatorLamp*, int>::Iterator iterlamp;
	for(iterlamp = m_lampMap.begin(); iterlamp != m_lampMap.end(); iterlamp++)
	{
		if(iterlamp.key()->getName() == name)
			return iterlamp.key();
	}
	return NULL;
}

QMeter::Type BasePage::getMeterType(const int pos) 
{
	QMeter *meter  = getMeter(pos);
	if(meter)
		return meter->getType();
	else
		return (QMeter::Type) -1;
	
}

int BasePage::getMeterPos(QMeter *meter) const
{
	QMeter::Type type = meter->getType();
	if(type != QMeter::Lamp)
	{
		QMap<QMeter*,int>::const_iterator iter;
		for(iter = m_meterMap.begin();iter != m_meterMap.end();iter++)
		{
			if(iter.key()->getName() == meter->getName())
				return iter.value(); 
		}
	}
	else
	{
		QMap<IndicatorLamp*, int>::const_iterator iter;
		for(iter = m_lampMap.begin();iter != m_lampMap.end();iter++)
		{
			if(iter.key()->getName() == meter->getName())
				return iter.value(); 
		}  
	}
	return -1;     //not found the meter
}

//void BasePage::meterAdjust(int current, int pre)
//{
//	if(current < 0 || pre < 0 || current < 0 || pre < 0 )
//		return ;
//		
//	QMeter *moveMeter = getMeter(pre);
//	
//	if(current == pre)
//		return;
//	else if (current > pre)
//	{
//		m_meterMap.insert(moveMeter,current);
//		m_meterMap.remove(getMeter(pre));
//	}
//	else
//	{
//		m_meterMap.insert(moveMeter, current+1);
//		m_meterMap.remove(getMeter(pre));
//	}
//	updateLayout();
//}

/**/
void BasePage::setRow(int row)
{
	m_row = row;
	updateLayout();
}


void BasePage::setColumn(int column)
{
	m_column = column;
	updateLayout();
}

void BasePage::setLampsEnabled(bool flags)
{
	LampEnabled = flags;
	updateLayout();
}

void BasePage::setMaxLamps(int num)
{
	m_maxLamps = num;
	updateLayout();
}

const int BasePage::meterFirstPos()
{
	int pos = -1;
	if(m_meterMap.isEmpty())
		return pos;
	else
		pos = 1;
	QMap<QMeter*,int>::iterator iter;
	for(iter = m_meterMap.begin(); iter != m_meterMap.end(); iter++)
	{
		if(iter.value() < pos)
			pos = iter.value();
	}
	return pos;
}

const int BasePage::meterLastPos()
{
	int pos = -1;
	if(m_meterMap.isEmpty())
		return pos;
	QMap<QMeter*,int>::iterator iter;
	for(iter = m_meterMap.begin(); iter != m_meterMap.end(); iter++)
	{
		if(iter.value() > pos)
			pos = iter.value();
	}
	return pos;
}
const int BasePage::lampFirstPos()
{
	int pos = -1;
	if(m_lampMap.isEmpty())
		return pos;
	else 
		pos = m_row * m_column + 1;
	QMap<IndicatorLamp*,int>::iterator iter;
	for(iter = m_lampMap.begin(); iter != m_lampMap.end(); iter++)
	{
		if(iter.value() < pos)
			pos = iter.value();
	}
	return pos;
}

const int BasePage::lampLastPos()
{
	int pos = -1;
	QMap<IndicatorLamp*,int>::iterator iter;
	for(iter = m_lampMap.begin(); iter != m_lampMap.end(); iter++)
	{
		if(iter.value() > pos)
			pos = iter.value();
	}
	return pos;
}

void BasePage::updateLayout()
{
	//clear all meters on the layout
    QLayoutItem *child;
    while((child = m_gridlayout->takeAt(0)) != 0)
        delete child;
    while((child = m_lamplayout->takeAt(0)) != 0)
        delete child;

	//re-layout all meters depend on the parameters of page (m_row,m_column,m_maxLamps)
	int maxMeterNum = m_row*m_column ; 
    QMap<QMeter*,int>::iterator iter;
	for(iter = m_meterMap.begin();iter != m_meterMap.end() && iter.value() <= maxMeterNum; iter++)
	{
		int pos = iter.value();
		m_gridlayout->addWidget(iter.key(),(pos-1)/m_column,(pos-1)%m_column);
	}
	if(LampEnabled)
	{  
		int meterMaxIndex = m_row * m_column + m_maxLamps;
        QMap<IndicatorLamp*, int>::iterator iter1;
		for(iter1 = m_lampMap.begin();iter1 != m_lampMap.end() && iter1.value() <= meterMaxIndex;iter1++)
		{
			m_lamplayout->addWidget(iter1.key(),0,iter1.value()-maxMeterNum-1);
            //info.info_log("type:%d,pos:%d\n",(int)iter1.key()->getType(),iter1.value()-maxMeterNum-1);
		}
	}
}

void BasePage::setMeterPos(QMeter* meter, int pos)
{
	QMeter::Type type = meter->getType();
	if(type == QMeter::Lamp && m_lampMap.contains((IndicatorLamp *)meter))
	{
		m_lampMap[(IndicatorLamp *)meter] = pos;
	}
	else if(m_meterMap.contains(meter))
	{
		m_meterMap[meter] = pos;
	}
	updateLayout();
}

void BasePage::setMeterPos(QString meterName, int pos)
{
	QMeter *meter  = getMeter(meterName);
	if(!meter)
		return;
	setMeterPos(meter, pos);
}		

void BasePage::moveMeterSeial(int steps)
{
	if(steps == 0)
		return;
	QMap<QMeter*,int>::iterator iter;
	for(iter = m_meterMap.begin(); iter != m_meterMap.end(); iter++)
	{
		iter.value() += steps;
	}
	updateLayout();
}

void BasePage::moveLampSerial(int steps)
{
	/*InfoMsg info;*/
	if(steps == 0)
	{
		return ;
	}
	QMap<IndicatorLamp*, int>::iterator iter;
	for(iter = m_lampMap.begin(); iter != m_lampMap.end(); iter++)
	{
		iter.value() += steps;
	}
	updateLayout();
}