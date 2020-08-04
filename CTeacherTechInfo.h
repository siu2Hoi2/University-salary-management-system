#pragma once



// CTeacherTechInfo 窗体视图

class CTeacherTechInfo : public CFormView
{
	DECLARE_DYNCREATE(CTeacherTechInfo)

protected:
	CTeacherTechInfo();           // 动态创建所使用的受保护的构造函数
	virtual ~CTeacherTechInfo();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = TEACHER_TECH_INFO };
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
	CListCtrl teacherTechList;    //教师兼职实验技术员汇总列表控件
public:
	virtual void OnInitialUpdate();   //初始化函数
};


