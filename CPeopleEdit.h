#pragma once

// CPeopleEdit 窗体视图

class CPeopleEdit : public CFormView
{
	DECLARE_DYNCREATE(CPeopleEdit)

protected:
	CPeopleEdit();           // 动态创建所使用的受保护的构造函数
	virtual ~CPeopleEdit();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EDIT };
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
	CComboBox peopleCombo;  //人员选择下拉框
	CString editName;    //待编辑姓名
	CString editID;     //待编辑编号
	CString editWork;    //待编辑工作量
	CString editSalary;  //待编辑总工资
public:
	afx_msg void OnBnClickedButton7();   //确认修改按钮
	afx_msg void OnBnClickedButton8();   //清空信息按钮
	afx_msg void OnCbnSelchangeCombo1();  ////修改下拉框内容后的操作
	virtual void OnInitialUpdate();  //初始化函数
private:
	CString peopleInfo;    //人员信息显示
};


