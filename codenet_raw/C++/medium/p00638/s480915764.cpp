#include <iostream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
#include <utility>
#include <string>
#include <ctype.h>
#include <cstring>
#include <sstream>
using namespace std;

#define FOR(i,k,n) for(int i = (k); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define INF 114514810
#define ll long long



int main()
{
	while (1)
	{
		int n;
		cin >> n; if (n == 0) return 0;
		vector<pair<int, int>> v;
		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			v.push_back(make_pair(b, a));
		}
		sort(begin(v), end(v));
		int w = 0;
		for (int i = 0; i < n; i++)
		{
			w += v[i].second;
			if (w > v[i].first)
			{
				cout << "NO" << endl;
				goto next;
			}
		}
		cout << "YES" << endl;
	next:;
	}
}