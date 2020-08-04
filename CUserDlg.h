#pragma once



// CUserDlg 窗体视图

class CUserDlg : public CFormView
{
	DECLARE_DYNCREATE(CUserDlg)

protected:
	CUserDlg();           // 动态创建所使用的受保护的构造函数
	virtual ~CUserDlg();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = DIALOG_USER };
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
public:
	CString m_user;   //用户类型
private:
	CString m_name;  //姓名
	CString m_newPwd;  //新密码
	CString m_surePwd;  //确认密码
public:
	virtual void OnInitialUpdate();  //初始化函数
	afx_msg void OnBnClickedButton1();  //确认修改密码
	afx_msg void OnBnClickedButton2();  //取消修改密码
};


