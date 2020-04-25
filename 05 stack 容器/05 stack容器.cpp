#include <iostream>
#include <stack>
using namespace std;

/*
stack ���캯��
	stack<T>stkT; //Ĭ�Ϲ���
	stack(const stack &stk);//��������
stack ��ֵ����
	stack& operator=(const stack &stk);
deque ˫�˲����ɾ������
	push(elem);
	pop();
	top();
stack ��С����
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
		cout << " " << s.top() << endl;  //ջ��Ԫ��
		s.pop(); //����ջ��
	}
	cout << "size: " << s.size() << endl;
}

int main()
{
	cout << "-----------------test01()----------------------- " << endl;
	test01();

	return EXIT_SUCCESS;
}