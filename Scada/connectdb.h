#ifndef CONNECTDB_H
#define CONNECTDB_H

#include <QThread>
#include <QtSql>
#include <qstringlist.h>
#include <qsqlquery.h>
#include <QSqlQueryModel>

class ConnectDB 
{
	//Q_OBJECT

public:
	ConnectDB(QString DataBaseName="scada.db", QString HostName="localhost", QString UserName="root", QString pwd="root");
	~ConnectDB();

	QString DatabaseName() {return m_DatabaseName;}
	QString HostName() {return m_hostName;}
	QString UserName() {return m_userName;}
	QString PassWord() {return m_pwd;}
    QStringList getTables();
	bool isOpen();
	void closeDB();
	bool createTable(QString SqlStr);
	bool execute(QString str);
	bool deleteData(QString tableName, QString key,QString data);
	bool deleteTable(QString tableName);
	void openDB();
	void run();
private:
	QSqlDatabase db;
	QString m_DatabaseName;
	QString m_hostName;
	QString m_userName;
	QString m_pwd;
	QStringList tableNames;
	bool m_opened;
};

#endif // CONNECTDB_H
