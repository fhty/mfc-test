#pragma once



// DisplayView ������ͼ

class DisplayView : public CFormView
{
	DECLARE_DYNCREATE(DisplayView)

protected:
	DisplayView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~DisplayView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DISPLAYVIEW };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};


