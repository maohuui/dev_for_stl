#include <iostream>
using namespace std;

//�������������ĵ��÷�ʽ
class MyPrint
{
public:
	void operator()(int val)
	{
		m_Count ++;

		cout << "val: " << val << endl;
		cout << "m_Count: " << m_Count << endl;
	}
	int m_Count = 0;
	//��������ͨ�������幹�캯�������������������˺������õ�����ʱ������
};

void test01()
{
	MyPrint p;
	p(100);
}

// �������󳬳���ͨ�����ĸ����������������Լ���״̬
void test02()
{
	MyPrint p1;
	p1(10);
	p1(20);
	p1(30);
	p1(40);
	p1(50);
}

// �������������Ϊ�����Ĳ�������
void  doWork(MyPrint mp, int num)
{
	mp(num);
}
void test03()
{
	doWork(MyPrint(), 10000);
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