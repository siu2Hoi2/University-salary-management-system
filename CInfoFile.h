#pragma once
#include <list>
#include <iostream>
#include <fstream>
#include <string>
#include <afx.h>
#include <iomanip>

#define _F_LOGIN     "./login.ini"
#define _F_TEACHER   "./teacher_stock.txt"
#define _F_TECH      "./tech_stock.txt"
#define _F_ADMIN     "./admin_stock.txt"
#define _F_T_AND_T   "./teachAndTech_stock.txt"
#define _F_A_AND_T   "./adminAndTeach_stock.txt"

using namespace std;

//教师
struct Teacher
{
	string id;  //编号
	string name;  //姓名
	int work_hours = 0;  //课时
	double total_salary = 0;  //总工资
};

//实验技术员
struct Tech
{
	string id;  
	string name;  
	int work_hours = 0;
	double total_salary = 0;
};

//行政人员
struct Admin
{
	string id;
	string name;
	double total_salary = 0;
};

//教师兼职实验技术员
struct TeachAndTech
{
	string id;
	string name;
	int work_hours = 0;
	double total_salary = 0;
};

//行政人员兼职教师
struct AdminAndTeach
{
	string id;
	string name;
	int num_class = 0;  //授课节次
	double total_salary = 0;
};



class CInfoFile
{
public:
	CInfoFile();  //文件类空构造函数
	~CInfoFile(); //文件类空析构函数

	//读取登录信息
	void ReadLogin(CString& name, CString& pwd);

	//修改密码
	void WritePwd(char* name, char* pwd);


	//教师编辑
	void ReadTeacher();  //读取教师信息到链表中
	void WriteTeacher();  //写入链表信息到文件中
	void AddTeacher(CString, CString, int);    //添加信息到链表中
	list<Teacher> l_teach;   //储存教师信息的链表

	//技术员编辑
	void ReadTech();        //读取实验技术员信息到链表
	void WriteTech();       //写入链表信息到文件中
	void AddTech(CString, CString, int); //添加信息到链表中
	list<Tech> l_tech;       //储存实验技术员的链表

	//行政人员编辑
	void ReadAdmin();     //读取行政人员信息到链表
	void WriteAdmin();    //写入链表信息到文件中
	void AddAdmin(CString, CString);  //添加信息到链表中
	list<Admin> l_admin;  //储存行政人员的链表

	//教师兼职技术员编辑
	void ReadTeachAndTech();   //读取教师兼职行政人员信息
	void WriteTeachAndTech();  //写入链表信息到文件中
	void AddTeachAndTech(CString, CString, int);  //添加信息到链表中
	list<TeachAndTech> l_TAT;   //储存行政人员的链表

	//行政人员兼职教师
	void ReadAdminAndTeach();   //读取行政人员兼职教师信息
	void WriteAdminAndTeach();  //写入链表信息到文件中
	void AddAdminAndTeach(CString, CString, int);  //添加信息到链表中
	list<AdminAndTeach> l_AAT;   //储存行政人员的链表


};
