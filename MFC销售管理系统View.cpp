
// MFC���۹���ϵͳView.cpp : CMFC���۹���ϵͳView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC���۹���ϵͳ.h"
#endif

#include "MFC���۹���ϵͳDoc.h"
#include "MFC���۹���ϵͳView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC���۹���ϵͳView

IMPLEMENT_DYNCREATE(CMFC���۹���ϵͳView, CView)

BEGIN_MESSAGE_MAP(CMFC���۹���ϵͳView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC���۹���ϵͳView ����/����

CMFC���۹���ϵͳView::CMFC���۹���ϵͳView()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC���۹���ϵͳView::~CMFC���۹���ϵͳView()
{
}

BOOL CMFC���۹���ϵͳView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC���۹���ϵͳView ����

void CMFC���۹���ϵͳView::OnDraw(CDC* /*pDC*/)
{
	CMFC���۹���ϵͳDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC���۹���ϵͳView ��ӡ

BOOL CMFC���۹���ϵͳView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC���۹���ϵͳView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC���۹���ϵͳView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFC���۹���ϵͳView ���

#ifdef _DEBUG
void CMFC���۹���ϵͳView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC���۹���ϵͳView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC���۹���ϵͳDoc* CMFC���۹���ϵͳView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC���۹���ϵͳDoc)));
	return (CMFC���۹���ϵͳDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC���۹���ϵͳView ��Ϣ�������
