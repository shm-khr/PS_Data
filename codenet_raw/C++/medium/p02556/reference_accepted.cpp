#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    ll max_z = -1000000000;
    ll min_z = 1000000000;
    ll max_w = -1000000000;
    ll min_w = 1000000000;
    for (int i = 0; i < n; i++) {
        ll x, y, z, w;
        cin >> x >> y;
        z = x + y;
        w = x - y;
        max_z = max(max_z, z);
        min_z = min(min_z, z);
        max_w = max(max_w, w);
        min_w = min(min_w, w);
    }
    ll ans;
    ans = max(max_z - min_z, max_w - min_w);
    cout << ans << endl;
    return 0;
}