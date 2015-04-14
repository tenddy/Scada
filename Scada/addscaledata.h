#ifndef ADDSCALEDATA_H
#define ADDSCALEDATA_H

#include <qstringlist.h>
#include <QDialog>
#include "ui_addscaledata.h"

class AddScaleData : public QDialog
{
    Q_OBJECT

public:
    AddScaleData(QWidget *parent = 0);
    ~AddScaleData();

    QStringList getStandardDistance();

    QStringList getReallyDistance();
private:
    Ui::AddScaleData ui;
public slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();
};

#endif // ADDSCALEDATA_H
