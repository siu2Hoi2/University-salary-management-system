// CSelectView.cpp: 实现文件
//

#include "pch.h"
#include "SalaryAdminSystem.h"
#include "CSelectView.h"
#include "MainFrm.h"

// CSelectView

IMPLEMENT_DYNCREATE(CSelectView, CTreeView)

CSelectView::CSelectView()
{

}

CSelectView::~CSelectView()
{
}

BEGIN_MESSAGE_MAP(CSelectView, CTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CSelectView::OnTvnSelchanged)
END_MESSAGE_MAP()


// CSelectView 诊断

#ifdef _DEBUG
void CSelectView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CSelectView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSelectView 消息处理程序


void CSelectView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();


	//初始化 树视图
	//获取树控件
	m_treeCtrl = &GetTreeCtrl();

	//设置树控件的风格
	m_treeCtrl->ModifyStyle(NULL, TVS_SHOWSELALWAYS);
	m_treeCtrl->ModifyStyle(NULL, TVS_HASBUTTONS);
	m_treeCtrl->ModifyStyle(NULL, TVS_HASLINES);
	m_treeCtrl->ModifyStyle(NULL, TVS_LINESATROOT);

	//图片集合
	HICON icon = AfxGetApp()->LoadIconW(IDI_EDIT);

	m_imageList.Create(25, 25, ILC_COLOR32, 1, 1);
	m_imageList.Add(icon);

	m_treeCtrl->SetImageList(&m_imageList, TVSIL_NORMAL);


	//添加节点
	HTREEITEM root=m_treeCtrl->InsertItem(TEXT("管理员信息"), 0, 0, NULL);
	HTREEITEM peopleEdit=m_treeCtrl->InsertItem(TEXT("人员管理"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("添加"),0, 0, peopleEdit);
	m_treeCtrl->InsertItem(TEXT("修改"), 0, 0, peopleEdit);
	m_treeCtrl->InsertItem(TEXT("查询"), 0, 0, peopleEdit);
	m_treeCtrl->InsertItem(TEXT("删除"), 0, 0, peopleEdit);
	

	HTREEITEM detailInfo= m_treeCtrl->InsertItem(TEXT("信息汇总"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("教师"), 0, 0, detailInfo);
	m_treeCtrl->InsertItem(TEXT("行政人员"), 0, 0, detailInfo);
	m_treeCtrl->InsertItem(TEXT("实验技术员"), 0, 0, detailInfo);
	m_treeCtrl->InsertItem(TEXT("教师兼职实验室技术员"), 0, 0, detailInfo);
	m_treeCtrl->InsertItem(TEXT("行政人员兼职教师"), 0, 0, detailInfo);

	//初始化展开节点
	m_treeCtrl->Expand(peopleEdit, TVE_EXPAND);
	m_treeCtrl->Expand(detailInfo, TVE_EXPAND);


	// TODO: 在此添加专用代码和/或调用基类
}


void CSelectView::OnTvnSelchanged(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;



	//获取当前选中项

	HTREEITEM  item = m_treeCtrl->GetSelectedItem();
	CString str = m_treeCtrl->GetItemText(item);

	if (str == TEXT("管理员信息"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WU_A, (WPARAM)WU_A, (LPARAM)0);
	}
	else if (str == TEXT("教师"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WU_B, (WPARAM)WU_B, (LPARAM)0);
	}
	else if (str == TEXT("行政人员"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WU_C, (WPARAM)WU_C, (LPARAM)0);
	}
	else if (str == TEXT("实验技术员"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WU_D, (WPARAM)WU_D, (LPARAM)0);
	}
	else if (str == TEXT("教师兼职实验室技术员"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WU_E, (WPARAM)WU_E, (LPARAM)0);
	}
	else if (str == TEXT("行政人员兼职教师"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WU_F, (WPARAM)WU_F, (LPARAM)0);
	}
	else if (str == TEXT("添加"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WU_ADD, (WPARAM)WU_ADD, (LPARAM)0);
	}
	else if (str == "修改")
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WU_EDIT, (WPARAM)WU_EDIT, (LPARAM)0);
	}
	else if (str == "查询")
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WU_LOOK, (WPARAM)WU_LOOK, (LPARAM)0);
	}
	else if (str == "删除")
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WU_DELE, (WPARAM)WU_DELE, (LPARAM)0);
	}
}
