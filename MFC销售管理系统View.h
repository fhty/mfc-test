
// MFC���۹���ϵͳView.h : CMFC���۹���ϵͳView ��Ľӿ�
//

#pragma once


class CMFC���۹���ϵͳView : public CView
{
protected: // �������л�����
	CMFC���۹���ϵͳView();
	DECLARE_DYNCREATE(CMFC���۹���ϵͳView)

// ����
public:
	CMFC���۹���ϵͳDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMFC���۹���ϵͳView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC���۹���ϵͳView.cpp �еĵ��԰汾
inline CMFC���۹���ϵͳDoc* CMFC���۹���ϵͳView::GetDocument() const
   { return reinterpret_cast<CMFC���۹���ϵͳDoc*>(m_pDocument); }
#endif

