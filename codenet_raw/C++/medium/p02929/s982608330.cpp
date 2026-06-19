#include<iostream>

#define SIZE 200005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

char str[SIZE];
bool black[SIZE];

ll factorial(int n)
{
	ll _n = (ll)n;
	while (n != 1)
	{
		_n *= --n;
	}
	return _n;
}

int main() {
	
	int n;
	cin >> n >> str;

	int bc = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		// 奇数番目
		if (i % 2)
		{
			black[i] = str[i] == 'B';
		}
		// 偶数番目
		else
		{
			black[i] = str[i] == 'W';
		}
	}
	// 組み合わせなしチェック
	for (int i = 0; i < 2 * n; i++)
	{
		if(black[i])
			bc++;
	}
	if (bc != n)
	{
		cout << 0;
		return 0;
	}
	ll ret = factorial(n);
	int stack = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		// white
		if (black[i] == false)
		{
			stack++;
			//cout << stack << endl;
		}
		else
		{
			// 組み合わせなし
			if (stack == 0)
			{
				cout << 0;
				return 0;
			}
			ret *= stack;
			stack--;
			//cout << stack << " : " << ret << endl;
		}
	}

	cout << ret % MOD;
	return 0;
}