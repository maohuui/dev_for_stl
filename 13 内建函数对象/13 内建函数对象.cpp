#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

/*
6个算法类函数对象，除了negate 是一元运算，其他都为二元运算
	template<class T> T plus <T>;  //加法仿函数
	template<class T> T minus <T>;  //减法仿函数
	template<class T> T multiplies <T>;  //乘法仿函数
	template<class T> T divides <T>;  //除法仿函数
	template<class T> T modulus <T>;  //取模仿函数
	template<class T> T negate <T>;  //取反仿函数
*/
void test01()
{
	plus<int> p;
	cout << "相加： " << p(20, 20) << endl;

	minus<int> mi;
	cout << "相减： " << mi(20, 20) << endl;

	multiplies<int> ml;
	cout << "相乘： " << ml(20, 20) << endl;

	divides<int> d;
	cout << "相除： " << d(20, 20) << endl;

	modulus<int> mo;
	cout << "取模： " << mo(20, 20) << endl;

	negate<int> n;
	cout << "10 的取反： " << n(10) << endl;
}

/*
6个关系类函数对象，都为二元运算
	template<class T> bool equal_to <T>;  //等于
	template<class T> bool not_equal_to <T>;  //不等于
	template<class T> bool greater <T>;  //大于
	template<class T> bool greater_equal <T>;  //大于等于
	template<class T> bool less <T>;  //小于
	template<class T> bool less_equal <T>;  //小于等于
*/
void test02()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(45);
	v.push_back(30);
	v.push_back(50);
	v.push_back(23);
	v.push_back(100);

	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	cout << endl;
}

/*
6逻辑运算类运算函数，not 为一元运算，其他为二元运算
	template<class T> bool logical_and <T>;  //逻辑与
	template<class T> bool logical_or <T>;  //逻辑或
	template<class T> bool logical_not <T>;  //逻辑非
*/
void test03()
{
	logical_and<int> la;
	cout << "logical_and: " << la(0, 1) << endl;

	logical_or<int> lo;
	cout << "logical_or: " << lo(0, 1) << endl;

	logical_not<int> ln;
	cout << "logical_not: " << ln(0) << endl;
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