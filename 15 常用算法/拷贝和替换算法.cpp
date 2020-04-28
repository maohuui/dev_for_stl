#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <time.h>
#include <iterator>
using namespace std;

/*
copy算法：将容器内指定范围内的元素拷贝到另一个容器中
	参数1：开始迭代器
	参数2：结束迭代器
	参数3：目标容器开始迭代器
*/
void test01()
{
	vector<int>v1;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i * 2);
	}

	vector<int>v2; //目标容器
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());
	copy(v1.begin() ,v1.end(), ostream_iterator<int>(cout, " "));
	//for_each(v2.begin(), v2.end(), [](int val) {
	//	cout << val << " ";
	//	});
	cout << endl;
}
/*
replace算法：将容器内指定范围内的旧元素修改为新元素
	参数1：容器开始迭代器
	参数2：容器结束迭代器
	参数3：oldvale 旧元素
	参数4：newvalue 新元素
*/
void test02()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(5);
	v.push_back(10);
	v.push_back(3);

	replace(v.begin(), v.end(), 10, 1000);
	for_each(v.begin(), v.end(), [](int val) {
		cout << val << " ";
		});
	cout << endl;
}

/*
replace_if算法：将容器内指定范围内满足条件的旧元素修改为新元素
	参数1：容器开始迭代器
	参数2：容器结束迭代器
	参数3：callback 函数回调或者谓词（返回bool类型的函数对象）
	参数4：newvalue 新元素
*/
class ReplaceClass
{
public:
	bool operator()(int val)
	{
		return val > 8;
	}
};
void test03()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	replace_if(v.begin(), v.end(), ReplaceClass(), 300);
	for_each(v.begin(), v.end(), [](int val) {
		cout << val << " ";
		});
	cout << endl;
}
/*
swap 算法，互换两个容器的元素
	参数1：第一个容器
	参数2：第二个容器
*/
void test04()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i*2);
		v2.push_back(i * 2 + 1);
	}

	swap(v1, v2);

	for_each(v1.begin(), v1.end(), [](int val) {
		cout << val << " ";
		});
	cout << endl;

	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
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

	return EXIT_SUCCESS;
}