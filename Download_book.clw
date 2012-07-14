; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDownload_bookDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Download_book.h"

ClassCount=3
Class1=CDownload_bookApp
Class2=CDownload_bookDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DOWNLOAD_BOOK_DIALOG
Resource4=IDD_ABOUTBOX (English (U.S.))
Resource5=IDD_DOWNLOAD_BOOK_DIALOG (English (U.S.))

[CLS:CDownload_bookApp]
Type=0
HeaderFile=Download_book.h
ImplementationFile=Download_book.cpp
Filter=N

[CLS:CDownload_bookDlg]
Type=0
HeaderFile=Download_bookDlg.h
ImplementationFile=Download_bookDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_SOURCE

[CLS:CAboutDlg]
Type=0
HeaderFile=Download_bookDlg.h
ImplementationFile=Download_bookDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg


[DLG:IDD_DOWNLOAD_BOOK_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CDownload_bookDlg

[DLG:IDD_DOWNLOAD_BOOK_DIALOG (English (U.S.))]
Type=1
Class=CDownload_bookDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_SOURCE,edit,1350631552
Control4=IDC_DOWNLOAD,button,1342242816

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

