
// MainFrm.h : CMainFrame ��Ľӿ�
//

#pragma once

#define WM_SLECTVIEW  WM_USER+1001
#define WM_SLECTVIEW2  WM_USER+1002
#define WM_SLECTVIEW3  WM_USER+1003
#define WM_SLECTVIEW4  WM_USER+1004


class CMainFrame : public CFrameWnd
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CStatusBar        m_wndStatusBar;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnApplicationLook(UINT id);
	afx_msg void OnUpdateApplicationLook(CCmdUI* pCmdUI);
	afx_msg LRESULT OnMyChange(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

private:
	CSplitterWnd _spliter;
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
public:
	afx_msg void On32771();
	afx_msg void On32772();
};


