#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

/*
map ���캯��
	map<T1, T2> mapTT;
	map(const map &mp);
map ��ֵ����
	map& operator=(const map &mp);
	seap(mp);
map ��С����
	size();
	empty();
map �����ɾ������
	map.insert(elem); //����pair<interator,bool>
	map<int,string>mapStu;
//��һ��ͨ��pair�ķ�ʽ�������
	mapStu.insert(pair<int, string>(3, ""));
//�ڶ���ͨ��make_pair�ķ�ʽ�������
	mapStu.insert(make_pair(3, ""));
//������ͨ��value_type�ķ�ʽ�������
	mapStu.insert(map<int, string>::value_type(3, ""));
//������ͨ������ķ�ʽ�������
	mapStu[3] = "С��"
*/

void test01()
{
	map<int, int> mp;

	//���뷽ʽ��
	//��һ��
	mp.insert(pair<int, int>(1, 20));

	//�ڶ���
	mp.insert(make_pair(2, 40));

	//������
	mp.insert(map<int, int>::value_type(3, 60));

	//������
	mp[4] = 80;

	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		cout << " key = " << it->first << " value =  " << it->second << endl;
	}
	
	//�����
	// �ᴴ��һ��0ֵ���������Բ�����ʹ�õ����¸�ֵ��ʽ
	cout << mp[5] << endl;
	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		cout << " key = " << it->first << " value =  " << it->second << endl;
	}
}
/*
map ɾ������
	clear();
	erase(pos); 
	erase(beg, end);
	erase(keyElem); //����keyɾ��
map ���Ҳ���
	find(key) //����key ����
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
		cout << "�ҵ� key = " << pos->first << " value =  " << pos->second << endl;
	}

	int num = mp.count(4);
	cout << "�ҵ� key = 4 �ĸ���: " << num << endl;

	map<int, int>::iterator res = mp.lower_bound(3);
	if (res != mp.end())
	{
		cout << "�ҵ� lower_bound �� key = " << res->first << " value =  " << res->second << endl;
	}

	res = mp.upper_bound(3);
	if (res != mp.end())
	{
		cout << "�ҵ� upper_bound �� key = " << res->first << " value =  " << res->second << endl;
	}

	pair<map<int, int>::iterator, map<int, int>::iterator>it1 = mp.equal_range(3);
	if (it1.first != mp.end())
	{
		cout << "�ҵ�equal_range �� lower_bound �� key = " << it1.first->first << " value =  " << it1.first->second << endl;
	}
	else
	{
		cout << " δ�ҵ�" << endl;
	}

	if (it1.second != mp.end())
	{
		cout << "�ҵ�equal_range �� upper_bound �� key = " << it1.second->first << " value =  " << it1.second->second << endl;
	}
	else
	{
		cout << " δ�ҵ�" << endl;
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
��key����
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