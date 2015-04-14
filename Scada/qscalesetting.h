#ifndef QSCALESETTING_H
#define QSCALESETTING_H

#include <QWidget>
#include "ui_qscalesetting.h"

class QScaleSetting : public QWidget
{
    Q_OBJECT

public:
    QScaleSetting(QWidget *parent = 0);
    ~QScaleSetting();

private:
    Ui::QScaleSetting ui;
    bool insertScaleRow(int row);
    void initTableView();
public slots:
    void on_pushButton_addData_clicked();
    void on_pushButton_deleteData_clicked();
    void on_pushButton_save_clicked();
    void on_pushButton_cancel_clicked();
    void on_pushButton_default_clicked();
};

#endif // QSCALESETTING_H
