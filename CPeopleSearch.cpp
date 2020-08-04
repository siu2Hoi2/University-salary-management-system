// CPeopleSearch.cpp: 实现文件
//

#include "pch.h"
#include "SalaryAdminSystem.h"
#include "CPeopleSearch.h"
#include "CInfoFile.h"

// CPeopleSearch

IMPLEMENT_DYNCREATE(CPeopleSearch, CFormView)

CPeopleSearch::CPeopleSearch()
	: CFormView(IDD_SEARCH)
	, searchName(_T(""))
	, searchID(_T(""))
	, peopleInfo(_T(""))
{

}

CPeopleSearch::~CPeopleSearch()
{
}

void CPeopleSearch::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, peopleCombo);
	DDX_Text(pDX, IDC_EDIT1, searchName);
	DDX_Text(pDX, IDC_EDIT2, searchID);
	DDX_Text(pDX, IDC_EDIT3, peopleInfo);
}

BEGIN_MESSAGE_MAP(CPeopleSearch, CFormView)
	ON_BN_CLICKED(IDC_BUTTON2, &CPeopleSearch::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON9, &CPeopleSearch::OnBnClickedButton9)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CPeopleSearch::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CPeopleSearch 诊断

#ifdef _DEBUG
void CPeopleSearch::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CPeopleSearch::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPeopleSearch 消息处理程序


void CPeopleSearch::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	
	///查询信息
	int index = peopleCombo.GetCurSel();

	CString str;   //存放获取的下拉框内容
	peopleCombo.GetLBText(index, str);

	if (str == "教师")
	{
		UpdateData(TRUE);
		if (searchName.IsEmpty() || searchID.IsEmpty())
		{
			MessageBox(TEXT("输入内容不能为空"), TEXT("错误"), MB_ICONWARNING);
			return;
		}

		CInfoFile file;
		string tempID = (CStringA)searchID;  //CString转string
		string tempName = (CStringA)searchName;
		CString infoStr;
		file.ReadTeacher();

		list<Teacher>::iterator it = file.l_teach.begin();

		int count = 0;   //已遍历计数
		for (it = file.l_teach.begin(); it != file.l_teach.end(); it++)
		{
			if (it->id != tempID || it->name != tempName)
			{
				count++;
				if (count == file.l_teach.size())
				{
					MessageBox(_T("没有找到相关信息！"), TEXT("错误"), MB_ICONWARNING);
					break;
				}
			}

			else if (it->id == tempID && it->name == tempName)
			{
				MessageBox(_T("查找成功！"));
				infoStr.Format(_T("ID：%s \r\n姓名： %s \r\n工作量： %d \r\n工资： %0.2lf"),
					searchID, searchName, it->work_hours, it->total_salary);
				peopleInfo = infoStr;
				UpdateData(FALSE);
				break;
			}
		}
	}

	else if (str == "行政人员")
	{
		UpdateData(TRUE);
		if (searchName.IsEmpty() || searchID.IsEmpty())
		{
			MessageBox(TEXT("输入内容不能为空"), TEXT("错误"), MB_ICONWARNING);
			return;
		}

		CInfoFile file;
		string tempID = (CStringA)searchID;  //CString转string
		string tempName = (CStringA)searchName;
		CString infoStr;
		file.ReadAdmin();

		list<Admin>::iterator it = file.l_admin.begin();

		int count = 0;   //已遍历计数
		for (it = file.l_admin.begin(); it != file.l_admin.end(); it++)
		{
			if (it->id != tempID || it->name != tempName)
			{
				count++;
				if (count == file.l_admin.size())
				{
					MessageBox(_T("没有找到相关信息！"), TEXT("错误"), MB_ICONWARNING);
					break;
				}
			}

			else if (it->id == tempID && it->name == tempName)
			{
				MessageBox(_T("查找成功！"));
				infoStr.Format(_T("ID：%s \r\n姓名： %s  \r\n工资： %0.2lf"),
					searchID, searchName, it->total_salary);
				peopleInfo = infoStr;
				UpdateData(FALSE);
				break;
			}
		}
	}

	else if (str == "实验技术员")
	{
		UpdateData(TRUE);
		if (searchName.IsEmpty() || searchID.IsEmpty())
		{
			MessageBox(TEXT("输入内容不能为空"), TEXT("错误"), MB_ICONWARNING);
			return;
		}

		CInfoFile file;
		string tempID = (CStringA)searchID;  //CString转string
		string tempName = (CStringA)searchName;
		CString infoStr;
		file.ReadTech();

		list<Tech>::iterator it = file.l_tech.begin();

		int count = 0;   //已遍历计数
		for (it = file.l_tech.begin(); it != file.l_tech.end(); it++)
		{
			if (it->id != tempID || it->name != tempName)
			{
				count++;
				if (count == file.l_tech.size())
				{
					MessageBox(_T("没有找到相关信息！"), TEXT("错误"), MB_ICONWARNING);
					break;
				}
			}

			else if (it->id == tempID && it->name == tempName)
			{
				MessageBox(_T("查找成功！"));
				infoStr.Format(_T("ID：%s \r\n姓名： %s \r\n工作量： %d \r\n工资： %0.2lf"),
					searchID, searchName, it->work_hours, it->total_salary);
				peopleInfo = infoStr;
				UpdateData(FALSE);
				break;
			}
		}
	}

	else if (str == "教师兼职实验技术员")
	{
		UpdateData(TRUE);
		if (searchName.IsEmpty() || searchID.IsEmpty())
		{
			MessageBox(TEXT("输入内容不能为空"), TEXT("错误"), MB_ICONWARNING);
			return;
		}

		CInfoFile file;
		string tempID = (CStringA)searchID;  //CString转string
		string tempName = (CStringA)searchName;
		CString infoStr;
		file.ReadTeachAndTech();

		list<TeachAndTech>::iterator it = file.l_TAT.begin();

		int count = 0;   //已遍历计数
		for (it = file.l_TAT.begin(); it != file.l_TAT.end(); it++)
		{
			if (it->id != tempID || it->name != tempName)
			{
				count++;
				if (count == file.l_TAT.size())
				{
					MessageBox(_T("没有找到相关信息！"), TEXT("错误"), MB_ICONWARNING);
					break;
				}
			}

			else if (it->id == tempID && it->name == tempName)
			{
				MessageBox(_T("查找成功！"));
				infoStr.Format(_T("ID：%s \r\n姓名： %s \r\n工作量： %d \r\n工资： %0.2lf"),
					searchID, searchName, it->work_hours, it->total_salary);
				peopleInfo = infoStr;
				UpdateData(FALSE);
				break;
			}
		}

    }

	else if (str == "行政人员兼职教师")
	{
		UpdateData(TRUE);
		if (searchName.IsEmpty() || searchID.IsEmpty())
		{
			MessageBox(TEXT("输入内容不能为空"), TEXT("错误"), MB_ICONWARNING);
			return;
		}

		CInfoFile file;
		string tempID = (CStringA)searchID;   //CString转string
		string tempName = (CStringA)searchName;
		CString infoStr;
		file.ReadAdminAndTeach();

		list<AdminAndTeach>::iterator it = file.l_AAT.begin();

		int count = 0;   //已遍历计数
		for (it = file.l_AAT.begin(); it != file.l_AAT.end(); it++)
		{
			if (it->id != tempID || it->name != tempName)
			{
				count++;
				if (count == file.l_AAT.size())
				{
					MessageBox(_T("没有找到相关信息！"), TEXT("错误"), MB_ICONWARNING);
					break;
				}
			}

			else if (it->id == tempID && it->name == tempName)
			{
				MessageBox(_T("查找成功！"));
				infoStr.Format(_T("ID：%s \r\n姓名： %s \r\n节次： %d \r\n工资： %0.2lf"),
					searchID, searchName, it->num_class, it->total_salary);
				peopleInfo = infoStr;
				UpdateData(FALSE);
				break;
			}
		}
    }
}


void CPeopleSearch::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	
	//清空查询信息
	UpdateData(TRUE);

	searchID.Empty();
	searchName.Empty();
	peopleInfo.Empty();

	UpdateData(FALSE);  //显示控件
}


void CPeopleSearch::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码

	
}


void CPeopleSearch::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	//下拉框初始化

	peopleCombo.AddString(TEXT("教师"));
	peopleCombo.AddString(TEXT("行政人员"));
	peopleCombo.AddString(TEXT("实验技术员"));
	peopleCombo.AddString(TEXT("教师兼职实验技术员"));
	peopleCombo.AddString(TEXT("行政人员兼职教师"));

	//设置默认选项
	peopleCombo.SetCurSel(0);
}
