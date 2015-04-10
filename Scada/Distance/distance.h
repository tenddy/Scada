#ifndef DISTANCE_H
#define DISTANCE_H

#include <QtCore\Qtglobal>
#include <QObject>
#include <QtSerialPort\qserialport.h>
#include <qvector.h>
#include <qtimer.h>
#include <qqueue>
#include "globalData.h"
#include "dataoperate.h"
#include <qstringlist.h>

class Distance : public QObject
{
    Q_OBJECT

public:
    Distance(QObject *parent=0);
    ~Distance();

    static OutputData* tagData;

    bool openSerialPort(QString name="COM1",quint32 baudRate = 9600,
        QSerialPort::DataBits dataBits = QSerialPort::Data8, QSerialPort::Parity parity = QSerialPort::NoParity,
        QSerialPort::StopBits stopBits = QSerialPort::OneStop, QSerialPort::FlowControl flowCtl = QSerialPort::NoFlowControl);
    void closeSeialPort();
    void tagOperate(Tag *tag,QString tagData);
    void judgeMac(QString wholeMac);
    void predict(Tag *tag);
   
    QString read();
    QStringList readAll();
    
    void outPut(Tag *tag);

private:   
    QVector<QTimer *> vectTimer;
    QSerialPort* serial;
    QString buf;
    QQueue<QString>  dataBuffer;
    int tagnum;
signals:
    void readReady();
public slots:
   
    void writeData(const QByteArray &data);
    void readData();
    //void getHexString();
    void handleError(QSerialPort::SerialPortError error);
    void judgeLost();

};

#endif // DISTANCE_H
