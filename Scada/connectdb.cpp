#include "connectdb.h"


ConnectDB::ConnectDB(QString DataBaseName, QString HostName, QString UserName, QString pwd)
	:m_hostName(HostName),m_userName(UserName),m_pwd(pwd)
{
	
	if(QSqlDatabase::contains("qt_sql_default_connection"))
		db = QSqlDatabase::database("qt_sql_default_connection");
	else
		db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(DataBaseName);
	db.setHostName(HostName);
	db.setUserName(UserName);
	db.setPassword(pwd);
	m_opened = false;
}

ConnectDB::~ConnectDB()
{

}
bool ConnectDB::createTable(QString SqlStr)
{
	QSqlQuery query;
	return query.exec(SqlStr);
	/*
	bool flag = query.exec(QString("create table if not exists %1").arg(tablename));
	return flag;
	*/
}

QStringList ConnectDB::getTables()
{
    QStringList tableList = db.tables();
    QFile file("tables.txt");
    bool fileerr = true;;
    if(!file.open(QFile::WriteOnly /*| QFile::Append */| QFile::Text))
        fileerr = false;
    QTextStream out(&file);
    out << "tables:\n";
    for(int i=0; i<tableList.size();i++)
        out << tableList[i] << "\t";
    file.close();

    return tableList;
}
/*
**  @description:
**	execute SQL syntax.
**  @parameter:NULL
**
**  @return value:bool
**	Return true when execute SQL syntax successful,otherwise return false. 
**  author:teddy.tu
**  date: 2014/11/26
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
bool ConnectDB::execute(QString str)
{
	if(!db.isOpen())
		db.open();
	QSqlQuery query;
	bool flag = query.exec(str);
	db.close();
	return flag;
}
bool ConnectDB::deleteData(QString tableName, QString key, QString data)
{
	if(!db.isOpen())
		db.open();
	QSqlQuery query;
	bool flag = query.exec(QString("delete from '%1' where '%2'='%3'").arg(tableName,key,data));
	//db.close();
	return flag;
}
bool ConnectDB::deleteTable(QString tableName)
{
	if(!db.isOpen())
		db.open();
	QSqlQuery query;
	bool flag = query.exec(QString("drop table if exists '%1' ").arg(tableName));
	db.close();
	return flag;
}
void ConnectDB::run()
{
	m_opened = db.open();
}
void ConnectDB::openDB()
{
	m_opened = db.open();
}
void ConnectDB::closeDB()
{
	db.close();
	m_opened = false;
}
bool ConnectDB::isOpen()
{
	return m_opened;
}