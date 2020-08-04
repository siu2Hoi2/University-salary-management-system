#pragma once



// CTechInfo 窗体视图

class CTechInfo : public CFormView
{
	DECLARE_DYNCREATE(CTechInfo)

protected:
	CTechInfo();           // 动态创建所使用的受保护的构造函数
	virtual ~CTechInfo();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = TECH_INFO };
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
	CListCtrl techList;  //实验技术员汇总列表信息
public:
	virtual void OnInitialUpdate();   //初始化函数
};


