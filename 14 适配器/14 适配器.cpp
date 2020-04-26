#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

//��������������
class MyPrint : public binary_function<int, int, void>
{
public:
	void operator()(int val, int start) const
	{
		cout << "val: " << val << " start: " << start << " sum: " << val + start << endl;
	}
};
void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//for_each(v.begin(), v.end(), MyPrint());

	int num;
	cout << "�������ʼֵ�� " << endl;
	cin >> num;

	for_each(v.begin(), v.end(), bind2nd(MyPrint(), num));

	//bind1st�Ĳ��������෴��
	//for_each(v.begin(), v.end(), bind1st(MyPrint(), num));
	//1. ���������а�bind2nd
	//2. ��̳�binary_function<��������1�� ��������2������ֵ����>
	//3. ��const 
}

// ȡ��������
class greatherFive : public unary_function<int, bool>
{
public:
	bool operator()(int val)const
	{
		return val > 5;
	}
};
void test02()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	/*vector<int>::iterator pos = find_if(v.begin(), v.end(), greatherFive());
	if (pos != v.end())
	{
		cout << " �ҵ�����5�� " << *pos << endl;
	}
	else
	{
		cout << " û���ҵ� " << endl;
	}*/
	//ȡ��
	vector<int>::iterator pos = find_if(v.begin(), v.end(), not1(greatherFive()));
	if (pos != v.end())
	{
		cout << " �ҵ�С��5�� " << *pos << endl;
	}
	else
	{
		cout << " û���ҵ� " << endl;
	}
	//1. һԪȡ�� not1
	//2. �̳���unary_function<����1�� ����ֵ>
	//3. ��const

	//����
	//vector<int>::iterator pos = find_if(v.begin(), v.end(), not1(bind2nd(greatherFive(), 5)));
}

// ����ָ��������
void MyPrint03(int val, int start)
{
	cout << "val = " << val << ", start = " << start << ",sum = " << val + start << endl;
}
void test03()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	int num;
	cout << "�������ʼֵ�� " << endl;
	cin >> num;

	// ����ָ����������������ָ������ɺ�������
	// ptr_fun
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(MyPrint03), num));
	//1. ptr_fun
	//2. �� bind2nd
}

//��Ա����������
class Person
{
public:
	Person(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
	void showPerson()
	{
		cout << "name: " << m_Name << " age: " << m_Age << endl;
	}

	void addAge()
	{
		m_Age = m_Age + 10;
	}

	string m_Name;
	int m_Age;
};
void PrintPerson(Person& p)
{
	cout << "name: " << p.m_Name << " age: " << p.m_Age << endl;
}
void test04()
{
	vector<Person> v;
	Person p1("aaa", 10);
	Person p2("bbb", 10);
	Person p3("ccc", 10);
	Person p4("ddd", 10);
	Person p5("eee", 10);
	Person p6("fff", 10);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	v.push_back(p6);

	//for_each(v.begin(), v.end(), PrintPerson);

	for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::addAge));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
}

int main()
{
	cout << "-----------------test01()----------------------- " << endl;
	test01();

	cout << "-----------------test02()----------------------- " << endl;
	test02();

	cout << "-----------------test03()----------------------- " << endl;
	test03();

	cout << "-----------------test04()----------------------- " << endl;
	test04();
	return EXIT_SUCCESS;
}