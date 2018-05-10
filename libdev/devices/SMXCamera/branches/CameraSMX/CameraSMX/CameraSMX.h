// CameraSMX.h : Hauptheaderdatei f�r die PROJECT_NAME-Anwendung
//

#pragma once

#ifndef __AFXWIN_H__
	#error "\"stdafx.h\" vor dieser Datei f�r PCH einschlie�en"
#endif

#include "resource.h"		// Hauptsymbole
#include "CameraSMX150.h"
#include "DlgSMXCameraSettings.h"
#include "CameraSMXDlg.h"

// CCameraSMXApp:
// Siehe CameraSMX.cpp f�r die Implementierung dieser Klasse
//

class CCameraSMXApp : public CWinApp
{
public:
	CCameraSMXApp();

// �berschreibungen
	public:
	virtual BOOL InitInstance();

// Implementierung
	CCameraSMXDlg dlg;
	CDlgSMXCameraSettings m_DlgSMXCameraSettings;

	DECLARE_MESSAGE_MAP()
};

extern CCameraSMXApp theApp;

extern CameraSMX Camera;