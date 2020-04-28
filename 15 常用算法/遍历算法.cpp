#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

/*
��������Ԫ��
	for_each()
		����1����ʼ������
		����2������������
		����3�������ص����ߺ�������
		����ֵ����������
*/
class MyPrintClass
{
public:
	void operator()(int val)
	{
		m_Count++;
		cout << val << endl;
	}
	int m_Count = 0;
};

class MyPrintClass1 : public binary_function<int, int, void>
{
public:
	void operator()(int val, int start)const
	{
		cout << val + start << endl;
	}
};
void MyprintFunc(int val)
{
	cout << val << endl;
}
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(10 * i);
	}
	//����
	for_each(v.begin(), v.end(), MyprintFunc);

	// ��������
	MyPrintClass mp = for_each(v.begin(), v.end(), MyPrintClass());

	//�����з���ֵ
	cout << "count: " << mp.m_Count << endl;

	//���԰󶨲������������
	for_each(v.begin(), v.end(), bind2nd(MyPrintClass1(), 1000));
}

/*
transform �㷨���������������е�Ԫ�ذ��˵���һ��������
	transform�����Ŀ�����������ڴ棬������Ҫ��ǰ����
	����1��Դ������ʼ������
	����2��Դ��������������
	����3��Ŀ��������ʼ������
	����4���ص��������ߺ�������
	����ֵ������Ŀ������������
*/
class MyTransform
{
public:
	int operator()(int val)
	{
		return val;
	}
};
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(20 * i);
	}
	vector<int> target;
	target.resize(v.size()); //��ǰָ����С
	transform(v.begin(), v.end(), target.begin(), MyTransform());
	for_each (target.begin(), target.end(), [](int val) { cout << val << endl; });
}
int main()
{
	cout << "--------------------test01()---------------" << endl;
	test01();

	cout << "--------------------test02()---------------" << endl;
	test02();

	return EXIT_SUCCESS;
}