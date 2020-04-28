#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <time.h>
#include <iterator>
using namespace std;

/*
copy�㷨����������ָ����Χ�ڵ�Ԫ�ؿ�������һ��������
	����1����ʼ������
	����2������������
	����3��Ŀ��������ʼ������
*/
void test01()
{
	vector<int>v1;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i * 2);
	}

	vector<int>v2; //Ŀ������
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());
	copy(v1.begin() ,v1.end(), ostream_iterator<int>(cout, " "));
	//for_each(v2.begin(), v2.end(), [](int val) {
	//	cout << val << " ";
	//	});
	cout << endl;
}
/*
replace�㷨����������ָ����Χ�ڵľ�Ԫ���޸�Ϊ��Ԫ��
	����1��������ʼ������
	����2����������������
	����3��oldvale ��Ԫ��
	����4��newvalue ��Ԫ��
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
replace_if�㷨����������ָ����Χ�����������ľ�Ԫ���޸�Ϊ��Ԫ��
	����1��������ʼ������
	����2����������������
	����3��callback �����ص�����ν�ʣ�����bool���͵ĺ�������
	����4��newvalue ��Ԫ��
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
swap �㷨����������������Ԫ��
	����1����һ������
	����2���ڶ�������
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