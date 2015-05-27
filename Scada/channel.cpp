#include "channel.h"
#include <qfile.h>
#include <qtextstream.h>
#include <qmessagebox.h>

Channel::Channel(int id, bool adFlag, float min, float max, int inhibit)
    :m_id(id),m_ADFlag(adFlag),m_minVal(min),m_maxVal(max),m_inhibit(inhibit)
{
    m_name = "Channel_" + QString::number(id);
	
    m_strVal = "-1";
}

Channel::~Channel()
{

}
int Channel::getChannelId() 
{
    return m_id;
}
QString Channel::getChannelName() const
{
    return m_name;
} 
bool Channel::IsDigit() const 
{
    return !m_ADFlag;
}
bool Channel::IsAnalog() const 
{
    return m_ADFlag;
}
QString Channel::getStrValue() const
{
    return m_strVal;
}
float Channel::getMinValue() const 
{
    return m_minVal;
}

float Channel::getMaxValue() const 
{
    return m_maxVal;
}

int Channel::getInhibitTime() const
{
    return m_inhibit;
}

int Channel::getIntValue() const 
{
    return  m_strVal.toInt();
}

double Channel::getFloatValue(int precise ) const 
{
    return m_strVal.toDouble();
}

void Channel::setAnalogValue(float val, int precise, bool adflag)
{
	QFile file("value.txt");
	if(!file.open(QFile::WriteOnly | QFile::Append | QFile::Text))
		QMessageBox::about(0,"debug","error");
	 
	QTextStream out(&file);
    if(adflag)
        m_strVal = QString("%1").arg(val*(m_maxVal-m_minVal)+m_minVal, 8, 'f',2);
    else
        m_strVal = QString::number(val);
	out << "id:" << m_id  << "\tmax:" << m_maxVal << "\tmin:" << m_minVal
		<< "\tval:" << m_strVal << "\n";
}

void Channel::setDigitValue(int val, bool adflag)
{
    if(adflag)
        m_strVal = QString("%1").arg(val*(m_maxVal-m_minVal)+m_minVal, 8, 'f',2);
    else
        m_strVal = QString::number(val);
}

void Channel::print()
{
    QFile file("print.txt");
    bool fileerr = true;;
    if(!file.open(QFile::WriteOnly | QFile::Append | QFile::Text))
        fileerr = false;
    QTextStream out(&file);
    out << "print\n" ;
    out << "min:" << m_minVal << "\n"
        << "max:" << m_maxVal << "\n"
        << "time:" << m_inhibit << "\n";
    file.close();
}
