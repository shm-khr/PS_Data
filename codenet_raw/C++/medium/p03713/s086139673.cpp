#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int MOD = 1000000007;
const ll INF = 10e12;
using namespace std;

ll f1(ll tate, ll yoko)
{
    if (tate < 3 || yoko < 3)
        return INF;
    else
    {
        int l1 = tate / 3, l2 = tate / 3, l3 = tate / 3;
        if (tate % 3 == 1)
            l1++;
        else if (tate % 3 == 2)
            l1++, l2++;
        return yoko * abs(l1 - l3);
    }
}
ll f2(ll tate, ll yoko)
{
    ll res = INF;
    if (tate % 2 == 1)
        swap(tate, yoko);
    for (int i = 1; i < yoko - 1; ++i)
    {
        ll s1, s2;
        s1 = tate * i;
        s2 = (tate / 2) * (yoko - i);
        res = min(res, abs(s1 - s2));
    }
    return res;
}
ll f3(ll tate, ll yoko)
{
    ll res = INF;
    for (int i = 1; i < min(yoko - 1, tate - 1); ++i)
    {
        ll s1, s2, s3;
        s1 = i * i;
        s2 = i * (yoko - i);
        s3 = yoko * (tate - i);
        ll mx = max(s1, max(s2, s3));
        ll mn = min(s1, min(s2, s3));
        res = min(res, mx - mn);
    }
    return res;
}
int main(void)
{
    int h, w;
    cin >> h >> w;
    ll ans = INF;
    ans = min(ans, min(f1(h, w), f1(w, h)));
    if (h % 2 == 0 || w % 2 == 0)
        ans = min(ans, min(f2(h, w), f2(w, h)));
    ans = min(ans, f3(h, w));
    cout << ans << endl;
}
