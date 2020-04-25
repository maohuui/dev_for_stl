#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

/*
map 构造函数
	map<T1, T2> mapTT;
	map(const map &mp);
map 赋值操作
	map& operator=(const map &mp);
	seap(mp);
map 大小操作
	size();
	empty();
map 插入和删除操作
	map.insert(elem); //返回pair<interator,bool>
	map<int,string>mapStu;
//第一种通过pair的方式插入对象
	mapStu.insert(pair<int, string>(3, ""));
//第二种通过make_pair的方式插入对象
	mapStu.insert(make_pair(3, ""));
//第三种通过value_type的方式插入对象
	mapStu.insert(map<int, string>::value_type(3, ""));
//第四种通过数组的方式插入对象
	mapStu[3] = "小王"
*/

void test01()
{
	map<int, int> mp;

	//插入方式：
	//第一种
	mp.insert(pair<int, int>(1, 20));

	//第二种
	mp.insert(make_pair(2, 40));

	//第三种
	mp.insert(map<int, int>::value_type(3, 60));

	//第四种
	mp[4] = 80;

	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		cout << " key = " << it->first << " value =  " << it->second << endl;
	}
	
	//误操作
	// 会创建一个0值出来，所以不建议使用第四章赋值方式
	cout << mp[5] << endl;
	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		cout << " key = " << it->first << " value =  " << it->second << endl;
	}
}
/*
map 删除操作
	clear();
	erase(pos); 
	erase(beg, end);
	erase(keyElem); //按照key删除
map 查找操作
	find(key) //按照key 查找
	count(keyelem);
	lower_bound(keyElem);
	upper_bound(keyElem);
	equal_bound(keyElem);
*/
void test02()
{
	map<int, int> mp;

	mp.insert(pair<int, int>(1, 20));
	mp.insert(make_pair(2, 40));
	mp.insert(map<int, int>::value_type(3, 60));
	mp[4] = 80;

	mp.erase(3);
	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		cout << " key = " << it->first << " value =  " << it->second << endl;
	}
	mp.insert(map<int, int>::value_type(3, 100));

	map<int, int>::iterator pos = mp.find(3);
	if(pos != mp.end())
	{
		cout << "找到 key = " << pos->first << " value =  " << pos->second << endl;
	}

	int num = mp.count(4);
	cout << "找到 key = 4 的个数: " << num << endl;

	map<int, int>::iterator res = mp.lower_bound(3);
	if (res != mp.end())
	{
		cout << "找到 lower_bound 的 key = " << res->first << " value =  " << res->second << endl;
	}

	res = mp.upper_bound(3);
	if (res != mp.end())
	{
		cout << "找到 upper_bound 的 key = " << res->first << " value =  " << res->second << endl;
	}

	pair<map<int, int>::iterator, map<int, int>::iterator>it1 = mp.equal_range(3);
	if (it1.first != mp.end())
	{
		cout << "找到equal_range 中 lower_bound 的 key = " << it1.first->first << " value =  " << it1.first->second << endl;
	}
	else
	{
		cout << " 未找到" << endl;
	}

	if (it1.second != mp.end())
	{
		cout << "找到equal_range 中 upper_bound 的 key = " << it1.second->first << " value =  " << it1.second->second << endl;
	}
	else
	{
		cout << " 未找到" << endl;
	}
}
class MyCompare
{
public:
	bool operator()(int val1, int val2)const
	{
		return val1 > val2;
	}
};
/*
按key降序
*/
void test03()
{
	map<int, int, MyCompare> mp;

	mp.insert(pair<int, int>(1, 20));
	mp.insert(make_pair(2, 40));
	mp.insert(map<int, int>::value_type(3, 60));
	mp[4] = 80;

	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		cout << " key = " << it->first << " value =  " << it->second << endl;
	}
}

int main()
{
	cout << "-------------------- test01() -----------------------" << endl;
	test01();

	cout << "-------------------- test02() -----------------------" << endl;
	test02();

	cout << "-------------------- test03() -----------------------" << endl;
	test03();

	return EXIT_SUCCESS;
}