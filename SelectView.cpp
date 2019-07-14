// SelectView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC���۹���ϵͳ.h"
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


// SelectView ���

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


// SelectView ��Ϣ�������


void SelectView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���

	m_treeCtrl = &GetTreeCtrl();
	m_imageList = new CImageList;
	HICON icon = AfxGetApp()->LoadIconW(IDI_ICON_sele);
	m_imageList->Create(30, 30, ILC_COLOR32, 1, 1);
	m_imageList->Add(icon);
	m_treeCtrl->SetImageList(m_imageList, TVSIL_NORMAL);

	m_treeCtrl->SetImageList(m_imageList,TVSIL_NORMAL);
	m_treeCtrl->InsertItem(TEXT("������Ϣ"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("���۹���"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("�����Ϣ"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("������"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("���ɾ��"), 0, 0, NULL);
}


void SelectView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	//��ȡѡ���
	HTREEITEM item = m_treeCtrl->GetSelectedItem();
	//��ȡ���������ݡ�
	CString str = m_treeCtrl->GetItemText(item);
	if (str == TEXT("������Ϣ")) {
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WM_SLECTVIEW, (WPARAM)WM_SLECTVIEW, (LPARAM)0);
	}
	else if (str == TEXT("���۹���")) {
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WM_SLECTVIEW2, (WPARAM)WM_SLECTVIEW2, (LPARAM)0);
	}
}
