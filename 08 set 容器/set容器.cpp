#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

/*
set 构造函数
	set<T>st;
	multiset<T> mst;
	set(const set &st);
set 赋值操作
	set& operator=(const set &st);
	seap(st);
set 大小操作
	size();
	empty();
set 插入和删除操作
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
set 查找操作
	find(key);
	count(key);
	lower_bound(keyElem); //返回第一个key>=keyElem元素的迭代器
	upper_bound(keyElem); //返回第一个key>keyElem元素的迭代器
	equal_range(keyElem) ;//返回 key== keyElem元素的上下限的两个迭代器
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
		cout << " 找到了元素："<< *res << endl;
	}
	else
	{
		cout << " 没有找到 " << endl;
	} 
	int num = st.count(10); //set 的count要么是0 要么是1
	cout << "10 的个数： "<< num  << endl;

	res = st.lower_bound(5);
	if (res != st.end())
	{
		cout << " 找到了lower_bound >= 5的元素的值为：" << *res << endl;
	}
	else
	{
		cout << " 没有找到 " << endl;
	}
	res = st.upper_bound(5);
	if (res != st.end())
	{
		cout << " 找到了upper_bound > 5的元素的值为：" << *res << endl;
	}
	else
	{
		cout << " 没有找到 " << endl;
	}
	//对组
	pair<set<int>::iterator, set<int>::iterator> res1 = st.equal_range(5);
	if (res1.first != st.end())
	{
		cout << " 找到了equal_range lower_bound 的元素的值为：" << *res1.first << endl;
	}
	else
	{
		cout << " 没有找到 " << endl;
	}
	if (res1.second != st.end())
	{
		cout << " 找到了equal_range upper_bound 的元素的值为：" << *res1.second << endl;
	}
	else
	{
		cout << " 没有找到 " << endl;
	}
}
//对组声明
void test03()
{
	//第一种声明
	pair<string,int> p(string("tom"), 19);
	cout << "姓名： " << p.first << " 年龄： " << p.second << endl;

	//第二种声明
	pair<string, int> p2 = make_pair("locy", 19);
	cout << "姓名： " << p2.first << " 年龄： " << p2.second << endl;
}
//
void test04()
{
	set<int> s;
	pair<set<int>::iterator, bool> res = s.insert(10);
	if (res.second)
	{
		cout << "第一次插入成功 " << endl;
	}
	else 
	{
		cout << "第一次插入失败 " << endl;
	}
	res = s.insert(20);
	if (res.second)
	{
		cout << "第二次插入成功 " << endl;
	}
	else
	{
		cout << "第二次插入失败 " << endl;
	}
	res = s.insert(10);
	if (res.second)
	{
		cout << "第三次插入成功 " << endl;
	}
	else
	{
		cout << "第三次插入失败 " << endl;
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
//默认从小到大，修改插入前排序规则
//利用仿函数，指定set容器的排序规则
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
	set<int, MyCompare> st; //只能是类型不能是函数

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
//自定义数据类型
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
		cout << "姓名：" << (*it).m_Name << " 年龄：" << (*it).m_Age << endl;;
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