// ReademeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "piano.h"
#include "ReademeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReademeDlg dialog


CReademeDlg::CReademeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReademeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReademeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CReademeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReademeDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReademeDlg, CDialog)
	//{{AFX_MSG_MAP(CReademeDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReademeDlg message handlers
