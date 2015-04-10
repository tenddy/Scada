#include "datamanager.h"
#include <qsqlquerymodel.h>
#include <qmessagebox.h>
#include <qtimer.h>
DataManager::DataManager(QWidget *parent)
	: QWidget(parent)
{
	dataManagerUI.setupUi(this);
    ConnectDB db;
    QStringList tables = db.getTables();
    dataManagerUI.comboBoxTableList->insertItems(0,tables);
    
    connect(dataManagerUI.pushButtonClearData,SIGNAL(clicked()),this,SLOT(on_PushButtonClearData()));
    connect(dataManagerUI.comboBoxTableList,SIGNAL(activated(QString)),this,SLOT(on_TableNameChanged(QString)));
    dataManagerUI.comboBoxTableList->setCurrentText("configdb");
	db.closeDB();
    //updataData();
}

DataManager::~DataManager()
{
	
}

void DataManager::tableChanged()
{
	ConnectDB db;
    QStringList tables = db.getTables();
	dataManagerUI.comboBoxTableList->clear();
    dataManagerUI.comboBoxTableList->insertItems(0,tables);
	dataManagerUI.comboBoxTableList->setCurrentText("configdb");
	db.closeDB();
	on_TableNameChanged("configdb");
}

void DataManager::on_TableNameChanged(QString tableName)
{
    ConnectDB db;
	db.openDB();
	QSqlQueryModel *model = new QSqlQueryModel;
	model->setQuery(QString("select * from '%1'").arg(tableName));
    while(model->canFetchMore())
        model->fetchMore();
	dataManagerUI.tableView->setModel(model);
	db.closeDB();
}

void DataManager::on_PushButtonClearData()
{
    QMessageBox *msgBox = new QMessageBox(this);
    msgBox->setText(QStringLiteral("Çå³ýÊý¾Ý..."));
    msgBox->show();

    ConnectDB db;
	db.openDB();
    QString tableName = dataManagerUI.comboBoxTableList->currentText();
	QSqlQuery query(QString("select * from '%1'").arg(tableName));
    while(query.next())
    {
         QString time = query.value(0).toString();
        QSqlQuery qdelete;
        qdelete.exec(QString("delete from '%1' where time='%2'").arg(tableName).arg(time));
    }

    QSqlQueryModel *model = new QSqlQueryModel;
	model->setQuery(QString("select * from '%1'").arg(tableName));
    while(model->canFetchMore())
        model->fetchMore();
	dataManagerUI.tableView->setModel(model);
    QTimer::singleShot(1000,msgBox,SLOT(close()));
    //delete msgBox;
	db.closeDB();
}