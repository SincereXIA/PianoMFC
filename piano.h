// piano.h : main header file for the PIANO application
//

#if !defined(AFX_PIANO_H__D21AB9CC_8DB6_4AE1_8770_A24EB84A7EBF__INCLUDED_)
#define AFX_PIANO_H__D21AB9CC_8DB6_4AE1_8770_A24EB84A7EBF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPianoApp:
// See piano.cpp for the implementation of this class
//

class CPianoApp : public CWinApp
{
public:
	CPianoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPianoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPianoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PIANO_H__D21AB9CC_8DB6_4AE1_8770_A24EB84A7EBF__INCLUDED_)
