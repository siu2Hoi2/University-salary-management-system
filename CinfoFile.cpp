#include "CInfoFile.h"

CInfoFile::CInfoFile()
{
}

CInfoFile::~CInfoFile()
{
}


//��ȡ��½��Ϣ
void CInfoFile::ReadLogin(CString& name, CString& pwd)
{
	ifstream ifs;  //�����ļ��������
	ifs.open(_F_LOGIN);

	char buf[1024] = { 0 };

	ifs.getline(buf, sizeof(buf));   //��ȡһ������
	name = CString(buf);    //��char* ת��ΪCString

	ifs.getline(buf, sizeof(buf));    //��ȡһ������
	pwd = CString(buf);         //��char* ת��ΪCString

	ifs.close();
}


//�޸ĵ�½����
void CInfoFile::WritePwd(char* name, char* pwd)
{
	ofstream outf; // �����ļ��������
	outf.open(_F_LOGIN);    //���ļ�

	outf << name << endl;   //nameд���ļ�
	outf << pwd << endl;     //pwdд���ļ�

	outf.close();   	//�ر��ļ�
}


//д���ʦ��Ϣ
void CInfoFile::WriteTeacher()
{
	ofstream outf(_F_TEACHER);
	string str = "ID|����|������|����";
	list<Teacher>::iterator it = l_teach.begin();
	//����ǿ�ʱ������ļ�
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


//������ʦ
void CInfoFile::AddTeacher(CString name_s, CString id_s, int hours)
{
	Teacher temp;
	if (l_teach.size() > 0)
	{
		if (!id_s.IsEmpty() && !name_s.IsEmpty() && hours >= 0)
		{
	
			CStringA str;
			str = name_s;  //CString תCStringA
			temp.name = str.GetBuffer();  //CString תΪchar *, ����

			str = id_s;
			temp.id = str.GetBuffer();

			temp.work_hours = hours;

			double salaryTemp = (1000.0 + (hours - 180.0) * 20);
			//�������Ϊ0
			if (salaryTemp <= 0)
			{
				temp.total_salary = 0.0;
			}
			else
			{
				temp.total_salary = salaryTemp;
			}
			//��Ϊ���Ԫ��׷�ӵ�����
			l_teach.push_back(temp);

		}
	}
}


//��ȡ��ʦ��Ϣ
void CInfoFile::ReadTeacher()
{
	ifstream inf(_F_TEACHER);

	char buf[2048] = { 0 };
	l_teach.clear();
	//ȡ����ͷ
	inf.getline(buf, sizeof(buf));

	while (!inf.eof())  //û���ļ���β
	{
		Teacher temp;

		inf.getline(buf, sizeof(buf));  //��ȡһ��
		char* sst = strtok(buf, "|");   //��"|"�ָ�
		if (sst != NULL)
		{
			
			temp.id = sst;

			sst = strtok(NULL, "|");
			temp.name = sst;

			sst = strtok(NULL, "|");
			temp.work_hours = atoi(sst);

			sst = strtok(NULL, "|");
			temp.total_salary = atoi(sst);
			//����ǿ�ʱ������ļ�
			l_teach.push_back(temp);
		}
	}

	inf.close();
}

//��ȡʵ�鼼��Ա��Ϣ
void CInfoFile::ReadTech()
{
	ifstream inf(_F_TECH);

	char buf[1024] = { 0 };
	l_tech.clear();
	//ȡ����ͷ
	inf.getline(buf, sizeof(buf));

	while (!inf.eof())  //û���ļ���β
	{
		Tech temp;

		inf.getline(buf, sizeof(buf));  //��ȡһ��
		char* sst = strtok(buf, "|");   //��"|"�ָ�
		if (sst != NULL)
		{
			temp.id = sst;
			
			sst = strtok(NULL, "|");
			temp.name = sst;

			sst = strtok(NULL, "|");
			temp.work_hours = atoi(sst);

			sst = strtok(NULL, "|");
			temp.total_salary = atoi(sst);
			//��Ϊ���Ԫ��׷�ӵ�����
			l_tech.push_back(temp);
		}
	}

	inf.close();
}

//д��ʵ�鼼��Ա��Ϣ
void CInfoFile::WriteTech()
{
	ofstream outf(_F_TECH);
	string str = "ID|����|������|����";
	list<Tech>::iterator it = l_tech.begin();
	//����ǿ�ʱ������ļ�
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

//����ʵ�鼼��Ա
void CInfoFile::AddTech(CString name_s, CString id_s,int hours)
{
	Tech temp;
	if (l_tech.size() > 0)
	{
		if (!name_s.IsEmpty() && hours >= 0&&!id_s.IsEmpty())
		{
			
			CStringA str;
			str = name_s;  //CString תCStringA
			temp.name = str.GetBuffer();  //CString תΪchar *, ����
			
			str=id_s;
			temp.id=str.GetBuffer();
			
			temp.work_hours=hours;

			//��������+ʵ���Ҳ���
			double salaryTemp = (850 + 180.0 + (hours - 100.0) * 20);
			//�������Ϊ0
			if(salaryTemp<=0)
			{
				temp.total_salary = 0.0;
			}
			else
			{
				temp.total_salary = salaryTemp;
			}
			//��Ϊ���Ԫ��׷�ӵ�����
			l_tech.push_back(temp);
		}
	}
}

//��ȡ������Ա��Ϣ
void CInfoFile::ReadAdmin()
{
	ifstream inf(_F_ADMIN);

	char buf[2048] = { 0 };
	l_admin.clear();
	//ȡ����ͷ
	inf.getline(buf, sizeof(buf));

	while (!inf.eof())  //û���ļ���β
	{
		Admin temp;

		inf.getline(buf, sizeof(buf));  //��ȡһ��
		char* sst = strtok(buf, "|");   //��"|"�ָ�
		if (sst != NULL)
		{
			temp.id = sst;
			
			sst = strtok(NULL, "|");
			temp.name = sst;

			sst = strtok(NULL, "|");
			temp.total_salary = atoi(sst);
			//��Ϊ���Ԫ��׷�ӵ�����
			l_admin.push_back(temp);
		}
	}

	inf.close();
}

//д��������Ա��Ϣ
void CInfoFile::WriteAdmin()
{
	ofstream outf(_F_ADMIN);
	string str = "ID|����|����";
	list<Admin>::iterator it = l_admin.begin();
	//����ǿ�ʱ������ļ�
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

//����������Ա
void CInfoFile::AddAdmin(CString name_s, CString id_s)
{
	Admin temp;
	if (l_admin.size() > 0)
	{
		if (!name_s.IsEmpty()&&!id_s.IsEmpty())
		{
			
			CStringA str;
			str = name_s;  //CString תCStringA
			temp.name = str.GetBuffer();  //CString תΪchar *, ����
			
			str=id_s;
			temp.id=str.GetBuffer();

			//��������+��������
			temp.total_salary = 950.0 + 280;
			//��Ϊ���Ԫ��׷�ӵ�����
			l_admin.push_back(temp);
		}
	}
}

//��ȡ��ʦ��ְʵ�鼼��Ա��Ϣ
void CInfoFile::ReadTeachAndTech()
{
	ifstream inf(_F_T_AND_T);

	char buf[1024] = { 0 };
	l_TAT.clear();
	//ȡ����ͷ
	inf.getline(buf, sizeof(buf));

	while (!inf.eof())  //û���ļ���β
	{
		TeachAndTech temp;

		inf.getline(buf, sizeof(buf));  //��ȡһ��
		char* sst = strtok(buf, "|");   //��"|"�ָ�
		if (sst != NULL)
		{
			temp.id = sst;

			sst = strtok(NULL, "|");
			temp.name = sst;

			sst = strtok(NULL, "|");
			temp.work_hours = atoi(sst);

			sst = strtok(NULL, "|");
			temp.total_salary = atoi(sst);
			//��Ϊ���Ԫ��׷�ӵ�����
			l_TAT.push_back(temp);
		}
	}

	inf.close();
}

//д���ʦ��ְʵ�鼼��Ա��Ϣ
void CInfoFile::WriteTeachAndTech()
{
	ofstream outf(_F_T_AND_T);
	string str = "ID|����|������|����";
	list<TeachAndTech>::iterator it = l_TAT.begin();
	//����ǿ�ʱ������ļ�
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

//������ʦ��ְʵ�鼼��Ա��Ϣ
void CInfoFile::AddTeachAndTech(CString name_s,CString id_s,int hours)
{
	TeachAndTech temp;
	if (l_TAT.size() > 0)
	{
		if (!name_s.IsEmpty() && hours >= 0&&!id_s.IsEmpty())
		{
			CStringA str;
			str = name_s;  //CString תCStringA
			temp.name = str.GetBuffer();  //CString תΪchar *, ����
			
			str=id_s;
			temp.id=str.GetBuffer();
			
			temp.work_hours = hours;
		
			//��������+��ʱ��+ʵ���Ҳ���
			double salaryTemp = (1000.0 + 850 + 180.0 + (hours - 180.0 - 100.0) * 20);
			if (salaryTemp <= 0)
			{
				temp.total_salary = 0.0;
			}
			else
			{
				temp.total_salary = salaryTemp;
			}
			//��Ϊ���Ԫ��׷�ӵ�����
			l_TAT.push_back(temp);

		}
	}

}

//��ȡ������Ա��ְ��ʦ
void CInfoFile::ReadAdminAndTeach()
{
	ifstream inf(_F_A_AND_T);

	char buf[1024] = { 0 };
	l_AAT.clear();
	//ȡ����ͷ
	inf.getline(buf, sizeof(buf));

	while (!inf.eof())  //û���ļ���β
	{
		AdminAndTeach temp;

		inf.getline(buf, sizeof(buf));  //��ȡһ��
		char* sst = strtok(buf, "|");   //��"|"�ָ�
		if (sst != NULL)
		{
			temp.id = sst;

			sst = strtok(NULL, "|");
			temp.name = sst;

			sst = strtok(NULL, "|");
			temp.num_class = atoi(sst);

			sst = strtok(NULL, "|");
			temp.total_salary = atoi(sst);
			//��Ϊ���Ԫ��׷�ӵ�����
			l_AAT.push_back(temp);
		}
	}

	inf.close();
}

//д��������Ա��ְ��ʦ
void CInfoFile::WriteAdminAndTeach()
{
	ofstream outf(_F_A_AND_T);
	string str = "ID|����|�ڴ�|����";
	list<AdminAndTeach>::iterator it = l_AAT.begin();
	//����ǿ�ʱ������ļ�
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

//���������Ա��ְ��ʦ
void CInfoFile::AddAdminAndTeach(CString name, CString id_s,int nums)
{
	AdminAndTeach temp;
	if (l_AAT.size() > 0)
	{
		if (!name.IsEmpty() && nums >= 0 && !id_s.IsEmpty())
		{
			CStringA str;
			str = name;  //CString תCStringA
			temp.name = str.GetBuffer();  //CString תΪchar *, ����
			
			str=id_s;
			temp.id=str.GetBuffer();
			
			temp.num_class = nums;
			
			//��������+��������+ÿ�ڿο�ʱ��
			temp.total_salary = 950.0 + 280 + 35.0 * nums;
			//��Ϊ���Ԫ��׷�ӵ�����
			l_AAT.push_back(temp);

		}
	}
}
