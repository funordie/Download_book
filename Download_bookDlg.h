// Download_bookDlg.h : header file
//

#if !defined(AFX_DOWNLOAD_BOOKDLG_H__B73C15E4_B461_458F_B1BC_D32CE6484157__INCLUDED_)
#define AFX_DOWNLOAD_BOOKDLG_H__B73C15E4_B461_458F_B1BC_D32CE6484157__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDownload_bookDlg dialog

class CDownload_bookDlg : public CDialog
{
// Construction
public:
	CDownload_bookDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDownload_bookDlg)
	enum { IDD = IDD_DOWNLOAD_BOOK_DIALOG };
	CString	m_strSource;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDownload_bookDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDownload_bookDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDownload();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOWNLOAD_BOOKDLG_H__B73C15E4_B461_458F_B1BC_D32CE6484157__INCLUDED_)
