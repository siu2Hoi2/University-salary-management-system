// CAdminTeacherInfo.cpp: 实现文件
//

#include "pch.h"
#include "SalaryAdminSystem.h"
#include "CAdminTeacherInfo.h"
#include "CInfoFile.h"


// CAdminTeacherInfo

IMPLEMENT_DYNCREATE(CAdminTeacherInfo, CFormView)

CAdminTeacherInfo::CAdminTeacherInfo()
	: CFormView(ADMIN_TEACHER_INFO)
{

}

CAdminTeacherInfo::~CAdminTeacherInfo()
{
}

void CAdminTeacherInfo::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, adminTeacherList);
}

BEGIN_MESSAGE_MAP(CAdminTeacherInfo, CFormView)
END_MESSAGE_MAP()


// CAdminTeacherInfo 诊断

#ifdef _DEBUG
void CAdminTeacherInfo::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CAdminTeacherInfo::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CAdminTeacherInfo 消息处理程序


void CAdminTeacherInfo::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	UpdateData(TRUE); ///同步对文件的修改

	//添加列表控件
	int k = 0;
	CString str[] = { TEXT("ID"),TEXT("姓名"),TEXT("节次"),TEXT("工资") };
	for (int i = 0; i < 4; i++)
	{
		//设置表头  参数1索引 2字符 3对齐方式  4宽度
		adminTeacherList.InsertColumn(i, str[i], LVCFMT_LEFT, 150);
	}

	CInfoFile file;
	file.ReadAdminAndTeach();
	list<AdminAndTeach>::iterator it = file.l_AAT.begin();

	it++;   ///去掉第一个标识符数据

	//设置正文
	k = file.l_AAT.size() - 1;  //去掉第一行标识符数据

	//通过迭代器以列表形式依次打印
	for (int i = 0; i < k; i++)
	{
		CString strTemp;

		adminTeacherList.InsertItem(i, (CString)it->id.c_str());
		adminTeacherList.SetItemText(i, 1, (CString)it->name.c_str());

		strTemp.Format(TEXT("%d"), it->num_class);
		adminTeacherList.SetItemText(i, 2, strTemp);

		strTemp.Format(TEXT("%0.2lf"), it->total_salary);
		adminTeacherList.SetItemText(i, 3, strTemp);

		it++;
	}

	//设置属性 整行选中  显示网格
	adminTeacherList.SetExtendedStyle(adminTeacherList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	UpdateData(FALSE);  ///同步对文件的修改
}
