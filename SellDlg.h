#pragma once
#include "afxwin.h"



// SellDlg ������ͼ

class SellDlg : public CFormView
{
	DECLARE_DYNCREATE(SellDlg)

protected:
	SellDlg();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~SellDlg();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SELL };
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
private:
	CComboBox _combox;
	int _price;
	int _left;
	int _num;
	CString _sellInfo;
};


