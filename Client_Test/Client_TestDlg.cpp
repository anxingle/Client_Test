
// Client_TestDlg.cpp : ʵ���ļ�
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

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
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

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CClient_TestDlg �Ի���




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


// CClient_TestDlg ��Ϣ�������

BOOL CClient_TestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//m_editMultiLine.SetWindowTextW(_T("Love is Good!"));
	//m_editMultiLine.SetWindowTextW(_T("God is My only Lord"));
	//m_editMultiLine.SetSel(3,5);
	//m_editMultiLine.ReplaceSel(_T("What is That?"));
	SetTimer(1, 1000, NULL);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CClient_TestDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
	/*
	 if( (_access( "exist.txt", 0 )) != -1 )
	 {
		 AfxMessageBox(_T("���ڿͻ�����ע��...."));
	 }
	 */
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CClient_TestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CClient_TestDlg::OnBnClickedFile()
{
	if(exist == true)//û���ļ��Ļ�
	{
		AfxMessageBox(_T("����û�����룡"));
	}
	else
	{
	// ���ǵ�һ���ؼ�Ҫ��ʾ��ͼƬ
	  CStatic* pWnd = (CStatic*)GetDlgItem(IDC_PIC); 
  //���þ�̬�ؼ����ڷ��Ϊλͼ������ʾ
  pWnd->ModifyStyle(0xf,SS_BITMAP|SS_CENTERIMAGE);
  //��ʾͼƬ
  pWnd->SetBitmap((HBITMAP)::LoadImage(NULL,
    _T("D:\\6.bmp"),  //��Դ�Ż򱾵��ļ���
    IMAGE_BITMAP,       //װ��λͼ IMAGE_CURSOR��� IMAGE_ICONͼ��
        0,                  //��� 0ΪĬ�ϴ�С
        0,                  //�߶� ����Ϊ��λ
        LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE));
   // ���ǵڶ����ؼ�Ҫ��ʾ��ͼƬ
    CStatic* pWnd_2 = (CStatic*)GetDlgItem(IDC_PIC2); 
  //���þ�̬�ؼ����ڷ��Ϊλͼ������ʾ
  pWnd_2->ModifyStyle(0xf,SS_BITMAP|SS_CENTERIMAGE);
  //��ʾͼƬ
  pWnd_2->SetBitmap((HBITMAP)::LoadImage(NULL,
    _T("D:\\7.bmp"),  //��Դ�Ż򱾵��ļ���
    IMAGE_BITMAP,       //װ��λͼ IMAGE_CURSOR��� IMAGE_ICONͼ��
        0,                  //��� 0ΪĬ�ϴ�С
        0,                  //�߶� ����Ϊ��λ
        LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE));
  /*  ��ʾ���ƶ�*/
  CString buff;
  FILE *fp1=fopen("identity_file\\distance.txt","r");
  float distance0;
  fscanf(fp1,"%f",&distance0);
  fclose(fp1);
  //float a=3.45;
  buff.Format(L"%f",distance0);
  m_editMultiLine.SetWindowTextW(buff);
    /*  ��ʾ���֤*/
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
	AfxMessageBox(_T("�ܾ���ע�����룡"));

} 



void CClient_TestDlg::OnBnClickedApp()
{
	FILE *fp2=fopen("identity_file\\accept.txt","w");				
	int accept1=1;
    fprintf(fp2,"%d",accept1);
	fclose(fp2);
	AfxMessageBox(_T("ͬ����ע�����룡"));
}


void CClient_TestDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//while((_access("a.txt",0)) == -1 );
	if((_access("a.txt",0)) != -1 && exist == true)
	{
		AfxMessageBox(_T("���ڴ��ļ�"));
		exist = false;
	}
	CDialogEx::OnTimer(nIDEvent);
}
