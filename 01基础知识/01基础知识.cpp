#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//普通指针也属于一种迭代器
void test01()
{
	int arr[5] = { 1,2,3,4,5 };
	int* p = arr;

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << *(p++) << endl;
	}
}
void myPrint(int val)
{
	cout << val << endl;
}
//内置属性类型
void test02()
{
	vector<int> v; //声明一个vector的容器
	v.push_back(10);
	v.push_back(20);
	v.push_back(1);
	v.push_back(4);

	//通过迭代器可以变量容器
	//每个容器都有自己的专属迭代器
	//第一种遍历方式
	cout << "========/第一种遍历方式=========" << endl;
	vector<int>::iterator itBegin = v.begin(); //起始迭代器
	vector<int>::iterator itEnd = v.end(); //结束迭代器，指向最后一个数据的下一个位置
	while (itBegin != itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}
	//第二种遍历方式
	cout << "========/第二种遍历方式=========" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
	//第三种遍历方式
	cout << "========/第三种遍历方式=========" << endl;
	for_each(v.begin(), v.end(), myPrint);
}

//自定义的数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

void test03()
{
	vector<Person> v;

	Person p1("aa", 10);
	Person p2("bb", 40);
	Person p3("cc", 3);
	Person p4("dd", 5);
	Person p5("ee", 20);
	
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "age: " << (*it).m_Age <<" name: " << (*it).m_Name << endl;

		//cout << it->m_Age << it->m_Name << endl;
	}
}
//存放自定义类型的指针
void test04()
{
	vector<Person*> v;

	Person p1("aa", 10);
	Person p2("bb", 40);
	Person p3("cc", 3);
	Person p4("dd", 5);
	Person p5("ee", 20);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "age: " << (*it)->m_Age << " name: " << (*it)->m_Name << endl;
	}
}

//容器嵌套容器
void test05()
{
	vector<vector<int>> v; //类似于二位数组
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i+10);
		v3.push_back(i+100);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << *vit << " ";
		}
		cout << endl;
	}
}
int main()
{
	cout << "--------------test01()----------------" << endl;
	test01();
	cout << "--------------test02()----------------" << endl;
	test02();
	cout << "--------------test03()----------------" << endl;
	test03();
	cout << "--------------test04()----------------" << endl;
	test04();
	cout << "--------------test05()----------------" << endl;
	test05();
	return EXIT_SUCCESS;
}