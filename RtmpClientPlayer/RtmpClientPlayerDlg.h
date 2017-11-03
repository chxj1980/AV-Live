// RtmpClientPlayerDlg.h : ͷ�ļ�
//

#pragma once

#include "H264Render.h"
#include "RtmpPlayer.h"
#include "RtmpPublish.h"


// CRtmpClientPlayerDlg �Ի���
class CRtmpClientPlayerDlg : public CDialog
{
// ����
public:
	CRtmpClientPlayerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_RTMPCLIENTPLAYER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

public:
	H264Render* render_;
	RtmpPlayer* player_;
	RtmpPublish* publish_;

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonPublish();
	afx_msg void OnBnClickedButtonPlayfile();
	afx_msg void OnBnClickedButtonSelect();
};
