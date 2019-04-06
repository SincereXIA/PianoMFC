#if !defined(AFX_READEMEDLG_H__6F7C5F3F_0956_459C_8BD3_C860B277E6A9__INCLUDED_)
#define AFX_READEMEDLG_H__6F7C5F3F_0956_459C_8BD3_C860B277E6A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReademeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CReademeDlg dialog

class CReademeDlg : public CDialog
{
// Construction
public:
	CReademeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CReademeDlg)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReademeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CReademeDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_READEMEDLG_H__6F7C5F3F_0956_459C_8BD3_C860B277E6A9__INCLUDED_)
