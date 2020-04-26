#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//ν�ʣ���ͨ�������߷º�������ֵΪbool����
class GreaterThen20
{
public:
	bool operator()(int val1)
	{
		return val1 > 50;
	}
};

void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(34);
	v.push_back(67);
	v.push_back(34);
	v.push_back(80);

	//�ҵ���һ������50����
	vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterThen20());

	if(pos != v.end())
	{
		cout << "�ҵ���һ������50����Ϊ�� " << *pos << endl;
	}
	else {
		cout << " û���ҵ� " << endl;
	}
}

class MyCompare
{
public:
	bool operator()(int val1, int val2)
	{
		return val1 > val2;
	}
};

bool MyCompareFunc(int val1, int val2)
{
	return val1 > val2;
}

//��Ԫν��
void test02()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(34);
	v.push_back(67);
	v.push_back(34);
	v.push_back(80);

	//sort(v.begin(), v.end()); // Ĭ���Ǵ�С����
	 //ʵ�ִӴ�С
	sort(v.begin(), v.end(), MyCompareFunc); // ʹ����ͨ����
	//sort(v.begin(), v.end(), MyCompare()); // ʹ�÷º���

	//lamda ���ʽ
	for_each(v.begin(), v.end(), [](int val) { cout << val << endl; });
}

int main()
{
	cout << "-----------------test01()----------------------- " << endl;
	test01();

	cout << "-----------------test02()----------------------- " << endl;
	test02();
	return EXIT_SUCCESS;
}