
// MainFrm.cpp: CMainFrame 类的实现
//

#include "pch.h"
#include "framework.h"
#include "SalaryAdminSystem.h"

#include "MainFrm.h"
#include "CSelectView.h"
#include "CDisplayView.h"

#include "CUserDlg.h"

#include "CPeopleAdd.h"
#include "CPeopleEdit.h"
#include "CPeopleSearch.h"
#include "CPeopleDelete.h"

#include "CAdminInfo.h"
#include "CAdminTeacherInfo.h"
#include "CTeacherInfo.h"
#include "CTeacherTechInfo.h"
#include "CTechInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()

	//ON_MESSAGE响应的是自定义消息
	//产生WU_X消息，自动调用OnMyChange()函数
	ON_MESSAGE(WU_A, OnMyChange)
	ON_MESSAGE(WU_B, OnMyChange)
	ON_MESSAGE(WU_C, OnMyChange)
	ON_MESSAGE(WU_D, OnMyChange)
	ON_MESSAGE(WU_E, OnMyChange)
	ON_MESSAGE(WU_F, OnMyChange)
	ON_MESSAGE(WU_ADD, OnMyChange)
	ON_MESSAGE(WU_EDIT, OnMyChange)
	ON_MESSAGE(WU_LOOK, OnMyChange)
	ON_MESSAGE(WU_DELE, OnMyChange)
	

	ON_COMMAND(ID_32771, &CMainFrame::OnMenuExit)
	ON_COMMAND(ID_32772, &CMainFrame::OnMenuUser)
	ON_COMMAND(ID_32773, &CMainFrame::OnMenuTeacher)
	ON_COMMAND(ID_32774, &CMainFrame::OnMenuAdmin)
	ON_COMMAND(ID_32775, &CMainFrame::OnMenuTech)
	ON_COMMAND(ID_32776, &CMainFrame::OnMenuTeacherTech)
	ON_COMMAND(ID_32777, &CMainFrame::OnMenuAdminTeacher)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame() noexcept
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));


	//设置窗口标题栏的图标  
	SetClassLong(m_hWnd, GCL_HICON, (LONG)AfxGetApp()->LoadIconW(IDI_HOME_TITLE));

	//设置标题栏的右侧标题文字  设置左侧标题在CSalaryAdminSystemDoc类OnNewDocument()函数
	SetTitle(TEXT("2019/9/5"));

	//设置窗口的大小
	MoveWindow(0, 0, 1300, 750);

	//设置居中显示
	CenterWindow();

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类

	//return CFrameWnd::OnCreateClient(lpcs, pContext);

	//拆成一行两列
	m_splitter.CreateStatic(this, 1, 2);

	//左右侧具体显示的内容
	m_splitter.CreateView(0, 0, RUNTIME_CLASS(CSelectView), CSize(270, 750), pContext);
	m_splitter.CreateView(0, 1, RUNTIME_CLASS(CDisplayView), CSize(1030, 750), pContext);

	return TRUE;     //代表自己拆分  
}

LRESULT CMainFrame::OnMyChange(WPARAM wParam, LPARAM lParam)
{
	CCreateContext context;

	if (WU_A == wParam)
	{
		//挂载管理员界面
		context.m_pNewViewClass = RUNTIME_CLASS(CUserDlg);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView*)m_splitter.GetPane(0, 1);
		m_splitter.DeleteView(0, 1);
		m_splitter.CreateView(0, 1, RUNTIME_CLASS(CUserDlg), CSize(900, 750), &context);
		CUserDlg* pNewView = (CUserDlg*)m_splitter.GetPane(0, 1);
		m_splitter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_splitter.SetActivePane(0, 1);

	}

	else if (WU_ADD == wParam)
	{
		context.m_pNewViewClass = RUNTIME_CLASS(CPeopleAdd);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView*)m_splitter.GetPane(0, 1);
		m_splitter.DeleteView(0, 1);
		m_splitter.CreateView(0, 1, RUNTIME_CLASS(CPeopleAdd), CSize(900, 750), &context);
		CPeopleAdd* pNewView = (CPeopleAdd*)m_splitter.GetPane(0, 1);
		m_splitter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_splitter.SetActivePane(0, 1);
	}

	else if (WU_EDIT == wParam)
	{
		context.m_pNewViewClass = RUNTIME_CLASS(CPeopleEdit);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView*)m_splitter.GetPane(0, 1);
		m_splitter.DeleteView(0, 1);
		m_splitter.CreateView(0, 1, RUNTIME_CLASS(CPeopleEdit), CSize(900, 750), &context);
		CPeopleEdit* pNewView = (CPeopleEdit*)m_splitter.GetPane(0, 1);
		m_splitter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_splitter.SetActivePane(0, 1);
	}

	else if (WU_LOOK == wParam)
	{
		context.m_pNewViewClass = RUNTIME_CLASS(CPeopleSearch);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView*)m_splitter.GetPane(0, 1);
		m_splitter.DeleteView(0, 1);
		m_splitter.CreateView(0, 1, RUNTIME_CLASS(CPeopleSearch), CSize(900, 750), &context);
		CPeopleSearch* pNewView = (CPeopleSearch*)m_splitter.GetPane(0, 1);
		m_splitter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_splitter.SetActivePane(0, 1);
	}

	else if (WU_DELE == wParam)
	{
		context.m_pNewViewClass = RUNTIME_CLASS(CPeopleDelete);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView*)m_splitter.GetPane(0, 1);
		m_splitter.DeleteView(0, 1);
		m_splitter.CreateView(0, 1, RUNTIME_CLASS(CPeopleDelete), CSize(900, 750), &context);
		CPeopleDelete* pNewView = (CPeopleDelete*)m_splitter.GetPane(0, 1);
		m_splitter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_splitter.SetActivePane(0, 1);
	}

	else if (WU_B == wParam)
	{
		//挂载教师信息界面
		context.m_pNewViewClass = RUNTIME_CLASS(CTeacherInfo);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView*)m_splitter.GetPane(0, 1);
		m_splitter.DeleteView(0, 1);
		m_splitter.CreateView(0, 1, RUNTIME_CLASS(CTeacherInfo), CSize(900, 750), &context);
		CTeacherInfo* pNewView = (CTeacherInfo*)m_splitter.GetPane(0, 1);
		m_splitter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_splitter.SetActivePane(0, 1);

	}

	else if (wParam == WU_C)
	{
		//挂载行政人员信息界面
		context.m_pNewViewClass = RUNTIME_CLASS(CAdminInfo);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView*)m_splitter.GetPane(0, 1);
		m_splitter.DeleteView(0, 1);
		m_splitter.CreateView(0, 1, RUNTIME_CLASS(CAdminInfo), CSize(900, 750), &context);
		CAdminInfo* pNewView = (CAdminInfo*)m_splitter.GetPane(0, 1);
		m_splitter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_splitter.SetActivePane(0, 1);
	}

	else if (wParam == WU_D)
	{
		//挂载实验员信息界面
		context.m_pNewViewClass = RUNTIME_CLASS(CTechInfo);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView*)m_splitter.GetPane(0, 1);
		m_splitter.DeleteView(0, 1);
		m_splitter.CreateView(0, 1, RUNTIME_CLASS(CTechInfo), CSize(900, 750), &context);
		CTechInfo* pNewView = (CTechInfo*)m_splitter.GetPane(0, 1);
		m_splitter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_splitter.SetActivePane(0, 1);
	}

	else if (wParam == WU_E)
	{
		//挂载教师兼职实验员信息界面
		context.m_pNewViewClass = RUNTIME_CLASS(CTeacherTechInfo);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView*)m_splitter.GetPane(0, 1);
		m_splitter.DeleteView(0, 1);
		m_splitter.CreateView(0, 1, RUNTIME_CLASS(CTeacherTechInfo), CSize(900, 750), &context);
		CTeacherTechInfo* pNewView = (CTeacherTechInfo*)m_splitter.GetPane(0, 1);
		m_splitter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_splitter.SetActivePane(0, 1);
	}

	else if (wParam == WU_F)
	{
		//挂载行政人员兼职教师信息界面
		context.m_pNewViewClass = RUNTIME_CLASS(CAdminTeacherInfo);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView*)m_splitter.GetPane(0, 1);
		m_splitter.DeleteView(0, 1);
		m_splitter.CreateView(0, 1, RUNTIME_CLASS(CAdminTeacherInfo), CSize(900, 750), &context);
		CAdminTeacherInfo* pNewView = (CAdminTeacherInfo*)m_splitter.GetPane(0, 1);
		m_splitter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_splitter.SetActivePane(0, 1);
	}

	return 0;
}


void CMainFrame::OnMenuExit()
{
	// TODO: 在此添加命令处理程序代码
	//退出菜单
	exit(0);
}

void CMainFrame::OnMenuUser()
{
	// TODO: 在此添加命令处理程序代码
	//管理员菜单
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WU_A, (WPARAM)WU_A, (LPARAM)0);

}

void CMainFrame::OnMenuTeacher()
{
	// TODO: 在此添加命令处理程序代码
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WU_B, (WPARAM)WU_B, (LPARAM)0);
}

void CMainFrame::OnMenuAdmin()
{
	// TODO: 在此添加命令处理程序代码
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WU_C, (WPARAM)WU_C, (LPARAM)0);
}

void CMainFrame::OnMenuTech()
{
	// TODO: 在此添加命令处理程序代码
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WU_D, (WPARAM)WU_D, (LPARAM)0);
}

void CMainFrame::OnMenuTeacherTech()
{
	// TODO: 在此添加命令处理程序代码
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WU_E, (WPARAM)WU_E, (LPARAM)0);
}

void CMainFrame::OnMenuAdminTeacher()
{
	// TODO: 在此添加命令处理程序代码
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WU_F, (WPARAM)WU_F, (LPARAM)0);
}
