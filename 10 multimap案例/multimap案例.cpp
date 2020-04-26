#include <iostream>
#include <vector>
#include <map>
#include <time.h>
using namespace std;

/*
	��˾��Ƹ��5��Ա����5��Ա�����벻ͬ�Ĳ���
	��Ա��Ϣ������ ����绰���ʵ�
	ͨ��multimap������Ϣ�Ĳ��뱣����ʾ
	�ֲ�����ʾԱ����Ϣ
*/

enum  Departiment
{
	SALE_DEPARTMENT, // ����
	DEVLOP_DEPARTMENT,// ����
	FINACIAL_DEPARTMENT,//����
	UI_DEPARTMENT //����
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
		worker.m_Name = "Ա��";
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
	cout << "----------------���񲿷���Ա����---------------" << endl;
	int count = mp.count(FINACIAL_DEPARTMENT);
	multimap<int, Worker>::iterator pos = mp.find(FINACIAL_DEPARTMENT);
	int index = 0;
	for (; pos != mp.end(), index < count; index++, pos++)
	{
		cout << "����:" << pos->second.m_Name << " ����:" << pos->second.m_Age << " ����:" << pos->second.m_Money << endl;
	}

	cout << "-----------------���۲�����Ա����--------------" << endl;
	count = mp.count(SALE_DEPARTMENT);
	pos = mp.find(SALE_DEPARTMENT);
	index = 0;
	for (; pos != mp.end(), index < count; index++, pos++)
	{
		cout << "����:" << pos->second.m_Name << " ���䣺 " << pos->second.m_Age << " ���ʣ� " << pos->second.m_Money << endl;
	}

	cout << "-----------------����������Ա����-------------" << endl;
	count = mp.count(DEVLOP_DEPARTMENT);
	pos = mp.find(DEVLOP_DEPARTMENT);
	index = 0;
	for (; pos != mp.end(), index < count; index++, pos++)
	{
		cout << "����:" << pos->second.m_Name << " ����:" << pos->second.m_Age << " ����:" << pos->second.m_Money << endl;
	}

	cout << "-----------------����������Ա����-------------" << endl;
	count = mp.count(UI_DEPARTMENT);
	pos = mp.find(UI_DEPARTMENT);
	index = 0;
	for (; pos != mp.end(), index < count; index++, pos++)
	{
		cout << "����:" << pos->second.m_Name << " ����:" << pos->second.m_Age << " ����:" << pos->second.m_Money << endl;
	}
	
}

void test01()
{
	vector<Worker> v;

	//����Ա��
	createWorker(v);

	multimap<int, Worker> mp;
	//Ա������
	setGroup(v, mp);

	//�鿴
	showWorker(mp);
}

int main()
{
	srand((unsigned int)time(NULL));
	test01();
	return EXIT_SUCCESS;
}