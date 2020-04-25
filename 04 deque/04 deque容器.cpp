#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <time.h>
using namespace std;

/*
deque 构造函数
	deque<T>deqT; //默认构造
	deque(beg, end);//将[beg, end)区间中的元素拷贝
	deque(n, elem);//将n个elem拷贝
	deque(const deque &deq);//拷贝构造
deque 赋值操作
	assign(beg, end); //将[beg, end)区间中的元素赋值
	assign(n, elem);//将n个elem赋值
	deque& operator=(const deque &deq);
	swap(deq);//将deq与本身元素互换
deque 大小操作
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
//三种迭代器
// 普通：iterator
// 反向： reverse_iterator
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
		cout << " deq 为空 " << endl;
	}
	else
	{
		cout << " deq 不为空" << endl;
	}
}
/*
deque 双端插入和删除操作
	push_back(elem);//尾部插入元素
	push_front(elem);//头部插入元素
	pop_back(); //删除最后一个元素
	pop_front();//删除第一个元素
deque 数据存取
	at(idx);
	operator[];
	front();
	back();
deque 插入操作
	insert(pos, elem);
	insert(pos, n, elem);
	insert(pos, beg, end);
deque 删除操作
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
降序
*/
bool MyCompare(int v1, int v2)
{
	return v1 > v2;
}
/*
选手打分，去除最高最低，求平均
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

	//利用sort 排序
	//sort(deq.begin(), deq.end());
	sort(deq.begin(), deq.end(), MyCompare); //默认是升序，降序使用
	printDeque(deq);

	deq.pop_back();
	deq.pop_front();
	int sum = 0;
	for (deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
	{
		sum += (*it);
	}
	cout << " 平均分： " << (sum / deq.size()) << endl;
}

/*
有五名选手，选手ABCDE，10个评委分别对每一位选手打分，去除最高，去除最低，去平均分
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
		string name = "选手";
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
		deque<int> d; //存放评委打分的容器
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60; // 60 ~ 100
			d.push_back(score);
		}
		sort(d.begin(), d.end());

		d.pop_back(); // 去除最高
		d.pop_front(); // 去除最低

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

	//设置随机种子
	srand((unsigned int)time(NULL));
	test04();

	return EXIT_SUCCESS;
}