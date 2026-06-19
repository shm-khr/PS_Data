#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <list>
#include <string.h>
#include <functional>
//#include <Windows.h>
//#include "Library.h"
//#include "Math.h"
using namespace std;
typedef long long int ll; typedef pair <int, int> P; typedef vector <int> vecint;
//const int INF = 2000000000;
const double EPS = 10e-9;
const int mvm = 1000001;
int v[100], w[100], m[100];
int dp[10001];
int main()
{
	int n, W; cin >> n >> W;
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++)
		cin >> v[i] >> w[i] >> m[i];
	for (int i = 0; i < n; i++)
	{
		for (int a = 0; a < w[i]; a++)
		{
			deque <int> deq, deqi;
			for (int j = 0; j * w[i] + a <= W; j++)
			{
				int val = dp[a + j * w[i]] - j * v[i];
				while (!deq.empty() && val >= deq.back()) { deq.pop_back(); deqi.pop_front();}
				deq.push_back(val);
				deqi.push_back(j);
				dp[a + j * w[i]] = deq.front() + j * v[i];
				if (j - deqi.front() == m[i]) { deqi.pop_front(); deq.pop_front(); }
			}
		}
	}
	cout << dp[W] << endl;
	return 0;
}