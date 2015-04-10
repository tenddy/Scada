#ifndef CANNODE_H_
#define CANNODE_H_
#include <qstring.h>
#include <qvector.h>
#include <qmessagebox.h>

class CanNode
{
public:
	CanNode(unsigned long COB_ID = 11, int can_idx = 0, int node_id = 0);
	~CanNode(void);
	
    enum BAUDRATE{
		BAUD_10k = 1,
		BAUD_20k = 2,
		BAUD_50k = 3,
		BAUD_100k = 4,
		BAUD_125k = 5,
		BAUD_250k = 6,
		BAUD_500k = 7,
		BAUD_800k = 8,
		BAUD_1000k = 9
	};
    
    /*initialize*/
    void initCanNode(int can_idx = 0, int node_id = 0);

    /*baud rate*/
	int getBaudRate(){return m_baudRate;};
	void setBaudRate(int baudrate) {m_baudRate = baudrate;}
    
    /*COB-ID*/
	void setCanNodeAddr(unsigned char nodeaddr) {m_canAddr = nodeaddr;}
    unsigned char getCanAddr(){return m_canAddr;}
    /*send message*/
	bool sendSDO( QString data,unsigned long canAddr = 11,unsigned char can_idx=0, unsigned char can_node=0);
	bool sendSDO( unsigned char* msg,unsigned long canAddr = 11, unsigned char can_idx=0, unsigned char can_node=0);
	bool sendState(unsigned char cs, unsigned char nodeId,unsigned char can_idx=0, unsigned char can_node=0);
    bool sendState(QString data,unsigned char can_idx=0, unsigned char can_node=0);
    bool sendNMT(QString data,unsigned long canAddr = 11,unsigned char can_idx=0, unsigned char can_node=0);

    /*control canopen stack*/
	bool startCan() {return sendState(0x01,0x00);}
	bool resetCan() {return sendState(0x81,0x00);}
	bool stopCan() {

		sendState(01,00);
		setHeartBeat(0);
		setEventDriver(false);
		sendState(0x02, 0x00);
		_sleep(10);
		sendState(0x80, 0x00);
		_sleep(10);
		return true;
	}
	void setHeartBeat(int ms);
    void setEventDriver(bool flag );

    /*channels of digit input or output, channels of analog input or output*/ 
	bool setChannelCounts(int index, int counts) {
		if(index>=4)
			return false;
		m_Channels[index] = counts;
		return true;	
	}
	
    QVector<unsigned int> getChannelCounts(); 
    
    int getChannelCounts(int index);
    /*{ 
        if(index<0 || index>3 ||m_Channels.size()!=4) 
            return -1;
        return m_Channels[index];
    }*/

private:
	unsigned long m_canAddr;
	//unsigned char m_mode;  // 0 --- CAN_11B, 1 --- CAN_29B
	int m_baudRate;
	//int m_errCode;		  /* error code */
    bool m_eventDriver;
	QVector<unsigned int> m_Channels;
};

#endif

