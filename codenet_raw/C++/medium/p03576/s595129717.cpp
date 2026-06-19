#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
typedef pair<long long int, long long int> P;

void solve()
{
	long long int N, K;
	cin >> N >> K;
	vector<P> p(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> p[i].first >> p[i].second;
	}
	__int128 ans = 1e36;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			P p1 = p[i];
			P p2 = p[j];
			__int128 xMin = min(p1.first, p2.first);
			__int128 xMax = max(p1.first, p2.first);
			__int128 yMin = min(p1.second, p2.second);
			__int128 yMax = max(p1.second, p2.second);
			long long int cnt = 0;
			for (int k = 0; k < N; ++k)
			{
				if (xMin <= p[k].first && p[k].first <= xMax && yMin <= p[k].second && p[k].second <= yMax)
				{
					++cnt;
				}
			}
			if (cnt >= K)
			{
				ans = min(ans, (xMax - xMin) * (yMax - yMin));
			}
		}
	}
	cout << ans << endl;
}

int main()
{
	solve();
	return(0);
}