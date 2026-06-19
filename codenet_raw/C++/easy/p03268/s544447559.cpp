#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <stack>
#include <queue>

#define FOR(i, b, e) for(int i = (int)(b); i < (int)(e); ++i)
#define RFOR(i, b, e) for(int i = (int)(e-1); i >= 0; --i)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define REPC(x,c) for(const auto& x:(c))
#define REPP(x,y,c) for(const auto& [x,y]:(c))
#define VS vector<string>
#define VI vector<int>
#define VVI vector<vector<int>>
#define ALL(x) (x).begin(),(x).end()
#define PAIR pair<int,int>
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

using  ll = long long;

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	const int base = n / k;
	const int dis = n % k;

	ll ans = pow(base, 3);

	if (k % 2 == 0) {
		ll t = base;
		if (dis + 1 >= k / 2) { ++t; }
		ans += pow(t, 3);
	}

	cout << ans << endl;
}
