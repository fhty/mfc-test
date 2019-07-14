// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC销售管理系统.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "InfoFile.h"


// LoginDlg 对话框

IMPLEMENT_DYNAMIC(LoginDlg, CDialogEx)

LoginDlg::LoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(DLG_LOGIN, pParent)
	, User_(_T(""))
	, Pasw_(_T(""))
{

}

LoginDlg::~LoginDlg()
{
}

void LoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, User_);
	DDX_Text(pDX, IDC_EDIT2, Pasw_);
}


BEGIN_MESSAGE_MAP(LoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &LoginDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &LoginDlg::OnBnClickedButton2)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// LoginDlg 消息处理程序


void LoginDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码,登录按钮.
	UpdateData(true);

	if (User_.IsEmpty() || Pasw_.IsEmpty()) {
		MessageBox(TEXT("用户名或密码为空！"));
		return;
	}
	InfoFile file;
	CString user, pass;
	file.readLogin(user, pass);

	if (User_ == user&&Pasw_ == pass) {
		MessageBox(TEXT("登录成功！"));
		CDialog::OnCancel();
	}
	else {
		MessageBox(TEXT("用户名或密码不正确"));
	}
}


void LoginDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);//关闭整个程序。
}


BOOL LoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	InfoFile file;
	CString name, pas;
	file.readLogin(name, pas);
	User_ = name;
	Pasw_ = pas;
	UpdateData(false);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void LoginDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


void LoginDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//CDialogEx::OnClose();
	exit(0);
}
