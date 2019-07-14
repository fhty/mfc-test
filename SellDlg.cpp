// SellDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC销售管理系统.h"
#include "SellDlg.h"


// SellDlg

IMPLEMENT_DYNCREATE(SellDlg, CFormView)

SellDlg::SellDlg()
	: CFormView(IDD_DIALOG_SELL)
	, _price(0)
	, _left(0)
	, _num(0)
	, _sellInfo(_T(""))
{

}

SellDlg::~SellDlg()
{
}

void SellDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, _combox);
	DDX_Text(pDX, IDC_EDIT1, _price);
	DDX_Text(pDX, IDC_EDIT2, _left);
	DDX_Text(pDX, IDC_EDIT5, _num);
	DDX_Text(pDX, IDC_EDIT4, _sellInfo);
}

BEGIN_MESSAGE_MAP(SellDlg, CFormView)
END_MESSAGE_MAP()


// SellDlg 诊断

#ifdef _DEBUG
void SellDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void SellDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// SellDlg 消息处理程序
