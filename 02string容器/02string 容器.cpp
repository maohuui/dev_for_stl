#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
using namespace std;
/*
C++ 标准库定义了一种 string 类，定义在头文件<string>
	​（1）​string 和 c 风格的字符串比较​：
	​    ​char* 是一个指针，string 是一个类，string类封装了 char* ，管理这个字符串，是char * 型的容器；

	​（2）string封装了很多实用的成员方法，例如 find、copy、delete、replace、insert等；
	​（3）不用考虑内存的释放和越界。

string容器常用的操作
*/

/*
string 的构造函数
	string();
	string(const string& str);
	string(const char *c);
	string(int n, char c);
string 基本操作
	string& operator=(const char *s);
	string& operator=(const string &s);
	string& operator=(char c);
	string assign(const char *s); //把字符串s赋给当前的字符串
	string assign(const char *s, int n);//把字符串s的前n个字符赋值给当前的字符串
	string assign(const string& s);//把字符串s赋给当前字符串
	string assign(int n, char c);//用n个字符c赋值给当前字符串
	string assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串
*/

void test01()
{
	string s1;
	string s2(s1);
	string s3("aaa");
	string s4(10, 'b');

	cout << s3 << endl;
	cout << s4 << endl;

	string s5;
	s5 = s4;
	cout << s5 << endl;

	s5.assign("abcdef", 3);
	cout << s5 << endl;

	string s6 = "qwertyu";
	string s7;
	s7.assign(s6, 2, 3);
	cout << s7 << endl;
}
/*
string 存取字符操作
	char& operator[](int n);
	char& at(int n);
*/
void test02()
{
	string s = "adhfgdhgfd";
	for (int i = 0; i < s.size(); i++)
	{
		//cout << s[i];
		cout << s.at(i) << " ";
	}
	cout << endl;
	//at 和 [] 的区别：[]访问越界直接挂掉，at访问越界，会抛出一个异常out_of_range
	try
	{
		//s[100];
		//s.at(100);
	}
	catch (out_of_range& e)
	//catch(exception &e)
	{
		cout << e.what() << endl;
	}
}
/*
string 拼接操作
	string& operator+=(const string& str);
	string& operator+=(const char* str);
	string& operator+=(const char* c);
	string& append(const char *s);
	string& append(const char *s,int n);
	string& append(const string &s);
	string& append(const string &s, int pos, int n);
	string& append(int n, char c);
*/
void test03()
{
	string str1 = "ni";
	string str2 = "hao";
	str1 += str2;
	cout << str1 << endl;

	string str3 = "STL";
	str1.append(str3);
	cout << str1 << endl;
}
/*
string 查找和替换
	int find(const string& str, int pos=0)const;
	int find(const char* s, int pos=0)const;
	int find(const char*s, int pos, int n)const;
	int find(const char c, int pos=0)const;
	int rfind(const string& str, int pos=npos)const;
	int rfind(const char* s, int pos=npos)const;
	int rfind(const char*s, int pos, int n)const;
	int rfind(const char c, int pos=0)const;
	string& replace(int pos, int n, const string& str);
	string& replace(int pos, int n, const char *s);
*/
void test04()
{
	string str = "abcdef";
	int pos = str.find("def");
	cout << "pos: " << pos << endl; //找到返回第一次找到的位置，找不到返回-1

	int pos1 = str.rfind("f"); //从右往左找,但是返回的还是正常查找的位置
	cout << "pos1: " << pos1 << endl;

	string  str1 = str.replace(1, 3, "1234");
	cout << str1 << endl;
}
/*
string 比较操作
	int compare(const string &s)const;
	int compare(const char &s)const;
*/
void test05()
{
	string str1 = "abcdef";
	string str2 = "abcdef";

	if (str1.compare(str2) == 0)
	{
		cout << " str1 == str2" << endl;
	}
	else if (str1.compare(str2) > 0)
	{
		cout << " str1 > str2" << endl;
	}
	else
	{
		cout << " str1 < str2" << endl;
	}
}
/*
string 子串
	string& substr(int pos = 0, int n = npos)const; //pos开始n个字符组成的字符串
*/
void test06()
{
	string str = "abcdef";
	string substr = str.substr(1, 3);
	cout << substr << endl;

	string email = "mmmh@qq.com";
	int pos = email.find("@");
	string userName = email.substr(0, pos);

	cout << userName << endl;

	string str1 = "www.iii.com";
	//将网站中的每个单词都截取到vector中
	vector<string> v;
	int start = 0;
	while (true)
	{
		int pos = str1.find(".", start);
		if (pos == -1)
		{
			string tmp = str1.substr(start, str1.size() - start);
			v.push_back(tmp);
			break;
		}
		string tmp = str1.substr(start, pos-start);
		v.push_back(tmp);
		start = pos + 1;
	}
	for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " " << endl;
	}
}
/*
string 插入和删除
	string& insert(int pos, const char* s);
	string& insert(int pos, const string& s);
	string& insert(int pos, int n, char c);
	string& erase(int pos, int n = npos); //从pos开始删除n个字符
*/
void test07()
{
	string str = "abcdef";
	str.insert(1, "123");
	cout << str << endl;

	str.erase(1, 3);
	cout << str << endl;
}
/*
string <-->c-style
*/
void test08()
{
	const char* str = "hello";
	string s(str);

	const char* c = s.c_str();
}
/*
注意的地方
*/
void test09()
{
	string s = "abcdef";
	char& a = s[2];
	char& b = s[3];
	a = '1';
	b = '2';
	cout << s << endl;
	cout << (int*)s.c_str() << endl;

	s = "qqqqqqqqqqqqqqqqqqqqqqqqqq"; //如果重新分配内存，原来的引用可能会失效
	//a = '1'; //原来的a 和 b的指向变了，
	//b = '2';

	cout << s << endl;
	cout << (int*)s.c_str() << endl;
}

//将string字符串的所有小写变为大写
void test10()
{
	string s = "abceEFG";
	for (int i = 0; i < s.size(); i++)
	{
		s[i] = toupper(s[i]); //小写转大写
		//s[i] = tolower(s[i]); //大写转小写
	}
	cout << s << endl;


}
int main()
{
	cout << "-------------- test01() ------------- " << endl;
	test01();

	cout << "-------------- test02() ------------- " << endl;
	test02();

	cout << "-------------- test03() ------------- " << endl;
	test03();

	cout << "-------------- test04() ------------- " << endl;
	test04();

	cout << "-------------- test05() ------------- " << endl;
	test05();

	cout << "-------------- test06() ------------- " << endl;
	test06();

	cout << "-------------- test07() ------------- " << endl;
	test07();

	cout << "-------------- test08() ------------- " << endl;
	test08();

	cout << "-------------- test09() ------------- " << endl;
	test09();

	cout << "-------------- test10() ------------- " << endl;
	test10();

	return EXIT_SUCCESS;
}