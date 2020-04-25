#include <iostream>
#include <vector>
#include <list>
using namespace std;

void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		cout << "capacity: " << v.capacity() << endl;
	}
}
/*
vector ���캯��
	vector<T> v;
	vector(v.begin(), v.end());
	vector(n. elem);
	vector(const vector &v);

vector ���ø�ֵ����
	assign(begin, end);
	assign(n, elem);
	vector& operator=(const vector &vec);
	swap(vec);
*/
void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << " " << *it;
	}
	cout << endl;
}
void test02()
{
	vector<int> v1;

	vector<int> v2(10, 30);
	printVector(v2);

	vector<int>v3(v2.begin(), v2.end());
	printVector(v3);

	vector<int> v4;
	//v4.assign(v3.begin(), v3.end());
	v4 = v3;
	printVector(v4);


	int arr[] = { 2,3,4,5,6,1 };
	vector<int> v5(arr, arr + sizeof(arr) / sizeof(int));
	printVector(v5);

	v4.swap(v5);
	printVector(v4);
}
/*
vector ��С����
	size();
	empty();
	resize(int num);
	resize(int num, elem);//����ָ���������ȣ��������䳤��elem��䣬����򳬳��Ĳ���ɾ��
	capacity();
	reserve(int len);
vector ���ݴ�ȡ����
	at(int idx);
	operator[];
	fron();//���������е�һ������Ԫ��
	back();//�������������һ������Ԫ��
vector �����ɾ������
	insert(const_iterator pos, int count, ele);//������ָ���λ��pos����count��Ԫ��ele
	push_back(ele);//β������Ԫ��ele
	pop_back();//ɾ�����һ��Ԫ��
	erase(const_itreator start, const_iteratorend);//ɾ����������start��end֮���Ԫ��
	clear();//ɾ�����������е�Ԫ��
*/
void test03()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(3);
	v.push_back(23);

	cout << v.size() << endl;
	if (v.empty())
	{
		cout << "vΪ�� " << endl;
	}
	else
	{
		cout << "v ��Ϊ�� " << endl;
	}
	v.resize(10);
	printVector(v);

	v.resize(3);
	printVector(v);

	v.resize(10, 5);

	cout << "v�ĵ�һ��Ԫ�أ� " << v.front() << endl;
	cout << "v�����һ��Ԫ�أ� " << v.back() << endl;

	v.insert(v.begin(), 10000);
	printVector(v);

	v.insert(v.begin(), 4, 20000);
	printVector(v);

	v.pop_back();
	printVector(v);

	v.erase(v.begin());
	printVector(v);

	//v.erase(v.begin(), v.end());
	v.clear();
	printVector(v);
}
/*
����swap�����ڴ�
*/
void test04()
{
	vector<int> v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	cout << "v ������ " << v.capacity() << endl;
	cout << "v �Ĵ�С " << v.size() << endl;

	v.resize(3);
	cout << "v ������ " << v.capacity() << endl;
	cout << "v �Ĵ�С " << v.size() << endl;

	//�����ڴ�
	vector<int>(v).swap(v);
	cout << "v ������ " << v.capacity() << endl;
	cout << "v �Ĵ�С " << v.size() << endl;
}
/*
����reverseԤ���ռ�
*/
void test05()
{
	vector<int> v;
	//v.reserve(100000);//Ԥ���ռ�

	int num = 0;
	int* p = NULL;

	//�жϿ���100000���˶��ٴοռ�
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if(p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
	cout << " num: " << num << endl;
}

void test06()
{
	//�������
	vector<int>v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(3);
	v.push_back(23);
	cout << " ��������Ľ���� " << endl;
	printVector(v);

	cout << " ��������Ľ���� " << endl;
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
	{
		cout << " " << *it;
	}
	cout << endl;

	/*
	vector �����ĵ�������������ʵ�����
	����ж�һ�������ĵ������Ƿ�֧���������
	*/
	vector<int>::iterator it = v.begin();
	it++;
	it--;
	it = it + 1; //����﷨ͨ����֧���������

	list<int>l;
	l.push_back(10);
	l.push_back(2);
	list<int>::iterator it1 = l.begin();
	it1++;
	it1--;
	//it1 = it1 + 1;
}

int main()
{
	cout << "----------------------test01()--------------------------" << endl;
	test01();

	cout << "----------------------test02()--------------------------" << endl;
	test02();

	cout << "----------------------test03()--------------------------" << endl;
	test03();

	cout << "----------------------test04()--------------------------" << endl;
	test04();

	cout << "----------------------test05()--------------------------" << endl;
	test05();

	cout << "----------------------test06()--------------------------" << endl;
	test06();

	return EXIT_SUCCESS;
}