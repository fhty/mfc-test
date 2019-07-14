// LoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC���۹���ϵͳ.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "InfoFile.h"


// LoginDlg �Ի���

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


// LoginDlg ��Ϣ�������


void LoginDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������,��¼��ť.
	UpdateData(true);

	if (User_.IsEmpty() || Pasw_.IsEmpty()) {
		MessageBox(TEXT("�û���������Ϊ�գ�"));
		return;
	}
	InfoFile file;
	CString user, pass;
	file.readLogin(user, pass);

	if (User_ == user&&Pasw_ == pass) {
		MessageBox(TEXT("��¼�ɹ���"));
		CDialog::OnCancel();
	}
	else {
		MessageBox(TEXT("�û��������벻��ȷ"));
	}
}


void LoginDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);//�ر���������
}


BOOL LoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	InfoFile file;
	CString name, pas;
	file.readLogin(name, pas);
	User_ = name;
	Pasw_ = pas;
	UpdateData(false);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void LoginDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialogEx::OnOK();
}


void LoginDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//CDialogEx::OnClose();
	exit(0);
}
