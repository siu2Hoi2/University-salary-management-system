// CTeacherTechInfo.cpp: 实现文件
//

#include "pch.h"
#include "SalaryAdminSystem.h"
#include "CTeacherTechInfo.h"
#include "CInfoFile.h"


// CTeacherTechInfo

IMPLEMENT_DYNCREATE(CTeacherTechInfo, CFormView)

CTeacherTechInfo::CTeacherTechInfo()
	: CFormView(TEACHER_TECH_INFO)
{

}

CTeacherTechInfo::~CTeacherTechInfo()
{
}

void CTeacherTechInfo::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, teacherTechList);
}

BEGIN_MESSAGE_MAP(CTeacherTechInfo, CFormView)
END_MESSAGE_MAP()


// CTeacherTechInfo 诊断

#ifdef _DEBUG
void CTeacherTechInfo::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CTeacherTechInfo::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CTeacherTechInfo 消息处理程序


void CTeacherTechInfo::OnInitialUpdate()
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
		teacherTechList.InsertColumn(i, str[i], LVCFMT_LEFT, 150);
	}

	CInfoFile file;
	file.ReadTeachAndTech();
	list<TeachAndTech>::iterator it = file.l_TAT.begin();

	it++;   //去掉第一个标识符数据

	//设置正文
	k = file.l_TAT.size() - 1;
	//通过迭代器以列表形式依次打印
	for (int i = 0; i < k; i++)
	{
		CString strTemp;

		teacherTechList.InsertItem(i, (CString)it->id.c_str());
		teacherTechList.SetItemText(i, 1, (CString)it->name.c_str());

		strTemp.Format(TEXT("%d"), it->work_hours);
		teacherTechList.SetItemText(i, 2, strTemp);

		strTemp.Format(TEXT("%0.2lf"), it->total_salary);
		teacherTechList.SetItemText(i, 3, strTemp);

		it++;
	}

	//设置属性 整行选中  显示网格
	teacherTechList.SetExtendedStyle(teacherTechList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	UpdateData(FALSE);  //同步对文件的修改
}
