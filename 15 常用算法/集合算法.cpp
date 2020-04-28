#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

/*
set_intersection�㷨��������set ���ϵĽ���
���� set �ķ���������һ��ͨ�ú���
�������ϱ�������������
	����1������1��ʼ������
	����2������1����������
	����3������2��ʼ������
	����4������2����������
	����3��Ŀ��������ʼ������
	����ֵ�� Ŀ���������һ��Ԫ�صĵ�������ַ
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
set_union �㷨��������set ���ϵĲ���
�������ϱ�������������
	����1������1��ʼ������
	����2������1����������
	����3������2��ʼ������
	����4������2����������
	����3��Ŀ��������ʼ������
	����ֵ�� Ŀ���������һ��Ԫ�صĵ�������ַ
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
set_different �㷨��������set ���ϵĲ
�������ϱ�������������
	����1������1��ʼ������
	����2������1����������
	����3������2��ʼ������
	����4������2����������
	����3��Ŀ��������ʼ������
	����ֵ�� Ŀ���������һ��Ԫ�صĵ�������ַ
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