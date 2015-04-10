#ifndef DATAMANGER_H
#define DATAMANGER_H

#include <QWidget>
#include "ui_dataManager.h"
#include "connectdb.h"
class DataManager : public QWidget
{
	Q_OBJECT

public:
	DataManager(QWidget *parent=0);
	~DataManager();
private:
	Ui::DataManager dataManagerUI;
public slots:
	void tableChanged();
private slots:
	
    void on_TableNameChanged(QString);
    void on_PushButtonClearData();
};

#endif // DATAMANGER_H
