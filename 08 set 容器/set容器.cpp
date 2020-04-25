#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

/*
set ���캯��
	set<T>st;
	multiset<T> mst;
	set(const set &st);
set ��ֵ����
	set& operator=(const set &st);
	seap(st);
set ��С����
	size();
	empty();
set �����ɾ������
	insert(elem);
	clear();
	erase(pos);
	erase(beg, end);
	erase(elem);
*/
void PrintSet(set<int>& st)
{
	for (set<int>::iterator it = st.begin(); it != st.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	set<int> st;
	st.insert(10);
	st.insert(4);
	st.insert(5);
	st.insert(6);
	st.insert(10);
	st.insert(3);
	st.insert(10);
	st.insert(19);

	PrintSet(st);
}
/*
set ���Ҳ���
	find(key);
	count(key);
	lower_bound(keyElem); //���ص�һ��key>=keyElemԪ�صĵ�����
	upper_bound(keyElem); //���ص�һ��key>keyElemԪ�صĵ�����
	equal_range(keyElem) ;//���� key== keyElemԪ�ص������޵�����������
*/
void test02()
{
	set<int> st;
	st.insert(10);
	st.insert(4);
	st.insert(5);
	st.insert(6);
	st.insert(19);

	set<int>::iterator res = st.find(6);
	if (res != st.end())
	{
		cout << " �ҵ���Ԫ�أ�"<< *res << endl;
	}
	else
	{
		cout << " û���ҵ� " << endl;
	} 
	int num = st.count(10); //set ��countҪô��0 Ҫô��1
	cout << "10 �ĸ����� "<< num  << endl;

	res = st.lower_bound(5);
	if (res != st.end())
	{
		cout << " �ҵ���lower_bound >= 5��Ԫ�ص�ֵΪ��" << *res << endl;
	}
	else
	{
		cout << " û���ҵ� " << endl;
	}
	res = st.upper_bound(5);
	if (res != st.end())
	{
		cout << " �ҵ���upper_bound > 5��Ԫ�ص�ֵΪ��" << *res << endl;
	}
	else
	{
		cout << " û���ҵ� " << endl;
	}
	//����
	pair<set<int>::iterator, set<int>::iterator> res1 = st.equal_range(5);
	if (res1.first != st.end())
	{
		cout << " �ҵ���equal_range lower_bound ��Ԫ�ص�ֵΪ��" << *res1.first << endl;
	}
	else
	{
		cout << " û���ҵ� " << endl;
	}
	if (res1.second != st.end())
	{
		cout << " �ҵ���equal_range upper_bound ��Ԫ�ص�ֵΪ��" << *res1.second << endl;
	}
	else
	{
		cout << " û���ҵ� " << endl;
	}
}
//��������
void test03()
{
	//��һ������
	pair<string,int> p(string("tom"), 19);
	cout << "������ " << p.first << " ���䣺 " << p.second << endl;

	//�ڶ�������
	pair<string, int> p2 = make_pair("locy", 19);
	cout << "������ " << p2.first << " ���䣺 " << p2.second << endl;
}
//
void test04()
{
	set<int> s;
	pair<set<int>::iterator, bool> res = s.insert(10);
	if (res.second)
	{
		cout << "��һ�β���ɹ� " << endl;
	}
	else 
	{
		cout << "��һ�β���ʧ�� " << endl;
	}
	res = s.insert(20);
	if (res.second)
	{
		cout << "�ڶ��β���ɹ� " << endl;
	}
	else
	{
		cout << "�ڶ��β���ʧ�� " << endl;
	}
	res = s.insert(10);
	if (res.second)
	{
		cout << "�����β���ɹ� " << endl;
	}
	else
	{
		cout << "�����β���ʧ�� " << endl;
	}
	PrintSet(s);

	multiset<int> ms;
	ms.insert(10);
	ms.insert(20);
	ms.insert(10);

	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//Ĭ�ϴ�С�����޸Ĳ���ǰ�������
//���÷º�����ָ��set�������������
class MyCompare
{
public:
	bool operator()(int v1, int v2)const
	{
		return v1 > v2;
	}
};
void test05()
{
	set<int, MyCompare> st; //ֻ�������Ͳ����Ǻ���

	st.insert(10);
	st.insert(4);
	st.insert(5);
	st.insert(6);
	st.insert(19);

	for (set<int, MyCompare>::iterator it = st.begin(); it != st.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//�Զ�����������
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Age = age;
		this->m_Name = name;
	}
	string m_Name;
	int m_Age;
};
class MyComparePerson
{
public:
	bool operator()(const Person& p1, const Person& p2)const
	{
		return p1.m_Age > p2.m_Age;
	}
};
void test06()
{
	set<Person, MyComparePerson> st;

	Person p1("aaa", 10);
	Person p2("bbb", 24);
	Person p3("ccc", 22);
	Person p4("ddd", 34);
	Person p5("eee", 55);

	st.insert(p1);
	st.insert(p2);
	st.insert(p3);
	st.insert(p4);
	st.insert(p5);

	for (set<Person, MyComparePerson>::iterator it = st.begin(); it != st.end(); it++)
	{
		cout << "������" << (*it).m_Name << " ���䣺" << (*it).m_Age << endl;;
	}
}
int main()
{
	cout << "-------------------- test01() -----------------------" << endl;
	test01();

	cout << "-------------------- test02() -----------------------" << endl;
	test02();

	cout << "-------------------- test03() -----------------------" << endl;
	test03();

	cout << "-------------------- test04() -----------------------" << endl;
	test04();

	cout << "-------------------- test05() -----------------------" << endl;
	test05();

	cout << "-------------------- test06() -----------------------" << endl;
	test06();

	return EXIT_SUCCESS;
}