#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

/*
遍历容器元素
	for_each()
		参数1：开始迭代器
		参数2：结束迭代器
		参数3：函数回调或者函数对象
		返回值：函数对象
*/
class MyPrintClass
{
public:
	void operator()(int val)
	{
		m_Count++;
		cout << val << endl;
	}
	int m_Count = 0;
};

class MyPrintClass1 : public binary_function<int, int, void>
{
public:
	void operator()(int val, int start)const
	{
		cout << val + start << endl;
	}
};
void MyprintFunc(int val)
{
	cout << val << endl;
}
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(10 * i);
	}
	//函数
	for_each(v.begin(), v.end(), MyprintFunc);

	// 函数对象
	MyPrintClass mp = for_each(v.begin(), v.end(), MyPrintClass());

	//可以有返回值
	cout << "count: " << mp.m_Count << endl;

	//可以绑定参数，进行输出
	for_each(v.begin(), v.end(), bind2nd(MyPrintClass1(), 1000));
}

/*
transform 算法：将制容器区间中的元素搬运到另一个容器中
	transform不会给目标容器分配内存，所以需要提前分配
	参数1：源容器开始迭代器
	参数2：源容器结束迭代器
	参数3：目标容器开始迭代器
	参数4：回调函数或者函数对象
	返回值：返回目标容器迭代器
*/
class MyTransform
{
public:
	int operator()(int val)
	{
		return val;
	}
};
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(20 * i);
	}
	vector<int> target;
	target.resize(v.size()); //提前指定大小
	transform(v.begin(), v.end(), target.begin(), MyTransform());
	for_each (target.begin(), target.end(), [](int val) { cout << val << endl; });
}
int main()
{
	cout << "--------------------test01()---------------" << endl;
	test01();

	cout << "--------------------test02()---------------" << endl;
	test02();

	return EXIT_SUCCESS;
}