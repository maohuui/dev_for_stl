#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
using namespace std;

/*
accmulate�㷨����������Ԫ���ۼ��к�
	����1����ʼ������
	����2������������
	����3����ʼ���ۼ�ֵ
	����ֵ�� �ۼƺ�
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
fill �㷨�������������Ԫ��
	����1��������ʼ������
	����2����������������
	����3�����Ԫ��
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