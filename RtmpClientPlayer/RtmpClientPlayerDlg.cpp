// RtmpClientPlayerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RtmpClientPlayer.h"
#include "RtmpClientPlayerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CRtmpClientPlayerDlg �Ի���




CRtmpClientPlayerDlg::CRtmpClientPlayerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRtmpClientPlayerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CRtmpClientPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CRtmpClientPlayerDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_START, &CRtmpClientPlayerDlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_PUBLISH, &CRtmpClientPlayerDlg::OnBnClickedButtonPublish)
	ON_BN_CLICKED(IDC_BUTTON_PLAYFILE, &CRtmpClientPlayerDlg::OnBnClickedButtonPlayfile)
	ON_BN_CLICKED(IDC_BUTTON_SELECT, &CRtmpClientPlayerDlg::OnBnClickedButtonSelect)
END_MESSAGE_MAP()


// CRtmpClientPlayerDlg ��Ϣ�������

BOOL CRtmpClientPlayerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	render_ = new H264Render();
	player_ = new RtmpPlayer();
	publish_ = new RtmpPublish();

	CString rtmpUrl = "rtmp://192.168.8.240/myapp/livestream";
	GetDlgItem(IDC_EDIT_RTMP_URL)->SetWindowText(rtmpUrl);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CRtmpClientPlayerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CRtmpClientPlayerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}


//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CRtmpClientPlayerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRtmpClientPlayerDlg::OnBnClickedButtonStart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString url;
	GetDlgItem(IDC_EDIT_RTMP_URL)->GetWindowText(url);
	CWnd* pWnd = GetDlgItem(IDC_STATIC_VIDEO);
	if (player_ != NULL && pWnd != NULL)
	{
		player_->init(pWnd->m_hWnd);
		player_->setupRtmp((LPCTSTR)url);
	}

}


void CRtmpClientPlayerDlg::OnBnClickedButtonPublish()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString url;
	GetDlgItem(IDC_EDIT_RTMP_URL)->GetWindowText(url);
	CString file;
	GetDlgItem(IDC_EDIT_FILEPATH)->GetWindowText(file);
	if (publish_ != NULL)
	{
		publish_->publishH264((LPCTSTR)url, (LPCTSTR)file);
	}
}


void CRtmpClientPlayerDlg::OnBnClickedButtonPlayfile()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CWnd* pWnd = GetDlgItem(IDC_STATIC_VIDEO);
	CString file;
	GetDlgItem(IDC_EDIT_FILEPATH)->GetWindowText(file);
	if (render_ != NULL && pWnd != NULL)
	{
		render_->init(pWnd->m_hWnd);
		render_->renderFile((LPCTSTR)file);
	}
}


void CRtmpClientPlayerDlg::OnBnClickedButtonSelect()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString filePath;
	CFileDialog dlg(TRUE, "Bsr", NULL, 0,
		"Bmpeg Files (*.h264)|*.bsr|All Files (*.*)|*.*||", AfxGetMainWnd());
	//dlg.m_ofn.lpstrInitialDir = gSysParamerter.GetVideoPath();
	if (dlg.DoModal() == IDOK)
	{
		filePath = dlg.GetPathName();
	}
	else
	{
		return ;
	}

	GetDlgItem(IDC_EDIT_FILEPATH)->SetWindowText(filePath);
}
