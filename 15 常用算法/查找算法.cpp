#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

/*
find算法：查找元素
	参数1：开始迭代器
	参数2：结束迭代器
	参数3：查找元素
	返回值：返回查找元素的位置
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
	
	//查找有没有5这个元素
	vector<int>::iterator pos =  find(v.begin(), v.end(), 5);
	if (pos != v.end())
	{
		cout << " 找到了 "<< *pos << endl;
	}
	else
	{
		cout << " 未找到" << endl;
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
		cout << " 找到了 name: " << (*pos1).m_Name << " Age:" << (*pos1).m_Age << endl;
	}
	else
	{
		cout << " 未找到" << endl;
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
		cout << " 找到了 name: " << (*pos1)->m_Name << " Age:" << (*pos1)->m_Age << endl;
	}
	else
	{
		cout << " 未找到" << endl;
	}
}

/*
adjacent_find 算法 查找相邻重复元素
	参数1：开始迭代器
	参数2：结束迭代器
	参数3：callback回调函数或者谓词（bool类型的函数对象）
	返回值：返回相邻元素的第一个位置的迭代器
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
		cout << " 找到重复元素 "<< *it << endl;
	}
	else
	{
		cout << " 没有 " << endl;
	}
}
/*
binary_search 算法，二分查找,有序序列
	参数1：开始迭代器
	参数2：结束迭代器
	参数3：value 查找的元素
	返回值：bool 查找返回true，否则false
*/
void test04()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);

	bool ret = binary_search(v.begin(), v.end(), 5);
	if (ret)
	{
		cout << " 找到了元素 " << endl;
	}
	else
	{
		cout << " 没有 " << endl;
	}
}
/*
count 算法 统计元素出现次数
	参数1：开始迭代器
	参数2：结束迭代器
	参数3：value 回调函数或者谓词（bool类型的函数对象）
	返回值：返回元素个数
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
count_if 算法 统计元素出现次数
	参数1：开始迭代器
	参数2：结束迭代器
	参数3：callback 回调函数或者谓词（bool类型的函数对象）
	返回值：返回元素个数
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