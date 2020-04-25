#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

/*
判断 list 是一个双向循环链表
*/
void test01()
{
	list<int> myList;
	for (int i = 0; i < 10; i++)
	{
		myList.push_back(i + 10);
	}

	//2013才有
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
list 构造函数
	list<T> list;
	list(beg, end);
	list(n, elem);
	list(const list &list);
list 数据元素的插入和删除
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

	//逆序打印
	for (list<int>::reverse_iterator it = L4.rbegin(); it != L4.rend(); it++)
	{
		cout << " " << *it;
	}
	cout << endl;

	L4.insert(L4.begin(), 80000);
	printList(L4);

	L4.erase(L4.begin());
	printList(L4);

	L4.remove(200); //直接删除所有容器中的与elem元素匹配的元素
	printList(L4);
}
/*
list 大小操作
	size();
	empty();
	resize(num);
	resize(num, elem);
list 赋值操作
	assign(beg, end):
	assign(n.elem);
	list& operator=(const list &lst);
	swap(lst);
list 数据存取
	front();第一个元素
	back();最后一个元素
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
list 反转和排序
	reverse(); 反转链表
	sort();排序
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

	L4.reverse(); //反转，质变算法
	printList(L4);

	//排序，
	//所有的系统提供的标准算法，使用的容器提供的迭代器必须支持随机访问
	//不支持随机访问的迭代器的容器，内部会对应提供相应的算法的接口
	//sort(L4.begin(), L4.end());
	L4.sort(); //默认的排序规则 是从小到大

	//修改排序规则为从大到小
	L4.sort(MyCompareList); 
	printList(L4);
}
// 自定义数据类型
class Person
{
public:
	Person(string name, int age, int height)
		: m_Name(name)
		, m_Age(age)
		, m_Height(height)
	{}

	// 重载==运算法
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

//二次排序
bool MyComparePerson(Person& p1, Person& p2)
{
	//如果年龄相同，按照身高降序
	if(p1.m_Age == p2.m_Age)
		return p1.m_Height < p2.m_Height;
	return p1.m_Age < p2.m_Age; //升序
}
void test05()
{
	list<Person> L;

	Person p1("小李", 20, 155);
	Person p2("小张", 20, 160);
	Person p3("老李", 40, 175);
	Person p4("老张", 56, 166);
	Person p5("小红", 20, 160);
	Person p6("老龙", 70, 175);
	Person p7("小红", 20, 160);

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
	cout << " 排序后： " << endl;
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << " name : " << (*it).m_Name << " age: " << (*it).m_Age << " height: " << (*it).m_Height << endl;;
	}
	L.remove(p5);// 删除重复
	cout << " 删除后： " << endl;
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