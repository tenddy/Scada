

#include "serialdialog.h"
#include "ui_serialdialog.h"
#include "console.h"
#include "settingsdialog.h"
#include "dataoperate.h"
#include "Leastsquare.h"

#include <QMessageBox>
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QTextStream>
#include <QFile>
#include <QChar>

SerialDialog::SerialDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SerialDialog)
{
    ui->setupUi(this);
    console = new Console;
    console->setEnabled(false);
    setCentralWidget(console);
    distance = new Distance;
    settings = new SettingsDialog;

    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionQuit->setEnabled(true);
    ui->actionConfigure->setEnabled(true);

    initActionsConnections();

    connect(distance, SIGNAL(readReady()), this, SLOT(readData()));

    connect(console, SIGNAL(getData(QByteArray)), this, SLOT(writeData(QByteArray)));
    
    resize(500,400);
}


SerialDialog::~SerialDialog()
{
    delete settings;
    delete ui;
}

void SerialDialog::openSerialDialog()
{
    SettingsDialog::Settings p = settings->settings();
   
    if (distance->openSerialPort(p.name,p.baudRate,p.dataBits,p.parity,p.stopBits,p.flowControl)) {
            console->setEnabled(true);
            console->setLocalEchoEnabled(p.localEchoEnabled);
            ui->actionConnect->setEnabled(false);
            ui->actionDisconnect->setEnabled(true);
            ui->actionConfigure->setEnabled(false);
            ui->statusBar->showMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                                       .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                                       .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
    } else {
        QMessageBox::critical(this, tr("Error"), "connect failed");

        ui->statusBar->showMessage(tr("Open error"));
    }
}
//! [4]

//! [5]
void SerialDialog::closeSerialDialog()
{
    distance->closeSeialPort();
    console->setEnabled(false);
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);
    ui->statusBar->showMessage(tr("Disconnected"));
}
//! [5]

void SerialDialog::about()
{
    QMessageBox::about(this, tr("About Simple Terminal"),
                       tr("The <b>Simple Terminal</b> example demonstrates how to "
                          "use the Qt Serial Port module in modern GUI applications "
                          "using Qt, with a menu bar, toolbars, and a status bar."));
}

//! [6]
void SerialDialog::writeData(const QByteArray &data)
{
    distance->writeData(data);
}
//! [6]

//! [7]
void SerialDialog::readData()
{
    QStringList data = distance->readAll();
    for(int i=0; i< data.size(); i++)
        console->putData(data[i]);
}

void SerialDialog::initActionsConnections()
{
    connect(ui->actionConnect, SIGNAL(triggered()), this, SLOT(openSerialDialog()));
    connect(ui->actionDisconnect, SIGNAL(triggered()), this, SLOT(closeSerialDialog()));
    connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionConfigure, SIGNAL(triggered()), settings, SLOT(show()));
    connect(ui->actionClear, SIGNAL(triggered()), console, SLOT(clear()));
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(about()));
    connect(ui->actionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}







