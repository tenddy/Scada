#ifndef QCONFIG_H
#define QCONFIG_H

#include <QObject>
#include <qsettings.h>

class Configure : public QObject
{
	Q_OBJECT

public:
	Configure(int flag = Configure::Normal);
	Configure(QString configfile = "config.ini");
	~Configure();
	enum{Default = 0,Normal};
	void configureWrite(QVariant val, QString param , QString group0 = NULL,QString group1 = NULL , QSettings *settings = m_configure);
	void configureWrite(QSettings *settings,QVariant val,QString param , QString group0 = NULL,QString group1 = NULL);
	QVariant configureRead(QString param, QString widgets = NULL, QString page = NULL, QSettings *settings = m_configure);
	void clear();

private:
	static QSettings *m_configDefault;
	static QSettings *m_configure;
	QSettings *m_settings;
};

#endif // CONFIGURE_H
