#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;

ll n, k, l = 20;
vector<ll> g[2100];
ll up[2100][25];
ll timer;
ll tin[2100];
ll tout[2100];
ll height[2100];
ll res = 1000000000;

bool upper(int a, int b) { return tin[a] <= tin[b] && tout[b] <= tout[a]; };

int lca(int a, int b) {
	if (upper(a, b))return a;
	if (upper(b, a))return b;
	for (int i = l; i >= 0; i--) {
		if (upper(up[a][i], b))continue;
		a = up[a][i];
	}
	return up[a][0];
}

int d(int a, int b) {
	int c = lca(a, b);
	return height[a] + height[b] - 2 * height[c];
}

void dfs(int v, int p, int lev) {
	tin[v] = ++timer;
	up[v][0] = p;
	height[v] = lev;
	for (int i = 1; i <= l; i++) {
		up[v][i] = up[up[v][i - 1]][i - 1];
	}
	for (auto to : g[v]) {
		if (to != p)dfs(to, v, lev + 1);
	}
	tout[v] = ++timer;
};

int main() {
	scanf("%lld %lld", &n, &k);
	for (int i = 0; i < n - 1; i++) {
		ll a, b; scanf("%lld %lld", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 1, 1);
	for (int center = 1; center <= n; center++) {
		ll current = 0;
		for (int i = 1; i <= n; i++) current += ll(d(center, i) >= k);
		res = min(res, current);
	}
	printf("%lld", res);
	return 0;
}