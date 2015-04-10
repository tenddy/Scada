

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QtGlobal>

#include <QMainWindow>

#include <QtSerialPort/QSerialPort>
#include "distance.h"

QT_BEGIN_NAMESPACE

namespace Ui {
class SerialDialog;
}

QT_END_NAMESPACE

class Console;
class SettingsDialog;

class SerialDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit SerialDialog(QWidget *parent = 0);
    ~SerialDialog();

private slots:
    void openSerialDialog();
    void closeSerialDialog();
    void about();
    void writeData(const QByteArray &data);
    void readData();

private:
    void initActionsConnections();

private:
    Ui::SerialDialog *ui;
    Console *console;
    SettingsDialog *settings;
    Distance *distance;
};

#endif // MAINWINDOW_H
