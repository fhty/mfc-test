// SelectView.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC销售管理系统.h"
#include "SelectView.h"
#include "DisplayView.h"
#include "MainFrm.h"


// SelectView

IMPLEMENT_DYNCREATE(SelectView, CTreeView)

SelectView::SelectView()
{

}

SelectView::~SelectView()
{
}

BEGIN_MESSAGE_MAP(SelectView, CTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &SelectView::OnTvnSelchanged)

END_MESSAGE_MAP()


// SelectView 诊断

#ifdef _DEBUG
void SelectView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void SelectView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// SelectView 消息处理程序


void SelectView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	m_treeCtrl = &GetTreeCtrl();
	m_imageList = new CImageList;
	HICON icon = AfxGetApp()->LoadIconW(IDI_ICON_sele);
	m_imageList->Create(30, 30, ILC_COLOR32, 1, 1);
	m_imageList->Add(icon);
	m_treeCtrl->SetImageList(m_imageList, TVSIL_NORMAL);

	m_treeCtrl->SetImageList(m_imageList,TVSIL_NORMAL);
	m_treeCtrl->InsertItem(TEXT("个人信息"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("销售管理"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("库存信息"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("库存添加"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("库存删除"), 0, 0, NULL);
}


void SelectView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	//获取选中项。
	HTREEITEM item = m_treeCtrl->GetSelectedItem();
	//获取该项中内容。
	CString str = m_treeCtrl->GetItemText(item);
	if (str == TEXT("个人信息")) {
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WM_SLECTVIEW, (WPARAM)WM_SLECTVIEW, (LPARAM)0);
	}
	else if (str == TEXT("销售管理")) {
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WM_SLECTVIEW2, (WPARAM)WM_SLECTVIEW2, (LPARAM)0);
	}
}
