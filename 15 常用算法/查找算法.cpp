#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

/*
find�㷨������Ԫ��
	����1����ʼ������
	����2������������
	����3������Ԫ��
	����ֵ�����ز���Ԫ�ص�λ��
*/
class Person
{
public:
	Person(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}

	bool operator==(const Person& p)
	{
		if (this->m_Age == p.m_Age && this->m_Name == p.m_Name)
			return true;
		else
			return false;
	}
	string m_Name;
	int m_Age;
};

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(10 * i);
	}
	
	//������û��5���Ԫ��
	vector<int>::iterator pos =  find(v.begin(), v.end(), 5);
	if (pos != v.end())
	{
		cout << " �ҵ��� "<< *pos << endl;
	}
	else
	{
		cout << " δ�ҵ�" << endl;
	}

	vector<Person>v1;

	Person p1("aaa", 12);
	Person p2("bbb", 34);
	Person p3("ccc", 5);
	Person p4("ddd", 3);

	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);

	vector<Person>::iterator pos1 = find(v1.begin(), v1.end(), p3);
	if (pos1 != v1.end())
	{
		cout << " �ҵ��� name: " << (*pos1).m_Name << " Age:" << (*pos1).m_Age << endl;
	}
	else
	{
		cout << " δ�ҵ�" << endl;
	}
}

class MyComparePerson : public binary_function<Person *, Person *, bool>
{
public:
	bool operator()(Person* p1, Person* p2)const
	{
		if (p1->m_Age == p2->m_Age && p1->m_Name == p2->m_Name)
			return true;
		else
			return false;
	}
};
//find_if
void test02()
{
	vector<Person*>v1;

	Person p1("aaa", 12);
	Person p2("bbb", 34);
	Person p3("ccc", 5);
	Person p4("ddd", 3);

	v1.push_back(&p1);
	v1.push_back(&p2);
	v1.push_back(&p3);
	v1.push_back(&p4);

	Person *p = new Person("bbb", 34);

	vector<Person*>::iterator pos1  = find_if(v1.begin(), v1.end(), bind2nd(MyComparePerson(), p));
	if (pos1 != v1.end())
	{
		cout << " �ҵ��� name: " << (*pos1)->m_Name << " Age:" << (*pos1)->m_Age << endl;
	}
	else
	{
		cout << " δ�ҵ�" << endl;
	}
}

/*
adjacent_find �㷨 ���������ظ�Ԫ��
	����1����ʼ������
	����2������������
	����3��callback�ص���������ν�ʣ�bool���͵ĺ�������
	����ֵ����������Ԫ�صĵ�һ��λ�õĵ�����
*/
void test03()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(5);
	v.push_back(10);
	v.push_back(3);

	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it != v.end())
	{
		cout << " �ҵ��ظ�Ԫ�� "<< *it << endl;
	}
	else
	{
		cout << " û�� " << endl;
	}
}
/*
binary_search �㷨�����ֲ���,��������
	����1����ʼ������
	����2������������
	����3��value ���ҵ�Ԫ��
	����ֵ��bool ���ҷ���true������false
*/
void test04()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);

	bool ret = binary_search(v.begin(), v.end(), 5);
	if (ret)
	{
		cout << " �ҵ���Ԫ�� " << endl;
	}
	else
	{
		cout << " û�� " << endl;
	}
}
/*
count �㷨 ͳ��Ԫ�س��ִ���
	����1����ʼ������
	����2������������
	����3��value �ص���������ν�ʣ�bool���͵ĺ�������
	����ֵ������Ԫ�ظ���
*/
void test05()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(5);
	v.push_back(10);
	v.push_back(3);

	int num = count(v.begin(), v.end(), 10);
	cout << "count: " << num << endl;
}
/*
count_if �㷨 ͳ��Ԫ�س��ִ���
	����1����ʼ������
	����2������������
	����3��callback �ص���������ν�ʣ�bool���͵ĺ�������
	����ֵ������Ԫ�ظ���
*/
class MyCompare
{
public:
	bool operator()(int val)
	{
		return val > 4;
	}
};
void test06()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(5);
	v.push_back(10);
	v.push_back(3);

	int count = count_if(v.begin(), v.end(), MyCompare());
	cout << "count: " << count << endl;
}
int main()
{
	cout << "--------------------test01()---------------" << endl;
	test01();

	cout << "--------------------test02()---------------" << endl;
	test02();

	cout << "--------------------test03()---------------" << endl;
	test03();

	cout << "--------------------test04()---------------" << endl;
	test04();

	cout << "--------------------test05()---------------" << endl;
	test05();

	cout << "--------------------test06()---------------" << endl;
	test06();
	return EXIT_SUCCESS;
}