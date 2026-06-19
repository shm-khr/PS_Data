#include <iostream>
#include <vector>
#include <map>
#include<algorithm>
#include <climits>
#include <cstdio>
typedef long long ll;
#define INF (LLONG_MAX/10)
using namespace std;

int main() {
	ll N, W; scanf("%I64d%I64d", &N, &W);
	vector<ll> w(N + 1), v(N + 1);
	vector<pair<ll, ll>> ps(1 << ((N+1)/ 2));
	for (int i = 0; i < N;i++) {
		scanf("%I64d%I64d", &N, &W);
	}

	int N2 = N / 2;
	for (int i = 0; i < 1 << N2;i++) {
		ll sw = 0, sv = 0;
		for (int j = 0; j < N2;j++) {
			if (i >> j & 1) {
				sw += w[j];
				sv += v[j];
			}
		}
		ps[i] = make_pair(sw, sv);
	}

	sort(ps.begin(), ps.begin() + (1 << N2));

	int m = 1;
	for (int i = 1; i < 1 << N2; i++) {
		if (ps[m - 1].second < ps[i].second) {
			ps[m++] = ps[i];
		}
	}

	ll res = 0;
	for (int i = 0; i < 1 << (N - N2); i++) {
		ll sw = 0, sv = 0;
		for (int j = 0; j < N - N2;j++) {
			if (i >> j & 1) {
				sw += w[N2 + j];
				sv += v[N2 + j];
			}
		}
		if (sw <= W) {
			ll tv = (lower_bound(ps.begin(), ps.begin() + m, make_pair(W - sw, INF)) - 1)->second;
			res = max(res, sv + tv);
		}
	}
	printf("%I64d\n", res);
}