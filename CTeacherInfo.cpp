// CTeacherInfo.cpp: 实现文件
//

#include "pch.h"
#include "SalaryAdminSystem.h"
#include "CTeacherInfo.h"
#include "CInfoFile.h"

// CTeacherInfo

IMPLEMENT_DYNCREATE(CTeacherInfo, CFormView)

CTeacherInfo::CTeacherInfo()
	: CFormView(TEACHER_INFO)
{

}

CTeacherInfo::~CTeacherInfo()
{
}

void CTeacherInfo::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, teacherList);
}

BEGIN_MESSAGE_MAP(CTeacherInfo, CFormView)
END_MESSAGE_MAP()


// CTeacherInfo 诊断

#ifdef _DEBUG
void CTeacherInfo::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CTeacherInfo::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CTeacherInfo 消息处理程序


void CTeacherInfo::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	UpdateData(TRUE); //同步对文件的修改
	
	//添加列表控件
	int k = 0;
	CString str[] = { TEXT("ID"),TEXT("姓名"),TEXT("课时"),TEXT("工资") };
	for (int i = 0; i < 4; i++)
	{
		//设置表头  参数1索引 2字符 3对齐方式  4宽度
		teacherList.InsertColumn(i, str[i], LVCFMT_LEFT, 150);
	}

	CInfoFile file;
	file.ReadTeacher();
	list<Teacher>::iterator it = file.l_teach.begin();

	it++;   //去掉第一个标识符数据

	//设置正文
	k = file.l_teach.size() - 1;
	
	for (int i = 0; i < k; i++)
	{
		CString strTemp;
		
		teacherList.InsertItem(i, (CString)it->id.c_str());
		teacherList.SetItemText(i, 1, (CString)it->name.c_str());
		
		strTemp.Format(TEXT("%d"), it->work_hours);
		teacherList.SetItemText(i, 2, strTemp);
		
		strTemp.Format(TEXT("%0.2lf"), it->total_salary);
		teacherList.SetItemText(i, 3, strTemp);
		
		it++;
	}

	//设置属性 整行选中  显示网格
	teacherList.SetExtendedStyle(teacherList.GetExtendedStyle()|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	UpdateData(FALSE);  //同步对文件的修改
}
