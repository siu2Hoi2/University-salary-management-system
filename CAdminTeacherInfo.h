#pragma once



// CAdminTeacherInfo 窗体视图

class CAdminTeacherInfo : public CFormView
{
	DECLARE_DYNCREATE(CAdminTeacherInfo)

protected:
	CAdminTeacherInfo();           // 动态创建所使用的受保护的构造函数
	virtual ~CAdminTeacherInfo();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = ADMIN_TEACHER_INFO };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CListCtrl adminTeacherList;   //行政人员兼职教师汇总列表控件
public:
	virtual void OnInitialUpdate();  //初始化函数
};


