/////////////////////////////////////////////////////////////////////////////
//	ICAN Application Programming Interface (API) 
// 
//	Copyright : ICP Electronics Inc.,2003
////////////////////////////////////////////////////////////////////////////
#ifndef ICANAPI_H_
#define ICANAPI_H_
#ifdef IEICAN02_EXPORTS
#define ICAN_API extern "C" __declspec(dllexport)
#else
#define ICAN_API extern "C" __declspec(dllimport)
#endif

/****************************************************************************
**	constant and macro
*****************************************************************************/
#ifndef UINT8
#define UINT8	unsigned char
#endif

#ifndef UINT16
#define UINT16	unsigned short
#endif

#ifndef UINT32
#define UINT32	unsigned long
#endif

#ifndef INT32
#define INT32	signed long
#endif

/*
** Values for the CAN node
*/
#define CAN_11B		0		// 11 bit identifier mode
#define CAN_29B		1		// 29 bit identifier mode
#define CAN_TX_QUE	0		// transmit queue
#define CAN_RX_QUE	1		// transmit queue

/*
** VCI return codes of the fucntion
*/
#define	CAN_ERR			0
#define CAN_QUE_EMPTY	0
#define CAN_QUE_FULL	0
#define CAN_OLD			0
#define CAN_OK			1	// successful completion
#define CAN_ERR_HWSW	-1	// function could not be performed
							// because of hard or software errors

#define CAN_ERR_SUPP	-2	// function is not supported
							// this way (support-error)

#define CAN_ERR_PARA	-3	// calling parameter(s) is (are)
							// not correct or out of range

#define CAN_ERR_RES		-4	// resource error
							// the resource limit exceeded
							// at creation of a queue or soming else

#define CAN_ERR_QUE		-5	// Queue overrun
							// One or more objects couldn't be
							// iinserted into the queue and wew lost.

#define CAN_ERR_TX		-6	// A CAN message couldn't be sent
							// for a long time
							// cable error, wrong baud rate etc.

/*
**  Baudrates from CAN in Automation  (CIA)
*/

#define BAUD_10K     0x31,0x1C
#define BAUD_20K     0x18,0x1C
#define BAUD_50K     0x09,0x1C
#define BAUD_100K    0x04,0x1C
#define BAUD_125K    0x03,0x1C
#define BAUD_250K    0x01,0x1C
#define BAUD_500K    0x00,0x1C
#define BAUD_800K    0x00,0x16
#define BAUD_1M		 0x00,0x14


/*****************************************************************
**	data_types
*****************************************************************/
#ifdef _MSC_VER
	#pragma pack(1)			// set aligment to 1 byte (Microsoft style)
#endif // _MSC_VER
#ifdef _BORLANDC__
#if (__BORLANDC__ < 0x460)
	#pragma -a-				// set aligment to 1 byte (Borland C style )
#else
	#pragma option -al		// set aligment to 1 byte ( Borland C++ Builder style)
#endif
	#pragma alignment		// output alignment in compile window (Borland)
#endif // __BORLANDC__

/*
** Informations, delivered from the interface board
*/

typedef struct{
	UINT16	sw_version;
    UINT32	dwAddr;				// local dwAddress
    UINT32  dwBus;				// on which bus
    UINT32  dwSlot;				// which slot
    char    cName[32];          // Name of card.
	UINT16	irq_num;
} CAN_BOARD_INFO;

/*
** CAN-Controller information
*/
typedef struct {
	UINT8			bt0;		// Value set for Baudrate (bustiming reg 0 )
	UINT8			bt1;		// Value set for Baudrate (bustiming reg 1 )
	UINT32			acc_code;	// Value set for acceptance filter (id code)
	UINT32			acc_mask;	// Value set for acceptance filter (relevance mask )
} CAN_INFO;

/*
**	CAN status 
*/
typedef struct {
	bool  bus_status;
	bool  error_status;
	bool  tx_status;
	bool  rx_status;
	bool  tx_complete_status;
	bool  tx_buffer_status;
	bool  data_overrun_status;
	bool  rx_buffer_status;
} CAN_STS;

/*
**	Structure of a CAN object
*/
typedef struct {
	UINT32	time_stamp;			// Timestamp for receive queue objects
	UINT32	id;					// Identifier 11/29-Bit
	UINT8	len;				// number of data bytes ( 0~8)
	UINT8	rtr;				// RTR-Bit: 0=dataframe, 1=Remoteframe
	UINT8	a_data[8];			// Array for up to 8 data bytes
} CAN_MSG;

#ifdef _MSC_VER
	#pragma pack(1)			// set aligment to 1 byte (Microsoft style)
#endif // _MSC_VER
#ifdef _BORLANDC__
#if (__BORLANDC__ < 0x460)
	#pragma -a-				// set aligment to 1 byte (Borland C style )
#else
	#pragma option -al		// set aligment to 1 byte ( Borland C++ Builder style)
#endif
	#pragma alignment		// output alignment in compile window (Borland)
#endif // __BORLANDC__

////// API declaration ////////////////////
/////// Board Level Functions /////////////////////////////////////////////////////////////////////////
ICAN_API INT32 _stdcall CAN_CountCards();
ICAN_API INT32 _stdcall CAN_ReadBoardInfo(UINT16 card_idx,CAN_BOARD_INFO* p_info);
/////// CAN Level Functions ///////////////////////////////////////////////////////////////////////////
ICAN_API INT32 _stdcall CAN_Mode(UINT16 card_idx, UINT8 can_no);
ICAN_API INT32 _stdcall CAN_Init(UINT16 card_idx, UINT8 can_no,UINT8 bt0, UINT8 bt1, UINT8 mode );
ICAN_API INT32 _stdcall CAN_Reset(UINT16 card_idx, UINT8 can_no );
ICAN_API INT32 _stdcall CAN_ReadCanInfo(UINT16 card_idx, UINT8 can_no, CAN_INFO *p_info);
ICAN_API INT32 _stdcall CAN_ReadCanStatus(UINT16 card_idx, UINT8 can_no, CAN_STS *p_sts);
ICAN_API INT32 _stdcall CAN_Start(UINT16 card_idx, UINT8 can_no );
ICAN_API bool  _stdcall CAN_IsRun(UINT16 card_idx, UINT8 can_no);
//////// Message Level Functoins ///////////////////////////////////////////////////////////////////////
ICAN_API UINT16 _stdcall CAN_ConfigQueue(UINT16 card_idx, UINT8 can_no,UINT8 que_type, UINT16 que_size);
ICAN_API INT32 _stdcall CAN_SetAccMask(UINT16 card_idx, UINT8 can_no,UINT32 acc_code, UINT32 acc_mask );
ICAN_API INT32 _stdcall CAN_CountMsgs(UINT16 card_idx, UINT8 can_no,UINT8 que_type);
ICAN_API INT32 _stdcall CAN_SendMsg(UINT16 card_idx, UINT8 can_no, UINT32 id, UINT8 len,UINT8* p_data);
ICAN_API INT32 _stdcall CAN_ReadMsg(UINT16 card_idx, UINT8 can_no, UINT16 count, CAN_MSG* p_obj);
ICAN_API INT32 _stdcall CAN_RequestMsg(UINT16 card_idx, UINT8 can_no, UINT32 id, UINT8 len);
////////// Miscelleous /////////////////////////////////////////////////////////////////////////////////
ICAN_API INT32 _stdcall CAN_UpdateBufObj(UINT16 card_idx, UINT8 can_no, UINT8 len, UINT8 *p_data);
ICAN_API INT32 _stdcall CAN_SelfTest(UINT16 card_idx, UINT8 can_no);

#endif //ICANAPI_H_









