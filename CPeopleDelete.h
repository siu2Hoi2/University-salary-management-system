#pragma once



// CPeopleDelete 窗体视图

class CPeopleDelete : public CFormView
{
	DECLARE_DYNCREATE(CPeopleDelete)

protected:
	CPeopleDelete();           // 动态创建所使用的受保护的构造函数
	virtual ~CPeopleDelete();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DELETE };
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
	CString deleteName;     //输入待删除姓名
	CString deleteID;       //输入待删除编号
public:
	afx_msg void OnBnClickedButton2();  //删除按钮
	afx_msg void OnBnClickedButton9();   //清空信息按钮
	virtual void OnInitialUpdate();      //初始化函数 
private:
	CString peopleInfo;    //显示人员信息
};


