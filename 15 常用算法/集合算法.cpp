#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

/*
set_intersection算法：求两个set 集合的交集
不是 set 的方法，而是一个通用函数
两个集合必须是有序序列
	参数1：容器1开始迭代器
	参数2：容器1结束迭代器
	参数3：容器2开始迭代器
	参数4：容器2结束迭代器
	参数3：目标容器开始迭代器
	返回值： 目标容器最后一个元素的迭代器地址
*/
void test01()
{
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i+5);
	}

	vector<int> v;
	v.resize(min(v1.size(), v2.size()));	
	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());

	copy(v.begin(), itEnd, ostream_iterator<int>(cout, " "));
	cout << endl;
}
/*
set_union 算法：求两个set 集合的并集
两个集合必须是有序序列
	参数1：容器1开始迭代器
	参数2：容器1结束迭代器
	参数3：容器2开始迭代器
	参数4：容器2结束迭代器
	参数3：目标容器开始迭代器
	返回值： 目标容器最后一个元素的迭代器地址
*/
void test02()
{
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int> v;
	v.resize(v1.size()+v2.size());
	vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());

	copy(v.begin(), itEnd, ostream_iterator<int>(cout, " "));
	cout << endl;
}
/*
set_different 算法：求两个set 集合的差集
两个集合必须是有序序列
	参数1：容器1开始迭代器
	参数2：容器1结束迭代器
	参数3：容器2开始迭代器
	参数4：容器2结束迭代器
	参数3：目标容器开始迭代器
	返回值： 目标容器最后一个元素的迭代器地址
*/
void test03()
{
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int> v;
	v.resize(max(v1.size(), v2.size()));
	vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());

	copy(v.begin(), itEnd, ostream_iterator<int>(cout, " "));
	cout << endl;

	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), v.begin());

	copy(v.begin(), itEnd, ostream_iterator<int>(cout, " "));
	cout << endl;
}
int main()
{
	cout << "--------------------test01()---------------" << endl;
	test01();

	cout << "--------------------test02()---------------" << endl;
	test02();

	cout << "--------------------test03()---------------" << endl;
	test03();

	return EXIT_SUCCESS;
}