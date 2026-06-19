#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue> 
#include <stack>
#include <set>
#include <list>

using namespace std;
typedef long long ll;
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define all(x) x.begin(),x.end()


int main()
{
	int n; cin >> n;
	vector<int> v1(25, 0);
	v1[0] = v1[24] = 1;
	rep(i, n) {
		int d; cin >> d;
		++v1[d];
	}
	if (v1[0] > 1) {
		cout << 0 << endl;
		return 0;
	}
	int res = 0;
	rep(i, pow(2, 12)) {
		vector<int> v = v1;
		rep(j, 12) {
			if (((i >> j) & 1) && v[j] > 0) {
				--v[j];
				++v[24 - j];
			}
		}
		int mn = 12;
		if (i == pow(2, 11)) {
			int a = 0;
		}
		for (int j = 1; j < 25; ++j) {
			int cnt = 0;
			if (v[j] > 1)mn = 0;
			else {
				while (j < 25 && v[j] == 0) {
					++cnt;
					++j;
				}
				if (v[j] > 1)mn = 0;
			}
			mn = min(mn, cnt+1);
		}

		res = max(res, mn);
	}
	cout << res << endl;
}