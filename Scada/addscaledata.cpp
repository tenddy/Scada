#include "addscaledata.h"

AddScaleData::AddScaleData(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
}

AddScaleData::~AddScaleData()
{

}

QStringList AddScaleData::getStandardDistance()
{
    QString str = ui.lineEdit_standardDistance->text();
    QStringList dataList = str.split(",");
    return dataList;
}
QStringList AddScaleData::getReallyDistance()
{
    QString str = ui.lineEdit_reallyDistance->text();
    return str.split(",");
}

void AddScaleData::on_okButton_clicked()
{
    this->accept();
}
void AddScaleData::on_cancelButton_clicked()
{
    this->reject();
}