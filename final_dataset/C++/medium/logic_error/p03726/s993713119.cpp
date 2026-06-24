#include <bits/stdc++.h>

template <typename T> inline void rd(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, dg[kN], d[kN]; bool flag = false;
std::vector <int> E[kN];
void Add(int u, int v) { E[u].push_back(v); }

void Dfs(int u, int fa) {
	int cnt = 0;
	d[u] = 1;
	for(auto v : E[u]) if(v != fa) {
		Dfs(v, u);
		d[u] = std::max(d[v] + 1, d[u]);
		if(d[v] == 1) ++cnt;
	}
	if(cnt >= 2) flag = true;
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n);
		if(n <= 3) {
			printf("Second\n"); break;
		}
		for(int i = 1; i < n; ++i) {
			int u, v; rd(u, v);
			Add(u, v); Add(v, u);
			++dg[u]; ++dg[v];
		}
		for(int i = 1; i <= n; ++i)
			if(dg[i] >= 2) {
				Dfs(i, 0);
				break;
			}
		if(flag) printf("First\n");
		else printf("Second\n");
	} return 0;
}