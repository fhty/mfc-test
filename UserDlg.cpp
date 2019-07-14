// UserDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC销售管理系统.h"
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


// UserDlg 诊断

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


// UserDlg 消息处理程序


void UserDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	// TODO: 在此添加专用代码和/或调用基类
	_user = TEXT("销售员");

	InfoFile file;
	CString name, pwd;
	file.readLogin(name, pwd);
	_name = name;
	
	UpdateData(0);
}


void UserDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);
	if (_newPwd.IsEmpty() || _checkPwd.IsEmpty()) {
		MessageBox(TEXT("输入不能为空！"));
		return;
	}
	if (_newPwd != _checkPwd) {
		MessageBox(TEXT("输入不一致！"));
		return;
	}
	
	InfoFile file;
	CString name, pwd;
	file.readLogin(name, pwd);
	
	if (pwd == _newPwd) {
		MessageBox(TEXT("输入与旧密码一致！"));
		return;
	}
	CStringA t, t1;
	t = _name;
	t1 = _newPwd;
	file.changePaw(t.GetBuffer(), t1.GetBuffer());
	MessageBox(TEXT("修改成功！"));

	_newPwd.Empty();
	_checkPwd.Empty();
	UpdateData(0);
}


void UserDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	_newPwd.Empty();
	_checkPwd.Empty();
	UpdateData(0);
}
