#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

bool comp(P p, P q) {
    if (p.second < q.second)
        return true;
    else if (p.second == q.second && p.first < q.first)
        return true;
    
    return false;
}

int main() {
    int n;  cin >> n;
    vector<P> v(n);
    for (int i = 0; i < n; i++) {
        ll l, x;    cin >> l >> x;
        v[i].first = l - x;
        v[i].second = l + x;
    }
    sort(v.begin(), v.end(), comp);

    ll ans = 0, sup = -1e18;
    for (int i = 0; i < n; i++) {
        if (sup <= v[i].first) {
            sup = v[i].second;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}