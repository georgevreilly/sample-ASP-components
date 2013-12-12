// AspTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AspTest.h"
#include "AspTestDlg.h"
#include "Component.h"
#include "utility.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

static LPCTSTR s_szCompDir = _T("comp");
static UINT NEAR WM_THREADS_DONE = ::RegisterWindowMessage( _T("AspTest: threads done") );

/////////////////////////////////////////////////////////////////////////////
// CAspTestDlg dialog

CAspTestDlg::CAspTestDlg(CWnd* pParent /*=NULL*/)
	:	CDialog(CAspTestDlg::IDD, pParent),
		m_lNumThreadsRunning( 0 )
{
	//{{AFX_DATA_INIT(CAspTestDlg)
	m_bInfinite = FALSE;
	m_uNumThreads = 10;
	m_uNumIterations = 100;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	// determine the app's directory
	::GetModuleFileName(AfxGetInstanceHandle(), m_szAppDir, sizeof(m_szAppDir));

	// remove the filename
	_TCHAR* pch = _tcsrchr(m_szAppDir, '\\');
	if (pch == NULL)
	{
		// the path should have at least one backslash
		_ASSERT(0);
		pch = m_szAppDir;
	}
	*(pch+1) = _T('\0');

	m_hevtThreadsDone = ::CreateEvent(
		NULL,
		TRUE,
		TRUE,	//initially signaled
		NULL );
}

CAspTestDlg::~CAspTestDlg()
{
	StopWorkThreads();
	::CloseHandle( m_hevtThreadsDone );
}

void CAspTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAspTestDlg)
	DDX_Control(pDX, IDC_STOP, m_btnStop);
	DDX_Control(pDX, IDC_START, m_btnStart);
	DDX_Control(pDX, IDC_COMPONENT_LIST, m_cmbxComponent);
	DDX_Check(pDX, IDC_INFINITE, m_bInfinite);
	DDX_Text(pDX, IDC_NUM_THREADS, m_uNumThreads);
	DDV_MinMaxUInt(pDX, m_uNumThreads, 1, 255);
	DDX_Text(pDX, IDC_NUM_ITERATIONS, m_uNumIterations);
	DDV_MinMaxUInt(pDX, m_uNumIterations, 0, 4294967295);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAspTestDlg, CDialog)
	//{{AFX_MSG_MAP(CAspTestDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, OnStart)
	ON_BN_CLICKED(IDC_INFINITE, OnInfinite)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_REGISTERED_MESSAGE(WM_THREADS_DONE, OnThreadsDone)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAspTestDlg message handlers

BOOL CAspTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	InitComponentList();

	m_btnStop.EnableWindow( FALSE );

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAspTestDlg::OnPaint() 
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
HCURSOR CAspTestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


// this function will initialize the component list combobox by searching the
// the applications directory for all of the .ini files.  The .ini files aren't
// read yet.
void
CAspTestDlg::InitComponentList()
{
	// first clear out all of the strings in the combo box
	m_cmbxComponent.ResetContent();

	// go through the app's comp directory and find all the .ini files
	CString strCompDir = m_szAppDir;
	strCompDir += s_szCompDir;
	strCompDir += "\\*.ini";

	WIN32_FIND_DATA	fd;
	HANDLE hFind = NULL;
	hFind = ::FindFirstFile(
		strCompDir,
		&fd );
	if ( hFind != INVALID_HANDLE_VALUE )
	{
		bool bDone = false;
		do
		{
			CString strFile = fd.cFileName;
			// delete the last four characters ( ".ini" )
			int pos = strFile.ReverseFind( _T('.') );
			if ( pos >= 0 )
			{
				CString strComp = strFile.Left( pos );
				// add the component to the combo box
				m_cmbxComponent.AddString( strComp );
			}
			if ( ::FindNextFile( hFind, &fd ) )
			{
			}
			else
			{
				::FindClose( hFind );
				bDone = true;
			}
		} while ( !bDone );
		m_cmbxComponent.SetCurSel( 0 );
	}
}

void CAspTestDlg::OnStart()
{
	if ( UpdateData( TRUE ) )
	{
		StartWorkThreads();
	}
}

//---------------------------------------------------------------------------
//
//	Implementation of the CWorkStatus interface.  This is called when a
//	work thread has exited
//
//---------------------------------------------------------------------------
void
CAspTestDlg::Done()
{
	if ( ::InterlockedDecrement( &m_lNumThreadsRunning ) <= 0 )
	{
		ASSERT( m_lNumThreadsRunning == 0 );
		m_lNumThreadsRunning = 0;
		::SetEvent( m_hevtThreadsDone );
		PostMessage( WM_THREADS_DONE );
	}
}

//---------------------------------------------------------------------------
//
//	Wait for all of the work threads to finish
//
//---------------------------------------------------------------------------
void
CAspTestDlg::WaitForWorkThreads()
{
	::WaitForSingleObject( m_hevtThreadsDone, INFINITE );
}

//---------------------------------------------------------------------------
//
//	Start all of the work threads
//
//---------------------------------------------------------------------------
void
CAspTestDlg::StartWorkThreads()
{
	// make sure there are no work threads running
	StopWorkThreads();

	CString strIniFile = m_szAppDir;
	strIniFile += s_szCompDir;

	int nCurSel = m_cmbxComponent.GetCurSel();
	if ( nCurSel != CB_ERR )
	{
		CString strComp;
		m_cmbxComponent.GetLBText( nCurSel, strComp );
		strIniFile += _T("\\");
		strIniFile += strComp;
		strIniFile += _T(".ini");

		CComponent cmp( strIniFile );
		if ( cmp.Initialize() )
		{
			// create threads
			if ( m_uNumThreads > 0 )
			{
				UINT uIters = m_bInfinite ? 0 : m_uNumIterations;
				m_lNumThreadsRunning = m_uNumThreads;
				::ResetEvent( m_hevtThreadsDone );
				for ( int i = 0; i < m_uNumThreads; i++ )
				{
					CWorkThread* pThread = new CWorkThread( cmp, this, uIters );
					pThread->Start();
					m_threads.push_back( pThread );
				}
				m_btnStop.EnableWindow( TRUE );
				m_btnStart.EnableWindow( FALSE );
			}
		}
	}
}

//---------------------------------------------------------------------------
//
//	Stop all of the work threads, and wait to make sure they're done
//
//---------------------------------------------------------------------------
void
CAspTestDlg::StopWorkThreads()
{
	for ( int i = 0; i < m_threads.size(); i++ )
	{
		m_threads[i]->Quit();
	}
	WaitForWorkThreads();

	DeleteList( m_threads );
}

void CAspTestDlg::OnInfinite() 
{
	CWnd* pWnd = GetDlgItem( IDC_NUM_ITERATIONS );
	if ( pWnd )
	{
		if ( IsDlgButtonChecked( IDC_INFINITE ) )
		{
			pWnd->EnableWindow( FALSE );
		}
		else
		{
			pWnd->EnableWindow( TRUE );
		}
	}
}

void CAspTestDlg::OnStop() 
{
	StopWorkThreads();
}

LRESULT
CAspTestDlg::OnThreadsDone(
	WPARAM,
	LPARAM )
{
	m_btnStop.EnableWindow( FALSE );
	m_btnStart.EnableWindow( TRUE );
	return 0;
}
