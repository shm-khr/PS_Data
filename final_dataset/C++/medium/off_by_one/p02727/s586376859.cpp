#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;

int main()
{
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<int> p(a), q(b), r(c);
    rep(i, a) cin >> p.at(i);
    rep(i, b) cin >> q.at(i);
    rep(i, c) cin >> r.at(i);

    sort(p.rbegin(), p.rend());
    sort(q.rbegin(), q.rend());

    vector<int> d;
    rep(i, x) d.push_back(p[i]);
    rep(i, y) d.push_back(q[i]);
    rep(i, c) d.push_back(r[i]);

    ll ans = 0;
    rep(i, x + y) ans += d[i];
    cout << ans << endl;

    cout << sum << endl;
}
