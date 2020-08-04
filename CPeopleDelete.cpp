// CPeopleDelete.cpp: 实现文件
//

#include "pch.h"
#include "SalaryAdminSystem.h"
#include "CPeopleDelete.h"
#include "CInfoFile.h"


IMPLEMENT_DYNCREATE(CPeopleDelete, CFormView)

CPeopleDelete::CPeopleDelete()
	: CFormView(IDD_DELETE)
	, deleteName(_T(""))
	, deleteID(_T(""))
	, peopleInfo(_T(""))
{

}

CPeopleDelete::~CPeopleDelete()
{
}

void CPeopleDelete::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, peopleCombo);
	DDX_Text(pDX, IDC_EDIT1, deleteName);
	DDX_Text(pDX, IDC_EDIT2, deleteID);
	DDX_Text(pDX, IDC_EDIT3, peopleInfo);
}

BEGIN_MESSAGE_MAP(CPeopleDelete, CFormView)
	ON_BN_CLICKED(IDC_BUTTON2, &CPeopleDelete::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON9, &CPeopleDelete::OnBnClickedButton9)
END_MESSAGE_MAP()


// CPeopleDelete 诊断

#ifdef _DEBUG
void CPeopleDelete::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CPeopleDelete::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPeopleDelete 消息处理程序


void CPeopleDelete::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	///删除信息
	int index = peopleCombo.GetCurSel();

	CString str;   //存放获取的下拉框内容
	peopleCombo.GetLBText(index, str);

	if (str == "教师")
	{
		UpdateData(TRUE);
		if (deleteName.IsEmpty() || deleteID.IsEmpty())
		{
			MessageBox(TEXT("输入内容不能为空"), TEXT("错误"), MB_ICONWARNING);
			return;
		}

		CInfoFile file;
		string tempID = (CStringA)deleteID;
		string tempName = (CStringA)deleteName;
		CString infoStr;
		file.ReadTeacher();

		list<Teacher>::iterator it = file.l_teach.begin();

		int count = 0;   //已遍历计数
		for (it = file.l_teach.begin(); it != file.l_teach.end(); it++)
		{
			if (it->id != tempID || it->name != tempName)
			{
				count++;  //已遍历计数器
				if (count == file.l_teach.size())
				{
					MessageBox(_T("没有找到相关信息！"), TEXT("错误"), MB_ICONWARNING);
					break;
				}
			}

			else if (it->id == tempID && it->name == tempName)
			{
				int result = MessageBox(TEXT("确定要删除吗？删除后将无法恢复"), TEXT("询问"), MB_YESNO);
				if (result == IDYES)
				{
					infoStr.Format(_T("ID(已删除)：%s \r\n姓名(已删除)： %s \r\n工作量： %d \r\n工资： %0.2lf"),
						deleteID, deleteName, it->work_hours, it->total_salary);
					peopleInfo = infoStr;
					UpdateData(FALSE);
					
					it = file.l_teach.erase(it);  //通过迭代器删除元素
					file.WriteTeacher();          //同步到文件中
					MessageBox(_T("删除成功！"));

					peopleInfo.Empty();    //清空信息
					deleteName.Empty();
					deleteID.Empty();
					UpdateData(FALSE);
					
					break;
				}
				//如果为否则跳出循环
				else if (result == IDNO)
				{
					break;
				}
			}
			
		}

	}

	else if (str == "行政人员")
	{
		UpdateData(TRUE);
		if (deleteName.IsEmpty() || deleteID.IsEmpty())
		{
			MessageBox(TEXT("输入内容不能为空"), TEXT("错误"), MB_ICONWARNING);
			return;
		}

		CInfoFile file;
		string tempID = (CStringA)deleteID;
		string tempName = (CStringA)deleteName;
		CString infoStr;
		file.ReadAdmin();

		list<Admin>::iterator it = file.l_admin.begin();

		int count = 0;   //已遍历计数器
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
				int result = MessageBox(TEXT("确定要删除吗？删除后将无法恢复"), TEXT("询问"), MB_YESNO);
				if (result == IDYES)
				{
					infoStr.Format(_T("ID(已删除)：%s \r\n姓名(已删除)： %s  \r\n工资： %0.2lf"),
						deleteID, deleteName, it->total_salary);
					peopleInfo = infoStr;
					UpdateData(FALSE);

					it = file.l_admin.erase(it);  //通过迭代器删除元素
					file.WriteAdmin();          //同步到文件中
					MessageBox(_T("删除成功！"));

					peopleInfo.Empty();    //清空信息
					deleteName.Empty();
					deleteID.Empty();
					UpdateData(FALSE);

					break;
				}
				//如果为否则跳出循环
				else if (result == IDNO)
				{
					break;
				}
			}

		}
	}

	else if (str == "实验技术员")
	{
		UpdateData(TRUE);
		if (deleteName.IsEmpty() || deleteID.IsEmpty())
		{
			MessageBox(TEXT("输入内容不能为空"), TEXT("错误"), MB_ICONWARNING);
			return;
		}

		CInfoFile file;
		string tempID = (CStringA)deleteID;
		string tempName = (CStringA)deleteName;
		CString infoStr;
		file.ReadTech();

		list<Tech>::iterator it = file.l_tech.begin();

		int count = 0;   //已遍历计数器
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
				int result = MessageBox(TEXT("确定要删除吗？删除后将无法恢复"), TEXT("询问"), MB_YESNO);
				if (result == IDYES)
				{
					infoStr.Format(_T("ID(已删除)：%s \r\n姓名(已删除)： %s \r\n工作量： %d \r\n工资： %0.2lf"),
						deleteID, deleteName, it->work_hours, it->total_salary);
					peopleInfo = infoStr;
					UpdateData(FALSE);

					it = file.l_tech.erase(it);  //通过迭代器删除元素
					file.WriteTech();          //同步到文件中
					MessageBox(_T("删除成功！"));

					peopleInfo.Empty();    //清空信息
					deleteName.Empty();
					deleteID.Empty();
					UpdateData(FALSE);

					break;
				}
				//如果为否则跳出循环
				else if (result == IDNO)
				{
					break;
				}
			}

		}
    }

	else if (str == "教师兼职实验技术员")
	{
		UpdateData(TRUE);
		if (deleteName.IsEmpty() || deleteID.IsEmpty())
		{
			MessageBox(TEXT("输入内容不能为空"), TEXT("错误"), MB_ICONWARNING);
			return;
		}

		CInfoFile file;
		string tempID = (CStringA)deleteID;
		string tempName = (CStringA)deleteName;
		CString infoStr;
		file.ReadTeachAndTech();

		list<TeachAndTech>::iterator it = file.l_TAT.begin();

		int count = 0;   //已遍历计数器
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
				int result = MessageBox(TEXT("确定要删除吗？删除后将无法恢复"), TEXT("询问"), MB_YESNO);
				if (result == IDYES)
				{
					infoStr.Format(_T("ID(已删除)：%s \r\n姓名(已删除)： %s \r\n工作量： %d \r\n工资： %0.2lf"),
						deleteID, deleteName, it->work_hours, it->total_salary);
					peopleInfo = infoStr;
					UpdateData(FALSE);

					it = file.l_TAT.erase(it);  //通过迭代器删除元素
					file.WriteTeachAndTech();          //同步到文件中
					MessageBox(_T("删除成功！"));

					peopleInfo.Empty();    //清空信息
					deleteName.Empty();
					deleteID.Empty();
					UpdateData(FALSE);

					break;
				}
				//如果为否则跳出循环
				else if (result == IDNO)
				{
					break;
				}
			}

		}
    }

	else if (str == "行政人员兼职教师")
	{
		UpdateData(TRUE);
		if (deleteName.IsEmpty() || deleteID.IsEmpty())
		{
			MessageBox(TEXT("输入内容不能为空"), TEXT("错误"), MB_ICONWARNING);
			return;
		}

		CInfoFile file;
		string tempID = (CStringA)deleteID;
		string tempName = (CStringA)deleteName;
		CString infoStr;
		file.ReadAdminAndTeach();

		list<AdminAndTeach>::iterator it = file.l_AAT.begin();

		int count = 0;   //已遍历计数器
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
				int result = MessageBox(TEXT("确定要删除吗？删除后将无法恢复"), TEXT("询问"), MB_YESNO);
				if (result == IDYES)
				{
					infoStr.Format(_T("ID(已删除)：%s \r\n姓名(已删除)： %s \r\n节次： %d \r\n工资： %0.2lf"),
						deleteID, deleteName, it->num_class, it->total_salary);
					peopleInfo = infoStr;
					UpdateData(FALSE);

					it = file.l_AAT.erase(it);  //通过迭代器删除元素
					file.WriteAdminAndTeach();          //同步到文件中
					MessageBox(_T("删除成功！"));

					peopleInfo.Empty();    //清空信息
					deleteName.Empty();
					deleteID.Empty();
					UpdateData(FALSE);

					break;
				}
				//如果为否则跳出循环
				else if (result == IDNO)
				{
					break;
				}
			}

		}
    }
}


void CPeopleDelete::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码

	//清空删除信息
	UpdateData(TRUE);

	deleteName.Empty();
	deleteID.Empty();
	peopleInfo.Empty();

	UpdateData(FALSE);  //显示控件
}


void CPeopleDelete::OnInitialUpdate()
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
