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
#define ELEM(array) (sizeof (array)/sizeof *(array))
#define MAX_N 100
#define SAFE_FREE(ptr) if( ptr != NULL ){ free(ptr); ptr = NULL; }
typedef unsigned int UINT;
typedef long long ll;

int main()
{
	while (1)
	{
		int n;

		vector<pair<int, int>> isl;

		cin >> n;
		if (n==0)return 0;
		
		REP(i, n){
			int a, b;
			cin >> a >> b;
			isl.push_back(make_pair(b, a));
		}
		sort(begin(isl), end(isl));

		int w = 0;
		REP(i, n)
		{
			w += isl[i].second;
			if (w > isl[i].first)
			{
				cout << "No" << endl;
				goto next;
			}
		}
		cout << "Yes" << endl;
	next:;
	}
}