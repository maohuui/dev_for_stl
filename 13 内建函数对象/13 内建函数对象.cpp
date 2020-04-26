#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

/*
6���㷨�ຯ�����󣬳���negate ��һԪ���㣬������Ϊ��Ԫ����
	template<class T> T plus <T>;  //�ӷ��º���
	template<class T> T minus <T>;  //�����º���
	template<class T> T multiplies <T>;  //�˷��º���
	template<class T> T divides <T>;  //�����º���
	template<class T> T modulus <T>;  //ȡģ�º���
	template<class T> T negate <T>;  //ȡ���º���
*/
void test01()
{
	plus<int> p;
	cout << "��ӣ� " << p(20, 20) << endl;

	minus<int> mi;
	cout << "����� " << mi(20, 20) << endl;

	multiplies<int> ml;
	cout << "��ˣ� " << ml(20, 20) << endl;

	divides<int> d;
	cout << "����� " << d(20, 20) << endl;

	modulus<int> mo;
	cout << "ȡģ�� " << mo(20, 20) << endl;

	negate<int> n;
	cout << "10 ��ȡ���� " << n(10) << endl;
}

/*
6����ϵ�ຯ�����󣬶�Ϊ��Ԫ����
	template<class T> bool equal_to <T>;  //����
	template<class T> bool not_equal_to <T>;  //������
	template<class T> bool greater <T>;  //����
	template<class T> bool greater_equal <T>;  //���ڵ���
	template<class T> bool less <T>;  //С��
	template<class T> bool less_equal <T>;  //С�ڵ���
*/
void test02()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(45);
	v.push_back(30);
	v.push_back(50);
	v.push_back(23);
	v.push_back(100);

	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	cout << endl;
}

/*
6�߼����������㺯����not ΪһԪ���㣬����Ϊ��Ԫ����
	template<class T> bool logical_and <T>;  //�߼���
	template<class T> bool logical_or <T>;  //�߼���
	template<class T> bool logical_not <T>;  //�߼���
*/
void test03()
{
	logical_and<int> la;
	cout << "logical_and: " << la(0, 1) << endl;

	logical_or<int> lo;
	cout << "logical_or: " << lo(0, 1) << endl;

	logical_not<int> ln;
	cout << "logical_not: " << ln(0) << endl;
}

int main()
{
	cout << "-----------------test01()----------------------- " << endl;
	test01();

	cout << "-----------------test02()----------------------- " << endl;
	test02();

	cout << "-----------------test03()----------------------- " << endl;
	test03();
	return EXIT_SUCCESS;
}