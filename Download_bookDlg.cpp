// Download_bookDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Download_book.h"
#include "Download_bookDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//my include files
#include "MyInternetSession.h"
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
// CDownload_bookDlg dialog

CDownload_bookDlg::CDownload_bookDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDownload_bookDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDownload_bookDlg)
	m_strSource = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_strSource = "http://gidb.ru/book_view.jsp?idn=021659&page=220&format=djvu";

}

void CDownload_bookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDownload_bookDlg)
	DDX_Text(pDX, IDC_SOURCE, m_strSource);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDownload_bookDlg, CDialog)
	//{{AFX_MSG_MAP(CDownload_bookDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_DOWNLOAD, OnDownload)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDownload_bookDlg message handlers

BOOL CDownload_bookDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDownload_bookDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDownload_bookDlg::OnPaint() 
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
HCURSOR CDownload_bookDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//tread global variables
unsigned int Start, Count;
CString strFileName, strDirectory, strExt;
CMyInternetSession * pMySession = NULL;
CDownload_bookDlg * pMainDlg = NULL;

CString strServerName = "gidb.ru";
CString strPathName;

int m_start = 1;
int m_count = 224;

UINT DownloadTread(LPVOID pParam ) {
	
	CString Statustext;
	unsigned long Status;
	CString pszAppName = "GetApp";
	CString strURL;
	
	for(unsigned i = 1; i <= 224; i++) {
		//compose reqired URL

		strURL.Format("http://gidb.ru/book_view.jsp?idn=021659&page=%d&format=djvu", i);
				

		CInternetSession Session;// = new CInternetSession();
		CHttpFile * pHttpFile = (CHttpFile *)Session.OpenURL(strURL);

		pHttpFile->SetReadBufferSize(4086);

		CString str;
		while(pHttpFile->ReadString(str)) {
			//find inside string
			int res = str.Find("x.djvu\" flags=\"zoom=page toolbar=auto\"");
			if( res >= 0) {
				//find string SRC="
				res = str.Find("SRC=\"", res);
				res = res+5;

				int len = str.GetLength();

				//get second symbol "for end of string
				int res2 = str.Find('"', res);

				strPathName = str.Mid(res, res2-res);
				break;
			}
			
		}

		Status = pMySession->GetWebFile(pszAppName, strServerName, 80, strPathName);
	}

	return 0;
}

void CDownload_bookDlg::OnDownload() 
{
	// TODO: Add your control notification handler code here
	UpdateData();

	pMySession = new CMyInternetSession();//(CMyInternetSession *)AfxGetMainWnd();

	//create download directory
	pMySession->SetDownloadDirectory("Download");

	//update global variables
	Start = m_start;
	Count = m_count;

	//save main dialog painter
	pMainDlg = this;

	HWND hWnd = GetSafeHwnd();
	AfxBeginThread(DownloadTread, hWnd, THREAD_PRIORITY_NORMAL);
}
