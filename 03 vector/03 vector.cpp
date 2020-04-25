#include <iostream>
#include <vector>
#include <list>
using namespace std;

void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		cout << "capacity: " << v.capacity() << endl;
	}
}
/*
vector 构造函数
	vector<T> v;
	vector(v.begin(), v.end());
	vector(n. elem);
	vector(const vector &v);

vector 常用赋值操作
	assign(begin, end);
	assign(n, elem);
	vector& operator=(const vector &vec);
	swap(vec);
*/
void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << " " << *it;
	}
	cout << endl;
}
void test02()
{
	vector<int> v1;

	vector<int> v2(10, 30);
	printVector(v2);

	vector<int>v3(v2.begin(), v2.end());
	printVector(v3);

	vector<int> v4;
	//v4.assign(v3.begin(), v3.end());
	v4 = v3;
	printVector(v4);


	int arr[] = { 2,3,4,5,6,1 };
	vector<int> v5(arr, arr + sizeof(arr) / sizeof(int));
	printVector(v5);

	v4.swap(v5);
	printVector(v4);
}
/*
vector 大小操作
	size();
	empty();
	resize(int num);
	resize(int num, elem);//重新指定容器长度，容容器变长用elem填充，变短则超出的部分删除
	capacity();
	reserve(int len);
vector 数据存取操作
	at(int idx);
	operator[];
	fron();//返回容器中第一个数据元素
	back();//返回容器中最后一个数据元素
vector 插入和删除操作
	insert(const_iterator pos, int count, ele);//迭代器指向的位置pos插入count个元素ele
	push_back(ele);//尾部插入元素ele
	pop_back();//删除最后一个元素
	erase(const_itreator start, const_iteratorend);//删除迭代器从start到end之间的元素
	clear();//删除容器中所有的元素
*/
void test03()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(3);
	v.push_back(23);

	cout << v.size() << endl;
	if (v.empty())
	{
		cout << "v为空 " << endl;
	}
	else
	{
		cout << "v 不为空 " << endl;
	}
	v.resize(10);
	printVector(v);

	v.resize(3);
	printVector(v);

	v.resize(10, 5);

	cout << "v的第一个元素： " << v.front() << endl;
	cout << "v的最后一个元素： " << v.back() << endl;

	v.insert(v.begin(), 10000);
	printVector(v);

	v.insert(v.begin(), 4, 20000);
	printVector(v);

	v.pop_back();
	printVector(v);

	v.erase(v.begin());
	printVector(v);

	//v.erase(v.begin(), v.end());
	v.clear();
	printVector(v);
}
/*
巧用swap收缩内存
*/
void test04()
{
	vector<int> v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	cout << "v 的容量 " << v.capacity() << endl;
	cout << "v 的大小 " << v.size() << endl;

	v.resize(3);
	cout << "v 的容量 " << v.capacity() << endl;
	cout << "v 的大小 " << v.size() << endl;

	//收缩内存
	vector<int>(v).swap(v);
	cout << "v 的容量 " << v.capacity() << endl;
	cout << "v 的大小 " << v.size() << endl;
}
/*
巧用reverse预留空间
*/
void test05()
{
	vector<int> v;
	//v.reserve(100000);//预留空间

	int num = 0;
	int* p = NULL;

	//判断开辟100000找了多少次空间
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if(p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
	cout << " num: " << num << endl;
}

void test06()
{
	//逆序遍历
	vector<int>v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(3);
	v.push_back(23);
	cout << " 正序遍历的结果： " << endl;
	printVector(v);

	cout << " 逆序遍历的结果： " << endl;
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
	{
		cout << " " << *it;
	}
	cout << endl;

	/*
	vector 容器的迭代器是随机访问迭代器
	如果判断一个容器的迭代器是否支持随机访问
	*/
	vector<int>::iterator it = v.begin();
	it++;
	it--;
	it = it + 1; //如果语法通过，支持随机访问

	list<int>l;
	l.push_back(10);
	l.push_back(2);
	list<int>::iterator it1 = l.begin();
	it1++;
	it1--;
	//it1 = it1 + 1;
}

int main()
{
	cout << "----------------------test01()--------------------------" << endl;
	test01();

	cout << "----------------------test02()--------------------------" << endl;
	test02();

	cout << "----------------------test03()--------------------------" << endl;
	test03();

	cout << "----------------------test04()--------------------------" << endl;
	test04();

	cout << "----------------------test05()--------------------------" << endl;
	test05();

	cout << "----------------------test06()--------------------------" << endl;
	test06();

	return EXIT_SUCCESS;
}