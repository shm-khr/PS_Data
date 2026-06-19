#include<bits/stdc++.h>

#define gc() getchar()

#define ll long long
#define ri register int 

using std::cout;
using std::swap;
using std::bitset;

inline int read()
{
	int ret=0;char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))
	{
		ret=ret*10+ch-'0';
		ch=gc();
	}
	return ret;
}

const int MAXN=51;
const int MAXM=21;

int n,m;

int en,eh[MAXN];
struct edge
{
	int v,next;
}e[MAXN*2];
inline void add_edge(int u,int v)
{
	e[++en]=(edge){v,eh[u]};eh[u]=en;
	e[++en]=(edge){u,eh[v]};eh[v]=en;
}

int fa[MAXN],d[MAXN];
void dfs(int u)
{
	for(ri i=eh[u],v;i;i=e[i].next)
	{
		v=e[i].v;
		if(v!=fa[u])
		{
			fa[v]=u;
			d[v]=d[u]+1;
			dfs(v);
		}
	}
}

ll rt[1<<MAXM],a[1<<MAXM],ans;
inline ll lowbit(ll x){return x&-x;}
inline int op(ll x){return x&1?1:-1;}
inline ll pro(int t){return (ll)1<<n-1-t;}
inline ll route(int u,int v)
{
	ll ret=0;
	while(u!=v)
	{
		if(d[u]<d[v])swap(u,v);
		ret|=(ll)1<<u-2;
		u=fa[u];
	}
	return ret;
}
inline int cnt(ll x)
{
	int ret=0;
	while(x)
	{
		ret+=x&1;
		x>>=1;
	}
	return ret;
}

int main()
{
//	freopen("in.in","r",stdin);
	
	n=read();
	for(ri i=2,u,v;i<=n;++i)
	{
		u=read();v=read();
		add_edge(u,v);
	}
	dfs(1);
	
	m=read();
	for(ri i=0,u,v,t;i<m;++i)
	{
		u=read();v=read();
		rt[1<<i]=route(u,v);
	}
	for(ri i=1,j;i<(1<<m);++i)
	{
		j=lowbit(i);
		rt[i]=rt[i-j]|rt[j];
		a[i]=pro(cnt(rt[i]));
		ans+=op(cnt(i))*a[i];
	}
	printf("%lld\n",((ll)1<<n-1)-ans);
	
	return 0;
}