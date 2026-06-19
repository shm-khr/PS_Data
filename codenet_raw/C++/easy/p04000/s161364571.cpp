#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

int main() {

	ll h, w, n; scanf("%lld %lld %lld", &h, &w, &n);
	
	int dx[9] = { 0, 0, 0, -1, -1, -1, -2, -2, -2 };
	int dy[9] = { 0, -1, -2, 0, -1, -2, 0, -1, -2 };

	vector<ll> ans(10);
	map<pi, int> map;

	for (int i = 0; i < n; i++) {

		int a, b; scanf("%d %d", &a, &b);

		for (int i = 0; i < 9; i++) {

			pi front = { a + dx[i], b + dy[i] };

			if (front.first < 1 || front.first > h - 2 || front.second < 1 || front.second > w - 2) continue;

			map[front]++;

		}

	}

	for (auto p : map) ans[p.second]++;

	for (ll l : ans)
		printf("%lld\n", l);

	return 0;

}