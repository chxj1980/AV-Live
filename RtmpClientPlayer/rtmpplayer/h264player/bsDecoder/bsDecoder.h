// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� BSDECODER_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// BSDECODER_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef BSDECODER_EXPORTS
#define BSDECODER_API __declspec(dllexport)
#else
#define BSDECODER_API __declspec(dllimport)
#endif


struct bsDecFrameInfo
{
	unsigned char* pY;                 //Y plane base address of the picture
	unsigned char* pU;                 //U plane base address of the picture
	unsigned char* pV;                 //V plane base address of the picture
	unsigned int   uWidth;               //The width of output picture in pixel
	unsigned int   uHeight;              //The height of output picture in pixel
	unsigned int   uYStride;             //Luma plane stride in pixel
	unsigned int   uUVStride;            //Chroma plane stride in pixel
	unsigned int   uCroppingLeftOffset;  //Crop information in pixel
	unsigned int   uCroppingRightOffset; //
	unsigned int   uCroppingTopOffset;   //
	unsigned int   uCroppingBottomOffset;//
	unsigned int   uPicFlag;             //0: Frame; 1: Top filed; 2: Bottom field  
	unsigned int   bError;               //0: picture is correct; 1: picture is corrupted
	unsigned int   bIntra;               //0: intra picture; 1:inter picture
	unsigned int   uPictureID;           //The sequence ID of this output picture decoded
	unsigned int   uReserved;            //Reserved for future
	void           *pUserData;           //Pointer to the first userdata
};

//����������

BSDECODER_API HANDLE bsDecCreate( );

/*
	return value

	-1 = λ��ʼ��
	0  = OK
    1  = ��Ҫ��������
*/
//����
BSDECODER_API int    bsDecFrame( HANDLE hDec, char *pFrame, int len, unsigned char encType, bsDecFrameInfo *pOutInfo );

//���ٽ�����
BSDECODER_API void   bsDecDestroy( HANDLE hDec );