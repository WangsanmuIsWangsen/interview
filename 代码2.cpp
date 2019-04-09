#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string trans(int x);
int main(void)
{
	int T;   //数据组数
	cin >> T;    //1<=T<=10
	int num[11];
	for (int i = 0; i < T; i++)
	{
		cin >> num[i];
	}
	for (int i = 0; i < T; i++)
	{
		int z = 0,temp=num[i];
		while (temp)   //计算十进制数的位数
		{
			temp = temp / 10;
			z++;
		}
		if (z <= 3)
		{
			string result = trans(num[i]);
			cout << result << endl;
		}
		else {
			int temp2=num[i];
			string result_1, str1;
			while (temp2)
			{
				if (temp2 <= 999)
				{
					str1 = trans(temp2);
					temp2 = 0;
				}
				else {
					int temp1 = 0;
					for (int t = 0; t < 3; t++)
					{
						int quanzhi = 0;
						switch (t) {
						case 0: {
							quanzhi = 100;
							break;
						}
						case 1: {
							quanzhi = 10;
							break;
						}
						case 2: {
							quanzhi = 1;
							break;
						}
						}
						temp1 += (temp2 % 10)*quanzhi;
						temp2 = temp2 / 10;
					}
					str1 = trans(temp1);
				}
				result_1 = str1 + result_1;
			}
			cout << result_1 << endl;
		}
	}
	return 0;
}
string trans(int x)
{
	string s;
	while (x)  //当x!=0
	{
		s.push_back('0' + x % 2);
		x = x / 2;
	}
	while((s.size())%5!=0)   //如果不是5的倍数，那么前边补0
	{
		s.push_back('0');   //插入0
	}
	reverse(s.begin(),s.end());   //反转
	string ret;
	int length = s.size() / 5;
	for (int j = 0; j < length; j++)
	{
		int count = 0;
		for (int i = j*5; i < j*5+5; i++)
		{
			int quan;
			switch (i - j * 5) {
			case 0: {
				quan = 16;
				break;
				}
			case 1: {
				quan = 8;
				break;
			}
			case 2: {
				quan = 4;
				break;
			}
			case 3: {
				quan = 2;
				break;
			}
			case 4: {
				quan = 1;
				break;
			}
			}
			
			count += (s[i] - '0')*quan;   //每五个一组计算数值
		}
		if (count >= 10)
		{
			ret.push_back('A' + count - 10);
		}
		else ret.push_back('0' + count);
	}
	return ret;
}