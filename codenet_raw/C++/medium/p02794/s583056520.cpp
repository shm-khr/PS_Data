#pragma GCC optimize ("Ofast")
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define FORD(i, a, b) for (int i=(a); i>(b); i--)
#define PPC(x) __builtin_popcount(x)
#define MSB(x) (31 - __builtin_clz(x))
#define SZ(x) ((int)(x).size())
#define BACK(x) prev((x).end())
#define HASK(x, y) ((x).find(y) != (x).end())
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define ithBit(m, i) ((m) >> (i) & 1)
#define ft first
#define sd second
#define kw(a) ((a) * (a))
#ifdef DEBUG
#include "debug.h"
#else
#define dbg(...) 0
#endif
using namespace std;
 
const int maxN = 53, maxM = 20;

vector <pair <int, int> > G[maxN];
long long pats[maxN][maxN], subg[1 << maxM];

void dfs(int v, int fat, int r)
{
	for (auto [u, e] : G[v]) if (u != fat)
	{
		pats[r][u] = pats[r][v] | 1ll<<e;
		dfs(u, v, r);
	}
}

void solve()
{
	int n;
	scanf ("%d", &n);
	FOR(i, 0, n-1)
	{
		int a, b;
		scanf ("%d%d", &a, &b);
		G[a].pb({b, i});
		G[b].pb({a, i});
	}
	
	FOR(v, 1, n+1)
		dfs(v, v, v);
		
	int M;
	scanf ("%d", &M);
	vector <pair <int, int> > Q(M);
	FOR(i, 0, M)
		scanf ("%d%d", &Q[i].ft, &Q[i].sd);
		
	__int128 res = 0;
		
	FOR(m, 1, 1<<M)
	{
		int i = __builtin_ctz(m);
		subg[m] = subg[m ^ (1<<i)];
		int a, b; tie(a, b) = Q[i];
		subg[m] |= pats[a][b];
		
		long long dx = 1ll << (n-1-PPC(subg[m]));
		if (PPC(m) % 2 == 0)
			dx *= -1ll;
		res += dx;
	}
	
	res = (1ll << n-1) - res;
	printf("%lld\n", res);
}
 
int main()
{
	int t = 1;
	//scanf ("%d", &t);
	FOR(tid, 1, t+1)
	{
		//printf("Case #%d: ", tid);
		solve();
	}
	return 0;
}



