#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    int n; cin >> n;

    vector<pair<int, int>> p(n);

    for (int i = 0; i < n; ++i) {
        int x, l; cin >> x >> l;

        p[i] = make_pair(x, l);
    }

    sort(p.begin(), p.end());

    int sum = 0;

    if (n <= 2) {
        if (p[0].first + p[0].second > p[1].first - p[1].second) {
            ++sum;
        }
    } else {
        auto itr = p.begin();
        for (int i = 1; i < n-1; ++i) {
            if (p[i-1].first + p[i-1].second > p[i].first - p[i].second && p[i].first + p[i].second > p[i+1].first - p[i+1].second) {
                ++sum;
            }
        }
    }

    cout << n - sum << endl;
}