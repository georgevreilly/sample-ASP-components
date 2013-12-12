// AspTestDlg.h : header file
//

#if !defined(AFX_ASPTESTDLG_H__DFBE270B_304A_11D1_8AFA_00C0F00910F9__INCLUDED_)
#define AFX_ASPTESTDLG_H__DFBE270B_304A_11D1_8AFA_00C0F00910F9__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "WorkThread.h"

/////////////////////////////////////////////////////////////////////////////
// CAspTestDlg dialog

class CAspTestDlg : public CDialog, public CWorkStatus
{
// Construction
public:
	CAspTestDlg(CWnd* pParent = NULL);	// standard constructor
	~CAspTestDlg();

// Dialog Data
	//{{AFX_DATA(CAspTestDlg)
	enum { IDD = IDD_ASPTEST_DIALOG };
	CButton	m_btnStop;
	CButton	m_btnStart;
	CComboBox	m_cmbxComponent;
	BOOL	m_bInfinite;
	UINT	m_uNumThreads;
	UINT	m_uNumIterations;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAspTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// CWorkStatus interface
	virtual void	Done();

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAspTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();
	afx_msg void OnInfinite();
	afx_msg void OnStop();
	afx_msg LRESULT OnThreadsDone( WPARAM, LPARAM );
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void	InitComponentList();
	void	WaitForWorkThreads();
	void	StartWorkThreads();
	void	StopWorkThreads();

	long					m_lNumThreadsRunning;
	HANDLE					m_hevtThreadsDone;
	vector<CWorkThread*>	m_threads;
	UINT					m_msgDone;

	_TCHAR	m_szAppDir[_MAX_PATH];
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASPTESTDLG_H__DFBE270B_304A_11D1_8AFA_00C0F00910F9__INCLUDED_)
