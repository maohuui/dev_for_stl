#include <iostream>
#include <vector>
#include <map>
#include <time.h>
using namespace std;

/*
	公司招聘了5个员工，5个员工进入不同的部门
	人员信息：姓名 年龄电话工资等
	通过multimap进行信息的插入保存显示
	分部门显示员工信息
*/

enum  Departiment
{
	SALE_DEPARTMENT, // 销售
	DEVLOP_DEPARTMENT,// 开发
	FINACIAL_DEPARTMENT,//财务
	UI_DEPARTMENT //美术
};

class Worker
{
public:

	string m_Name;
	int m_Age;
	int m_Money;
};

void createWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEF";
	for (int i = 0; i < 5; i++)
	{
		Worker worker;
		worker.m_Name = "员工";
		worker.m_Name += nameSeed[i];

		worker.m_Age = 30 + i;
		worker.m_Money = 10000 + rand() % 10000;
		v.push_back(worker);

	}
}

void setGroup(vector<Worker>& v, multimap<int, Worker>& mp)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int id = rand() % 4;
		mp.insert(make_pair(id, *it));

	}
}

void showWorker(multimap<int, Worker>& mp)
{
	cout << "----------------财务部分人员如下---------------" << endl;
	int count = mp.count(FINACIAL_DEPARTMENT);
	multimap<int, Worker>::iterator pos = mp.find(FINACIAL_DEPARTMENT);
	int index = 0;
	for (; pos != mp.end(), index < count; index++, pos++)
	{
		cout << "姓名:" << pos->second.m_Name << " 年龄:" << pos->second.m_Age << " 工资:" << pos->second.m_Money << endl;
	}

	cout << "-----------------销售部分人员如下--------------" << endl;
	count = mp.count(SALE_DEPARTMENT);
	pos = mp.find(SALE_DEPARTMENT);
	index = 0;
	for (; pos != mp.end(), index < count; index++, pos++)
	{
		cout << "姓名:" << pos->second.m_Name << " 年龄： " << pos->second.m_Age << " 工资： " << pos->second.m_Money << endl;
	}

	cout << "-----------------开发部分人员如下-------------" << endl;
	count = mp.count(DEVLOP_DEPARTMENT);
	pos = mp.find(DEVLOP_DEPARTMENT);
	index = 0;
	for (; pos != mp.end(), index < count; index++, pos++)
	{
		cout << "姓名:" << pos->second.m_Name << " 年龄:" << pos->second.m_Age << " 工资:" << pos->second.m_Money << endl;
	}

	cout << "-----------------美术部分人员如下-------------" << endl;
	count = mp.count(UI_DEPARTMENT);
	pos = mp.find(UI_DEPARTMENT);
	index = 0;
	for (; pos != mp.end(), index < count; index++, pos++)
	{
		cout << "姓名:" << pos->second.m_Name << " 年龄:" << pos->second.m_Age << " 工资:" << pos->second.m_Money << endl;
	}
	
}

void test01()
{
	vector<Worker> v;

	//创建员工
	createWorker(v);

	multimap<int, Worker> mp;
	//员工分组
	setGroup(v, mp);

	//查看
	showWorker(mp);
}

int main()
{
	srand((unsigned int)time(NULL));
	test01();
	return EXIT_SUCCESS;
}