/**
 * BSFP��غ궨��, �����빫˾�ĵ�����һ��. 
 * ��չ�����赥��ע��. 
 */


#ifndef BSFPDEFINED_HPP_
#define BSFPDEFINED_HPP_

#include <time.h>
#define BSTP_HEADER_MARK  0xBF9D1FDB



/*
  BSTPHeader::type ֵ
*/
#define BSTP_TYPE_AUDIO       1   // ����
#define BSTP_TYPE_VIDEO       2   // ��Ƶ
#define BSTP_TYPE_INTELLIGENT 4   // ����Ƶ���ܵ�֡
#define BSTP_TYPE_SPEECH_C2D  6   // �����Խ�,�ͻ���->�豸
#define BSTP_TYPE_MESSAGE     9   // ��Ϣ֡,������.
#define BSTP_TYPE_COMMAND     10  // ��������/Ӧ��
#define BSTP_TYPE_SYNC        21  // ��Ƶ��Ϣ֪ͨ
#define BSTP_TYPE_CFG         22  // ������Ϣ֡(��������������,��չ����Ƶ�������ݵ�)



/*
  ��Ƶ֡ʱ,����
  BSTPHeader::format[0] ֵ
*/
#define BSTP_FORMAT_MPEG4   1
#define BSTP_FORMAT_H263    3
#define BSTP_FORMAT_H264    4

/*
  ��Ƶ֡ʱ,�ֱ���
  BSTPHeader::format[1] ֵ
*/
#define BSTP_FORMAT_DCIF   1
#define BSTP_FORMAT_CIF    2
#define BSTP_FORMAT_2CIF   3
#define BSTP_FORMAT_D1     4
#define BSTP_FORMAT_HALFD1 5
#define BSTP_FORMAT_720I   11
#define BSTP_FORMAT_720P   12
#define BSTP_FORMAT_1080I  13
#define BSTP_FORMAT_1080P  14


/*
  ��Ƶ֡ʱ,֡����
  BSTPHeader::format[3] ֵ
*/
#define BSTP_FORMAT_VIDEO_I   1   // i֡
#define BSTP_FORMAT_VIDEO_B   2   // b֡
#define BSTP_FORMAT_VIDEO_P   3   // p֡



/*
  ��Ƶ֡ʱ,֡����
  BSTPHeader::format[0] ֵ
*/
#define BSTP_FORMAT_AUDIO_PCM     0
#define BSTP_FORMAT_AUDIO_OGG     1
#define BSTP_FORMAT_AUDIO_MP2     2
#define BSTP_FORMAT_AUDIO_MP3     3
#define BSTP_FORMAT_AUDIO_AAC     4

#define BSTP_FORMAT_AUDIO_G711u   9 //����4�ֽڵı�׼G.711u
#define BSTP_FORMAT_AUDIO_G711u4  109 //��4�ֽ�ͷ��G.711u
#define BSTP_FORMAT_AUDIO_ADPCM   10 // ��4�ֽ�ͷ��adpcm
#define BSTP_FORMAT_AUDIO_G711    11
#define BSTP_FORMAT_AUDIO_G719    19
#define BSTP_FORMAT_AUDIO_G726    26
#define BSTP_FORMAT_AUDIO_G729    29
#define BSTP_FORMAT_AUDIO_G711a4  111 // ��4�ֽ�ͷ��G.711a

// ����Ϊ28�ֽ�.
struct BSTPHeader
{
  /*
  �̶�ֵ: 0xBF9D1FDB
  ���г��������Ǵ˱�־
  */
  unsigned int mark;


  /*
  1=����,2=��Ƶ,9=������Ϣ֡
  ���ڷ����ǵ���,�����ְ�������Ƶ,����Ϊ2.

  ����,�������ǵ������Խ�,6=�����Խ�֡(�豸->�ͻ���),1=�����Խ�֡(�ͻ���->�豸,��ʱdevice�ֶ�Ϊ0xFF00)
  */
  char type;


  /*
  ͨ����: -127-128
  �ñ�־Ŀǰû��ʹ��
  */
  char channel;

  /*
  �豸���
  �ô˱�ʾ�������豸��������.
  �ڴ�֮ǰ,0xFF00���������ǵ������Խ���,
  ���ǵ��豸���������ʱ,������Ϊ0x0000,Ҳ������Ϊ0x0001,��ȷ���Ƿ�������ֵ.


  ���������̰����·�ʽ����,
  Ŀǰ���ø�8λʶ����,��8λ����Ϊ0x00(Ϊ����������Ԥ��,�������ͻ�����ȷ����������).

  ����:
  0xEF00 - 0xEFFF (0xEF01 - 15ϵ��, 0xEF02 - 17ϵ��, 0xEF03 - Limitϵ��)

  ����,��ʹ�ú����忨�Ĺ��ػ�:
  0xEE00 - 0xEEFF

  ��,��ʹ�ô󻪰忨�Ĺ��ػ�:
  0xED00 - 0xEDFF

  �ʳ�:
  0xEC00 - 0xECFF

  ����:
  0xEB00 - 0xEBFF

  ͬ����Ծ:
  0xEA00 - 0xEAFF

  Xilink:
  0xE900 - 0xE9FF

  SNC(sony):  0xE800 - 0xE8FF
  SHANY:      0xE700 - 0xE7FF
  ZXW:        0xE600 - 0xE6FF
  ����(PSC):  0xE500 - 0xE5FF 
  ����:       0xE400 - 0xE4FF
  �������:    0xE300 - 0xE3FF
  */
  short device;

  /*
  ��֡����,ָ�������س���,bytes
  */
  unsigned int length;

  /*
  ������֡�ڸ�ͨ��(channel)�����,��������
  */
  unsigned int sequence;

  /*
  ��֡�����ϵͳʱ�䣬Ϊtime_t��׼ʱ��
  �������ǵ�TCP��,��ֵΪǰ���豸���,UDP��,����������,
  ����������ȫ��Ϊ���������.
  */
  unsigned int timeStamp;

  /*
  ��֡�����ϵͳʱ�Ӽ�������������Ƶ��ȷ��ʱ�����,
  ����������,���¼΢��
  */
  unsigned int tick;

  /*
  ֡�ľ����ʽ��Ϣ, �������BSFP�ĵ�.
  ��Ƶ֡:           ~~~~~~~~~~~~~~~~
  ����1�ֽ�: 2(mp2), 3(mp3) ...
  �ֱ���1�ֽ�:   1-4bitsΪ�������, ��8bit(0)|16bit(1)|32bit(2)|24bit(3)|64bit(3) 
                 5-8bitsΪͨ����(1Ϊ˫ͨ��, 0�ǵ�ͨ��)
  ֡��1�ֽ�: 2(2k), 4(4k), 8(8k), 16(16k) 
  ����1�ֽ� 

  ��Ƶ֡:
  ����1�ֽڣ�  1(mpeg4), 3(h263), 4(h264), 11(P440 ��64 �ֽ�SOLO ֡ͷ��mpeg4)
  �ֱ���1�ֽ�: PAL DCIF(1), CIF(2),2CIF(3),D1(4),halfD1(5)
  ֡��1�ֽڣ�  1-30 ��ʵ��ȡֵ,��λΪ֡/��,��25,
  ֡����1�ֽڣ�1(I ֡), 2(B ֡), 3(P ֡)

  */
  char format[4];

};


#define IS_BSTP_IFRAME(bstp)  ((bstp).type == BSTP_TYPE_VIDEO && (bstp).format[3] == BSTP_FORMAT_VIDEO_I)


#endif

