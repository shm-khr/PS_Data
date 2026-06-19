#include <bits/stdc++.h>

using namespace std;

#define DEBUG(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define fst first
#define snd second
#define SZ(u) ((int) (u).size())
#define ALL(u) (u).begin(), (u).end()

inline void proc_status()
{
	ifstream t("/proc/self/status");
	cerr << string(istreambuf_iterator<char>(t), istreambuf_iterator<char>()) << endl;
}

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline T read()
{
	register T sum(0), fg(1);
	register char ch(getchar());
	for(; !isdigit(ch); ch = getchar()) if(ch == '-') fg = -1;
	for(;  isdigit(ch); ch = getchar()) sum = sum * 10 - '0' + ch;
	return sum * fg;
}

typedef long long LL;
typedef pair<int, int> pii;

const int MOD = (int) 1e9 + 7;

const int MAXN = (int) 2e5;

int n;

int x[MAXN + 5], y[MAXN + 5];

vector<pii> adj[MAXN * 2 + 5];

inline void input()
{
	n = read<int>();
	for(int i = 1; i <= 2 * n; ++i)
	{
		int u = read<int>(), v = read<int>();
		adj[u].emplace_back(n + v, u + v);
		adj[n + v].emplace_back(u, u + v);
	}
}

int dfn[MAXN * 2 + 5], dfn_cur = 0;
vector<int> stk;

int cir[MAXN * 2 + 5], len = 0;

inline void dfs_cir(int u, int fa)
{
	dfn[u] = ++dfn_cur;

	stk.push_back(u);
	for(auto it : adj[u])
	{
		int v = it.fst;
		if(v != fa)
		{
			if(!dfn[v]) dfs_cir(v, u);
			else if(dfn[u] > dfn[v])
			{
				for(int i = SZ(stk) - 1; stk[i] != v; --i) cir[++len] = stk[i];
				cir[++len] = v;
			}
		}
	}
	stk.pop_back();
}

int is_cir[MAXN * 2 + 5];
int w[MAXN * 2 + 5];

inline void dfs_w(int u, int fa)
{
	for(auto it : adj[u])
	{
		int v = it.fst;
		if(!is_cir[v] && v != fa) w[v] = it.snd, dfs_w(v, u);
	}
}

namespace MATH
{
	inline int fpm(int x, int y)
	{
		int res = 1;
		for(; y; y >>= 1, x = (LL) x * x % MOD) if(y & 1) res = (LL) res * x % MOD;
		return res;
	}

	int fac[MAXN * 2 + 5], ifac[MAXN * 2 + 5];

	inline int C(int N, int M) { return N < M ? 0 : (LL) fac[N] * ifac[N - M] % MOD * ifac[M] % MOD; }

	inline void init(int N)
	{
		fac[0] = 1;
		for(int i = 1; i <= N; ++i) fac[i] = (LL) fac[i - 1] * i % MOD;
		ifac[N] = fpm(fac[N], MOD - 2);
		for(int i = N - 1; i >= 0; --i) ifac[i] = (LL) ifac[i + 1] * (i + 1) % MOD;
	}
}
using MATH::C;

vector<int> sub[MAXN * 2 + 5];
int fa[MAXN + 5];

int f[MAXN + 5], size[MAXN + 5];

inline void dfs_ans(int u)
{
	f[u] = 1, size[u] = 1;
	for(auto v : sub[u]) if(v != fa[u])
	{
		dfs_ans(v);
		f[u] = (LL) f[u] * C(size[u] - 1 + size[v], size[v]) % MOD * f[v] % MOD;
		size[u] += size[v];
	}
}

inline int calc()
{
	for(int i = 0; i <= 2 * n; ++i) fa[i] = 0, sub[i].clear();

	for(int u = 1; u <= 2 * n; ++u)
		for(auto it : adj[u])
		{
			int v = it.fst, w0 = it.snd;
			if(w0 < w[u]) fa[v] = u, sub[u].push_back(v);
		}
	for(int i = 1; i <= 2 * n; ++i) if(fa[i] == 0) sub[0].push_back(i);

	dfs_ans(0);
	return f[0];
}

inline void solve()
{
	dfs_cir(1, 0);
	if(dfn_cur != 2 * n) { puts("0"); return; }

	int ans = 0;

	for(int i = 1; i <= len; ++i) is_cir[cir[i]] = 1;
	for(int i = 1; i <= len; ++i) dfs_w(cir[i], 0);

	MATH::init(2 * n);

	for(int i = 1; i <= len; ++i)
	{
		int u = cir[i];
		for(auto it : adj[u]) if(it.fst == cir[i % len + 1]) w[u] = it.snd;
	}

	(ans += calc()) %= MOD;

	for(int i = len + 1; i >= 1; --i) w[cir[i]] = w[cir[i - 1]];
	w[cir[1]] = w[cir[len + 1]];

	(ans += calc()) %= MOD;

	printf("%d\n", (ans + MOD) % MOD);
}

int main()
{
#ifndef ONLINE_JUDGE
//	freopen("F.in", "r", stdin);
//	freopen("F.out", "w", stdout);
#endif

	input();
	solve();

	return 0;
}

