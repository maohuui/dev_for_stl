#include <iostream>
#include <stack>
using namespace std;

/*
stack 构造函数
	stack<T>stkT; //默认构造
	stack(const stack &stk);//拷贝构造
stack 赋值操作
	stack& operator=(const stack &stk);
deque 双端插入和删除操作
	push(elem);
	pop();
	top();
stack 大小操作
	size();
	empty();
*/
void test01()
{
	stack<int> stkT;
	stkT.push(10);
	stkT.push(4);
	stkT.push(6);
	stkT.push(3);
	stkT.push(9);

	stack<int> s(stkT);
	cout << "size:  " << s.size() << endl;

	while (!s.empty())
	{
		cout << " " << s.top() << endl;  //栈顶元素
		s.pop(); //弹出栈顶
	}
	cout << "size: " << s.size() << endl;
}

int main()
{
	cout << "-----------------test01()----------------------- " << endl;
	test01();

	return EXIT_SUCCESS;
}