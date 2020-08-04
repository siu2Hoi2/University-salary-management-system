// CPeopleEdit.cpp: 实现文件
//

#include "pch.h"
#include "SalaryAdminSystem.h"
#include "CPeopleEdit.h"
#include "CInfoFile.h"

// CPeopleEdit

IMPLEMENT_DYNCREATE(CPeopleEdit, CFormView)

CPeopleEdit::CPeopleEdit()
	: CFormView(IDD_EDIT)
	, editName(_T(""))
	, editID(_T(""))
	, editWork(_T(""))
	, editSalary(_T(""))
	, peopleInfo(_T(""))
{

}

CPeopleEdit::~CPeopleEdit()
{
}

void CPeopleEdit::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, peopleCombo);
	DDX_Text(pDX, IDC_EDIT1, editName);
	DDX_Text(pDX, IDC_EDIT2, editID);
	DDX_Text(pDX, IDC_EDIT14, editWork);
	DDX_Text(pDX, IDC_EDIT15, editSalary);
	DDX_Text(pDX, IDC_EDIT3, peopleInfo);
}

BEGIN_MESSAGE_MAP(CPeopleEdit, CFormView)
	ON_BN_CLICKED(IDC_BUTTON7, &CPeopleEdit::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CPeopleEdit::OnBnClickedButton8)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CPeopleEdit::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CPeopleEdit 诊断

#ifdef _DEBUG
void CPeopleEdit::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CPeopleEdit::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPeopleEdit 消息处理程序


void CPeopleEdit::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码

	//确认修改按钮
	int index = peopleCombo.GetCurSel();

	CString str;   //存放获取的下拉框内容
	peopleCombo.GetLBText(index, str);

	if (str == "教师")
	{
		UpdateData(TRUE);
		if (editName.IsEmpty() || editID.IsEmpty() || editWork.IsEmpty() || editSalary.IsEmpty())
		{
			MessageBox(TEXT("输入内容不能为空"), TEXT("错误"), MB_ICONWARNING);
			return;
		}

		CInfoFile file;
		string tempID = (CStringA)editID;  //CString转string
		string tempName = (CStringA)editName;
		int tempNums = atoi((CStringA)editWork);
		double tempSalary = atof((CStringA)editSalary);

		CString infoStr;
		file.ReadTeacher();

		list<Teacher>::iterator it = file.l_teach.begin();
		int count = 0;     //已遍历计数
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
				//修改信息
				it->work_hours = tempNums;    
				it->total_salary = tempSalary;

				infoStr.Format(_T("被修改者ID：%s \r\n被修改者姓名： %s \r\n修改后工作量： %d \r\n修改后工资： %0.2lf"),
					editID, editName, tempNums, tempSalary);
				peopleInfo = infoStr;
				UpdateData(FALSE);

				file.WriteTeacher();
				MessageBox(_T("修改成功！"));
				peopleInfo.Empty();   //清空信息框
				UpdateData(FALSE);

				break;
			}
		}

	}

	else if (str == "实验技术员")
	{
		UpdateData(TRUE);
		if (editName.IsEmpty() || editID.IsEmpty() || editWork.IsEmpty() || editSalary.IsEmpty())
		{
			MessageBox(TEXT("输入内容不能为空"), TEXT("错误"), MB_ICONWARNING);
			return;
		}

		CInfoFile file;
		string tempID = (CStringA)editID;  //CString转string
		string tempName = (CStringA)editName;
		int tempNums = atoi((CStringA)editWork);
		double tempSalary = atof((CStringA)editSalary);

		CString infoStr;
		file.ReadTech();
		list<Tech>::iterator it = file.l_tech.begin();
		int count = 0;     //已遍历计数
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
				//修改信息
				it->work_hours = tempNums;
				it->total_salary = tempSalary;

				infoStr.Format(_T("被修改者ID：%s \r\n被修改者姓名： %s \r\n修改后工作量： %d \r\n修改后工资： %0.2lf"),
					editID, editName, tempNums, tempSalary);
				peopleInfo = infoStr;
				UpdateData(FALSE);

				file.WriteTech();
				MessageBox(_T("修改成功！"));
				peopleInfo.Empty();   //清空信息框
				UpdateData(FALSE);

				break;
			}
		}
	}

	else if (str == "行政人员")
	{
		UpdateData(TRUE);
		if (editName.IsEmpty() || editID.IsEmpty() || editSalary.IsEmpty())
		{
			MessageBox(TEXT("输入内容不能为空"), TEXT("错误"), MB_ICONWARNING);
			return;
		}

		CInfoFile file;
		string tempID = (CStringA)editID;  //CString转string
		string tempName = (CStringA)editName;
		double tempSalary = atof((CStringA)editSalary);

		CString infoStr;
		file.ReadAdmin();
		list<Admin>::iterator it = file.l_admin.begin();
		int count = 0;     //已遍历计数
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
				//修改信息
				it->total_salary = tempSalary;

				infoStr.Format(_T("被修改者ID：%s \r\n被修改者姓名： %s  \r\n修改后工资： %0.2lf"),
					editID, editName, tempSalary);
				peopleInfo = infoStr;
				UpdateData(FALSE);

				file.WriteAdmin();
				MessageBox(_T("修改成功！"));
				peopleInfo.Empty();   //清空信息框
				UpdateData(FALSE);

				break;
			}
		}

    }

	else if (str == "教师兼职实验技术员")
	{
		UpdateData(TRUE);
		if (editName.IsEmpty() || editID.IsEmpty() || editWork.IsEmpty() || editSalary.IsEmpty())
		{
			MessageBox(TEXT("输入内容不能为空"), TEXT("错误"), MB_ICONWARNING);
			return;
		}

		CInfoFile file;
		string tempID = (CStringA)editID;  //CString转string
		string tempName = (CStringA)editName;
		int tempNums = atoi((CStringA)editWork);
		double tempSalary = atof((CStringA)editSalary);

		CString infoStr;
		file.ReadTeachAndTech();

		list<TeachAndTech>::iterator it = file.l_TAT.begin();
		int count = 0;     //已遍历计数
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
				//修改信息
				it->work_hours = tempNums;
				it->total_salary = tempSalary;

				infoStr.Format(_T("被修改者ID：%s \r\n被修改者姓名： %s \r\n修改后工作量： %d \r\n修改后工资： %0.2lf"),
					editID, editName, tempNums, tempSalary);
				peopleInfo = infoStr;
				UpdateData(FALSE);

				file.WriteTeachAndTech();
				MessageBox(_T("修改成功！"));
				peopleInfo.Empty();   //清空信息框
				UpdateData(FALSE);

				break;
			}
		}
    }

	else if (str == "行政人员兼职教师")
	{
		UpdateData(TRUE);
		if (editName.IsEmpty() || editID.IsEmpty() || editWork.IsEmpty() || editSalary.IsEmpty())
		{
			MessageBox(TEXT("输入内容不能为空"), TEXT("错误"), MB_ICONWARNING);
			return;
		}

		CInfoFile file;
		string tempID = (CStringA)editID;  //CString转string
		string tempName = (CStringA)editName;
		int tempNums = atoi((CStringA)editWork);
		double tempSalary = atof((CStringA)editSalary);

		CString infoStr;
		file.ReadAdminAndTeach();

		list<AdminAndTeach>::iterator it = file.l_AAT.begin();
		int count = 0;     //已遍历计数
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
				//修改信息
				it->num_class = tempNums;
				it->total_salary = tempSalary;

				infoStr.Format(_T("被修改者ID：%s \r\n被修改者姓名： %s \r\n修改后节次： %d \r\n修改后工资： %0.2lf"),
					editID, editName, tempNums, tempSalary);
				peopleInfo = infoStr;
				UpdateData(FALSE);

				file.WriteAdminAndTeach();
				MessageBox(_T("修改成功！"));
				peopleInfo.Empty();   //清空信息框
				UpdateData(FALSE);

				break;
			}
		}
	}
	
}


void CPeopleEdit::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码

	//清空确认修改信息
	UpdateData(TRUE);

	editID.Empty();
	editName.Empty();
	editSalary.Empty();
	editWork.Empty();

	UpdateData(FALSE);  //显示控件
}


void CPeopleEdit::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码

	//修改下拉框内容后的操作
	//获取下拉框内容
	int index = peopleCombo.GetCurSel();

	CString str;   //存放获取的下拉框内容
	peopleCombo.GetLBText(index, str);

	if (str == "行政人员")
	{
		UpdateData(TRUE);
		editWork.Empty();       //清空输入框
		UpdateData(FALSE);

		CEdit* pEditUser = NULL;
		pEditUser = (CEdit*)GetDlgItem(IDC_EDIT14); //获取文本框指针
		pEditUser->SetReadOnly(TRUE);               //设置为不可读状态
	}
	else
	{
		CEdit* pEditUser = NULL;
		pEditUser = (CEdit*)GetDlgItem(IDC_EDIT14); //获取文本框指针
		pEditUser->SetReadOnly(FALSE);               //设置为不可读状态
	}

}


void CPeopleEdit::OnInitialUpdate()
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
