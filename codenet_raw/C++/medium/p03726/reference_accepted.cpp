#include<bits/stdc++.h>
#define ll long long
#define ljc 998244353
using namespace std;
#define gc getchar
inline ll read(){
    register ll x=0,f=1;char ch=gc();
    while (!isdigit(ch)){if (ch=='-') f=-1;ch=gc();}
    while (isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=gc();}
    return (f==1)?x:-x;
}
int head[1010101],tot,b[1010101];
struct edge{
	int to,nxt;
}g[1010011];
inline void made(int from,int to){
	g[++tot].to=to;g[tot].nxt=head[from];head[from]=tot;
}
int mat[1010101],n,ans;
void dfs(int u,int faa){
	if (faa&&!g[head[u]].nxt){
		if (!mat[faa]) mat[faa]=u,mat[u]=faa,ans++;
		return;
	}
	for (int i=head[u];i;i=g[i].nxt){
		int v=g[i].to;
		if (v==faa) continue;
		dfs(v,u);
	}
	if (!mat[u]){
		if (faa&&!mat[faa]) mat[faa]=u,mat[u]=faa,ans++;
	}
}
signed main(){
	n=read();
	if (n&1){
		printf("First");return 0;
	}
//	return 1;
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		made(x,y),made(y,x);
	}
	dfs(1,0);
	printf(ans!=n/2?"First":"Second");
//	for (int i=1;i<=n;i++){
//		for (int j=head[i];j;j=g[j].nxt){
//			int v=g[j].to;
//			if (indo[v]==1) b[i]++;
//		}
//		if (b[i]>=2){
//			puts("First");return 0;
//		}
//		if (indo[i]>=3){
//			puts("First");return 0;
//		}
//	}
//	puts("Second");
    return 0;
}



