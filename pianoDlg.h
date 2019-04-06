// pianoDlg.h : header file
//

#if !defined(AFX_PIANODLG_H__43EB1FC5_23B2_45CD_BCD2_A5A485DFF59D__INCLUDED_)
#define AFX_PIANODLG_H__43EB1FC5_23B2_45CD_BCD2_A5A485DFF59D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPianoDlg dialog

class CPianoDlg : public CDialog
{
// Construction
public:
	BOOL isA2Z;
	CPianoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPianoDlg)
	enum { IDD = IDD_PIANO_DIALOG };
	CStatic	m_NKeyPic;
	CStatic	m_MKeyPic;
	CStatic	m_CKeyPic;
	CStatic	m_BKeyPic;
	CStatic	m_VKeyPic;
	CStatic	m_XKeyPic;
	CStatic	m_ZKeyPic;
	CStatic	m_HKeyPic;
	CStatic	m_FKeyPic;
	CStatic	m_DKeyPic;
	CStatic	m_JKeyPic;
	CStatic	m_GKeyPic;
	CStatic	m_SKeyPic;
	CStatic	m_AKeyPic;
	CStatic	m_YKeyPic;
	CStatic	m_UKeyPic;
	CStatic	m_RKeyPic;
	CStatic	m_TKeyPic;
	CStatic	m_WKeyPic;
	CStatic	m_EKeyPic;
	CStatic	m_QKeyPic;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPianoDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

	void PressKey(char key);
	void RelaseKey(char key);

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPianoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnA2ZTrue();
	afx_msg void OnA2ZFalse();
	afx_msg void OnSoundLocalTrue();
	afx_msg void OnSoundLocalFalse();
	afx_msg void OnBeat1();
	afx_msg void OnBeat12();
	afx_msg void OnBeat14();
	afx_msg void OnBeat18();
	afx_msg void OnRhythmC();
	afx_msg void OnCRhythm();
	afx_msg void OnDRhythm();
	afx_msg void OnQuit();
	afx_msg void OnHelp();
	afx_msg void OnGKey();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PIANODLG_H__43EB1FC5_23B2_45CD_BCD2_A5A485DFF59D__INCLUDED_)
