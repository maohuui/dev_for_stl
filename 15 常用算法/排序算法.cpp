#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <time.h>
using namespace std;

/*
merge算法：容器元素合并，并存储到另一个容器
两个容器必须都是有序的
	参数1：容器1开始迭代器
	参数2：容器1结束迭代器
	参数1：容器2开始迭代器
	参数2：容器3结束迭代器
	参数3：目标容器开始迭代器
*/
void test01()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i*2);
		v2.push_back(i * 2 + 1);
	}

	vector<int> v; //目标容器
	v.resize(v1.size()+ v2.size());
	merge(v1.begin(), v1.end(), v2.begin(),v2.end(), v.begin());

	for (vector<int>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
/*
sort算法：容器元素排序
	参数1：容器1开始迭代器
	参数2：容器1结束迭代器
	参数3：_callback 回调函数或者谓词（返回bool类型的函数对象）
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

	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), [](int val) {
		cout << val << " ";
		});
	cout << endl;
}

/*
random_shuffle 算法 对指定范围内的元素随机调整次序
	参数1：开始迭代器
	参数2：结束迭代器
*/
void test03()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), [](int val) {
		cout << val << " ";
		});
	cout << endl;
}
/*
reverse 算法，反转指定范围的元素
	参数1：开始迭代器
	参数2：结束迭代器
*/
void test04()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), [](int val) {
		cout << val << " ";
		});
	cout << endl;
}

int main()
{
	srand((unsigned int)time(NULL)); //加个随机种子
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