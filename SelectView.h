#pragma once


// SelectView ��ͼ

class SelectView : public CTreeView
{
	DECLARE_DYNCREATE(SelectView)

protected:
	SelectView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~SelectView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()

public:
	CTreeCtrl *m_treeCtrl;//���ؼ���
	CImageList *m_imageList;//ͼ���б�
public:
	void OnInitialUpdate();
	afx_msg void OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult);
};


