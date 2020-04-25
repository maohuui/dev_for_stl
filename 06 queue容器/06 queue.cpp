#include <iostream>
#include <queue>
using namespace std;

/*
queue 构造函数
	queue<T> queT; //默认构造
	queue(const queue &que);//拷贝构造
queue 赋值操作
	queue& operator=(const queue &stk);
queue 双端插入和删除操作
	push(elem);
	pop();
	back()
	front();
queue 大小操作
	size();
	empty();
*/
class Person 
{
public:
	Person(string name, int age)
		: m_Name(name)
		, m_Age(age)
	{}
	string m_Name;
	int m_Age;

};
void test01()
{
	queue<Person> que;
	Person p1("aaa", 10);
	Person p2("bbb", 45);
	Person p3("ccc", 63);
	Person p4("dddd", 22);
	Person p5("eee", 4);

	que.push(p1);
	que.push(p2);
	que.push(p3);
	que.push(p4);
	que.push(p5);

	queue<Person> q(que);
	cout << "size:  " << q.size() << endl;

	while (!q.empty())
	{
		Person p = q.front(); // 对头元素
		cout << "对头---  name: " << p.m_Name << " age: " << p.m_Age << endl;  //元素

		Person p1 = q.back(); // 对尾元素
		cout << "对尾---  name: " << p1.m_Name << " age: " << p1.m_Age << endl;  //元素

		q.pop(); //弹出
	}
	cout << "size: " << q.size() << endl;
}

int main()
{
	cout << "-----------------test01()----------------------- " << endl;
	test01();

	return EXIT_SUCCESS;
}