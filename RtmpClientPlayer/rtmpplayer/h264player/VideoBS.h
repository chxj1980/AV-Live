/** $Id: //depot/NVS/v2.1/bsrExplorer/bsrMedia/media/VideoBS.h#7 $ $DateTime: 2009/01/09 18:55:57 $
*  @file VideoBS.h
*  @brief ��Ƶ����
*  @version 1.0.0
*  @since 1.0.0
*  @author dongming<DongM@bstar.com.cn> 
*  @date 2007-07-17    Created it
*/

/************************************************************ 
*  @note
*   Copyright 2005, BeiJing Bluestar Corporation, Limited	
*   ALL RIGHTS RESERVED			
*   Permission is hereby granted to licensees of BeiJing Bluestar, Inc.
*	 products to use or abstract this computer program for the sole purpose
*	 of implementing a product based on BeiJing Bluestar, Inc. products.
*	 No other rights to reproduce, use, or disseminate this computer program,
*	 whether in part or in whole, are granted. BeiJing Bluestar, Inc. 
*	 makes no representation or warranties with respect to the performance of
*	 this computer program, and specifically disclaims any responsibility for 
*	 any damages, special or consequential,connected with the use of this program.
*   For details, see http://www.bstar.com.cn/ 
***********************************************************/

#ifndef _VIDEO_BS_H_
#define _VIDEO_BS_H_
#pragma once

#ifndef USE_D3D
#define USE_D3D
#endif

//#undef USE_D3D

#include <afxmt.h>

#define CIFF_XDIM	352
#define CIFF_YDIM	288

#define ARROW_DIRECT_DOWN 1
#define ARROW_DIRECT_UP   2
#define ARROW_DIRECT_BOTH 3

 const double   PI = 3.1415925;

#ifdef USE_D3D
	#include "D3D/D3D9RenderImpl.h"
#else
	#include <ddraw.h>
#endif

#include <deque>

#include "MediaDefine.h"
#include "SysDef.h"

#include "./bsDecoder/bsDecoder.h"


using namespace std;

#define DECODE_BUFSIZE (1024*576*3/2)

#ifndef POST_SHARP 
#define POST_SHARP
#endif

#undef POST_SHARP

typedef void (CALLBACK *PCBFunGetDecFrameData)(LPDEC_FRAME_S lpFrameData, LPVOID lpUser);
typedef void (CALLBACK *BSDecYUVDataCB)(long nPort, char *pY, char *pU, char *pV, int width, int height, int yPitch, int uPitch, int vPitch, void* pUser);
typedef void (CALLBACK *BSDec17DataCB)(char *pBuf, int iLen, void* pUser);

class CVideoBS
{
public:
  CVideoBS(int iIndex);
  ~CVideoBS(void);
  enum VideoType {VT_NULL, VT_NTSC, VT_PAL, VT_SCEAM};
  enum SurfaceFormat {SF_YUV, SF_RGB};
  enum SurfaceRestorCtrl {RES_NULL, RES_NORMAL, RES_LOST, RES_RESTOR};
  enum DecoderResolution {DECODE_720P , DECODE_1080P};

public:
  // ��ʼ��
  BOOL Init(HWND hWnd, int iDecoder=MDECODE_NULL,DWORD dwFlag=0xf );
  // ����һ֡
  BOOL DisPlay(FrameStruct* pFrame, BOOL bIgnore );
	// �������һ֡�ܽ��������
	BOOL DisPlayLaseFrame();

  // ��ȡ��ǰ��Ƶ�ĳߴ�
  inline void GetFrameSize(DWORD& dwWidth, DWORD& dwHeight);
  // ����֡��ԭʼ��С
  BOOL SetFrameSize(DWORD dwWidth, DWORD dwHeight);
  // ��ȡ��ǰ��Ƶ��֡��
  inline int  GetFrameRate();
  // ���õ�ǰ��Ƶ���Ͻǵ�״̬ͼ��
  void SetStatus(char c, BOOL bFlag);
  // ���õ�ǰ��Ƶ�ı���
  void SetTitle(TitlePos iPos, LPCSTR lpTitle, DWORD dwColor, int iX=0, int iY=0,int nLine = 0);
  // ��������ط����б�����ʾ����
  void PreTextOut(HDC hdc, CString strTitle, int &iWidth, int &iHeigth);
  // ��ͼ
  BOOL Capture(LPCSTR lpPath, DWORD dwWidth=0, DWORD dwHeight=0);
  BOOL CaptureEx(LPCSTR lpPath, DWORD dwWidth=0, DWORD dwHeight=0);
  // ��һ���ڴ�DC����Ϊbmp
  static BOOL SaveBitmaps(LPCSTR lpSavePath, DWORD dwSaveWidth, DWORD dwSaveHeight, HDC hSrcDC, DWORD dwSrcWidth, DWORD dwSrcHeight);
  // ��һ���ڴ汣��Ϊbmp
  static BOOL SaveBitmapsEx(LPCSTR lpSavePath, DWORD dwSaveWidth, DWORD dwSaveHeight, DWORD dwWidth, DWORD dwHeight, PBYTE hSrcBuf, DWORD dwSrcWidth, DWORD dwSrcHeight, DWORD dwSrcStide);
  // ��һ֡
  BOOL DecodeFrame(FrameStruct* pFrame, BYTE* pVideoFrame = NULL);
  // ��ʾһ֡BMP
  BOOL DisPlayBmp(FrameStruct* pFrame);
  // ��ʾģʽ�Ƿ���YUV
  BOOL IsYuvMode()  { return !m_bRGB;}
  // ������Ƶ��ʽ 0.yuv, 1.rgb
  void SetSurfaceFormat(SurfaceFormat format);
  // ��ʾ������Ļ
  void ShowCaption(BOOL bShow);
  // ��ȡ��Ƶ����ʽ����
  inline VideoType GetVideoType();

	//�ص����������
	void SetCBDecFrameFun(PCBFunGetDecFrameData pCBFun, LPVOID pUserData);

  //��ӻ�ȡsurface�����С
  inline void GetSurfaceSize( DWORD &width, DWORD &height ); 

  //ֱ����ʾYUV����
  void RenderYV12( char *pY, char *pU, char *pV, int width, int height, int yPitch, int uPitch, int vPitch ); 

	void SetRealDecoder(int iDecoderId); // ������ʵ��DecoderID
	int GetRealDecoder();                // ��ȡ������DecoderID

	//�ж��Ƿ�ɹ���������Ƶ����
	inline bool VideoIsReady( ) { return m_bDecodeFrame; }
	void SetDelayTime(int delay, DWORD dwTmCur, int iflag);
	void DestroyD3DReneder( );

private:
  //////////////////////////////////////////////////////////////////////////
  // ���벿��

  // ��ʼ��bstar�����
  BOOL InitBsDecoder();
  // �ͷ�bstar�����
  void FreeBsDecoder();
  // ��ʾһ֡
  BOOL DisplayFrame(FrameStruct* pFrame, BOOL bDecode = TRUE, BOOL bIgnore = FALSE );
  // ֡��ͳ��
  void StatisticFrameRate();
  // ���Ŷ����Ƿ�׼������
  BOOL DisplayIsReady();
  // ��ֵ
  void DoInterlace(int interlace);
  // ��ʼ����Ƶ���ϵ�״̬ͼ��

  //Limit����
	void FreeLimitDecoder();
	BOOL InitLimitDecoder();

  //
  static void YUV2RGB(unsigned char *pdata, int stride, int width, int height, unsigned char *pdst);

  //����ͼ��
  void DrawTransBitmap( HDC hdcDest,     
	  int nXOriginDest,   // Ŀ��Xƫ��
	  int nYOriginDest,   // Ŀ��Yƫ��
	  int nWidthDest,     // Ŀ����
	  int nHeightDest,    // Ŀ��߶�
	  HDC hdcSrc,         // ԴDC
	  int nXOriginSrc,    // ԴX���
	  int nYOriginSrc,    // ԴY���
	  int nWidthSrc,      // Դ���
	  int nHeightSrc,     // Դ�߶�
	  UINT crTransparent  // ͸��ɫ,COLORREF����
	  );

#ifdef POST_SHARP
  void __cdecl FilterSharpen_SSE(unsigned __int8 *src, unsigned __int8 *dst, int width, int height, int filterStrength);
#endif

  void WaitDelay(int iDecodeTime);
  int   m_iDelayTime;
  DWORD m_iDwTmCur;
  BOOL  m_bRefresh;
  int      m_iDelayflag;
private:
  BOOL                  m_bExit;

 D3D9RenderImpl *m_pD3DRender;

  int                   m_iIndex;
  HWND                  m_hWnd;      // ��ʾ�Ĵ��ھ��
  RECT                  m_rcSrc;     // ���������Ƶ��ԭʼ����
  RECT                  m_rcDes;     // ��Ҫ��ʾ��Ƶ��Ŀ������
  RECT                  m_rectOldDes;

  void*                 m_hDecode;
  BYTE*                 m_pDecodeBuf;
  BOOL                  m_bDecodeOutBufIsOk;
  BYTE*                 m_pDecodeOutBuf;
  BYTE*                 m_pInterlaceBuf;
  int                   m_iDecodeOutBufSize;
  int                   m_iDecodeOutStide;
  int                   m_iDecodeOutWidth;
  int                   m_iDecodeOutHeight;
  BOOL                  m_bRGB;
  SurfaceFormat         m_iSurfaceFormat;

	PCBFunGetDecFrameData m_pCBFun;          //�ص�����������
	BSDecYUVDataCB        m_pBSDecYUVDataCB; //�ص�limit���yuv����
	BSDec17DataCB         m_pBS17DataCB;     //�ص�17����ǰ����
	LPVOID                m_pUserData;

  CCriticalSection      m_csInit;
  CCriticalSection      m_csInitAI;
  CCriticalSection      m_csDisplay;
  CString               m_sErrMes;
  
  SurfaceRestorCtrl     m_iThreeCtrl; // 3̬�������Ƿ�ָ�����  

 
  // ͼ���������
  BOOL           m_bCutPixel;     // �����Ƿ���
  POINT          m_ptCutLeftTop;
  POINT          m_ptCutRightBottom;

  // ״̬ͳ��
  DWORD            m_dwFrameRate;              // ֡��(F/s)
  DWORD            m_dwFramePlayed;            // �Ѳ���֡��
  static const int TIME_PER_STAT = 1;          // ��Ϣ��ˢ��ʱ��
  static const int SAMPLE_OF_STAT = 30;        // ��Ϣ�Ĳɼ�����
  DWORD            m_dwFramePlayedStatSample[SAMPLE_OF_STAT];   // һ��ͳ��ʱ���ڣ����ŵ�֡��
  int              m_iCurFrameRateStatSample;  // ����֡�ʲɼ�����
  DWORD            m_dwPreFrameRateStatTm;     // ��һ��֡��ͳ��ʱ��
  int              m_iNoDataSeconds;           // ͳ��û�����ݵ�ʱ��


  BOOL	m_bResetDD;
  BOOL  m_bDoDiagnostics;       // ���л����¸���ͷ ����ȡ��
	BOOL  m_bOpenDiagnostics;     //�Ƿ�����Ƶ���
  long m_nOldWidth;
  long m_nOldHeight;

	int  m_iDecoder;
	bsDecFrameInfo  m_dec_frame;

   //���HIS DEINTERLACE
   void *m_pHisDeinterlace;
   //DEINTERLACE_PARA_S  m_hisDeInParam;        //Deinterlace parameters

	 //BASE_PIC_INFO m_tagPicInfo;
	 int m_iRealDecoder; // ԭ��������decoder
	 int m_DecoderResolution; // ��ǰ����ֱ�
	 unsigned char* m_pRgbBuf;
	 int m_rgbSize;

	 bool m_bDecodeFrame;

	 int  m_videoWidth;
	 int  m_videoHeight;
public:
	 CString m_sTitle[MAX_TITLE_POS][MAX_TITLE_LINE];
	 DWORD   m_dwTitleColor[MAX_TITLE_POS];

};

inline void
CVideoBS::GetFrameSize(DWORD& dwWidth, DWORD& dwHeight)
{
  dwWidth  = m_rcSrc.right - m_rcSrc.left;
  dwHeight = m_rcSrc.bottom - m_rcSrc.top;
}

inline int
CVideoBS::GetFrameRate()
{
  return m_dwFrameRate;
}

inline CVideoBS::VideoType
CVideoBS::GetVideoType()
{
  int iHeight = m_rcSrc.bottom - m_rcSrc.top;
  if (iHeight % 120 == 0)
  {
		if( iHeight == 1080 || iHeight == 720 || iHeight == 240 )
		{
			return VT_PAL;
		}

    return VT_NTSC;
  }
  else if (iHeight % 144 == 0)
  {
    return VT_PAL;
  }
  return VT_NULL;
}

inline void 
CVideoBS::GetSurfaceSize( DWORD &width, DWORD &height )
{
  //��ֵ
  width  = m_iDecodeOutWidth;
  height = m_iDecodeOutHeight;
}
#endif
