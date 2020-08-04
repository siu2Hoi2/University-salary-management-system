
// MainFrm.h: CMainFrame 类的接口
//

#pragma once

//WU_USER		是用户自定义消息的一个起始值
//WU_USER+1000	是为了区分系统消息和用户消息，避免冲突
#define WU_A	WM_USER+1000	
#define WU_B	WM_USER+1001	
#define WU_C	WM_USER+1002	
#define WU_D	WM_USER+1003	
#define WU_E	WM_USER+1004	
#define WU_F	WM_USER+1005
#define WU_ADD  WM_USER+1006
#define WU_EDIT WM_USER+1007
#define WU_LOOK WM_USER+1008
#define WU_DELE WM_USER+1009



class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame() noexcept;
	DECLARE_DYNCREATE(CMainFrame)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CStatusBar        m_wndStatusBar;

// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()


private:
	CSplitterWnd m_splitter;    //切分窗口类对象
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);

	afx_msg LRESULT OnMyChange(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnMenuExit();  //顶部菜单栏-信息的实现函数
	afx_msg void OnMenuUser();
	afx_msg void OnMenuTeacher();
	afx_msg void OnMenuAdmin();
	afx_msg void OnMenuTech();
	afx_msg void OnMenuTeacherTech();
	afx_msg void OnMenuAdminTeacher();
};


