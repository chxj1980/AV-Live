/** $Id: //depot/NVS/v2.1/bsrExplorer/bsrMedia/media/MediaDef.h#9 $ $DateTime: 2009/01/13 16:49:56 $
 *  @file MediaDef.h
 *  @brief ý����ͷ�ļ�
 *  @version 2.0.0
 *  @since 1.0.0
 *  @author dongming<DongM@bstar.com.cn> 
 *  @date 2007-07-17    Created it
 */

#pragma once
#include <MMSystem.h>

#define WM_VIDEO_STOP       (WM_USER + 1401)     // ֹͣ
#define WM_VIDEO_D6T_NOTICE (WM_USER + 1403)     // BSTPӦ����Ϣ
#define WM_VIDEO_RTP_MES    (WM_USER + 1408)     // ������Ƶ��Ϣ
#define WM_VIDEO_NO_DATA    (WM_USER + 1418)     // ��Ƶ����������
#define WM_VIDEO_PS_CHANGED (WM_USER + 1430)     // ����״̬�ı�

//////////////////////////////////////////////////////////////////////////
// ��Ƶ�����λ��
enum TitlePos
{
  TP_CENTER           = 0,   // ����
  TP_LEFT_TOP,               // ����
  TP_RIGHT_TOP,              // ����
  TP_LEFT_BOTTOM,            // ����
  TP_RIGHT_BOTTOM,           // ����
};

//////////////////////////////////////////////////////////////////////////
// ����״̬
enum PlayStatus
{
  PS_NORMAL          = 0,    // ��������
  PS_PAUSE,                  // ��ͣ
  PS_STOP,                   // ֹͣ����
  PS_FAST_2,                 // 2����
  PS_FAST_4,                 // 4����
  PS_FAST_8,                 // 8����
  PS_FAST_16,                // 16����
  PS_SLOW_2,                 // 1/2����
  PS_SLOW_4,                 // 1/4����
  PS_SLOW_8,                 // 1/8����
  PS_SEEK,                   // ��λ
  PS_FRAME_NEXT,             // ��һ֡
  PS_FRAME_PRE,              // ��һ֡
  PS_FRAME_I,                // ����I֡
};

//////////////////////////////////////////////////////////////////////////
// �������汾
typedef enum MDecodeType
{
  MDECODE_NULL  = 0,
  MDECODE_,
  MDECODE_BSR   = 100,  // ��ɫ֮��(��)
  MDECODE_BSK,          // ��ɫ֮��(v6.x)
  MDECODE_BSX,
  MDECODE_BSA,
  MDECODE_HK    = 200,  // ����hc��
  MDECODE_HK_H  = 201,  // ����h��
  MDECODE_HK_9000 = 202,// ����9000
  MDECODE_HK_9000A = 203,// Ʒ��OEM����9000
  MDECODE_HK_IPC = 204,// ����IPC
  MDECODE_HK_8000 = 205,
  MDECODE_HK_793PFWD = 206,
  MDECODE_HK_9000ST  = 207,
  MDECODE_HK_9000AS  = 208,   //��Ӧ����PEAQE-9000A����

  MDECODE_DH    = 300,  // ��
  MDECODE_DL    = 400,
  MDECODE_LC    = 500,
  MDECODE_XVID  = 600,
  MDECODE_ZAB   = 700,
  MDECODE_SNC   = 800, //sony �豸
  MDECODE_XLINK = 900, //xilink �豸
  MDECODE_TM    = 1000, //ͼ���豸
  MDECODE_SHANY =  1100,//shany�豸
  MDECODE_PSC =   1200, //�����豸
  MDECODE_ZXW =   1300, //����΢�豸
  MDECODE_ZSLC =  1400, //������̽���
  MDECODE_ZSV5 =  1401,
  MDECODE_SAM  =  1500,
  MDECODE_WQ   =  1600,
  MDECODE_BK	 =	1700, // �����忨(�ٿ�)
  MDECODE_BOS  =  1800, // BOSCH IPC

  MDECODE_SHX  =  1900, // ��Ѷ
  MDECODE_ONVIF = 2000, // ֧�� ONVIF ���豸
	MDECODE_JZ   =  2100,//����
	MDECODE_HB   =  2200,//����

  MDECODE_HW = 2300,//�ά(���к������뿨)
  MDECODE_TJTY = 2400, // ͬ����Ծnvr
	MDECODE_SNE = 2500, //������ipc
	MDECODE_YS = 2600, // ����
  MDECODE_TZ = 2700, // ͬ��ƽ̨ipc
  MDECODE_TDY = 2800, //���ΰҵ
  MDECODE_TDY_CENTER_FILE = 2801, //���ΰҵ�������ص��ļ�

}MDT;

// ����
typedef enum MVendorType
{
  MVENDOR_NULL = 0,
  MVENDOR_,
  MVENDOR_BS   = 100,
  MVENDOR_HK   = 200,
  MVENDOR_DH   = 300,
  MVENDOR_DL   = 400,
  MVENDOR_LC   = 500,
  MVENDOR_ZAB  = 600,
  MVENDOR_SNC  = 700,  //sony
  MVENDOR_XLINK = 800, //xilink
  MVENDOR_TM    = 900, //ͼ���豸
  MVENDOR_SHANY = 1000, //shany�豸
  MVENDOR_PSC =   1100,   //�����豸
  MVENDOR_ZXW =   1200,   //����΢�豸
  MVENDOR_ZSLC =  1300,
  MVENDOR_SAM  =  1400,
  MVENDOR_WQ   =  1500,
  MVENDOR_BK	 =	1600, // �����忨(�ٿ�)
  MVENDOR_BOS  = 1700,
  MVENDOR_SHX  = 1800,   // ��Ѷ
  MVENDOR_ONVIF = 1900, // ֧�� ONVIF �ĳ���, ͳһ�����.
  MVENDOR_JZ = 2000,
  MVENDOR_HB = 2100,  // ����
  MVENDOR_TDY  = 2200,  //���ΰҵ

}MVT;

//////////////////////////////////////////////////////////////////////////
// ����Դ����
typedef enum MDataSource
{
  MDATA_NULL   = 0,
  MDATA_FILE   = 1,          // �����ļ�
  MDATA_TCP    = 2,          // TCP����
  MDATA_UDP    = 3,          // UDP����
  MDATA_RTP    = 4,          // RTP����
  MDATA_ALARM  = 5,          // ��������
  MDATA_RTP104 = 6,          // RTP104
  MDATA_PIPE   = 7,          // ѹջ��ʽ
  MDATA_RTPLIMIT = 8,        //limit����

}MDS;
//MDATA_RTP440 = 8,          // RTP440
//////////////////////////////////////////////////////////////////////////
// ֡����
typedef enum MFrameType
{
  MFT_UNKNOWN = 0,
  MFT_I_FRAME = 1,
  MFT_P_FRAME = 2,
  MFT_B_FRAME = 3,
}MFT;

//////////////////////////////////////////////////////////////////////////
// ResetBuffer Type
typedef enum MResetBufferType
{
  MRBT_ALL = 0,
  MRBT_BUF_VIDEO_SRC = 1,
  MRBT_BUF_AUDIO_SRC = 2,
  MRBT_BUF_VIDEO_RENDER = 3,
  MRBT_BUF_AUDIO_RENDER = 4,
}MRBT;
//////////////////////////////////////////////////////////////////////////
// ״̬��ʾ·��
const CString g_StatusBmpName = "bmp\\video_status.bmp";

//////////////////////////////////////////////////////////////////////////
// ���ݳ���
const static int SIZE_4K       = 1024 * 4;
const static int SIZE_16K      = 1024 * 16;
const static int SIZE_32K      = 1024 * 32;
static const int SIZE_40K      = 1024 * 40;   // 40k
static const int SIZE_64K      = 1024 * 64;   // 64k
static const int SIZE_80K      = 1024 * 80;   // 80k
static const int SIZE_128K     = 1024 * 128;  // 128k
static const int SIZE_256K     = 1024 * 256;  // 256K
static const int SIZE_512K     = 1024 * 512;  // 512K
static const int SIZE_1M       = 1024 * 1024; // 1M
static const int SIZE_FRAME_Q  = 50;          // ԭʼ֡����
static const int SIZE_4M       = 1024*1024*4;
static const int SIZE_5M       = 1025*1024*5;
static const int SIZE_35M      = 1024*1024*35;
static const int SIZE_70M      = 1024*1024*70;

//////////////////////////////////////////////////////////////////////////
// �������
enum MECode
{
  MERROR                = -1,      // ����ʧ��
  MERROR_NOERROR        = 0,       // �����ɹ�
  MERROR_PARAM_INVALID,            // �ղ���
  MERROR_URL_UNKNOWN,              // URL����ʶ��
  MERROR_HK             = 100,     // �����Ĵ������
  MERROR_HK_NO_DLL      = 101,     // ����-û�ҵ�hik.dll
  MERROR_HK_OPEN        = 130,     // ����-�����ļ�����
  MERROR_HK_WRITE       = 131,     // ����-д�ļ�����
  MERROR_BS             = 200,     // ��ɫ֮�ǵĴ������
  MERROR_DH             = 300,     // �󻪵Ĵ������
  MERROR_LC             = 400,     // �ɳ۵Ĵ������
  MERROR_XVID           = 400,     // �ɳ۵Ĵ������
	MERROR_LM							= 500,		 // �����忨(�ٿ�)�Ĵ������
  MERROR_DC_SOCKET      = 10000,   // SOCKET����
  MERROR_DC_FILE        = 11000,
};

//////////////////////////////////////////////////////////////////////////
// ��ɫ�Ǽ� Dvr v6.0 ���ݸ�ʽ
enum DHv6Type
{
  D6T_UNKNOWN  = 0,
  D6T_AUDIO,
  D6T_VIDEO,
  D6T_AUDIO_LIMIT       = 3,
  D6T_IAEvent           = 4,
  D6T_SPEECH            = 6,
  D6T_NOTICE            = 9,
  D6T_CMD_REQUEST_REPLY = 10,
  D6T_REPORT,
  D6T_AUDIO_G726,
};
enum DHv6Frame
{
  D6V_FRAME_UNKNOWN = 0,
  D6V_FRAME_I,
  D6V_FRAME_B,
  D6V_FRAME_P,
};

#define PB_MSG_END        0x01  // �طŽ���,����¼���ļ����Իط�
#define PB_MSG_FUTURE     0x02  // δ���Ļط�ʱ��
#define PB_MSG_RECORDERR  0x03  // �����¼���ʽ
#define PB_MSG_CTRLERR    0x04  // ����Ŀ�����Ϣ
#define PB_MSG_SEEKOK     0x05  // �û�seek��ķ���
#define PB_MSG_IFRAMER    0x06  // �û���ΪI֡������
#define PB_MSG_PLAYBACK   0x07  // �û���Ϊ���沥����
#define PB_MSG_RECEDE     0x08  // �û���Ϊ�˷���

//////////////////////////////////////////////////////////////////////////
// ״̬ͳ��
struct tagStatus
{
  PlayStatus iPS;                  // ��ǰ����״̬
  DWORD dwFrameRate;               // ֡��
  DWORD dwBitRate;                 // ����
  DWORD dwElapsedTime;             // ��ȥʱ��
  DWORD dwTotalTime;               // ��ʱ��
  DWORD dwWidth;                   // ֡ԭʼ���
  DWORD dwHeight;                  // ֡ԭʼ�߶�
};

// RTP_MSG.subtype = 1�Ľṹ
typedef struct RTP_MSG_SUB_01
{
  char          name[32];
  int           label;
  int           camera;
  int           site;
  unsigned long ipAddr;
  char          path[64];
  char          deviceType[16];    // mysql,system table ����.
}*LPRTP_MSG_SUB_01;

// RTP_MSG.subtype = 255�Ľṹ
typedef struct RTP_MSG_SUB_FF
{
  int camera; // ��ͷ���
  int issure; // ���ں�
  int type;   // ��������
}close_msg_t, *LPRTP_MSG_SUB_FF;


//�ص���������ݽṹ��
typedef struct _DEC_FRAME_S
{
	unsigned char* pY;
	unsigned char* pU;
	unsigned char* pV;
	unsigned int  uWidth;
	unsigned int  uHeight;
	unsigned int  uYStride;
	unsigned int  uUVStride;
}DEC_FRAME_S, *LPDEC_FRAME_S;
typedef struct portAgentReceiveInfo
{
	int port;
	int ipAddr;
	char res[32];
}AgentRecvInfo;
