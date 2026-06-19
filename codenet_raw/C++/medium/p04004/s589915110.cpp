#include <bits/stdc++.h>
#define For(i, l, r) for(int i = (l), i##end = (int)(r); i <= i##end; ++i)
#define Fordown(i, r, l) for(int i = (r), i##end = (int)(l); i >= i##end; --i)
#define Set(a, v) memset(a, v, sizeof(a))
using namespace std;

bool chkmin(int &a, int b) {return b < a ? a = b, 1 : 0;}
bool chkmax(int &a, int b) {return b > a ? a = b, 1 : 0;}

inline int read() {
    int x = 0, fh = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar() ) if (ch == '-') fh = -1;
    for (; isdigit(ch); ch = getchar() ) x = (x<<1) + (x<<3) + (ch ^ '0');
    return x * fh;
}

void File() {
#ifdef zjp_shadow
	freopen ("F.in", "r", stdin);
	freopen ("F.out", "w", stdout);
#endif
}

const int Mod = 1e9 + 7, N = 1e6 + 1e3;

typedef long long ll;

ll fac[N], ifac[N], pow3[N];

ll fpm(ll x, int power) {
	ll res = 1;
	for (; power; power >>= 1, (x *= x) %= Mod)
		if (power & 1) (res *= x) %= Mod;
	return res;
}

ll C(int m, int n) {
	if (m > n || n < 0 || m < 0) return 0;
	//cout << fac[n] << ' ' << ifac[m] << ' ' << ifac[n - m] << endl;
	return fac[n] * ifac[m] % Mod * ifac[n - m] % Mod;
}

int n, m, k, tot;

void Init(int maxn) {
	fac[0] = pow3[0] = 1; 
	For (i, 1, maxn) fac[i] = fac[i - 1] * i % Mod, pow3[i] = pow3[i - 1] * 3 % Mod;
	ifac[maxn] = fpm(fac[maxn], Mod - 2);
	Fordown (i, maxn - 1, 0) ifac[i] = ifac[i + 1] * (i + 1) % Mod;
}

inline ll Calc(int m, int S) {
	ll res = 0;
	For (i, 0, min(m, S))
		if (S - i <= k) (res += C(i, S)) %= Mod;
	return res;
}

ll res[N];

int main () {
	File();
	cin >> n >> m >> k; tot = n + m + k;
	Init(tot + 5);


	ll ans = 0, now = 1;
	For (S, 0, m + k) {
		(ans += pow3[tot - (n + S)] * C(n - 1, (n - 1) + S) % Mod * Calc(m, S) % Mod) %= Mod;
		now = (now << 1) % Mod;

		if (S >= m) (now += Mod - C(m, S)) %= Mod;
		if (S >= k) (now += Mod - C(k, S)) %= Mod;
	}

	printf ("%lld\n", ans);
    return 0;
}
