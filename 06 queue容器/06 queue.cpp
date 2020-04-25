#include <iostream>
#include <queue>
using namespace std;

/*
queue ���캯��
	queue<T> queT; //Ĭ�Ϲ���
	queue(const queue &que);//��������
queue ��ֵ����
	queue& operator=(const queue &stk);
queue ˫�˲����ɾ������
	push(elem);
	pop();
	back()
	front();
queue ��С����
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
		Person p = q.front(); // ��ͷԪ��
		cout << "��ͷ---  name: " << p.m_Name << " age: " << p.m_Age << endl;  //Ԫ��

		Person p1 = q.back(); // ��βԪ��
		cout << "��β---  name: " << p1.m_Name << " age: " << p1.m_Age << endl;  //Ԫ��

		q.pop(); //����
	}
	cout << "size: " << q.size() << endl;
}

int main()
{
	cout << "-----------------test01()----------------------- " << endl;
	test01();

	return EXIT_SUCCESS;
}