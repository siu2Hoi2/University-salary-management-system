// CTechInfo.cpp: 实现文件
//

#include "pch.h"
#include "SalaryAdminSystem.h"
#include "CTechInfo.h"
#include  "CInfoFile.h"

// CTechInfo

IMPLEMENT_DYNCREATE(CTechInfo, CFormView)

CTechInfo::CTechInfo()
	: CFormView(TECH_INFO)
{

}

CTechInfo::~CTechInfo()
{
}

void CTechInfo::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, techList);
}

BEGIN_MESSAGE_MAP(CTechInfo, CFormView)
END_MESSAGE_MAP()


// CTechInfo 诊断

#ifdef _DEBUG
void CTechInfo::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CTechInfo::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CTechInfo 消息处理程序


void CTechInfo::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	UpdateData(TRUE); //同步对文件的修改

	//添加列表控件
	int k = 0;
	CString str[] = { TEXT("ID"),TEXT("姓名"),TEXT("工作时"),TEXT("工资") };
	for (int i = 0; i < 4; i++)
	{
		//设置表头  参数1索引 2字符 3对齐方式  4宽度
		techList.InsertColumn(i, str[i], LVCFMT_LEFT, 150);
	}

	CInfoFile file;
	file.ReadTech();
	list<Tech>::iterator it = file.l_tech.begin();

	it++;   //去掉第一个标识符数据

	//设置正文
	k = file.l_tech.size() - 1;
	//通过迭代器以列表形式依次打印
	for (int i = 0; i < k; i++)
	{
		CString strTemp;

		techList.InsertItem(i, (CString)it->id.c_str());
		techList.SetItemText(i, 1, (CString)it->name.c_str());

		strTemp.Format(TEXT("%d"), it->work_hours);
		techList.SetItemText(i, 2, strTemp);

		strTemp.Format(TEXT("%0.2lf"), it->total_salary);
		techList.SetItemText(i, 3, strTemp);

		it++;
	}

	//设置属性 整行选中  显示网格
	techList.SetExtendedStyle(techList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	UpdateData(FALSE);  //同步对文件的修改
}
