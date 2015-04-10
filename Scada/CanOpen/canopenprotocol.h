#ifndef CANOPENPROTOCOL_H
#define CANOPENPROTOCOL_H

#include <qobject.h>
#include "ICANApi.h"
#include "CanNode.h"
#include <qtimer.h>
#include <qmap.h>
#include <qvector.h>
#include <qqueue.h>
#include <qstringlist.h>
#include "channel.h"

class CanOpenProtocol : public QObject
{
    Q_OBJECT

public:
    
    enum MSG{

        STATE   = 0x000,
        SDO     = 0x600,
        NMT     = 0x700
    };

    enum State{
        ERR  = -1,
        Pre_operational = 5,
        Operational = 6,
        Stop_Prepared = 7
    };

    CanOpenProtocol(int can_idx = 0, int can_node = 0,QObject *parent = 0);
    ~CanOpenProtocol();
    
    static QMap<int, Channel*> m_channelMap;            //id与已设置的通道 hash table
    static QVector<unsigned int> channelNum;
    void InitCardInterface(UINT8 bt0 = 0x03, UINT8 bt1 = 0x1C, UINT8 mode = CAN_11B);

    void ParseData(const CAN_MSG msg);
    void parseData(QString data);
    bool sendMsg(unsigned long cob_id, QString data); 
    void enabledTest(bool flag) { m_TestFlag = flag; }
    QVector<unsigned int> ChannelCounts(); 
    QStringList readAll();    //read all data from buffer
    QString read();           //read a data from buffer

    QMap<int, Channel*> getChannelMap();
private:
    int m_CardIndex;
    int m_CanNode;
    QTimer *timer;
    CanNode* node;
    int m_countRevMSG;
    QQueue<QString>  m_buffer;

    int m_emergency;
    State m_state;
    bool m_readReady;
    bool m_TestFlag;
    
    QMap<unsigned int,QString> m_channelData;
    int m_channelCounts;

    QVector<QVector<QString> > m_analogData;
    QVector<QVector<QString> > m_digitData;

    QString DigitTransform(char val);     // sava data
    QString AnalogTransform(double val, double min = 0, double max = 1);
    void initChannel();
signals:
    void readReady();
   
public slots:
    void run(int time = 0, bool eventFlag = false);  //start can
    void stop(); //stop can
    //void on_clearMsg();
    void receiveData();  //receive data

    void saveData();

};

#endif // CANOPENPROTOCOL_H
