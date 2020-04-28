#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <time.h>
using namespace std;

/*
merge�㷨������Ԫ�غϲ������洢����һ������
�����������붼�������
	����1������1��ʼ������
	����2������1����������
	����1������2��ʼ������
	����2������3����������
	����3��Ŀ��������ʼ������
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

	vector<int> v; //Ŀ������
	v.resize(v1.size()+ v2.size());
	merge(v1.begin(), v1.end(), v2.begin(),v2.end(), v.begin());

	for (vector<int>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
/*
sort�㷨������Ԫ������
	����1������1��ʼ������
	����2������1����������
	����3��_callback �ص���������ν�ʣ�����bool���͵ĺ�������
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
random_shuffle �㷨 ��ָ����Χ�ڵ�Ԫ�������������
	����1����ʼ������
	����2������������
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
reverse �㷨����תָ����Χ��Ԫ��
	����1����ʼ������
	����2������������
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
	srand((unsigned int)time(NULL)); //�Ӹ��������
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