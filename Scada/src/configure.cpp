#include "configure.h"
#include <qmessagebox.h>

QSettings* Configure::m_configure = new QSettings("config.ini",QSettings::IniFormat);
QSettings* Configure::m_configDefault = new QSettings("default.ini",QSettings::IniFormat);

Configure::Configure(int flag)
{
	if(flag == Configure::Default)
		m_settings = m_configDefault;
	else
		m_settings = m_configure;
}

Configure::Configure(QString filename)
{
	m_settings = new QSettings(filename,QSettings::IniFormat);
}

Configure::~Configure()
{

}

void Configure::configureWrite(QVariant val, QString param , QString group0 ,QString group1  , QSettings *settings)
{
	//if(group0 == NULL && group1 != NULL)
	//{
	//	QMessageBox::warning(0,"Configure",QString::fromLocal8Bit("参数设置错误，请检查参数"));
	//	return ;
	//}
	QString dir;
	if(group1 == NULL)
	{
		if(group0 == NULL)
			dir = param;
		else
			dir = "/"+group0+"/"+param;
	}
	else
		dir = "/"+group1+"/"+group0+"/"+param;
	m_settings->setValue(dir, val);
}

void Configure::configureWrite(QSettings *settings,QVariant val,QString param , QString group0 ,QString group1 )
{
	//if(group0 == NULL && group1 != NULL)
	//{
	//	QMessageBox::warning(0,"Configure",QString::fromLocal8Bit("参数设置错误，请检查参数"));
	//	return ;
	//}
	if(group1 == NULL)
	{
		if(group0 == NULL)
			settings->setValue(param,val);
		else
			settings->setValue("/"+group0+"/"+param, val);
	}
	else
		settings->setValue("/"+group1+"/"+group0+"/"+param, val);
}

QVariant Configure::configureRead(QString param, QString widgets , QString page , QSettings *settings)
{
	//if(widgets == NULL && page != NULL)
	//{
	//	QMessageBox::warning(0,"Configure",QString::fromLocal8Bit("参数错误，请检查参数"));
	//	return NULL;
	//}
	QString dir;
	if(page == NULL)
	{
		if(widgets == NULL)
			dir = param;
		else
			dir = "/"+widgets+"/"+param;
	}
	else
		dir = "/"+page+"/"+widgets+"/"+param;
	return m_settings->value(dir);
}

void Configure::clear()
{
	m_settings->clear();
}