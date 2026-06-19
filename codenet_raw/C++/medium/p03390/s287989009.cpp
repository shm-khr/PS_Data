#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
#define db long double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi totor<int>
#define vl totor<ll>
#define rep(i, x, y) for(register int i = x; i <= y; i ++)
#define rrep(i, x, y) for(register int i = x; i >= y; i --)
#define eps 1e-15
#define lb(x) x & -x
#define sz(x) (x).size()
usir namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
ll f(ll A, ll B)
{
    ll lim = A*B;
    ll l = 0, r = B;
    while (r - l > 1)
    {
        ll mid = (l + r) / 2;
        bool f = true;
        if (mid * (A + 1) >= lim)f = false;
        ll x = (A + mid + 1) / 2;
        for (ll xx = x - 2; xx < x + 3; ++xx) {
            if (xx >= 1 && xx <= mid) {
                ll y = xx * (A + 1 + mid - xx);
                if (y >= lim)f = false;
            }
        }
        (f ? l : r) = mid;
    }
    return l;
}

int main()
{
    int Q = read();
    while (Q --)
    {
        ll A, B;
        A = read1();
        B = read1();
        ll bb = f(A, B);
        ll aa = f(B, A);
        ll ans = aa + bb;
        ll x = B - bb - 1, y = A - aa - 1;
        ans += max(0ll, min(x, y));
        cout << ans << endl;
    }
}
