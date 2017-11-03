/** $Id: utypes.h 269 2009-06-09 03:24:48Z tiger $ $Date$
 *  @file utypes.h
 *  @brief short names of unsigned integer types 
 *  @version 0.0.1
 *  @since 0.0.1
 *  @author Tan Feng <tanf@bstar.com.cn>
 *  @date 2009-05-20    Created it
 */
/******************************************************************************
*@note
    Copyright 2009, BeiJing Bluestar Corporation, Limited
                 ALL RIGHTS RESERVED
Permission is hereby granted to licensees of BeiJing Bluestar, Inc. products
to use or abstract this computer program for the sole purpose of implementing
a product based on BeiJing Bluestar, Inc. products. No other rights to
reproduce, use, or disseminate this computer program,whether in part or in
whole, are granted. BeiJing Bluestar, Inc. makes no representation or
warranties with respect to the performance of this computer program, and
specifically disclaims any responsibility for any damages, special or
consequential, connected with the use of this program.
For details, see http://www.bstar.com.cn/
******************************************************************************/
#ifndef _UTYPES_H
#define _UTYPES_H

#pragma once

typedef unsigned char    uchar;
typedef unsigned int     uint;
typedef unsigned short   ushort;
typedef unsigned long    ulong;
typedef unsigned __int64 ullong;
typedef __int64 llong;



#define MAX_FRAMESIZE 1024*512


#define MAX_READUNIT 512


enum SOURCE_TYPE
{
	MEDIA_UNKNOW = 0,
	MEDIA_TCP,
	MEDIA_RTP,
};

struct SdkBsfpHead
{
	unsigned int mark;			/**< ֡ͷ��ǰ����ʶ������֡ͷ��λ���̶�ֵΪ0xBF9D1FDB */
	unsigned char type;			/**< ֡���ͱ�ʶ�� 1����Ƶ 2����Ƶ 3������ 4: ����Ƶ���ܷ�����Ϣ 9����Ϣͨ�� 10: ����������Ӧ��*/
	char channel;						/**< ͨ����  ȡֵ��Χ��-127~128��*/
	unsigned short device;	/**< �豸�������к� */
	unsigned int length;		/**< ��֡����(data)�ܳ��ȣ�������28 ���ֽڵ�֡ͷ */
	unsigned int sequence;	/**< ������֡�ڸ�ͨ��(channel)����ţ������Ͷ�����������ϵͳ������ʼ���� */
	unsigned int timestamp;	/**< ��֡�����ϵͳʱ�䣬Ϊtime_t ��׼ʱ�� */
	unsigned int tick;			/**< ��֡�����ϵͳ�ο�ʱ�Ӽ���(��λΪ΢��) SongZhanjunע��������� */
	
#if 1
	unsigned char codec;		
	unsigned char resolution;		/**< �ֱ��� */
	unsigned char frameRate;
	unsigned char frameType;   // 1 = iframe, 3 = p frame , 2 = b frame
#else
	unsigned char format[4];
#endif

};

#ifndef USE_HKINFO
#define USE_HKINFO
#endif

//#undef USE_HKINFO

#endif
