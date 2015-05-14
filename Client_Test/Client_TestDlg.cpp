
// Client_TestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Client_Test.h"
#include "Client_TestDlg.h"
#include "afxdialogex.h"
#include "io.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


bool exist=true;
float distance[5];

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CClient_TestDlg 对话框




CClient_TestDlg::CClient_TestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CClient_TestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClient_TestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_editMultiLine);
	DDX_Control(pDX, IDC_EDIT2, m_editMultiLine2);
}

BEGIN_MESSAGE_MAP(CClient_TestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_FILE, &CClient_TestDlg::OnBnClickedFile)
	ON_BN_CLICKED(IDC_DENY, &CClient_TestDlg::OnBnClickedDeny)
	ON_BN_CLICKED(IDC_APP, &CClient_TestDlg::OnBnClickedApp)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CClient_TestDlg 消息处理程序

BOOL CClient_TestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//m_editMultiLine.SetWindowTextW(_T("Love is Good!"));
	//m_editMultiLine.SetWindowTextW(_T("God is My only Lord"));
	//m_editMultiLine.SetSel(3,5);
	//m_editMultiLine.ReplaceSel(_T("What is That?"));
	SetTimer(1, 1000, NULL);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CClient_TestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CClient_TestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
	/*
	 if( (_access( "exist.txt", 0 )) != -1 )
	 {
		 AfxMessageBox(_T("存在客户申请注册...."));
	 }
	 */
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CClient_TestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CClient_TestDlg::OnBnClickedFile()
{
	if(exist == true)//没有文件的话
	{
		AfxMessageBox(_T("现在没有申请！"));
	}
	else
	{
	// 这是第一个控件要显示的图片
	  CStatic* pWnd = (CStatic*)GetDlgItem(IDC_PIC); 
  //设置静态控件窗口风格为位图居中显示
  pWnd->ModifyStyle(0xf,SS_BITMAP|SS_CENTERIMAGE);
  //显示图片
  pWnd->SetBitmap((HBITMAP)::LoadImage(NULL,
    _T("D:\\6.bmp"),  //资源号或本地文件名
    IMAGE_BITMAP,       //装载位图 IMAGE_CURSOR光标 IMAGE_ICON图标
        0,                  //宽度 0为默认大小
        0,                  //高度 像素为单位
        LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE));
   // 这是第二个控件要显示的图片
    CStatic* pWnd_2 = (CStatic*)GetDlgItem(IDC_PIC2); 
  //设置静态控件窗口风格为位图居中显示
  pWnd_2->ModifyStyle(0xf,SS_BITMAP|SS_CENTERIMAGE);
  //显示图片
  pWnd_2->SetBitmap((HBITMAP)::LoadImage(NULL,
    _T("D:\\7.bmp"),  //资源号或本地文件名
    IMAGE_BITMAP,       //装载位图 IMAGE_CURSOR光标 IMAGE_ICON图标
        0,                  //宽度 0为默认大小
        0,                  //高度 像素为单位
        LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE));
  /*  显示相似度*/
  CString buff;
  FILE *fp1=fopen("identity_file\\distance.txt","r");
  float distance0;
  fscanf(fp1,"%f",&distance0);
  fclose(fp1);
  //float a=3.45;
  buff.Format(L"%f",distance0);
  m_editMultiLine.SetWindowTextW(buff);
    /*  显示身份证*/
  CString buff_2;
  FILE *fp2=fopen("identity_file\\id.txt","r");
  char idNum[20];
  fscanf(fp2,"%s",idNum);
  fclose(fp2);
  //float a=3.45;GetSafeWnd(),
  //buff_2.Format("%s",idNum);
  buff_2 = idNum;
  m_editMultiLine2.SetWindowText(buff_2);
	}
}


void CClient_TestDlg::OnBnClickedDeny()
{
	FILE *fp1=fopen("identity_file\\accept.txt","w");				
	int accept=0;
    fprintf(fp1,"%d",accept);
	fclose(fp1);
	AfxMessageBox(_T("拒绝其注册申请！"));

} 



void CClient_TestDlg::OnBnClickedApp()
{
	FILE *fp2=fopen("identity_file\\accept.txt","w");				
	int accept1=1;
    fprintf(fp2,"%d",accept1);
	fclose(fp2);
	AfxMessageBox(_T("同意其注册申请！"));
}


void CClient_TestDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//while((_access("a.txt",0)) == -1 );
	if((_access("a.txt",0)) != -1 && exist == true)
	{
		AfxMessageBox(_T("存在此文件"));
		exist = false;
	}
	CDialogEx::OnTimer(nIDEvent);
}
