
// Client_TestDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CClient_TestDlg �Ի���
class CClient_TestDlg : public CDialogEx
{
// ����
public:
	CClient_TestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CLIENT_TEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


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
	afx_msg void OnBnClickedFile();
	afx_msg void OnBnClickedDeny();
	afx_msg void OnBnClickedApp();
private:
	CEdit m_editMultiLine;
public:
	CEdit m_editMultiLine2;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
