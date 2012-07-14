// Download_book.h : main header file for the DOWNLOAD_BOOK application
//

#if !defined(AFX_DOWNLOAD_BOOK_H__615B03E3_B71F_422B_9C16_41FB78815CE4__INCLUDED_)
#define AFX_DOWNLOAD_BOOK_H__615B03E3_B71F_422B_9C16_41FB78815CE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDownload_bookApp:
// See Download_book.cpp for the implementation of this class
//

class CDownload_bookApp : public CWinApp
{
public:
	CDownload_bookApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDownload_bookApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDownload_bookApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOWNLOAD_BOOK_H__615B03E3_B71F_422B_9C16_41FB78815CE4__INCLUDED_)
