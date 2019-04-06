; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPianoDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "piano.h"

ClassCount=4
Class1=CPianoApp
Class2=CPianoDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_PIANO_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CReademeDlg
Resource4=IDD_DIALOG1

[CLS:CPianoApp]
Type=0
HeaderFile=piano.h
ImplementationFile=piano.cpp
Filter=N

[CLS:CPianoDlg]
Type=0
HeaderFile=pianoDlg.h
ImplementationFile=pianoDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CPianoDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=pianoDlg.h
ImplementationFile=pianoDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PIANO_DIALOG]
Type=1
Class=CPianoDlg
ControlCount=43
Control1=ID_Quit,button,1342242816
Control2=ID_HELP,button,1342242816
Control3=IDC_QKey,static,1342177294
Control4=IDC_WKey,static,1342177294
Control5=IDC_EKey,static,1342177294
Control6=IDC_KVAL,static,1342308352
Control7=IDC_RKey,static,1342177294
Control8=IDC_TKey,static,1342177294
Control9=IDC_YKey,static,1342177294
Control10=IDC_UKey,static,1342177294
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342177294
Control13=IDC_STATIC,static,1342177294
Control14=IDC_INIT_INFO,static,1342308352
Control15=IDC_BUTTON1,button,1342242816
Control16=IDC_BUTTON2,button,1342242816
Control17=IDC_AKey,static,1342177294
Control18=IDC_SKey,static,1342177294
Control19=IDC_DKey,static,1342177294
Control20=IDC_FKey,static,1342177294
Control21=IDC_GKey,static,1342177294
Control22=IDC_HKey,static,1342177294
Control23=IDC_JKey,static,1342177294
Control24=IDC_ZKey,static,1342177294
Control25=IDC_XKey,static,1342177294
Control26=IDC_CKey,static,1342177294
Control27=IDC_VKey,static,1342177294
Control28=IDC_BKey,static,1342177294
Control29=IDC_NKey,static,1342177294
Control30=IDC_MKey,static,1342177294
Control31=IDC_STATIC,static,1342177294
Control32=IDC_A2ZTrue,button,1342308361
Control33=IDC_A2ZFalse,button,1342177289
Control34=IDC_SoundLocalTrue,button,1342308361
Control35=IDC_SoundLocalFalse,button,1342177289
Control36=IDC_Beat1,button,1342308361
Control37=IDC_Beat1_2,button,1342177289
Control38=IDC_Beat1_4,button,1342177289
Control39=IDC_Beat1_8,button,1342177289
Control40=IDC_STATIC,static,1342308352
Control41=IDC_CRhythm,button,1342308361
Control42=IDC_DRhythm,button,1342177289
Control43=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG1]
Type=1
Class=CReademeDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352

[CLS:CReademeDlg]
Type=0
HeaderFile=ReademeDlg.h
ImplementationFile=ReademeDlg.cpp
BaseClass=CDialog
Filter=D

