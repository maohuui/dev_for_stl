#include <iostream>
using namespace std;

//函数对象，像函数的调用方式
class MyPrint
{
public:
	void operator()(int val)
	{
		m_Count ++;

		cout << "val: " << val << endl;
		cout << "m_Count: " << m_Count << endl;
	}
	int m_Count = 0;
	//函数对象通常不定义构造函数和析构函数，避免了函数调用的运行时的问题
};

void test01()
{
	MyPrint p;
	p(100);
}

// 函数对象超出普通函数的概念，函数对象可以有自己的状态
void test02()
{
	MyPrint p1;
	p1(10);
	p1(20);
	p1(30);
	p1(40);
	p1(50);
}

// 函数对象可以作为函数的参数传递
void  doWork(MyPrint mp, int num)
{
	mp(num);
}
void test03()
{
	doWork(MyPrint(), 10000);
}

int main()
{
	cout << "-----------------test01()----------------------- " << endl;
	test01();

	cout << "-----------------test02()----------------------- " << endl;
	test02();

	cout << "-----------------test03()----------------------- " << endl;
	test03();

	return EXIT_SUCCESS;
}