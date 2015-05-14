
// Client_TestDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CClient_TestDlg 对话框
class CClient_TestDlg : public CDialogEx
{
// 构造
public:
	CClient_TestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CLIENT_TEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
