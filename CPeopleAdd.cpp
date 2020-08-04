// CPeopleAdd.cpp: 实现文件

#include "pch.h"
#include "SalaryAdminSystem.h"
#include "CPeopleAdd.h"
#include "CInfoFile.h"

// CPeopleAdd

IMPLEMENT_DYNCREATE(CPeopleAdd, CFormView)

CPeopleAdd::CPeopleAdd()
	: CFormView(IDD_ADD)
	, peopleInfo(_T(""))
	, addName(_T(""))
	, addID(_T(""))
	, addWork(_T(""))
{

}

CPeopleAdd::~CPeopleAdd()
{
}

void CPeopleAdd::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, peopleInfo);
	DDX_Control(pDX, IDC_COMBO1, peopleCombo);
	DDX_Text(pDX, IDC_EDIT1, addName);
	DDX_Text(pDX, IDC_EDIT2, addID);
	DDX_Text(pDX, IDC_EDIT14, addWork);
}

BEGIN_MESSAGE_MAP(CPeopleAdd, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CPeopleAdd::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON2, &CPeopleAdd::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON9, &CPeopleAdd::OnBnClickedButton9)
END_MESSAGE_MAP()


// CPeopleAdd 诊断

#ifdef _DEBUG
void CPeopleAdd::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CPeopleAdd::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPeopleAdd 消息处理程序


void CPeopleAdd::OnInitialUpdate()
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


void CPeopleAdd::OnCbnSelchangeCombo1()
{
	//TODO: 在此添加控件通知处理程序代码

	//修改下拉框内容后的操作
	//获取下拉框内容
	int index = peopleCombo.GetCurSel();
	
	CString str;   //存放获取的下拉框内容
	peopleCombo.GetLBText(index, str);
	
	if (str == "行政人员")
	{
		UpdateData(TRUE);
		addWork.Empty();    //清空输入框
		UpdateData(FALSE);

		CEdit* pEditUser = NULL;
		pEditUser = (CEdit*)GetDlgItem(IDC_EDIT14); //获取文本框指针
		pEditUser->SetReadOnly(TRUE);               //设置为不可读状态
	}
	else
	{
		CEdit* pEditUser = NULL;
		pEditUser = (CEdit*)GetDlgItem(IDC_EDIT14); //获取文本框指针
		pEditUser->SetReadOnly(FALSE);              //设置为不可读状态
	}
}


void CPeopleAdd::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = peopleCombo.GetCurSel();

	CString str;   //存放获取的下拉框内容
	peopleCombo.GetLBText(index, str);

	//录入教师
	if (str == "教师")
	{
		UpdateData(TRUE);
		if (addName.IsEmpty() || addWork.IsEmpty() || addID.IsEmpty())
		{
			MessageBox(TEXT("输入内容不能为空"), TEXT("错误"), MB_ICONWARNING);
			return;
		}

		CStringA num;  //CString转CStringA
		num = addWork;
		CInfoFile file;
		CString infoStr;
		file.ReadTeacher();  //读入文件内容
		list<Teacher>::iterator it = file.l_teach.begin();   //获取链表的最后一个元素 
		
        for (it = file.l_teach.begin(); it != file.l_teach.end(); it++)  //判断是否重复输入
		{
			if (it->id == (string)(CStringA)addID || it->name == (string)(CStringA)addName)
			{
				infoStr.Format(TEXT(" ID： %s \r\n 姓名： %s \r\n %s"), addID, addName,TEXT("ID或姓名已存在！请核实后输入！"));
				MessageBox(infoStr,MB_OK);
				return;
			}
		}

		while (it != file.l_teach.end()) { it++; }            //迭代器移动至表尾的下一位置

		file.AddTeacher(addName, addID, atoi(num.GetBuffer()));  //添加信息到链表中
		file.WriteTeacher();    //写入信息到文件中

		double salaryTemp = (1000.0 + (atoi(num.GetBuffer()) - 180.0) * 20);  //计算工资并缓存以待打印
		if (salaryTemp >= 0)
		{
			infoStr.Format(_T("ID：%s \r\n姓名： %s \r\n工作量： %d \r\n工资： %0.2lf"),  //详细信息赋值到infoStr
				addID, addName, atoi(num.GetBuffer()), salaryTemp);
		}

		else
		{
			infoStr.Format(_T("ID：%s \r\n姓名： %s \r\n工作量： %d \r\n工资： %0.2lf"),  //详细信息赋值到infoStr
				addID, addName, atoi(num.GetBuffer()), 0.0);
		}

		peopleInfo = infoStr;  //infoStr赋值到控件中
		UpdateData(FALSE);     //显示控件
	}

	//录入行政人员
	else if (str == "行政人员")
	{
		UpdateData(TRUE);
		if (addName.IsEmpty() || addID.IsEmpty())
		{
			MessageBox(TEXT("输入内容不能为空"), TEXT("错误"), MB_ICONWARNING);
			return;
		}

		CInfoFile file;
		file.ReadAdmin();
		CString infoStr;
		list<Admin>::iterator it = file.l_admin.begin();   //获取链表的最后一个元素 

		for (it = file.l_admin.begin(); it != file.l_admin.end(); it++)  //查找是否重复输入
		{
			if (it->id == (string)(CStringA)addID || it->name == (string)(CStringA)addName)
			{
				infoStr.Format(TEXT(" ID： %s \r\n 姓名： %s \r\n %s"), addID, addName, TEXT("ID或姓名已存在！请核实后输入！"));
				MessageBox(infoStr, MB_OK);
				return;
			}
		}

		while (it != file.l_admin.end()) { it++; }            //迭代器移动至表尾的下一位置

		file.AddAdmin(addName, addID);   //添加到链表
		file.WriteAdmin();    //写入信息到文件中

		infoStr.Format(_T("ID：%s \r\n姓名： %s \r\n工资： %0.2lf"),
		           addID, addName, 950.0+280.0);
		
		peopleInfo = infoStr;  //infoStr赋值到控件中
		UpdateData(FALSE);	   //显示控件
	}

	//录入实验技术员
	else if (str == "实验技术员")
	{
		UpdateData(TRUE);
		if (addName.IsEmpty() || addWork.IsEmpty() || addID.IsEmpty())
		{
			MessageBox(TEXT("输入内容不能为空"), TEXT("错误"), MB_ICONWARNING);
			return;
		}

		CStringA num;
		CInfoFile file;
		file.ReadTech();
		CString infoStr;
		num = addWork;
		list<Tech>::iterator it = file.l_tech.begin();   //获取链表的最后一个元素 

		for (it = file.l_tech.begin(); it != file.l_tech.end(); it++)  //查找是否重复输入
		{
			if (it->id == (string)(CStringA)addID || it->name == (string)(CStringA)addName)
			{
				infoStr.Format(TEXT(" ID： %s \r\n 姓名： %s \r\n %s"), addID, addName, TEXT("ID或姓名已存在！请核实后输入！"));
				MessageBox(infoStr, MB_OK);
				return;
			}
		}

		while (it != file.l_tech.end()) { it++; }        //迭代器移动至表尾的下一位置

		file.AddTech(addName, addID, atoi(num.GetBuffer()));  //添加到链表
		file.WriteTech();    //写入信息到文件中

		 //计算工资并缓存以待打印
		double salaryTemp = (850.0 + 180 + (atoi(num.GetBuffer()) - 100.0) * 20); 
		if (salaryTemp >= 0)
		{
			infoStr.Format(_T("ID：%s \r\n姓名： %s \r\n工作量： %d \r\n工资： %0.2lf"),
				addID, addName, atoi(num.GetBuffer()), salaryTemp);
		}

		else
		{
			infoStr.Format(_T("ID：%s \r\n姓名： %s \r\n工作量： %d \r\n工资： %0.2lf"),
				addID, addName, atoi(num.GetBuffer()), 0.0);
		}

		peopleInfo = infoStr;  //infoStr赋值到控件中
		UpdateData(FALSE);	   //显示控件
	}


	//录入教师兼职实验技术员
	else if (str == "教师兼职实验技术员")
	{
		UpdateData(TRUE);
		if (addName.IsEmpty() || addWork.IsEmpty() || addID.IsEmpty())
		{
			MessageBox(TEXT("输入内容不能为空"), TEXT("错误"), MB_ICONWARNING);
			return;
		}

		CStringA num;
		CInfoFile file;
		file.ReadTeachAndTech();
		CString infoStr;
		num = addWork;
		list<TeachAndTech>::iterator it = file.l_TAT.begin();   //获取链表的最后一个元素 

		for (it = file.l_TAT.begin(); it != file.l_TAT.end(); it++)  //查找是否重复输入
		{
			if (it->id == (string)(CStringA)addID || it->name == (string)(CStringA)addName)
			{
				infoStr.Format(TEXT(" ID： %s \r\n 姓名： %s \r\n %s"), addID, addName, TEXT("ID或姓名已存在！请核实后输入！"));
				MessageBox(infoStr, MB_OK);
				return;
			}
		}

		while (it != file.l_TAT.end()) { it++; }            //迭代器移动至表尾的下一位置

		file.AddTeachAndTech(addName, addID, atoi(num.GetBuffer())); //添加到链表
		file.WriteTeachAndTech();    //写入信息到文件中

		//计算工资并缓存以待打印
		double salaryTemp = (1000.0 + 850.0 + 180.0 + (atoi(num.GetBuffer()) - 180.0 - 100.0) * 20);
		if (salaryTemp >= 0)
		{
			infoStr.Format(_T("ID：%s \r\n姓名： %s \r\n工作量： %d \r\n工资： %0.2lf"),
				addID, addName, atoi(num.GetBuffer()), salaryTemp);
		}

		else
		{
			infoStr.Format(_T("ID：%s \r\n姓名： %s \r\n工作量： %d \r\n工资： %0.2lf"),
				addID, addName, atoi(num.GetBuffer()), 0.0);
		}

		peopleInfo = infoStr;   //infoStr赋值到控件中
		UpdateData(FALSE);		//显示控件
    }

	//录入行政人员兼职教师
	else if (str == "行政人员兼职教师")
	{
		UpdateData(TRUE);
		if (addName.IsEmpty() || addID.IsEmpty()||addWork.IsEmpty())
		{
			MessageBox(TEXT("输入内容不能为空"), TEXT("错误"), MB_ICONWARNING);
			return;
		}

		CStringA num;
		CInfoFile file;
		file.ReadAdminAndTeach();
		CString infoStr;
		num = addWork;
		list<AdminAndTeach>::iterator it = file.l_AAT.begin();   //获取链表的最后一个元素 

		for (it = file.l_AAT.begin(); it != file.l_AAT.end(); it++)  //查找是否重复输入
		{
			if (it->id == (string)(CStringA)addID || it->name == (string)(CStringA)addName)
			{
				infoStr.Format(TEXT(" ID： %s \r\n 姓名： %s \r\n %s"), addID, addName, TEXT("ID或姓名已存在！请核实后输入！"));
				MessageBox(infoStr, MB_OK);
				return;
			}
		}

		while (it != file.l_AAT.end()) { it++; }            //迭代器移动至表尾的下一位置

		file.AddAdminAndTeach(addName, addID,atoi(num.GetBuffer()));  //添加到链表
		file.WriteAdminAndTeach();    //写入信息到文件中

		infoStr.Format(_T("ID：%s \r\n姓名： %s \r\n节次：%d \r\n工资： %0.2lf"),
			addID, addName, atoi(num.GetBuffer()), 950.0 + 280.0 + 35 * atoi(num.GetBuffer()));

		peopleInfo = infoStr;   //infoStr赋值到控件中
		UpdateData(FALSE);		//显示控件
    }
}//录入函数体结束


void CPeopleAdd::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	//清空信息
	UpdateData(TRUE);

	addID.Empty();
	addName.Empty();
	addWork.Empty();
	peopleInfo.Empty();

	UpdateData(FALSE);  //显示控件
}
