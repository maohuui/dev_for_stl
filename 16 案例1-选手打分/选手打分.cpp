#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <algorithm>
#include <numeric>
#include <time.h>
using namespace std;

/*
�ݽ�������24 ��ѡ�֣�����
ѡ�� ������ �÷� ѡ�ֱ��
��һ�� ѡ�ֳ�ǩ ѡ�ֱ��� �鿴�������
�ڶ��� ѡ�ֳ�ǩ ѡ�ֱ��� �鿴�������
������ ѡ�ֳ�ǩ ѡ�ֱ��� �鿴�������
*/
class Speaker
{
public:
	string m_Name;
	int m_Score[3];//ѡ�����ֵ÷�

};
void createSpeaker(vector<int>& v, map<int, Speaker>& m)
{
	string nameSeed = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < 24; i++)
	{
		string name = "ѡ��";
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
	multimap<int, int, greater<int>>mGroup; // ���С����Ϣ��int 
	int num = 0;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		num++;
		deque<int>d;// deque�����ί���
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

		//����Ϣ��ŵ���ʱ������
		mGroup.insert(make_pair(avg, *it));

		//ÿ6��ѡ��ȡ��ǰ������
		if (num % 6 == 0)
		{
			/*for (multimap<int, int, greater<int>>::iterator mit = mGroup.begin(); mit != mGroup.end(); mit++)
			{
				cout << "��ţ� " << mit->second << " ������ " << m[mit->second].m_Name << " �÷֣�" << mit->first;
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
	cout << "��" << index << "�ֱ����ɼ����� " << endl;
	/*for (map<int, Speaker>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "��ţ� " << it->first << " ������ " << it->second.m_Name << " ������" << it->second.m_Score[index] << endl;
	}*/
	cout << " ������Ա������£�" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "��ţ� " << (*it) << endl;
	}
}
void test01()
{
	vector<int>v; //���ѡ�ֱ������
	map<int, Speaker> m; //���ѡ���Լ�ѡ�ֶ�Ӧ���

	//����ѡ��
	createSpeaker(v, m);
	for (map<int, Speaker>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "��ţ� " << it->first << " ������ " << it->second.m_Name << " ��һ�ַ�����" << it->second.m_Score[0] << endl;
	}
	cout << " -----------------------------��һ��---------------------------------" << endl;
	//��ǩ,�������
	speechDraw(v);

	//ѡ�ֱ���
	vector<int> v2; //��һ�ֽ�����Ա���
	speechContest(1, v, m, v2);

	//��ʾ�÷�
	showScore(1, v2, m);

	//�ڶ��ֱ���
	cout << " ------------------------------�ڶ���----------------------------------" << endl;
	speechDraw(v2);
	vector<int> v3; //��һ�ֽ�����Ա���
	speechContest(2, v2, m, v3);
	showScore(2, v3, m);

	//������
	cout << " -------------------------------������----------------------------------" << endl;
	speechDraw(v3);
	vector<int> v4; //��һ�ֽ�����Ա���
	speechContest(3, v3, m, v4);
	showScore(3, v4, m);
}
int main()
{
	srand((unsigned int)time(NULL));

	test01();
	return EXIT_SUCCESS;
}