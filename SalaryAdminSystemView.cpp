
// SalaryAdminSystemView.cpp: CSalaryAdminSystemView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "SalaryAdminSystem.h"
#endif

#include "SalaryAdminSystemDoc.h"
#include "SalaryAdminSystemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSalaryAdminSystemView

IMPLEMENT_DYNCREATE(CSalaryAdminSystemView, CView)

BEGIN_MESSAGE_MAP(CSalaryAdminSystemView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CSalaryAdminSystemView 构造/析构

CSalaryAdminSystemView::CSalaryAdminSystemView() noexcept
{
	// TODO: 在此处添加构造代码

}

CSalaryAdminSystemView::~CSalaryAdminSystemView()
{
}

BOOL CSalaryAdminSystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSalaryAdminSystemView 绘图

void CSalaryAdminSystemView::OnDraw(CDC* /*pDC*/)
{
	CSalaryAdminSystemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CSalaryAdminSystemView 打印

BOOL CSalaryAdminSystemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSalaryAdminSystemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CSalaryAdminSystemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CSalaryAdminSystemView 诊断

#ifdef _DEBUG
void CSalaryAdminSystemView::AssertValid() const
{
	CView::AssertValid();
}

void CSalaryAdminSystemView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSalaryAdminSystemDoc* CSalaryAdminSystemView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSalaryAdminSystemDoc)));
	return (CSalaryAdminSystemDoc*)m_pDocument;
}
#endif //_DEBUG


// CSalaryAdminSystemView 消息处理程序
