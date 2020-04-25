#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <time.h>
using namespace std;

/*
deque ���캯��
	deque<T>deqT; //Ĭ�Ϲ���
	deque(beg, end);//��[beg, end)�����е�Ԫ�ؿ���
	deque(n, elem);//��n��elem����
	deque(const deque &deq);//��������
deque ��ֵ����
	assign(beg, end); //��[beg, end)�����е�Ԫ�ظ�ֵ
	assign(n, elem);//��n��elem��ֵ
	deque& operator=(const deque &deq);
	swap(deq);//��deq�뱾��Ԫ�ػ���
deque ��С����
	size();
	empty();
	resize(num);
	resize(num, elem);
*/
void printDeque(deque<int>& d)
{
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
		cout << *it << " ";
	cout << endl;
}
//���ֵ�����
// ��ͨ��iterator
// ���� reverse_iterator
// const: const_iterator
void printDequeC(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		//*it = 100;
		cout << *it << " ";
	}
		
	cout << endl;
}

void test01()
{
	deque<int> deq;
	deq.push_back(12);
	deq.push_back(3);
	deq.push_back(4);
	deq.push_back(5);
	deq.push_back(2);
	printDeque(deq);

	deque<int>d2(10, 20);
	printDeque(d2);

	deq.swap(d2);
	printDeque(deq);
	printDeque(d2);

	if (deq.empty())
	{
		cout << " deq Ϊ�� " << endl;
	}
	else
	{
		cout << " deq ��Ϊ��" << endl;
	}
}
/*
deque ˫�˲����ɾ������
	push_back(elem);//β������Ԫ��
	push_front(elem);//ͷ������Ԫ��
	pop_back(); //ɾ�����һ��Ԫ��
	pop_front();//ɾ����һ��Ԫ��
deque ���ݴ�ȡ
	at(idx);
	operator[];
	front();
	back();
deque �������
	insert(pos, elem);
	insert(pos, n, elem);
	insert(pos, beg, end);
deque ɾ������
	clear();
	erase(beg, end);
	erase(pos);
*/
void test02()
{
	deque<int> deq;
	deq.push_back(12);
	deq.push_back(3);
	deq.push_back(4);
	deq.push_back(5);
	deq.push_back(2);
	printDeque(deq);

	deq.push_front(1000);
	printDeque(deq);

	deq.pop_back();
	printDeque(deq);

	deq.pop_front();
	printDeque(deq);

	deq.insert(++deq.begin(), 20000);
	printDeque(deq);

	deq.erase(++deq.begin());
	printDeque(deq);
}
/*
����
*/
bool MyCompare(int v1, int v2)
{
	return v1 > v2;
}
/*
ѡ�ִ�֣�ȥ�������ͣ���ƽ��
*/
void test03()
{
	deque<int> deq;
	deq.push_back(20);
	deq.push_back(50);
	deq.push_back(100);
	deq.push_back(80);
	deq.push_back(60);
	printDeque(deq);

	//����sort ����
	//sort(deq.begin(), deq.end());
	sort(deq.begin(), deq.end(), MyCompare); //Ĭ�������򣬽���ʹ��
	printDeque(deq);

	deq.pop_back();
	deq.pop_front();
	int sum = 0;
	for (deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
	{
		sum += (*it);
	}
	cout << " ƽ���֣� " << (sum / deq.size()) << endl;
}

/*
������ѡ�֣�ѡ��ABCDE��10����ί�ֱ��ÿһλѡ�ִ�֣�ȥ����ߣ�ȥ����ͣ�ȥƽ����
*/

class Person
{
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}
	string m_Name;
	int m_Score;
};

void createPerson(vector<Person> &v)
{

	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		int score = 0;
		Person p(name, score);
		v.push_back(p);
	}
}

void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int> d; //�����ί��ֵ�����
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60; // 60 ~ 100
			d.push_back(score);
		}
		sort(d.begin(), d.end());

		d.pop_back(); // ȥ�����
		d.pop_front(); // ȥ�����

		int sum = 0;
		for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
		{
			sum += (*it);
		}
		int avg = sum / d.size();

		(*it).m_Score = avg;
	}
}

void showScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "name: " << (*it).m_Name << " avg score: " << (*it).m_Score << endl;
	}
}
void test04()
{
	vector<Person> v;
	createPerson(v);

	setScore(v);

	showScore(v);

}

int main()
{
	/*cout << "-----------------test01()----------------------- " << endl;
	test01();

	cout << "-----------------test02()----------------------- " << endl;
	test02();

	cout << "-----------------test03()----------------------- " << endl;
	test03();*/

	//�����������
	srand((unsigned int)time(NULL));
	test04();

	return EXIT_SUCCESS;
}