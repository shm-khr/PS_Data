#include <bits/stdc++.h>
using namespace std;
#define M 4010
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
struct Edge{
	int u,v,Next;
} G[M];
int n,k;
int head[M],tot;
inline void add(int u,int v){
	G[++tot]=(Edge){u,v,head[u]};
	head[u]=tot;
}
int f[M][2010];
int g[M][2010];
inline void dfs(int x,int fa){
	for(int i=head[x];i!=-1;i=G[i].Next){
		if(G[i].v==fa)continue;
		dfs(G[i].v,x);
	}
	rep(j,0,n){
		for(int i=head[x];i!=-1;i=G[i].Next){
			if(G[i].v==fa)continue;
			g[x][j+1]+=f[G[i].v][j];
		}
	}
	f[x][0]=1;
	rep(j,1,k){
		for(int i=head[x];i!=-1;i=G[i].Next){
			if(G[i].v==fa)continue;
			f[x][j]=max(f[x][j],1+f[G[i].v][j-1]+g[x][k-j]-(k-j-1>=0?f[G[i].v][k-j-1]:0));
		}
	}
	rep(i,1,k)f[x][i]=max(f[x][i-1],f[x][i]);
}
int main() {
	scanf("%d%d",&n,&k);
	memset(head,-1,sizeof(head));
	rep(i,1,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	dfs(1,0);
	int ans=0;
	rep(j,1,n)rep(i,1,k){
		ans=max(ans,f[j][i]);
	}
	printf("%d\n",n-ans);
}