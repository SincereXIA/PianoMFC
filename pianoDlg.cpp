// pianoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "piano.h"
#include "pianoDlg.h"
#include "HWControl.h"
#include "ReademeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPianoDlg dialog

CPianoDlg::CPianoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPianoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPianoDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//init8254();
	

}

void CPianoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPianoDlg)
	DDX_Control(pDX, IDC_NKey, m_NKeyPic);
	DDX_Control(pDX, IDC_MKey, m_MKeyPic);
	DDX_Control(pDX, IDC_CKey, m_CKeyPic);
	DDX_Control(pDX, IDC_BKey, m_BKeyPic);
	DDX_Control(pDX, IDC_VKey, m_VKeyPic);
	DDX_Control(pDX, IDC_XKey, m_XKeyPic);
	DDX_Control(pDX, IDC_ZKey, m_ZKeyPic);
	DDX_Control(pDX, IDC_HKey, m_HKeyPic);
	DDX_Control(pDX, IDC_FKey, m_FKeyPic);
	DDX_Control(pDX, IDC_DKey, m_DKeyPic);
	DDX_Control(pDX, IDC_JKey, m_JKeyPic);
	DDX_Control(pDX, IDC_GKey, m_GKeyPic);
	DDX_Control(pDX, IDC_SKey, m_SKeyPic);
	DDX_Control(pDX, IDC_AKey, m_AKeyPic);
	DDX_Control(pDX, IDC_YKey, m_YKeyPic);
	DDX_Control(pDX, IDC_UKey, m_UKeyPic);
	DDX_Control(pDX, IDC_RKey, m_RKeyPic);
	DDX_Control(pDX, IDC_TKey, m_TKeyPic);
	DDX_Control(pDX, IDC_WKey, m_WKeyPic);
	DDX_Control(pDX, IDC_EKey, m_EKeyPic);
	DDX_Control(pDX, IDC_QKey, m_QKeyPic);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPianoDlg, CDialog)
	//{{AFX_MSG_MAP(CPianoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_DESTROY()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_A2ZTrue, OnA2ZTrue)
	ON_BN_CLICKED(IDC_A2ZFalse, OnA2ZFalse)
	ON_BN_CLICKED(IDC_SoundLocalTrue, OnSoundLocalTrue)
	ON_BN_CLICKED(IDC_SoundLocalFalse, OnSoundLocalFalse)
	ON_BN_CLICKED(IDC_Beat1, OnBeat1)
	ON_BN_CLICKED(IDC_Beat1_2, OnBeat12)
	ON_BN_CLICKED(IDC_Beat1_4, OnBeat14)
	ON_BN_CLICKED(IDC_Beat1_8, OnBeat18)
	ON_BN_CLICKED(IDC_CRhythm, OnCRhythm)
	ON_BN_CLICKED(IDC_DRhythm, OnDRhythm)
	ON_BN_CLICKED(ID_Quit, OnQuit)
	ON_BN_CLICKED(ID_HELP, OnHelp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPianoDlg message handlers

BOOL CPianoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	isA2Z = false;
	isLocalSound = false;
	((CButton*)GetDlgItem(IDC_SoundLocalFalse))->SetCheck(BST_CHECKED);

	if (init8254()){
		GetDlgItem(IDC_INIT_INFO)->SetWindowText(_T("硬件设备连接正常，初始化成功"));
	}else{
		GetDlgItem(IDC_INIT_INFO)->SetWindowText(_T("硬件初始化失败，请检查设备驱动是否安装！"));
		isLocalSound = true;
		((CButton*)GetDlgItem(IDC_SoundLocalFalse))->SetCheck(BST_UNCHECKED);
		((CButton*)GetDlgItem(IDC_SoundLocalTrue))->SetCheck(BST_CHECKED);
	}

	((CButton*)GetDlgItem(IDC_A2ZFalse))->SetCheck(BST_CHECKED);
	((CButton*)GetDlgItem(IDC_CRhythm))->SetCheck(BST_CHECKED);
	((CButton*)GetDlgItem(IDC_Beat1_4))->SetCheck(BST_CHECKED);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPianoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPianoDlg::OnDestroy()
{
	WinHelp(0L, HELP_QUIT);
	CDialog::OnDestroy();
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPianoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPianoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPianoDlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

BOOL CPianoDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message == WM_KEYDOWN){ // 按键按下
		CString str;
		str.Format(_T("%c"),(char)pMsg->wParam);
	//	AfxMessageBox(_T("PressDown  "+str));
		GetDlgItem(IDC_KVAL)->SetWindowText(str);

		
	//单独按键处理
		CPianoDlg::PressKey(pMsg->wParam);

		
	}
	else if(pMsg->message == WM_KEYUP){
		
		CPianoDlg::RelaseKey(pMsg->wParam);
	}
	
	//return CDialog::PreTranslateMessage(pMsg);
	return false;
}

void CPianoDlg::PressKey(char key) 
{

	CBitmap bitmap;
	HBITMAP hBmp;
	if(!isA2Z){
		switch(key){
		case 'Q':
			bitmap.LoadBitmap(IDB_press1);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_QKeyPic.SetBitmap(hBmp);
			play_one_tone(1,2);
			break;
		case 'W':
			bitmap.LoadBitmap(IDB_press2);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_WKeyPic.SetBitmap(hBmp);
			play_one_tone(2,2);
			break;
		case 'E':
			bitmap.LoadBitmap(IDB_press3);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_EKeyPic.SetBitmap(hBmp);
			play_one_tone(3,2);
			break;
		case 'R':
			bitmap.LoadBitmap(IDB_press4);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_RKeyPic.SetBitmap(hBmp);
			play_one_tone(4,2);
			break;
		case 'T':
			bitmap.LoadBitmap(IDB_press5);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_TKeyPic.SetBitmap(hBmp);
			play_one_tone(5,2);
			break;
		case 'Y':
			bitmap.LoadBitmap(IDB_press6);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_YKeyPic.SetBitmap(hBmp);
			play_one_tone(6,2);
			break;
		case 'U':
			bitmap.LoadBitmap(IDB_press7);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_UKeyPic.SetBitmap(hBmp);
			play_one_tone(7,2);
			break;
		case 'A':
			bitmap.LoadBitmap(IDB_press1);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_AKeyPic.SetBitmap(hBmp);
			play_one_tone(1,1);
			break;
		case 'S':
			bitmap.LoadBitmap(IDB_press2);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_SKeyPic.SetBitmap(hBmp);
			play_one_tone(2,1);
			break;
		case 'D':
			bitmap.LoadBitmap(IDB_press3);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_DKeyPic.SetBitmap(hBmp);
			play_one_tone(3,1);
			break;
		case 'F':
			bitmap.LoadBitmap(IDB_press4);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_FKeyPic.SetBitmap(hBmp);
			play_one_tone(4,1);
			break;
		case 'G':
			bitmap.LoadBitmap(IDB_press5);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_GKeyPic.SetBitmap(hBmp);
			play_one_tone(5,1);
			break;
		case 'H':
			bitmap.LoadBitmap(IDB_press6);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_HKeyPic.SetBitmap(hBmp);
			play_one_tone(6,1);
			break;
		case 'J':
			bitmap.LoadBitmap(IDB_press7);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_JKeyPic.SetBitmap(hBmp);
			play_one_tone(7,1);
			break;
		case 'Z':
			bitmap.LoadBitmap(IDB_press1);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_ZKeyPic.SetBitmap(hBmp);
			play_one_tone(1,0.5);
			break;
		case 'X':
			bitmap.LoadBitmap(IDB_press2);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_XKeyPic.SetBitmap(hBmp);
			play_one_tone(2,0.5);
			break;
		case 'C':
			bitmap.LoadBitmap(IDB_press3);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_CKeyPic.SetBitmap(hBmp);
			play_one_tone(3,0.5);
			break;
		case 'V':
			bitmap.LoadBitmap(IDB_press4);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_VKeyPic.SetBitmap(hBmp);
			play_one_tone(4,0.5);
			break;
		case 'B':
			bitmap.LoadBitmap(IDB_press5);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_BKeyPic.SetBitmap(hBmp);
			play_one_tone(5,0.5);
			break;
		case 'N':
			bitmap.LoadBitmap(IDB_press6);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_NKeyPic.SetBitmap(hBmp);
			play_one_tone(6,0.5);
			break;
		case 'M':
			bitmap.LoadBitmap(IDB_press7);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_MKeyPic.SetBitmap(hBmp);
			play_one_tone(7,0.5);
			break;
		}

	}else{
		switch(key){
		case 'A':
			bitmap.LoadBitmap(IDB_press1);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_QKeyPic.SetBitmap(hBmp);
			play_one_tone(1,0.5);
			break;
		case 'B':
			bitmap.LoadBitmap(IDB_press2);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_WKeyPic.SetBitmap(hBmp);
			play_one_tone(2,0.5);
			break;
		case 'C':
			bitmap.LoadBitmap(IDB_press3);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_EKeyPic.SetBitmap(hBmp);
			play_one_tone(3,0.5);
			break;
		case 'D':
			bitmap.LoadBitmap(IDB_press4);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_RKeyPic.SetBitmap(hBmp);
			play_one_tone(4,0.5);
			break;
		case 'E':
			bitmap.LoadBitmap(IDB_press5);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_TKeyPic.SetBitmap(hBmp);
			play_one_tone(5,0.5);
			break;
		case 'F':
			bitmap.LoadBitmap(IDB_press6);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_YKeyPic.SetBitmap(hBmp);
			play_one_tone(6,0.5);
			break;
		case 'G':
			bitmap.LoadBitmap(IDB_press7);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_UKeyPic.SetBitmap(hBmp);
			play_one_tone(7,0.5);
			break;
		case 'H':
			bitmap.LoadBitmap(IDB_press1);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_AKeyPic.SetBitmap(hBmp);
			play_one_tone(1,1);
			break;
		case 'I':
			bitmap.LoadBitmap(IDB_press2);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_SKeyPic.SetBitmap(hBmp);
			play_one_tone(2,1);
			break;
		case 'J':
			bitmap.LoadBitmap(IDB_press3);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_DKeyPic.SetBitmap(hBmp);
			play_one_tone(3,1);
			break;
		case 'K':
			bitmap.LoadBitmap(IDB_press4);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_FKeyPic.SetBitmap(hBmp);
			play_one_tone(4,1);
			break;
		case 'L':
			bitmap.LoadBitmap(IDB_press5);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_GKeyPic.SetBitmap(hBmp);
			play_one_tone(5,1);
			break;
		case 'M':
			bitmap.LoadBitmap(IDB_press6);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_HKeyPic.SetBitmap(hBmp);
			play_one_tone(6,1);
			break;
		case 'N':
			bitmap.LoadBitmap(IDB_press7);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_JKeyPic.SetBitmap(hBmp);
			play_one_tone(7,1);
			break;
		case 'O':
			bitmap.LoadBitmap(IDB_press1);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_ZKeyPic.SetBitmap(hBmp);
			play_one_tone(1,2);
			break;
		case 'P':
			bitmap.LoadBitmap(IDB_press2);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_XKeyPic.SetBitmap(hBmp);
			play_one_tone(2,2);
			break;
		case 'Q':
			bitmap.LoadBitmap(IDB_press3);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_CKeyPic.SetBitmap(hBmp);
			play_one_tone(3,2);
			break;
		case 'R':
			bitmap.LoadBitmap(IDB_press4);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_VKeyPic.SetBitmap(hBmp);
			play_one_tone(4,2);
			break;
		case 'S':
			bitmap.LoadBitmap(IDB_press5);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_BKeyPic.SetBitmap(hBmp);
			play_one_tone(5,2);
			break;
		case 'T':
			bitmap.LoadBitmap(IDB_press6);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_NKeyPic.SetBitmap(hBmp);
			play_one_tone(6,2);
			break;
		case 'U':
			bitmap.LoadBitmap(IDB_press7);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_MKeyPic.SetBitmap(hBmp);
			play_one_tone(7,2);
			break;
		case 'V':
			bitmap.LoadBitmap(IDB_press3);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			//m_CKeyPic.SetBitmap(hBmp);
			play_one_tone(8,2);
			break;
		case 'W':
			bitmap.LoadBitmap(IDB_press4);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			//m_VKeyPic.SetBitmap(hBmp);
			play_one_tone(9,2);
			break;
		case 'X':
			bitmap.LoadBitmap(IDB_press5);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			//m_BKeyPic.SetBitmap(hBmp);
			play_one_tone(10,2);
			break;
		case 'Y':
			bitmap.LoadBitmap(IDB_press6);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			//m_NKeyPic.SetBitmap(hBmp);
			play_one_tone(11,2);
			break;
		case 'Z':
			bitmap.LoadBitmap(IDB_press7);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			//m_MKeyPic.SetBitmap(hBmp);
			play_one_tone(12,2);
			break;
		}

	}


}
void CPianoDlg::RelaseKey(char key) 
{
	CBitmap bitmap;
	HBITMAP hBmp;
		//单独按键处理
	if(!isA2Z){
		switch(key){
		case 'Q':
			bitmap.LoadBitmap(IDB_unpress1);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_QKeyPic.SetBitmap(hBmp);
			break;
		case 'W':
			bitmap.LoadBitmap(IDB_unpress2);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_WKeyPic.SetBitmap(hBmp);
			break;
		case 'E':
			bitmap.LoadBitmap(IDB_unpress3);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_EKeyPic.SetBitmap(hBmp);
			break;
		case 'R':
			bitmap.LoadBitmap(IDB_unpress4);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_RKeyPic.SetBitmap(hBmp);
			break;
		case 'T':
			bitmap.LoadBitmap(IDB_unpress5);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_TKeyPic.SetBitmap(hBmp);
			break;
		case 'Y':
			bitmap.LoadBitmap(IDB_unpress6);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_YKeyPic.SetBitmap(hBmp);
			break;
		case 'U':
			bitmap.LoadBitmap(IDB_unpress7);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_UKeyPic.SetBitmap(hBmp);
			break;
		case 'A':
			bitmap.LoadBitmap(IDB_unpress1);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_AKeyPic.SetBitmap(hBmp);
			break;
		case 'S':
			bitmap.LoadBitmap(IDB_unpress2);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_SKeyPic.SetBitmap(hBmp);
			break;
		case 'D':
			bitmap.LoadBitmap(IDB_unpress3);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_DKeyPic.SetBitmap(hBmp);
			break;
		case 'F':
			bitmap.LoadBitmap(IDB_unpress4);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_FKeyPic.SetBitmap(hBmp);
			break;
		case 'G':
			bitmap.LoadBitmap(IDB_unpress5);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_GKeyPic.SetBitmap(hBmp);
			break;
		case 'H':
			bitmap.LoadBitmap(IDB_unpress6);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_HKeyPic.SetBitmap(hBmp);
			break;
		case 'J':
			bitmap.LoadBitmap(IDB_unpress7);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_JKeyPic.SetBitmap(hBmp);
			break;
		case 'Z':
			bitmap.LoadBitmap(IDB_unpress1);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_ZKeyPic.SetBitmap(hBmp);
			break;
		case 'X':
			bitmap.LoadBitmap(IDB_unpress2);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_XKeyPic.SetBitmap(hBmp);
			break;
		case 'C':
			bitmap.LoadBitmap(IDB_unpress3);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_CKeyPic.SetBitmap(hBmp);
			break;
		case 'V':
			bitmap.LoadBitmap(IDB_unpress4);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_VKeyPic.SetBitmap(hBmp);
			break;
		case 'B':
			bitmap.LoadBitmap(IDB_unpress5);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_BKeyPic.SetBitmap(hBmp);
			break;
		case 'N':
			bitmap.LoadBitmap(IDB_unpress6);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_NKeyPic.SetBitmap(hBmp);
			break;
		case 'M':
			bitmap.LoadBitmap(IDB_unpress7);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_MKeyPic.SetBitmap(hBmp);
			break;
		}
	}else{
		switch(key){
		case 'A':
			bitmap.LoadBitmap(IDB_unpress1);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_QKeyPic.SetBitmap(hBmp);
			break;
		case 'B':
			bitmap.LoadBitmap(IDB_unpress2);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_WKeyPic.SetBitmap(hBmp);
			break;
		case 'C':
			bitmap.LoadBitmap(IDB_unpress3);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_EKeyPic.SetBitmap(hBmp);
			break;
		case 'D':
			bitmap.LoadBitmap(IDB_unpress4);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_RKeyPic.SetBitmap(hBmp);
			break;
		case 'E':
			bitmap.LoadBitmap(IDB_unpress5);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_TKeyPic.SetBitmap(hBmp);
			break;
		case 'F':
			bitmap.LoadBitmap(IDB_unpress6);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_YKeyPic.SetBitmap(hBmp);
			break;
		case 'G':
			bitmap.LoadBitmap(IDB_unpress7);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_UKeyPic.SetBitmap(hBmp);
			break;
		case 'H':
			bitmap.LoadBitmap(IDB_unpress1);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_AKeyPic.SetBitmap(hBmp);
			break;
		case 'I':
			bitmap.LoadBitmap(IDB_unpress2);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_SKeyPic.SetBitmap(hBmp);
			break;
		case 'J':
			bitmap.LoadBitmap(IDB_unpress3);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_DKeyPic.SetBitmap(hBmp);
			break;
		case 'K':
			bitmap.LoadBitmap(IDB_unpress4);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_FKeyPic.SetBitmap(hBmp);
			break;
		case 'L':
			bitmap.LoadBitmap(IDB_unpress5);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_GKeyPic.SetBitmap(hBmp);
			break;
		case 'M':
			bitmap.LoadBitmap(IDB_unpress6);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_HKeyPic.SetBitmap(hBmp);
			break;
		case 'N':
			bitmap.LoadBitmap(IDB_unpress7);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_JKeyPic.SetBitmap(hBmp);
			break;
		case 'O':
			bitmap.LoadBitmap(IDB_unpress1);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_ZKeyPic.SetBitmap(hBmp);
			break;
		case 'P':
			bitmap.LoadBitmap(IDB_unpress2);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_XKeyPic.SetBitmap(hBmp);
			break;
		case 'Q':
			bitmap.LoadBitmap(IDB_unpress3);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_CKeyPic.SetBitmap(hBmp);
			break;
		case 'R':
			bitmap.LoadBitmap(IDB_unpress4);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_VKeyPic.SetBitmap(hBmp);
			break;
		case 'S':
			bitmap.LoadBitmap(IDB_unpress5);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_BKeyPic.SetBitmap(hBmp);
			break;
		case 'T':
			bitmap.LoadBitmap(IDB_unpress6);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_NKeyPic.SetBitmap(hBmp);
			break;
		case 'U':
			bitmap.LoadBitmap(IDB_unpress7);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_MKeyPic.SetBitmap(hBmp);
			break;
		}
	}
}


void CPianoDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	play_music(1);
}

void CPianoDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	play_music(2);
	
}

void CPianoDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	play_one_toneL('a');
	
}

void CPianoDlg::OnA2ZTrue() 
{
	isA2Z = true;
}

void CPianoDlg::OnA2ZFalse() 
{
	isA2Z = false;	
}

void CPianoDlg::OnSoundLocalTrue() 
{
	isLocalSound = true;
	
}

void CPianoDlg::OnSoundLocalFalse() 
{
	isLocalSound = false;
	
}

void CPianoDlg::OnBeat1() 
{
	setBeat(500);
}

void CPianoDlg::OnBeat12() 
{
	setBeat(250);
}

void CPianoDlg::OnBeat14() 
{
	setBeat(125);
}

void CPianoDlg::OnBeat18() 
{
	setBeat(62.5);	
}


void CPianoDlg::OnCRhythm() 
{
	setRhythm(true);
}

void CPianoDlg::OnDRhythm() 
{
	setRhythm(false);
}

void CPianoDlg::OnQuit() 
{
	this->SendMessage(WM_CLOSE);
}

void CPianoDlg::OnHelp() 
{
	CReademeDlg dlg;
	dlg.DoModal();
}
