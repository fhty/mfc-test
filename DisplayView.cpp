// DisplayView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC���۹���ϵͳ.h"
#include "DisplayView.h"


// DisplayView

IMPLEMENT_DYNCREATE(DisplayView, CFormView)

DisplayView::DisplayView()
	: CFormView(IDD_DISPLAYVIEW)
{

}

DisplayView::~DisplayView()
{
}

void DisplayView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(DisplayView, CFormView)
END_MESSAGE_MAP()


// DisplayView ���

#ifdef _DEBUG
void DisplayView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void DisplayView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// DisplayView ��Ϣ�������
