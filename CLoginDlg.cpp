// CLoginDlg.cpp: 实现文件
//

#include "pch.h"
#include "SalaryAdminSystem.h"
#include "CLoginDlg.h"
#include "afxdialogex.h"
#include "CInfoFile.h"

// CLoginDlg 对话框

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(DIALOG_LOGIN, pParent)
	, m_user(_T(""))
	, m_pwd(_T(""))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_user);
	DDX_Text(pDX, IDC_EDIT2, m_pwd);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CLoginDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CLoginDlg::OnBnClickedButton2)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序


void CLoginDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	//登陆按钮点击事件

	UpdateData(TRUE);

	if (m_user.IsEmpty() || m_pwd.IsEmpty())
	{
		MessageBox(TEXT("用户名和密码不能为空"), TEXT("错误"), MB_ICONWARNING);
		return;
	}

	//输入内容不为空  输入正确的值
	CInfoFile file;
	CString name, pwd;
	file.ReadLogin(name, pwd);

	//验证
	if (name == m_user)   //用户名一致
	{
		if (pwd == m_pwd)   //密码一致
		{
			//关闭当前对话框
			CDialog::OnOK();
		}
		else
		{
			MessageBox(TEXT("密码有误"), TEXT("错误"), MB_ICONERROR);
		}
	}
	else
	{
		MessageBox(TEXT("用户名有误"), TEXT("错误"), MB_ICONERROR);
	}

}


void CLoginDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	exit(0);
}


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化


	//默认登录信息
	CInfoFile file;
	CString name, pwd;
	file.ReadLogin(name, pwd);

	m_user = name;
	m_pwd = pwd;

	//同步到控件中
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CLoginDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类


	//下面的代码注释后可修复不输入任何内容直接回车会进入主界面的问题
	//CDialogEx::OnOK();
}


void CLoginDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
    //注释下面一行代码可修复关闭当前对话框仍然进入主界面的问题
	//CDialogEx::OnClose();


	//重写退出程序
	exit(0);
}
