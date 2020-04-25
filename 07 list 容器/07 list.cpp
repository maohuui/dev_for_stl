#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

/*
�ж� list ��һ��˫��ѭ������
*/
void test01()
{
	list<int> myList;
	for (int i = 0; i < 10; i++)
	{
		myList.push_back(i + 10);
	}

	//2013����
	/*
	list<int>::_Nodeptr node = myList._Myhead->_Next;
	for (int i = 0; i < myList._Mysize * 2; i++)
	{
		cout << "Node: " << node->_Myval << endl;
		node = node->_Next;
		//node->_Prev;
		if (node == myList._Myhead)
		{
			node = node->_Next;
		}
	}
	*/
}
/*
list ���캯��
	list<T> list;
	list(beg, end);
	list(n, elem);
	list(const list &list);
list ����Ԫ�صĲ����ɾ��
	push_back(elem);
	pop_back();
	push_front(elem);
	pop_front();
	insert(pos, elem);
	insert(pos, n, elem);
	insert(pos, beg, end);
	clear();
	erase(beg, end);
	erase(pos);
	remove(elem);
*/
void printList(list<int>& lt)
{
	for (list<int>::iterator it = lt.begin(); it != lt.end(); it++)
	{
		cout << " " << *it;
	}
	cout << endl;
}
void test02()
{
	list<int> L1;
	list<int> L2(10, 20);
	list<int> L3(L2.begin(), L2.end());

	list<int> L4;
	L4.push_back(10);
	L4.push_back(34);
	L4.push_back(3);
	L4.push_back(5);
	L4.push_front(200);
	L4.push_front(500);
	L4.push_front(300);
	L4.push_front(600);

	printList(L4);

	//�����ӡ
	for (list<int>::reverse_iterator it = L4.rbegin(); it != L4.rend(); it++)
	{
		cout << " " << *it;
	}
	cout << endl;

	L4.insert(L4.begin(), 80000);
	printList(L4);

	L4.erase(L4.begin());
	printList(L4);

	L4.remove(200); //ֱ��ɾ�����������е���elemԪ��ƥ���Ԫ��
	printList(L4);
}
/*
list ��С����
	size();
	empty();
	resize(num);
	resize(num, elem);
list ��ֵ����
	assign(beg, end):
	assign(n.elem);
	list& operator=(const list &lst);
	swap(lst);
list ���ݴ�ȡ
	front();��һ��Ԫ��
	back();���һ��Ԫ��
*/
void test03()
{
	list<int> L4;
	L4.push_back(10);
	L4.push_back(34);
	L4.push_back(3);
	L4.push_back(5);
	L4.push_front(200);
	L4.push_front(500);
	L4.push_front(300);
	L4.push_front(600);

	list <int> L;
	L.assign(L4.begin(), L4.end());
	printList(L);

	L.assign(10, 4000);
	printList(L);

	cout << " L.front() = " << L.front() << endl;
	cout << " L.back() = " << L.back() << endl;
}
/*
list ��ת������
	reverse(); ��ת����
	sort();����
*/
bool MyCompareList(int v1, int v2)
{
	return v1 > v2;
}
void test04()
{
	list<int> L4;
	L4.push_back(10);
	L4.push_back(34);
	L4.push_back(3);
	L4.push_back(5);
	L4.push_front(200);
	L4.push_front(500);
	L4.push_front(300);
	L4.push_front(600);

	L4.reverse(); //��ת���ʱ��㷨
	printList(L4);

	//����
	//���е�ϵͳ�ṩ�ı�׼�㷨��ʹ�õ������ṩ�ĵ���������֧���������
	//��֧��������ʵĵ��������������ڲ����Ӧ�ṩ��Ӧ���㷨�Ľӿ�
	//sort(L4.begin(), L4.end());
	L4.sort(); //Ĭ�ϵ�������� �Ǵ�С����

	//�޸��������Ϊ�Ӵ�С
	L4.sort(MyCompareList); 
	printList(L4);
}
// �Զ�����������
class Person
{
public:
	Person(string name, int age, int height)
		: m_Name(name)
		, m_Age(age)
		, m_Height(height)
	{}

	// ����==���㷨
	bool operator==(const Person& p)const
	{
		if (this->m_Age == p.m_Age && this->m_Height == p.m_Height && this->m_Name == p.m_Name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	string m_Name;
	int m_Age;
	int m_Height;
};

//��������
bool MyComparePerson(Person& p1, Person& p2)
{
	//���������ͬ��������߽���
	if(p1.m_Age == p2.m_Age)
		return p1.m_Height < p2.m_Height;
	return p1.m_Age < p2.m_Age; //����
}
void test05()
{
	list<Person> L;

	Person p1("С��", 20, 155);
	Person p2("С��", 20, 160);
	Person p3("����", 40, 175);
	Person p4("����", 56, 166);
	Person p5("С��", 20, 160);
	Person p6("����", 70, 175);
	Person p7("С��", 20, 160);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	L.push_back(p7);

	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << " name : " << (*it).m_Name << " age: " << (*it).m_Age << " height: " << (*it).m_Height << endl;;
	}
	L.sort(MyComparePerson);
	cout << " ����� " << endl;
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << " name : " << (*it).m_Name << " age: " << (*it).m_Age << " height: " << (*it).m_Height << endl;;
	}
	L.remove(p5);// ɾ���ظ�
	cout << " ɾ���� " << endl;
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << " name : " << (*it).m_Name << " age: " << (*it).m_Age << " height: " << (*it).m_Height << endl;;
	}
}
int main()
{
	cout << "-----------------test01()----------------------- " << endl;
	test01();

	cout << "-----------------test02()----------------------- " << endl;
	test02();

	cout << "-----------------test03()----------------------- " << endl;
	test03();

	cout << "-----------------test04()----------------------- " << endl;
	test04();

	cout << "-----------------test05()----------------------- " << endl;
	test05();

	return EXIT_SUCCESS;
}