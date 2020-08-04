#pragma once

// CPeopleAdd 窗体视图

class CPeopleAdd : public CFormView
{
	DECLARE_DYNCREATE(CPeopleAdd)

protected:
	CPeopleAdd();           // 动态创建所使用的受保护的构造函数
	virtual ~CPeopleAdd();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD };
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
	CString peopleInfo;  //显示人员信息
	CComboBox peopleCombo;  //人员选择下拉框
public:
	virtual void OnInitialUpdate();   //初始化函数
private:
	CString addName;  //待添加姓名
	CString addID;    //待添加编号
	CString addWork;   //待添加工作量
public:
	afx_msg void OnCbnSelchangeCombo1();  //修改下拉框内容后的操作
	afx_msg void OnBnClickedButton2();   //录入按钮
	afx_msg void OnBnClickedButton9();   //清空信息按钮
};


