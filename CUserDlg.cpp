// CUserDlg.cpp: 实现文件
//

#include "pch.h"
#include "SalaryAdminSystem.h"
#include "CUserDlg.h"
#include "CInfoFile.h"

// CUserDlg

IMPLEMENT_DYNCREATE(CUserDlg, CFormView)

CUserDlg::CUserDlg()
	: CFormView(DIALOG_USER)
	, m_user(_T(""))
	, m_name(_T(""))
	, m_newPwd(_T(""))
	, m_surePwd(_T(""))
{

}

CUserDlg::~CUserDlg()
{
}

void CUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_user);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDX_Text(pDX, IDC_EDIT3, m_newPwd);
	DDX_Text(pDX, IDC_EDIT4, m_surePwd);
}

BEGIN_MESSAGE_MAP(CUserDlg, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CUserDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CUserDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CUserDlg 诊断

#ifdef _DEBUG
void CUserDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUserDlg 消息处理程序


void CUserDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();


	//初始化

	m_user = TEXT("管理员");


	CInfoFile file;
	CString name, pwd;
	file.ReadLogin(name, pwd);
	m_name = name;


	//同步变量到控件中
	UpdateData(FALSE);
	// TODO: 在此添加专用代码和/或调用基类
}


void CUserDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	//修改密码确定

	UpdateData(TRUE);

	if (m_newPwd.IsEmpty() || m_surePwd.IsEmpty())
	{
		MessageBox(TEXT("输入内容不能为空"), TEXT("错误"), MB_ICONWARNING);
		return;
	}


	if (m_newPwd != m_surePwd)
	{
		MessageBox(TEXT("确认密码不一致"), TEXT("错误"), MB_ICONWARNING);
		return;
	}


	CInfoFile file;
	CString name, pwd;
	file.ReadLogin(name, pwd);  //读取账号密码
	if (m_surePwd == pwd)
	{
		MessageBox(TEXT("新密码与旧密码不能一致"), TEXT("错误"), MB_ICONWARNING);
		return;
	}


	//CString转 char*
	CStringA temp;
	CStringA temp2;
	temp = name;
	temp2 = m_newPwd;
	file.WritePwd(temp.GetBuffer(), temp2.GetBuffer());  //写入新密码
	MessageBox(TEXT("修改密码成功"), TEXT("成功"));


	//清空内容
	m_newPwd.Empty();
	m_surePwd.Empty();

	UpdateData(FALSE);


}


void CUserDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	//修改密码取消

	//清空内容
	m_newPwd.Empty();
	m_surePwd.Empty();

	UpdateData(FALSE);
}
