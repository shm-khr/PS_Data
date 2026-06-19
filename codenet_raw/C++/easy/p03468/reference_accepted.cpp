#include<bits/stdc++.h>
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define drep(i,a,b) for (int i = (a); i >= (b); --i)
#define grep(i,u) for (int i = head[u],v = e[i].v; i; v = e[i = e[i].nxt].v)
#define il inline
#define LL long long
#define ULL unsigned LL
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<LL,LL>
#define fi first
#define se second
using namespace std;
il LL read() {
	LL res = 0,f = 1; char ch = getchar(); while (!isdigit(ch)) {if (ch == '-') f = -f; ch = getchar();}
	while (isdigit(ch)) {res = res*10+ch-'0'; ch = getchar();} return res*f;
}
namespace qiqi {
	const int N = 10,C = 55,S = 1<<N; int n,c,l[N],f[N*C][S];
	void main() {
		int x,cnt = 0; LL ans = 0; n = read(); c = read(); rep(i,0,n-1) l[i] = read(); sort(l,l+n);
		while (1) {
			memset(f,0,sizeof(f)); f[l[n-1]*n][0] = 1;
			rep(i,1,c*n) if ((x = i%n-1) >= 0) rep(j,i,c*n) rep(s,0,(1<<(n-1))-1) if (!((s>>x)&1)) f[min(c*n,max(j,i+l[x]*n))][s|(1<<x)] += f[j][s];
			ans += f[c*n][(1<<(n-1))-1]; ++cnt; if (!next_permutation(l,l+n-1)) break;
		}
		printf("%.13lf\n",1.0*ans/cnt/pow(c,n-1));
	}
}
int main() {
	qiqi::main(); return 0;
}