#ifndef QEXCEL_H
#define QEXCEL_H

#include <QObject>
#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <qstringlist.h>

class qExcel : public QObject
{
	Q_OBJECT

public:
	qExcel(QObject *parent=0);
	~qExcel();
	bool createTable(QString statement,QString filepath="data.xls");
    bool deleteTable(QString sheetName);
    bool insertData(QStringList values,QString sheetName,QString filepath = "data.xls");
private:
	QSqlDatabase m_db;
	
};

#endif // QEXCEL_H
