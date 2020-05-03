#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <algorithm>
#include <numeric>
#include <time.h>
using namespace std;

/*
演讲比赛有24 个选手，三轮
选手 ：姓名 得分 选手编号
第一轮 选手抽签 选手比赛 查看比赛结果
第二轮 选手抽签 选手比赛 查看比赛结果
第三轮 选手抽签 选手比赛 查看比赛结果
*/
class Speaker
{
public:
	string m_Name;
	int m_Score[3];//选手三轮得分

};
void createSpeaker(vector<int>& v, map<int, Speaker>& m)
{
	string nameSeed = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < 24; i++)
	{
		string name = "选手";
		name += nameSeed[i];
		Speaker sp;
		sp.m_Name = name;

		for (int j = 0; j < 3; j++)
			sp.m_Score[j] = 0;

		v.push_back(i+100);
		m.insert(m.begin(), make_pair(i+100, sp));
	}
}
void speechDraw(vector<int>& v)
{
	random_shuffle(v.begin(), v.end());
}
void speechContest(int index, vector<int>& v, map<int, Speaker>& m, vector<int>& v2)
{
	multimap<int, int, greater<int>>mGroup; // 存放小组信息，int 
	int num = 0;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		num++;
		deque<int>d;// deque存放评委打分
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
		}
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();

		int sum = accumulate(d.begin(),d.end(), 0);
		int avg = sum / d.size();
		m[*it].m_Score[index-1] = avg;

		//将信息存放到临时容器中
		mGroup.insert(make_pair(avg, *it));

		//每6个选手取出前三晋级
		if (num % 6 == 0)
		{
			/*for (multimap<int, int, greater<int>>::iterator mit = mGroup.begin(); mit != mGroup.end(); mit++)
			{
				cout << "编号： " << mit->second << " 姓名： " << m[mit->second].m_Name << " 得分：" << mit->first;
			}
			num = 0;*/

			int count = 0;
			for (multimap<int, int, greater<int>>::iterator mit = mGroup.begin(); mit != mGroup.end(),count< 3; mit++, count ++)
			{
				v2.push_back((*mit).second);
			}
			mGroup.clear();
		}
;	}
}
void showScore(int index , vector<int>& v, map<int, Speaker>& m)
{
	cout << "第" << index << "轮比赛成绩如下 " << endl;
	/*for (map<int, Speaker>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "编号： " << it->first << " 姓名： " << it->second.m_Name << " 分数：" << it->second.m_Score[index] << endl;
	}*/
	cout << " 晋级人员编号如下：" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "编号： " << (*it) << endl;
	}
}
void test01()
{
	vector<int>v; //存放选手编号容器
	map<int, Speaker> m; //存放选手以及选手对应编号

	//创建选手
	createSpeaker(v, m);
	for (map<int, Speaker>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "编号： " << it->first << " 姓名： " << it->second.m_Name << " 第一轮分数：" << it->second.m_Score[0] << endl;
	}
	cout << " -----------------------------第一轮---------------------------------" << endl;
	//抽签,随机打乱
	speechDraw(v);

	//选手比赛
	vector<int> v2; //第一轮晋级人员编号
	speechContest(1, v, m, v2);

	//显示得分
	showScore(1, v2, m);

	//第二轮比赛
	cout << " ------------------------------第二轮----------------------------------" << endl;
	speechDraw(v2);
	vector<int> v3; //第一轮晋级人员编号
	speechContest(2, v2, m, v3);
	showScore(2, v3, m);

	//第三轮
	cout << " -------------------------------第三轮----------------------------------" << endl;
	speechDraw(v3);
	vector<int> v4; //第一轮晋级人员编号
	speechContest(3, v3, m, v4);
	showScore(3, v4, m);
}
int main()
{
	srand((unsigned int)time(NULL));

	test01();
	return EXIT_SUCCESS;
}