#pragma once


// CLoginDlg 对话框

class CLoginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CLoginDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = DIALOG_LOGIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString m_user;  //登陆用户名
	CString m_pwd;   //登陆密码
public:
	afx_msg void OnBnClickedButton1();  //登陆按钮
	afx_msg void OnBnClickedButton2();  //取消按钮
	virtual BOOL OnInitDialog();       //默认登录信息
	virtual void OnOK();               //修复不输入任何内容直接回车会进入主界面的问题
	afx_msg void OnClose();             //修复关闭当前对话框仍然进入主界面的问题
};
