#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 608;
typedef long long ll;
const ll MOD = 1000000007;

int a[N], b[N], c[N], n, k;
ll p[N], f[N][N], g[N][N];

inline bool in(int a, int l, int r) {
	return l <= a && a < r;
}

bool chk(int l, int r) {
	for (int i = 0; i < k; i++)
		if (in(a[i], l, r) ^ in(b[i], l, r)) return true;
	return false;
}

int main() {
	scanf("%d%d",&n,&k);
	if (n == 1) {puts("1"); return 0;}
	p[0] = 1;
	for (int i = 0; i < n; i++)
		p[i+1] = p[i] * (i<<1|1) %MOD;
	n <<= 1;
	for (int i = 0; i < k; i++) {
		scanf("%d%d",a+i,b+i);
		c[a[i]--] = c[b[i]--] = 1;
	}
	for (int i = 1; i <= n; i++)
		c[i] = !c[i] + c[i-1];
	ll ans = 0;
	for (int l = 0; l < n; l++)
		for (int r = l; (r += 2) <= n;) {
			int x = c[r] - c[l];
			if ((x&1) || chk(l, r)) continue;
			ll s = p[x>>1];
			for (int k = l; (k += 2) < r;)
				s = (s - f[l][k] * p[c[r] - c[k] >> 1]) %MOD;
			ans += s = s * p[n-x>>1] %MOD;
			f[l][r] = s;
		}
	if ((ans %= MOD) < 0) ans += MOD;
	printf("%lld\n",ans);
	return 0;
}
