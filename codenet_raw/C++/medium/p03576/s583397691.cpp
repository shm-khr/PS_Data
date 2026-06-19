#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <array>
#include <vector>
#include <utility>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

using ll = long long;
using p = pair<ll, ll>;

constexpr ll INF = 1LL << 62;
constexpr ll MAX_N = 200;

vector<p> points;
ll N, K;

ll count_included_points(ll x1, ll y1, ll x2, ll y2) {
    ll res = 0;
    for (ll i = 0; i < N; i++) {
        ll x = points[i].first;
        ll y = points[i].second;
        if (x1 <= x && x <= x2 && y1 <= y && y <= y2) {
            res++;
        }
    }

    return res;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> K;
    points = vector<p>(N);

    for (auto&& point : points) {
        cin >> point.first >> point.second;
    }

    ll ans = INF;

    sort(points.begin(), points.end());

    for (ll i = 1; i < N; i++) {
        for (ll j = 0; j < N - i; j++) {
            p a = points[j];
            p b = points[j + i];

            ll x1 = min(a.first, b.first);
            ll x2 = max(a.first, b.first);

            ll area = INF;
            for (ll s = 0; s < N; s++) {
                for (ll t = s + 1; t < N; t++) {

                    p c = points[s];
                    p d = points[t];
                    ll y1 = min(c.second, d.second);
                    ll y2 = max(c.second, d.second);
                    if (K <= count_included_points(x1, y1, x2, y2)) {
                        area = min(area, (y2 - y1) * (x2 - x1));
                    }
                }
            }

            ans = min(ans, area);
            if (ans != INF) {
                cout << ans << endl;
            }
        }
    }

    cout << ans << endl;

    return 0;
}

