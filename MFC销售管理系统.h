
// MFC���۹���ϵͳ.h : MFC���۹���ϵͳ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFC���۹���ϵͳApp:
// �йش����ʵ�֣������ MFC���۹���ϵͳ.cpp
//

class CMFC���۹���ϵͳApp : public CWinApp
{
public:
	CMFC���۹���ϵͳApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC���۹���ϵͳApp theApp;
