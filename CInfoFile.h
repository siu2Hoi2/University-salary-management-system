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

//��ʦ
struct Teacher
{
	string id;  //���
	string name;  //����
	int work_hours = 0;  //��ʱ
	double total_salary = 0;  //�ܹ���
};

//ʵ�鼼��Ա
struct Tech
{
	string id;  
	string name;  
	int work_hours = 0;
	double total_salary = 0;
};

//������Ա
struct Admin
{
	string id;
	string name;
	double total_salary = 0;
};

//��ʦ��ְʵ�鼼��Ա
struct TeachAndTech
{
	string id;
	string name;
	int work_hours = 0;
	double total_salary = 0;
};

//������Ա��ְ��ʦ
struct AdminAndTeach
{
	string id;
	string name;
	int num_class = 0;  //�ڿνڴ�
	double total_salary = 0;
};



class CInfoFile
{
public:
	CInfoFile();  //�ļ���չ��캯��
	~CInfoFile(); //�ļ������������

	//��ȡ��¼��Ϣ
	void ReadLogin(CString& name, CString& pwd);

	//�޸�����
	void WritePwd(char* name, char* pwd);


	//��ʦ�༭
	void ReadTeacher();  //��ȡ��ʦ��Ϣ��������
	void WriteTeacher();  //д��������Ϣ���ļ���
	void AddTeacher(CString, CString, int);    //�����Ϣ��������
	list<Teacher> l_teach;   //�����ʦ��Ϣ������

	//����Ա�༭
	void ReadTech();        //��ȡʵ�鼼��Ա��Ϣ������
	void WriteTech();       //д��������Ϣ���ļ���
	void AddTech(CString, CString, int); //�����Ϣ��������
	list<Tech> l_tech;       //����ʵ�鼼��Ա������

	//������Ա�༭
	void ReadAdmin();     //��ȡ������Ա��Ϣ������
	void WriteAdmin();    //д��������Ϣ���ļ���
	void AddAdmin(CString, CString);  //�����Ϣ��������
	list<Admin> l_admin;  //����������Ա������

	//��ʦ��ְ����Ա�༭
	void ReadTeachAndTech();   //��ȡ��ʦ��ְ������Ա��Ϣ
	void WriteTeachAndTech();  //д��������Ϣ���ļ���
	void AddTeachAndTech(CString, CString, int);  //�����Ϣ��������
	list<TeachAndTech> l_TAT;   //����������Ա������

	//������Ա��ְ��ʦ
	void ReadAdminAndTeach();   //��ȡ������Ա��ְ��ʦ��Ϣ
	void WriteAdminAndTeach();  //д��������Ϣ���ļ���
	void AddAdminAndTeach(CString, CString, int);  //�����Ϣ��������
	list<AdminAndTeach> l_AAT;   //����������Ա������


};
