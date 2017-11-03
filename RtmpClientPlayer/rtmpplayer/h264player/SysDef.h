#pragma once

//////////////////////////////////////////////////////////////////////////
// ���´��������������Ƶ���ݸ�ʽ��׼
struct magicInfo_t
{
  char logo[8];    // �̶�Ϊ"BLUESKY"
  char vcodec;     // ��Ƶ���룬��_videoInfo_t.codec��ͬ
  char acodec;     // ��Ƶ���룬��_audioInfo_t.codec��ͬ
  char media;      // Ƭ���ڰ�����ý������(bitmap): bit1=��Ƶ(0x01); bit2=��Ƶ(0x02); bit3=����(0x04); bit4=����(0x08); bit8=����
  char version;    // ͷ��Ϣ�汾�ţ���ǰΪ, ��ͷ���ȹ̶�Ϊbytes
  char res[4];     // (v1.3+)
};
//ͳ����Ϣ
struct sumInfo_t
{
  unsigned long long size; // �ļ���С(��λ�ֽ�,���ֶ����ļ��׵�ַ
  unsigned int time;       // ¼��ʱ��ϵͳʱ��,����ֵ,time(NULL)����ֵ, time_tΪbit
  unsigned long length;    // ¼��ʱ�䳤��,��
  char vendor[4];          // ¼�����ݵĳ�����Ϣ��DH|HK|DL|BS|BSK|BSA(PNX-mux)|BSN(-p440)
  char nextClip;           // (v1.3+) 0: �ޣ�1����
  char res[3];             // (v1.3+) �����ֶ�
};
//��Ƶ
struct videoInfo_t
{
  char codec;            // ���뷽ʽ: 1(mpeg4) | 3(h263) | 4(h264) |11(���ֽ�SOLO֡ͷ��mpeg4)
  char resolution;       // �ֱ���: 1:CIF; 2:2CIF; 3:1/2D1; 4:D1, 5:QCIF, NTSCʱ+128
  char frameRate;        // ֡��
  char flags;            // ��־λ���ݱ���Ϊ
  unsigned long bitRate; // ����(kb/s):
};
//��Ƶ
struct audioInfo_t
{
  char codec;            // ���뷽ʽ: ���룺(ogg) | 2(mp2) | 3(mp3) | 11(g.711) | 21(g.721) | 23(g.723) | 29(g.729)
  char resolution;       // 8-5bitΪͨ������(��ͨ��(0)|˫ͨ��(1|...)��4-1bitΪ������ȣ�bit(0)|16bit(1)|32bit(2)|24bit(3)|64bit(3)...
  char frameRate;        // ������(khz): ��/16/32/44
  char flags;            // ��־λ���ݱ���Ϊ
  unsigned long bitRate; // ����(kb/s):
};
//����
struct netInfo_t
{
  unsigned long clientAddr; // ¼��������IP��ַ
  unsigned long srcAddr;    // ��ƵԴIP��ַ,¼�������¼��ʱΪ
  short srcPort;            // ��ƵԴ�˿�
  short dstPort;            // ��ƵĿ�Ķ˿�
  char proto;               // ����Э��: 0x00: ���ش��̣�x01: RTP, 0x0x02: TCP
  char res[3];              //(v1.3+)����
};
//Դ��Ϣ
struct sourceInfo_t
{
  int district; // ����id,¼�������¼��ʱΪ
  int site;     // վ��id,¼�������¼��ʱΪ
  int device;   // �豸id, ¼����������
  int camera;   // ��ͷid, ͨ�����(1-32)
};
//����
struct issuerInfo_t
{
  int recordType;   // ¼����������: 1:����; 2:¼��ƻ�, 3: �ֹ�¼��: �ƶ����¼��
  int recordId;     // ¼��ƻ�id�򱨾���id
};
//����
struct textInfo_t
{
  char host[16];     // ¼��������(gethostname)���糬���ֽ�ȡǰ�ֽڣ��豸��
  char user[16];     // ¼�Ƶ��û������糬���ֽ�ȡǰ�ֽڣ�
  char title[64];    // (v1.3+) camera��, ͨ�������糬���ֽ�ȡǰ�ֽڣ�
  char keywords[16]; // (v1.3+) �ؼ����뱸ע
};
//ʵ��ͷ����Ϣ�ṹ
struct meta_t
{
  struct magicInfo_t magicInfo;
  struct sumInfo_t sumInfo;
  struct videoInfo_t videoInfo;
  struct audioInfo_t audioInfo;
  struct netInfo_t netInfo;
  struct sourceInfo_t sourceInfo;
  struct issuerInfo_t issuerInfo;
  struct textInfo_t textInfo;
};
//����ͷ����Ϣ�ܽṹ
struct clipHeader_t
{
  union
  {
    struct meta_t hdata;
    char padding[256]; //����ǿ��clipHeader_t��СΪBytes.
  }u;
};
//15����ʱ���ʽ
typedef struct DATETIME
{
  WORD  year;
  WORD  month   :4;
  WORD  day     :5;
  WORD  hour    :5;
  WORD  minute  :6;
  WORD  second  :6;
  WORD  week    :3;
}DATETIME;
//////////////////////////////////////////////////////////////////////////
// rtp mes header
typedef struct RTP_MSG
{
  short subtype;
  short length;
  char  body[1];
}*LPRTP_MSG;

struct rtp_hdr_t
{
  unsigned char tc1;    // 1 byte
  unsigned char tc2;    // 1 byte
  unsigned short seq;    /* sequence number */
  unsigned int ts;    /* timestamp */
  unsigned int ssrc;    /* synchronization source */

  RTP_MSG payload;
};

struct FrameStruct
{
  BOOL     iNeedIFrame;
  
  unsigned char  encType;  //��Ƶ֡��������
  unsigned char  res;
  unsigned short iType;    //��Ƶ֡����
  int       iLen;
  int       iTimeStamp;
  int       iTick;
  int       iWidth;
  int       iHeight;
  int       isequence;
  int       ichannel;
  int       idevice;
  int       iInterlace;
  BYTE*     pBuf;
};
