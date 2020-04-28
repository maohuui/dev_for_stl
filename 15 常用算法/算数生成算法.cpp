#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
using namespace std;

/*
accmulate算法：计算容器元素累计中和
	参数1：开始迭代器
	参数2：结束迭代器
	参数3：起始的累加值
	返回值： 累计和
*/
void test01()
{
	vector<int>v1;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i * 2);
	}

	int sum = accumulate(v1.begin(), v1.end(), 100000);

	cout << "sum:" << sum <<  endl;
}
/*
fill 算法：向容器中添加元素
	参数1：容器开始迭代器
	参数2：容器结束迭代器
	参数3：填充元素
*/
void test02()
{
	vector<int> v;
	v.resize(10);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	fill(v.begin(), v.end(), 1000);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}


int main()
{
	cout << "--------------------test01()---------------" << endl;
	test01();

	cout << "--------------------test02()---------------" << endl;
	test02();

	return EXIT_SUCCESS;
}