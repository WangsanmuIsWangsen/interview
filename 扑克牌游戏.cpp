#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
typedef struct mynode {
	int val;
	int number;
};
int main(void)
{
	mynode PK[13];    //创建13个扑克牌
	int T;
	cin >> T;
	vector<int > result;    //结果
	vector<int > tmp;
	for (int t = 0; t < T; t++)  //总共循环T次
	{
		for (int i = 0; i < 13; i++)   //初始化扑克牌
		{
			PK[i].val = i + 1;
			PK[i].number = 0;
		}
		int number;
		cin >> number;
		for (int i = 0; i < number; i++)
		{
			getchar();
			string str;
			cin >> str;
			if (str.size() == 1)
			{
				char a = str[0];
				if (a >= '2'&&a <= '9')
					tmp.push_back(a - '0');
				if (a == 'A') tmp.push_back(1);
				if (a == 'J') tmp.push_back(11);
				if (a == 'Q') tmp.push_back(12);
				if (a == 'K') tmp.push_back(13);
			}
			else if (str.size() == 2)    //10
				tmp.push_back(10);
		}
		sort(tmp.begin(), tmp.end());   //从小到大排序
		for(int j=0;j<tmp.size();j++)
		{
			for (int i = 0; i < 13; i++)
			{
				if (PK[i].val == tmp[j]&&PK->number<=4)
					PK[i].number++;
			}
		}
		//判断结构中的顺子
		//int flag = 0;
		int res = 0;
		for (int i = 0; i < 13; i++)
		{
			int beishu = 1;    //倍数
			int s_num = 0;   //用来计数顺子牌数
			if (PK[i].number >= 1)
			{
				int j;
				for (j = i; j < 13; j++)
				{
					if (PK[j].number >= 1)
					{
						beishu = beishu * PK[j].number;
						s_num++;
					}
					else break;
				}
				if (s_num >= 5)   //如果构成了顺子
				{
					switch (s_num) {
					case 5: {
						res += 1; break;
					}
					case 6: {
						res += 3; break;
					}
					case 7: {
						res += 6; break;
					}
					case 8: {
						res += 10; break;
					}
					case 9: {
						res += 15; break;
					}
					case 10: {
						res += 21; break;
					}
					case 11: {
						res += 28; break;
					}
					case 12: {
						res += 36; break;
					}
					case 13: {
						res += 45; break;
					}
					}
				}
				res = res * beishu;
				i = j;
			}
			else if (i > 8) break;  //不可能构成顺子
		}
		result.push_back(res);
		tmp.clear();   //清空
	}
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}
	return 0;
}
