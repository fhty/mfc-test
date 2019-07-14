
// MFC销售管理系统.h : MFC销售管理系统 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CMFC销售管理系统App:
// 有关此类的实现，请参阅 MFC销售管理系统.cpp
//

class CMFC销售管理系统App : public CWinApp
{
public:
	CMFC销售管理系统App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC销售管理系统App theApp;
