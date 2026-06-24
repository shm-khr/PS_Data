#include <functional>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
#include <map>
using namespace std;
int n, a[100009], b[100009], w[100009], cnt, col[100009], g[100009], dp[100009]; vector<pair<int, int>> x[100009]; vector<int>y[100009];
void dfs(int pos) {
	if (col[pos] >= 1)return;
	col[pos] = cnt;
	for (int i = 0; i < y[pos].size(); i++)dfs(y[pos][i]);
}
void dfs2(int pos, int minv) {
	if (dp[pos] != -1)return;
	dp[pos] = minv;
	for (int i = 0; i < x[pos].size(); i++) {
		int V = min(x[pos][i].second, minv);
		dfs2(x[pos][i].first, V);
	}
}
long long solve(int pos) {
	for (int i = 1; i <= n; i++)dp[i] = -1;
	dfs2(pos, 1000000007);
	long long ret = 0;
	for (int i = 1; i <= n; i++) {
		if (i == pos)continue;
		ret += dp[i];
	}
	return ret;
}
int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a[i] >> b[i] >> w[i];
		if (n <= 1000) { x[a[i]].push_back(make_pair(b[i], w[i])); x[b[i]].push_back(make_pair(a[i], w[i])); }
		else if (w[i] == 2) { y[a[i]].push_back(b[i]); y[b[i]].push_back(a[i]); }
	}
	if (n <= 1000) {
		for (int i = 1; i <= n; i++) {
			cout << solve(i) << endl;
		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (col[i] == 0) { cnt++; dfs(i); }
		}
		for (int i = 1; i <= n; i++) {
			cout << (g[i] - 1) + (n - 1) << endl;
		}
	}
	return 0;
}