
// MFC���۹���ϵͳDoc.cpp : CMFC���۹���ϵͳDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC���۹���ϵͳ.h"
#endif

#include "MFC���۹���ϵͳDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFC���۹���ϵͳDoc

IMPLEMENT_DYNCREATE(CMFC���۹���ϵͳDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFC���۹���ϵͳDoc, CDocument)
END_MESSAGE_MAP()


// CMFC���۹���ϵͳDoc ����/����

CMFC���۹���ϵͳDoc::CMFC���۹���ϵͳDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CMFC���۹���ϵͳDoc::~CMFC���۹���ϵͳDoc()
{
}

BOOL CMFC���۹���ϵͳDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)
	SetTitle(TEXT("���۹���ϵͳ"));

	return TRUE;
}




// CMFC���۹���ϵͳDoc ���л�

void CMFC���۹���ϵͳDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CMFC���۹���ϵͳDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CMFC���۹���ϵͳDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CMFC���۹���ϵͳDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFC���۹���ϵͳDoc ���

#ifdef _DEBUG
void CMFC���۹���ϵͳDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFC���۹���ϵͳDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFC���۹���ϵͳDoc ����
