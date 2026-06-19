//0015 National Budget
//80ÜÅÌ2ÂÌ®Ì«µZÊðoÍ¹æ
//1sÚÉf[^Zbgnª^¦çêé

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	while(n--)
	{
		const int N = 82;
		string str;
		int arg[2][N] = {0}, result[N] = {0};
		int digit[2];

		for(int i = 0; i < 2; i++)
		{
			cin >> str;
			digit[i] = str.size();
			for(int j = 0; j < digit[i]; j++)
			{
				arg[i][j] = str[j] - '0';
			}
			//vZµâ·¢æ¤É½]
			reverse(arg[i], arg[i]+digit[i]);
		}

		bool isRead[2] = {true, true};
		for(int i = 0; isRead[0] || isRead[1]; i++)
		{
			if(i > digit[0])
				isRead[0] = false;
			if(i > digit[1])
				isRead[1] = false;

			int s = 0;
			if(isRead[0])
				s += arg[0][i];
			if(isRead[1])
				s += arg[1][i];

			result[i] += s%10;
			result[i+1] += s/10 + result[i]/10;
			result[i] %= 10;
		}

		bool isPrint = false;
		for(int i = N-1; i >= 0; i--)
		{
			if(result[i])
				isPrint = true;
			if(isPrint)
				cout << result[i];
		}
		cout << endl;
	}
	return 0;
}