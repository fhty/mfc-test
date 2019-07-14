// UserDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC���۹���ϵͳ.h"
#include "UserDlg.h"
#include "InfoFile.h"


// UserDlg

IMPLEMENT_DYNCREATE(UserDlg, CFormView)

UserDlg::UserDlg()
	: CFormView(IDD_DIALOG_USER)
	, _user(_T(""))
	, _name(_T(""))
	, _newPwd(_T(""))
	, _checkPwd(_T(""))
{

}

UserDlg::~UserDlg()
{
}

void UserDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, _user);
	DDX_Text(pDX, IDC_EDIT2, _name);
	DDX_Text(pDX, IDC_EDIT3, _newPwd);
	DDX_Text(pDX, IDC_EDIT4, _checkPwd);
}

BEGIN_MESSAGE_MAP(UserDlg, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &UserDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &UserDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// UserDlg ���

#ifdef _DEBUG
void UserDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void UserDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// UserDlg ��Ϣ�������


void UserDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	// TODO: �ڴ����ר�ô����/����û���
	_user = TEXT("����Ա");

	InfoFile file;
	CString name, pwd;
	file.readLogin(name, pwd);
	_name = name;
	
	UpdateData(0);
}


void UserDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(1);
	if (_newPwd.IsEmpty() || _checkPwd.IsEmpty()) {
		MessageBox(TEXT("���벻��Ϊ�գ�"));
		return;
	}
	if (_newPwd != _checkPwd) {
		MessageBox(TEXT("���벻һ�£�"));
		return;
	}
	
	InfoFile file;
	CString name, pwd;
	file.readLogin(name, pwd);
	
	if (pwd == _newPwd) {
		MessageBox(TEXT("�����������һ�£�"));
		return;
	}
	CStringA t, t1;
	t = _name;
	t1 = _newPwd;
	file.changePaw(t.GetBuffer(), t1.GetBuffer());
	MessageBox(TEXT("�޸ĳɹ���"));

	_newPwd.Empty();
	_checkPwd.Empty();
	UpdateData(0);
}


void UserDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	_newPwd.Empty();
	_checkPwd.Empty();
	UpdateData(0);
}
