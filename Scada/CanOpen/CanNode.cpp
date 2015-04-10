#include "CanNode.h"
#include "ICANApi.h"
#include <qstringlist.h>
#include <qmessagebox.h>

CanNode::CanNode(unsigned long COB_ID, int can_idx , int node_id )
    :m_canAddr(COB_ID)
{
	m_baudRate = BAUD_125k;
    m_eventDriver = false;
	m_Channels = QVector<unsigned int>(4,0);
}


CanNode::~CanNode(void)
{
}

 /* init node */
void CanNode::initCanNode(int can_idx, int node_id)
{
	/* get the channels */
    CAN_MSG msg;
    //Digit input channels
	CAN_ConfigQueue(can_idx,node_id,CAN_RX_QUE,0);
	CAN_ConfigQueue(can_idx,node_id,CAN_RX_QUE,1);
    sendSDO("40 00 60 00");
    _sleep(100);
    if(CAN_ReadMsg(can_idx, node_id,1,&msg) == CAN_OK)
        m_Channels[0] = (int)msg.a_data[4] * 4;
	/*else
		QMessageBox::warning(0,"digit","read error");*/

	 //Digit output channels
	CAN_ConfigQueue(can_idx,node_id,CAN_RX_QUE,0);
	CAN_ConfigQueue(can_idx,node_id,CAN_RX_QUE,1);
    sendSDO("40 00 62 00");
    _sleep(100);
    if(CAN_ReadMsg(can_idx, node_id,1,&msg) == CAN_OK)
        m_Channels[1] = (int)msg.a_data[4] * 4;
	/*else
		QMessageBox::warning(0,"digit","read error");*/

    //IP2302 has 4 digit input channels and 4 digit output channels
    //sendState(00,80);
    //_sleep(1000);
    //if(CAN_ReadMsg(can_idx, node_id,1,&msg) == CAN_OK)
    //{
    //    m_Channels[0] = 4;
    //    m_Channels[1] = 4;
    //}
    //Analog input channels
    CAN_ConfigQueue(can_idx,node_id,CAN_RX_QUE,0);
    CAN_ConfigQueue(can_idx,node_id,CAN_RX_QUE,1);
   sendSDO("40 01 64 00");
    _sleep(100);
    if(CAN_ReadMsg(can_idx, node_id,1,&msg) == CAN_OK)
        m_Channels[2] = (int)msg.a_data[4];
  
	//Analog output channels
    CAN_ConfigQueue(can_idx,node_id,CAN_RX_QUE,0);
    CAN_ConfigQueue(can_idx,node_id,CAN_RX_QUE,1);
    sendSDO("40 11 64 00");
    _sleep(100);
    if(CAN_ReadMsg(can_idx, node_id,1,&msg) == CAN_OK)
        m_Channels[3] = (int)msg.a_data[4];

	//QMessageBox::about(0,"channels",QString("channels:%1,%2,%3,%4").arg(m_Channels[0]).arg(m_Channels[1]).arg(m_Channels[2]).arg(m_Channels[3]));
 
	sendState(01,00);
	setHeartBeat(0);
	setEventDriver(false);
}

/*
    send NMT telegraph
*/
bool CanNode::sendState(unsigned char cs, unsigned char COB_ID,unsigned char can_idx, unsigned char can_node)
{
	UINT8 pdata[2] = {cs,COB_ID};
	return (CAN_SendMsg(can_idx,can_node,0x00,2,pdata) > 0);
}

bool CanNode::sendState( QString data, unsigned char can_idx, unsigned char can_node)
{
    bool ok;
	QStringList listdata = data.split(" ");
	UINT8 pdata[8];
    memset(pdata,0,8);
    int len = listdata.length();

    for(int i=0; i<len; i++)
		pdata[i] =(UINT8) listdata[i].toUInt(&ok,16);

	return (CAN_SendMsg(can_idx,can_node, 0x00, len, pdata) > 0);
}
/* send NMT telegraph */
bool CanNode::sendNMT(QString data,unsigned long canaddr, unsigned char can_idx, unsigned char can_node)
{
    bool ok;
	QStringList listdata = data.split(" ");
	UINT8 pdata[8];
    memset(pdata,0,8);
    int len = listdata.length();

    for(int i=0; i<len; i++)
		pdata[i] =(UINT8) listdata[i].toUInt(&ok,16);

	return (CAN_SendMsg(can_idx,can_node, 0x700 + canaddr, len, pdata) > 0);
}

/*  send SDO telegraph */
bool CanNode::sendSDO(QString data,unsigned long nodeaddr,unsigned char can_idx, unsigned char can_node)
{
	bool ok;
	QStringList listdata = data.split(" ");
	UINT8 pdata[8];
    memset(pdata,0,8);
    int len = listdata.length();

    for(int i=0; i<len; i++)
		pdata[i] =(UINT8) listdata[i].toUInt(&ok,16);

	return (CAN_SendMsg(can_idx,can_node, 0x600 + nodeaddr, len, pdata) > 0);
}

bool CanNode::sendSDO(unsigned char* data,unsigned long nodeaddr,unsigned char can_idx, unsigned char can_node)
{
    return true;
}

/* set heartbeat time */
void CanNode::setHeartBeat(int ms)
{
	UINT8 pdata[8] ={0x22,0x17,0x10,0x00};
	QString str = "22 17 10 00 ";
	int low = 10*ms%256;
	int high = 10*ms/256;
	str += QString::number(low,16)+" "+QString::number(high,16)+" 00 00";
	sendSDO(str);
}

/* configure event driver */
void CanNode::setEventDriver(bool flag)
{
    if(flag)
        sendSDO("22 23 64 00 10 00 00 00");
    else
        sendSDO("22 23 64 00 00 00 00 00");
}

/* return channel counts */
QVector<unsigned int> CanNode::getChannelCounts()
{
    return m_Channels;
}

int CanNode::getChannelCounts(int index) 
{ 
    if(index<0 || index>3) 
        return -1;
    return m_Channels[index];
}