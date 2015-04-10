#include "qexcel.h"
#include <qmessagebox.h>

qExcel::qExcel(QObject *parent)
	: QObject(parent)
{
}

qExcel::~qExcel()
{
}

bool qExcel::createTable(QString statement,QString filepath )
{    
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC","excelexport");
    if( !db.isValid())
        return false;   //! type error

    QString dsn = QString("DRIVER={Microsoft Excel Driver (*.xls)};"
            "DSN='';FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\"%1\";DBQ=%2").arg(filepath).arg(filepath);
    db.setDatabaseName( dsn);

    // open connection
    if( !db.open())
        return false;  //! db error
    QSqlQuery query(db);

    query.prepare(statement);
    bool state = query.exec();
    db.close();
    return state;
}

bool qExcel::deleteTable(QString sheetName)
{
    QString sSql = QString("DROP TABLE [%1]").arg(sheetName);
    QSqlQuery query(m_db);
    return query.exec( sSql);
}

bool qExcel::insertData(QStringList values,QString sheetName,QString filepath)
{
   QSqlDatabase db = QSqlDatabase::addDatabase("QODBC","excelexport");
    if( !db.isValid())
        return false;   //! type error

    QString dsn = QString("DRIVER={Microsoft Excel Driver (*.xls)};"
            "DSN='';FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\"%1\";DBQ=%2").arg(filepath).arg(filepath);
    db.setDatabaseName( dsn);

    // open connection
    if( !db.open())
        return false;  //! db error
    QSqlQuery query(db);
    QString statement = QStringLiteral("INSERT INTO [%1$] VALUES(").arg(sheetName);
    for(int i=0; i<values.count();i++)
    {
        statement += QStringLiteral("'%1'").arg(values[i]);
        if(i!=values.count()-1)
            statement += ",";
        else
            statement += ")";
    }
    bool state = query.exec(statement);
    db.close();                 //save data
    return state;
}


