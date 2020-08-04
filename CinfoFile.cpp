#include "CInfoFile.h"

CInfoFile::CInfoFile()
{
}

CInfoFile::~CInfoFile()
{
}


//读取登陆信息
void CInfoFile::ReadLogin(CString& name, CString& pwd)
{
	ifstream ifs;  //创建文件输入对象
	ifs.open(_F_LOGIN);

	char buf[1024] = { 0 };

	ifs.getline(buf, sizeof(buf));   //读取一行内容
	name = CString(buf);    //将char* 转换为CString

	ifs.getline(buf, sizeof(buf));    //读取一行内容
	pwd = CString(buf);         //将char* 转换为CString

	ifs.close();
}


//修改登陆密码
void CInfoFile::WritePwd(char* name, char* pwd)
{
	ofstream outf; // 创建文件输出对象
	outf.open(_F_LOGIN);    //打开文件

	outf << name << endl;   //name写入文件
	outf << pwd << endl;     //pwd写入文件

	outf.close();   	//关闭文件
}


//写入教师信息
void CInfoFile::WriteTeacher()
{
	ofstream outf(_F_TEACHER);
	string str = "ID|姓名|工作量|工资";
	list<Teacher>::iterator it = l_teach.begin();
	//链表非空时输出到文件
	if (l_teach.size() > 0)
	{
		outf << str << endl;
		for (; it != l_teach.end(); it++)
		{
			outf << it->id << "|";
			outf << it->name << "|";
			outf << it->work_hours << "|";
			outf << fixed << setprecision(2) << it->total_salary << endl;
		}
	}

	outf.close();
}


//新增教师
void CInfoFile::AddTeacher(CString name_s, CString id_s, int hours)
{
	Teacher temp;
	if (l_teach.size() > 0)
	{
		if (!id_s.IsEmpty() && !name_s.IsEmpty() && hours >= 0)
		{
	
			CStringA str;
			str = name_s;  //CString 转CStringA
			temp.name = str.GetBuffer();  //CString 转为char *, 姓名

			str = id_s;
			temp.id = str.GetBuffer();

			temp.work_hours = hours;

			double salaryTemp = (1000.0 + (hours - 180.0) * 20);
			//工资最低为0
			if (salaryTemp <= 0)
			{
				temp.total_salary = 0.0;
			}
			else
			{
				temp.total_salary = salaryTemp;
			}
			//作为最后元素追加到链表
			l_teach.push_back(temp);

		}
	}
}


//读取教师信息
void CInfoFile::ReadTeacher()
{
	ifstream inf(_F_TEACHER);

	char buf[2048] = { 0 };
	l_teach.clear();
	//取出表头
	inf.getline(buf, sizeof(buf));

	while (!inf.eof())  //没到文件结尾
	{
		Teacher temp;

		inf.getline(buf, sizeof(buf));  //读取一行
		char* sst = strtok(buf, "|");   //以"|"分隔
		if (sst != NULL)
		{
			
			temp.id = sst;

			sst = strtok(NULL, "|");
			temp.name = sst;

			sst = strtok(NULL, "|");
			temp.work_hours = atoi(sst);

			sst = strtok(NULL, "|");
			temp.total_salary = atoi(sst);
			//链表非空时输出到文件
			l_teach.push_back(temp);
		}
	}

	inf.close();
}

//读取实验技术员信息
void CInfoFile::ReadTech()
{
	ifstream inf(_F_TECH);

	char buf[1024] = { 0 };
	l_tech.clear();
	//取出表头
	inf.getline(buf, sizeof(buf));

	while (!inf.eof())  //没到文件结尾
	{
		Tech temp;

		inf.getline(buf, sizeof(buf));  //读取一行
		char* sst = strtok(buf, "|");   //以"|"分隔
		if (sst != NULL)
		{
			temp.id = sst;
			
			sst = strtok(NULL, "|");
			temp.name = sst;

			sst = strtok(NULL, "|");
			temp.work_hours = atoi(sst);

			sst = strtok(NULL, "|");
			temp.total_salary = atoi(sst);
			//作为最后元素追加到链表
			l_tech.push_back(temp);
		}
	}

	inf.close();
}

//写入实验技术员信息
void CInfoFile::WriteTech()
{
	ofstream outf(_F_TECH);
	string str = "ID|姓名|工作量|工资";
	list<Tech>::iterator it = l_tech.begin();
	//链表非空时输出到文件
	if (l_tech.size() > 0)
	{
		outf << str << endl;
		for (; it != l_tech.end(); it++)
		{
			outf << it->id << "|";
			outf << it->name << "|";
			outf << it->work_hours << "|";
			outf << fixed << setprecision(2) << it->total_salary << endl;
		}
	}

	outf.close();
}

//新增实验技术员
void CInfoFile::AddTech(CString name_s, CString id_s,int hours)
{
	Tech temp;
	if (l_tech.size() > 0)
	{
		if (!name_s.IsEmpty() && hours >= 0&&!id_s.IsEmpty())
		{
			
			CStringA str;
			str = name_s;  //CString 转CStringA
			temp.name = str.GetBuffer();  //CString 转为char *, 姓名
			
			str=id_s;
			temp.id=str.GetBuffer();
			
			temp.work_hours=hours;

			//基本工资+实验室补助
			double salaryTemp = (850 + 180.0 + (hours - 100.0) * 20);
			//工资最低为0
			if(salaryTemp<=0)
			{
				temp.total_salary = 0.0;
			}
			else
			{
				temp.total_salary = salaryTemp;
			}
			//作为最后元素追加到链表
			l_tech.push_back(temp);
		}
	}
}

//读取行政人员信息
void CInfoFile::ReadAdmin()
{
	ifstream inf(_F_ADMIN);

	char buf[2048] = { 0 };
	l_admin.clear();
	//取出表头
	inf.getline(buf, sizeof(buf));

	while (!inf.eof())  //没到文件结尾
	{
		Admin temp;

		inf.getline(buf, sizeof(buf));  //读取一行
		char* sst = strtok(buf, "|");   //以"|"分隔
		if (sst != NULL)
		{
			temp.id = sst;
			
			sst = strtok(NULL, "|");
			temp.name = sst;

			sst = strtok(NULL, "|");
			temp.total_salary = atoi(sst);
			//作为最后元素追加到链表
			l_admin.push_back(temp);
		}
	}

	inf.close();
}

//写入行政人员信息
void CInfoFile::WriteAdmin()
{
	ofstream outf(_F_ADMIN);
	string str = "ID|姓名|工资";
	list<Admin>::iterator it = l_admin.begin();
	//链表非空时输出到文件
	if (l_admin.size() > 0)
	{
		outf << str << endl;
		for (; it != l_admin.end(); it++)
		{
			outf << it->id << "|";
			outf << it->name << "|";
			outf << fixed << setprecision(2) << it->total_salary << endl;
		}
	}

	outf.close();
}

//新增行政人员
void CInfoFile::AddAdmin(CString name_s, CString id_s)
{
	Admin temp;
	if (l_admin.size() > 0)
	{
		if (!name_s.IsEmpty()&&!id_s.IsEmpty())
		{
			
			CStringA str;
			str = name_s;  //CString 转CStringA
			temp.name = str.GetBuffer();  //CString 转为char *, 姓名
			
			str=id_s;
			temp.id=str.GetBuffer();

			//基本工资+行政补助
			temp.total_salary = 950.0 + 280;
			//作为最后元素追加到链表
			l_admin.push_back(temp);
		}
	}
}

//读取教师兼职实验技术员信息
void CInfoFile::ReadTeachAndTech()
{
	ifstream inf(_F_T_AND_T);

	char buf[1024] = { 0 };
	l_TAT.clear();
	//取出表头
	inf.getline(buf, sizeof(buf));

	while (!inf.eof())  //没到文件结尾
	{
		TeachAndTech temp;

		inf.getline(buf, sizeof(buf));  //读取一行
		char* sst = strtok(buf, "|");   //以"|"分隔
		if (sst != NULL)
		{
			temp.id = sst;

			sst = strtok(NULL, "|");
			temp.name = sst;

			sst = strtok(NULL, "|");
			temp.work_hours = atoi(sst);

			sst = strtok(NULL, "|");
			temp.total_salary = atoi(sst);
			//作为最后元素追加到链表
			l_TAT.push_back(temp);
		}
	}

	inf.close();
}

//写入教师兼职实验技术员信息
void CInfoFile::WriteTeachAndTech()
{
	ofstream outf(_F_T_AND_T);
	string str = "ID|姓名|工作量|工资";
	list<TeachAndTech>::iterator it = l_TAT.begin();
	//链表非空时输出到文件
	if (l_TAT.size() > 0)
	{
		outf << str << endl;
		for (; it != l_TAT.end(); it++)
		{
			outf << it->id << "|";
			outf << it->name << "|";
			outf << it->work_hours << "|";
			outf << fixed << setprecision(2) << it->total_salary << endl;
		}
	}

	outf.close();
}

//新增教师兼职实验技术员信息
void CInfoFile::AddTeachAndTech(CString name_s,CString id_s,int hours)
{
	TeachAndTech temp;
	if (l_TAT.size() > 0)
	{
		if (!name_s.IsEmpty() && hours >= 0&&!id_s.IsEmpty())
		{
			CStringA str;
			str = name_s;  //CString 转CStringA
			temp.name = str.GetBuffer();  //CString 转为char *, 姓名
			
			str=id_s;
			temp.id=str.GetBuffer();
			
			temp.work_hours = hours;
		
			//基本工资+课时费+实验室补助
			double salaryTemp = (1000.0 + 850 + 180.0 + (hours - 180.0 - 100.0) * 20);
			if (salaryTemp <= 0)
			{
				temp.total_salary = 0.0;
			}
			else
			{
				temp.total_salary = salaryTemp;
			}
			//作为最后元素追加到链表
			l_TAT.push_back(temp);

		}
	}

}

//读取行政人员兼职教师
void CInfoFile::ReadAdminAndTeach()
{
	ifstream inf(_F_A_AND_T);

	char buf[1024] = { 0 };
	l_AAT.clear();
	//取出表头
	inf.getline(buf, sizeof(buf));

	while (!inf.eof())  //没到文件结尾
	{
		AdminAndTeach temp;

		inf.getline(buf, sizeof(buf));  //读取一行
		char* sst = strtok(buf, "|");   //以"|"分隔
		if (sst != NULL)
		{
			temp.id = sst;

			sst = strtok(NULL, "|");
			temp.name = sst;

			sst = strtok(NULL, "|");
			temp.num_class = atoi(sst);

			sst = strtok(NULL, "|");
			temp.total_salary = atoi(sst);
			//作为最后元素追加到链表
			l_AAT.push_back(temp);
		}
	}

	inf.close();
}

//写入行政人员兼职教师
void CInfoFile::WriteAdminAndTeach()
{
	ofstream outf(_F_A_AND_T);
	string str = "ID|姓名|节次|工资";
	list<AdminAndTeach>::iterator it = l_AAT.begin();
	//链表非空时输出到文件
	if (l_AAT.size() > 0)
	{
		outf << str << endl;
		for (; it != l_AAT.end(); it++)
		{
			outf << it->id << "|";
			outf << it->name << "|";
			outf << it->num_class << "|";
			outf << fixed << setprecision(2) << it->total_salary << endl;
		}
	}

	outf.close();
}

//添加行政人员兼职教师
void CInfoFile::AddAdminAndTeach(CString name, CString id_s,int nums)
{
	AdminAndTeach temp;
	if (l_AAT.size() > 0)
	{
		if (!name.IsEmpty() && nums >= 0 && !id_s.IsEmpty())
		{
			CStringA str;
			str = name;  //CString 转CStringA
			temp.name = str.GetBuffer();  //CString 转为char *, 姓名
			
			str=id_s;
			temp.id=str.GetBuffer();
			
			temp.num_class = nums;
			
			//基本工资+行政补助+每节课课时费
			temp.total_salary = 950.0 + 280 + 35.0 * nums;
			//作为最后元素追加到链表
			l_AAT.push_back(temp);

		}
	}
}
