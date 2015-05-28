#include "canopenprotocol.h"
#include <qfile.h>
#include <qtextstream.h>
#include "connectdb.h"
#include <qmessagebox.h>

//#include "sysconfig.h"

QMap<int,Channel*> CanOpenProtocol::m_channelMap;
QVector<unsigned int> CanOpenProtocol::channelNum = QVector<unsigned int>(4);
CanOpenProtocol::CanOpenProtocol(int can_idx, int can_node,QObject *parent)
    : QObject(parent)
{
    m_CardIndex = can_idx;
    m_CanNode = can_node;
    
    m_countRevMSG = 0;
    m_emergency = 0;
    timer = new QTimer();
    node = new CanNode();
    m_readReady = false;
    m_TestFlag = true;
    m_channelCounts = 0;
    
    InitCardInterface();
    initChannel();
}

CanOpenProtocol::~CanOpenProtocol()
{
  if(node)
      delete node;
  if(timer)
      delete timer;
}

void CanOpenProtocol::InitCardInterface(UINT8 bt0, UINT8 bt1, UINT8 mode)
{

    /*init can card*/
    CAN_Init(m_CardIndex, m_CanNode, bt0, bt1, mode);
   
    /*start can*/
    CAN_Start(m_CardIndex, m_CanNode);

    /*init node */
    node->initCanNode();
	
	//input channels
    m_digitData.resize(node->getChannelCounts(0));
    m_analogData.resize(node->getChannelCounts(2));
    channelNum[0] = node->getChannelCounts(0);
    channelNum[1] = node->getChannelCounts(1);
    channelNum[2] = node->getChannelCounts(2);
    channelNum[3] = node->getChannelCounts(3);
    //QMessageBox::about(0,"channel",QString::number(channelNum[0]+channelNum[2]));
    //receive data
    connect(timer,SIGNAL(timeout()),this,SLOT(receiveData()));
    connect(timer,SIGNAL(timeout()),this,SLOT(saveData()));
    timer->start(1);
}

QVector<unsigned int> CanOpenProtocol::ChannelCounts() 
{
    return node->getChannelCounts();
}

/* parse the origin data*/
void CanOpenProtocol::ParseData(const CAN_MSG msg)
{
    int cob_id = msg.id; 
    QString data;
    int channel = 0;
    int digitNum = node->getChannelCounts(0);

    QFile file("data.txt");
    bool fileerr = true;;
    if(!file.open(QFile::WriteOnly | QFile::Append | QFile::Text))
        fileerr = false;
    QTextStream out(&file);
	
	/*QFile channelFile("channelDebug.txt");
	if(!file.open(QFile::WriteOnly | QFile::Append | QFile::Text))
		QMessageBox::about(0,"debug","open file failed");
	QTextStream out1(&channelFile);*/

    switch(cob_id&(~0x3F))
    {
    case 0x80: //emergency
        break;
    case 0x180:  //digit input
        for(int i=0; i<msg.len; i++)
        {
			int digit = (int)msg.a_data[i];
			for(int j=0; j<8 && channel < digitNum; j++)
            {
                //m_digitData[channel].push_back(DigitTransform((int)msg.a_data[i]&(0x01<<j)));
                m_digitData[channel].push_back(DigitTransform((digit>>j)&0x01));
				data += QString("channel_%1:").arg(channel+1) + DigitTransform((digit>>j)&0x01) + " "; 
				
                if(m_channelMap.contains(channel+1))
				{
                    m_channelMap[channel+1]->setDigitValue((digit>>j)&0x01);
					//data += QString("store value:\t%1").arg(m_channelMap[channel+1]->getIntValue());
				}
				if(m_channelData.contains(channel+1))
					m_channelData[channel+1] = DigitTransform((digit>>j)&0x01);
                channel++ ;
            }
        }
        break;
    case 0x280:  //analog input 
    case 0x380:
    case 0x480:
    case 0x680:
    case 0x1C0:  
    case 0x2C0:  
    case 0x3C0:
    case 0x4C0:
    case 0x5C0:
    case 0x6C0:
        /**/
       
        if((cob_id&0x0C0) == 0x0C0)
            channel = 16;
        else 
        {
            if((cob_id&0x680) == 0x680)
                channel = 12;
            else
                channel = ((cob_id>>8) -2) * 4 ;
        }
        for(int i=0;i<msg.len;i +=2)
        {
            int num = 0;
			int channelId = i/2+channel+digitNum+1;  //calculate channel id
			
			/*out << "digitNum:" << digitNum << "\tchannel:" << channel << "\ti:" << i
				<< "\n channelId:" << channelId <<"\n";*/
            
			if(i+1 >= msg.len)
            {
                m_analogData[i/2+channel].push_back(AnalogTransform(msg.a_data[i]/32767.0));
                
				data += QString("Channel_%1:").arg(channelId)+AnalogTransform(msg.a_data[i]/32767.0) + " ";
				if(m_channelMap.contains(channelId))
                {
					m_channelMap[channelId]->setAnalogValue(msg.a_data[i]/32767.0);
                }
				if(m_channelData.contains(channelId))
                {
					m_channelData[channelId] =  AnalogTransform(msg.a_data[i]/32767.0);
                }
            }
            else
            {
                m_analogData[i/2+channel].push_back(AnalogTransform((msg.a_data[i]+256*msg.a_data[i+1])/32767.0));
                
                data += QString("Channel_%1:").arg(channelId)+AnalogTransform((msg.a_data[i]+256*msg.a_data[i+1])/32767.0) + " ";
                if(m_channelMap.contains(channelId))
				{
					//out << "Channel_" << channelId << ":\t" << (msg.a_data[i]+256*msg.a_data[i+1])/32767.0 << "\n";
                    m_channelMap[channelId]->setAnalogValue((msg.a_data[i]+256*msg.a_data[i+1])/32767.0);
					//out << "detect value:" << m_channelMap[channelId]->getStrValue() << "\t";
				}
                if(m_channelData.contains(channelId))
                    m_channelData[channelId] =  AnalogTransform((msg.a_data[i]+256*msg.a_data[i+1])/32767.0);
            }    
        }
        break;
    case 0x580: //SDO

        break;
    case 0x700:
        data += "state:";
        if( msg.a_data[0] == Pre_operational)
        {
              m_state = Pre_operational;
              data += "pre-operational";
        }
        else if(msg.a_data[0] == Operational)
        {
              m_state = Operational;
              data += "operational";
        }
        else if(msg.a_data[0] == Stop_Prepared)
        {
              m_state = Stop_Prepared;
              data += "stop or prepared";
        }
        else
        {
              m_state = ERR;
              data += "error";
        }
        break; //Guarding/HeartBeat/Boot-up
    default:
        break;
    }
    if(fileerr && !data.isEmpty())
        out << data << "\n";
    file.close();
}

void CanOpenProtocol::parseData(QString data)
{
    if(data.isEmpty())
        return;
    QStringList dlist = data.trimmed().split(" ");
    unsigned long cob_id = dlist[0].toLong();   //get COB-ID
    int channel = 0;
    switch(cob_id &( ~0x3F))
    {
    case 0x80: //emergency
        break;
    case 0x180:  //digit input
        for(int i=1; i<dlist.size(); i++)
        {
            for(int j=0; j<8 && channel < node->getChannelCounts(0); j++)
            {
                m_digitData[channel].push_back(DigitTransform(dlist[i].toUShort()&(0x01<<j)));
                data += QString("channel_%1:").arg(channel+1) + DigitTransform(dlist[i].toUShort()&(0x01<<j)) + " "; 
                channel++ ;
            }
        }
        break;
    case 0x280:  //analog input 
    case 0x380:
    case 0x480:
    case 0x680:
    case 0x1C0:  
    case 0x2C0:  
    case 0x3C0:
    case 0x4C0:
    case 0x5C0:
    case 0x6C0:
        /**/
        if((cob_id&0x0c0) == 0x0c0)
            channel = 16;
        else 
        {
            if((cob_id&0x680) == 0x680)
                channel = 12;
            else
                channel = ((cob_id>>8) -2) * 4 ;
        }
        for(int i=1;i<dlist.size();i +=2)
        {
            int num = 0;
            if(i+1 >= dlist.size())
            {
                m_analogData[i/2+channel].push_back(AnalogTransform(dlist[i].toUShort()/32767.0));
                
                data += QString("Channel_%1:").arg(i/2+channel)+AnalogTransform(dlist[i].toUShort()/32767.0) + " ";
            }
            else
            {
                m_analogData[i/2+channel].push_back(AnalogTransform((dlist[i].toUShort()+256*dlist[i+1].toUShort())/32767.0));
                
                data += QString("Channel_%1:").arg(i/2+channel)+AnalogTransform(dlist[i].toUShort()/32767.0) + " "; 
            }    
        }
        break;
    case 0x580: //SDO

        break;
    case 0x700: //Guarding/HeartBeat/Boot-up
        data += "state:";
        if(dlist.size()>=2 && dlist[1].toUShort() == Pre_operational)
        {
              m_state = Pre_operational;
              data += "pre-operational";
        }
        else if(dlist.size()>=2 && dlist[1].toUShort() == Operational)
        {
              m_state = Operational;
              data += "operational";
        }
        else if(dlist.size()>=2 && dlist[1].toUShort() == Stop_Prepared)
        {
              m_state = Stop_Prepared;
              data += "stop or prepared";
        }
        else
        {
              m_state = ERR;
              data += "error";
        }
        break; 
    default:
        break;
    }
}


/*start can*/
void CanOpenProtocol::run(int time, bool eventFlag)
{
   
    if(!CAN_IsRun(m_CardIndex, m_CanNode));
        CAN_Start(m_CardIndex, m_CanNode);

     /*configure Tx & Rx buffer*/
    CAN_ConfigQueue(m_CardIndex, m_CanNode, CAN_RX_QUE, 1000);
    CAN_ConfigQueue(m_CardIndex, m_CanNode, CAN_TX_QUE, 100);
    
    node->setHeartBeat(time);
    node->setEventDriver(eventFlag);
    node->startCan();
    timer->start(1000);
    /*QMessageBox::about(0,"run","start");*/
}
/*stop can*/
void CanOpenProtocol::stop()
{
    node->stopCan();
    CAN_Reset(m_CardIndex, m_CanNode);
    timer->stop();
}

bool CanOpenProtocol::sendMsg(unsigned long cob_id, QString data)
{
    QStringList listdata = data.split(" ");
	UINT8 pdata[8];
    memset(pdata,0,8);
    int len = listdata.length();
    bool ok;
    for(int i=0; i<len; i++)
       pdata[i] =(UINT8) listdata[i].toUInt(&ok,16);

    return ( CAN_SendMsg(m_CardIndex, m_CanNode, cob_id, len, pdata) == CAN_OK );
}

void CanOpenProtocol::receiveData()
{  
    INT32 num = CAN_CountMsgs(m_CardIndex, m_CanNode, CAN_RX_QUE);
    if(num <= 0)
        return;

    CAN_MSG* pobj = (CAN_MSG*)malloc(sizeof(CAN_MSG)*num);
    int countMsg = CAN_ReadMsg(m_CardIndex, m_CanNode,num,pobj);
    for(int i=0; i < countMsg; i++)
    {
        QString data = QString::number(pobj[i].id,16).toUpper();
        for(int k=0;k<pobj[i].len;k++)
            data += " "+QString("%1").arg(pobj[i].a_data[k],2,16,(QLatin1Char)'0').toUpper();
        
        ParseData(pobj[i]);
        
        m_buffer.enqueue(data);
        while(m_buffer.size() >1000)
            read();

        m_countRevMSG++;
        emit readReady();
    }
    delete pobj;
    pobj = 0;
}

//transform the digit input data to string
QString CanOpenProtocol::DigitTransform(int val)
{
    return (QString("%1").arg(val));
}

//transform the analog input data to string
QString CanOpenProtocol::AnalogTransform(double val, double min, double max)
{
    return (QString("%1").arg(val*(max-min)+min, -8, 'f',2));
}

// initialize the channel parameters 
void CanOpenProtocol::initChannel()
{

#ifndef SAVEFILE 
#define SAVEFILE 1
    QFile file("channel.txt");
    bool fileerr = true;;
    if(!file.open(QFile::WriteOnly /*| QFile::Append*/ | QFile::Text))
        fileerr = false;
    QTextStream out(&file);
#endif  //SAVEFILE
    ConnectDB db;
    db.openDB();
    QSqlQuery query("SELECT * FROM configdb");
    m_channelMap.clear();
    while(query.next())
    {
        if(query.value(1).toString().isEmpty())
           continue;
       int id = query.value(1).toString().mid(8).toInt();
        bool adFlag = false;
        if(query.value(6).toInt() == 1)
           adFlag = true;

        float maxVal = 1, minVal =  0;
        if(!query.value(7).toString().isEmpty())
           maxVal = query.value(7).toString().toFloat();

        if(!query.value(8).toString().isEmpty())
           minVal = query.value(8).toString().toFloat(); 
        
        int inhibitTime = query.value(9).toString().toInt();
        if(inhibitTime < 1)
            inhibitTime = 1;
        Channel  *ch =new Channel(id,adFlag,minVal,maxVal,inhibitTime);
        m_channelMap[id] = ch;
        m_channelData[id] = "0";
    }
#if SAVEFILE
    file.close();
#endif 
}

QMap<int,Channel*> CanOpenProtocol::getChannelMap()
{
    return m_channelMap;
}

/* read a message form message buffer*/
QString CanOpenProtocol::read()
{
    if(m_buffer.isEmpty())
        return QString();
    return m_buffer.dequeue();
}

/*read all message in message buffer*/
QStringList CanOpenProtocol::readAll()
{
    if(m_buffer.isEmpty())
        return QStringList();

    QStringList data;
    while(!m_buffer.isEmpty())
        data << m_buffer.dequeue();
    return data;
}

void CanOpenProtocol::saveData()
{
    static int clock = 0;
    clock++;

    /*if(m_TestFlag)
        return;*/

    QFile file("log.txt");
    bool fileerr = true;;
    if(!file.open(QFile::WriteOnly | QFile::Append | QFile::Text))
        fileerr = false;
    QTextStream out(&file);

    ConnectDB db;
    db.openDB();
    QSqlQuery query;
    QString time = QDateTime::currentDateTime().toLocalTime().toString("yyyy-MM-dd hh:mm:ss");

    QMap<int,Channel*>::iterator chiter;
    for(chiter = m_channelMap.begin(); chiter != m_channelMap.end();chiter++)
    {
        if(clock % chiter.value()->getInhibitTime() == 0)
        {
            out << time <<"\t" << chiter.value()->getChannelName() << "\tvalue:" << chiter.value()->getStrValue() << "\n";
            query.prepare(QString("insert into '%1' values (?,?)").arg(chiter.value()->getChannelName()));
            query.bindValue(0,time);
            query.bindValue(1,chiter.value()->getStrValue());
            if(!query.exec())
                out << chiter.value()->getChannelName() << ":\tinsert data failed.\n";
        }
    }

    db.closeDB();
    file.close();
}

