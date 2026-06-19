#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
random_device rnd;
mt19937 mt(rnd());
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1000000007;

int main()
{
    int n;
    cin >> n;
    assert(n != 1);
    if (n == 2)
    {
        cout << -1 << endl;
        return 0;
    }
    if (n % 2 == 1)
    {
        rep(i, n)
        {
            rep(j, n - 1)
            {
                cout << (i + 1 + j) % n + 1 << " ";
            }
            cout << endl;
        }
    }
    else
    {
        rep(i, n - 2)
        {
            rep(j, n - 2)
            {
                cout << (i + 1 + j) % (n - 1) + 1 << " ";
            }
            cout << n << endl;
        }
        cout << n << " ";
        int tmp = 0;
        int cnt = 0;
        int cur = 2;
        while (cnt != n - 2)
        {
            if (cur == n - 1)
            {
                cur = (cur + 1) % (n - 1);
            }
            cout << cur << " ";
            cur++;
            cnt++;
        }
        cout << endl;
        rep(i, n - 2)
        {
            cout << (i) % (n - 1) + 1 << " ";
        }
        cout << n - 1 << endl;
    }
    return 0;
}