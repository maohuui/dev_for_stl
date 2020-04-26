#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//谓词，普通函数或者仿函数返回值为bool类型
class GreaterThen20
{
public:
	bool operator()(int val1)
	{
		return val1 > 50;
	}
};

void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(34);
	v.push_back(67);
	v.push_back(34);
	v.push_back(80);

	//找到第一个大于50的数
	vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterThen20());

	if(pos != v.end())
	{
		cout << "找到第一个大于50的数为： " << *pos << endl;
	}
	else {
		cout << " 没有找到 " << endl;
	}
}

class MyCompare
{
public:
	bool operator()(int val1, int val2)
	{
		return val1 > val2;
	}
};

bool MyCompareFunc(int val1, int val2)
{
	return val1 > val2;
}

//二元谓词
void test02()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(34);
	v.push_back(67);
	v.push_back(34);
	v.push_back(80);

	//sort(v.begin(), v.end()); // 默认是从小到大
	 //实现从大到小
	sort(v.begin(), v.end(), MyCompareFunc); // 使用普通函数
	//sort(v.begin(), v.end(), MyCompare()); // 使用仿函数

	//lamda 表达式
	for_each(v.begin(), v.end(), [](int val) { cout << val << endl; });
}

int main()
{
	cout << "-----------------test01()----------------------- " << endl;
	test01();

	cout << "-----------------test02()----------------------- " << endl;
	test02();
	return EXIT_SUCCESS;
}