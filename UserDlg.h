#pragma once



// UserDlg 窗体视图

class UserDlg : public CFormView
{
	DECLARE_DYNCREATE(UserDlg)

protected:
	UserDlg();           // 动态创建所使用的受保护的构造函数
	virtual ~UserDlg();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_USER };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString _user;
	CString _name;
	CString _newPwd;
	CString _checkPwd;
public:
	virtual void OnInitialUpdate();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};


