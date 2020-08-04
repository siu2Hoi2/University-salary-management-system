// CAdminInfo.cpp: 实现文件
//

#include "pch.h"
#include "SalaryAdminSystem.h"
#include "CAdminInfo.h"
#include "CInfoFile.h"


// CAdminInfo

IMPLEMENT_DYNCREATE(CAdminInfo, CFormView)

CAdminInfo::CAdminInfo()
	: CFormView(ADMIN_INFO)
{

}

CAdminInfo::~CAdminInfo()
{
}

void CAdminInfo::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, adminList);
}

BEGIN_MESSAGE_MAP(CAdminInfo, CFormView)
END_MESSAGE_MAP()


// CAdminInfo 诊断

#ifdef _DEBUG
void CAdminInfo::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CAdminInfo::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CAdminInfo 消息处理程序


void CAdminInfo::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	UpdateData(TRUE); ///同步对文件的修改

	//添加列表控件
	int k = 0;
	CString str[] = { TEXT("ID"),TEXT("姓名"),TEXT("工资") };
	for (int i = 0; i < 3; i++)
	{
		//设置表头  参数1索引 2字符 3对齐方式  4宽度
		adminList.InsertColumn(i, str[i], LVCFMT_LEFT, 150);
	}

	CInfoFile file;
	file.ReadAdmin();
	list<Admin>::iterator it = file.l_admin.begin();

	it++;   ///去掉第一个标识符数据

	//设置正文
	k = file.l_admin.size() - 1;  //去掉第一行标识符数据

	//通过迭代器以列表形式依次打印
	for (int i = 0; i < k; i++)
	{
		CString strTemp;

		adminList.InsertItem(i, (CString)it->id.c_str());
		adminList.SetItemText(i, 1, (CString)it->name.c_str());

		strTemp.Format(TEXT("%0.2lf"), it->total_salary);
		adminList.SetItemText(i, 2, strTemp);

		it++;
	}

	//设置属性 整行选中  显示网格
	adminList.SetExtendedStyle(adminList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	UpdateData(FALSE);  ///同步对文件的修改
}
