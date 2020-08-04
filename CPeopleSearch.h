#pragma once



// CPeopleSearch 窗体视图

class CPeopleSearch : public CFormView
{
	DECLARE_DYNCREATE(CPeopleSearch)

protected:
	CPeopleSearch();           // 动态创建所使用的受保护的构造函数
	virtual ~CPeopleSearch();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEARCH };
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
public:
	afx_msg void OnBnClickedButton2();  //搜索按钮
	afx_msg void OnBnClickedButton9();    //清空信息按钮
private:
	CComboBox peopleCombo;   //人员选择下拉框
	CString searchName;      //输入待搜索信息
	CString searchID;        //输入待搜索编号
	CString peopleInfo;      //显示人员信息
public:     
	afx_msg void OnCbnSelchangeCombo1(); //修改下拉框内容后的操作
	virtual void OnInitialUpdate();       //初始化函数
};


