#pragma GCC optimize("O3")

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstring>
#include <numeric>
#include <set>
#include <queue>
#include <deque>
#include <array>
#include <string>
#include <cmath>
#include <random>
#include <ctime>
#include <map>
#include <functional>
#include <bitset>
#include <complex>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

const int N = 50000;

int n, m;
int type;
vi x, y;
bitset<N> foo[N];
vector<vi> bs;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> type;
	if (type == 2) {
		return 0;
	}
	x.resize(m);
	y.resize(m);
	bs.resize(n);

	for (int i = 0; i < n; i++) {
		foo[i][i] = 1;
	}

	for (int i = 0; i < m; i++) {
		cin >> x[i] >> y[i];
		--x[i];
		--y[i];


		foo[x[i]] |= foo[y[i]];
		foo[y[i]] = foo[x[i]];

		bs[x[i]].pb(i);
		bs[y[i]].pb(i);
	}

	int ends = -1;

	for (int i = 0; i < n; i++) {
		if (foo[i].count() == n) {
			ends = i;
			break;
		}
	}

	if (ends == -1) {
		cout << -1 << '\n';
		return 0;
	}
	/*
	string ans(m, '^');
	vector<bool> was(n, false);
	queue<int> q;
	q.push(ends);
	was[ends] = true;
	vector<bool> wb(m, false);

	while (!q.empty()) {
		int i = q.front();
		q.pop();

		for (int j = sz(bs[i]) - 1; j >= 0; j--) {

			int b = bs[i][j];

			if (wb[b]) {
				continue;
			}
			wb[b] = true;

			if (x[b] == i) {
				ans[b] = '^';
				int to = y[b];
				if (!was[to]) {
					q.push(to);
					was[to] = true;
					while (!bs[to].empty() && bs[to].back() >= b) {
						bs[to].pop_back();
					}
				}
			}
			else {
				ans[b] = 'v';
				int to = x[b];
				if (!was[to]) {
					q.push(to);
					was[to] = true;
					while (!bs[to].empty() && bs[to].back() >= b) {
						bs[to].pop_back();
					}
				}
			}
		}
	}
	*/

	string ans(m, '^');
	set<pii> q;
	q.insert({ bs[ends].back(), ends });

	while (!q.empty()) {
		auto e = *--q.end();
		q.erase(--q.end());
		int b = e.first;
		int i = e.second;
		int to = x[b] ^ y[b] ^ i;

		if (x[b] == i) {
			ans[b] = '^';
		}
		else {
			ans[b] = 'v';
		}

		while (!bs[to].empty() && bs[to].back() >= b) {
			bs[to].pop_back();
		}

		if (!bs[to].empty()) {
			q.insert({ bs[to].back(), to });
		}
		
		bs[i].pop_back();
		if (!bs[i].empty()) {
			q.insert({ bs[i].back(), i });
		}
	}

	cout << ans;
}
