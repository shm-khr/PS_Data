#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<stack>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
const ll N=2e5+7;
const ll INF=1e15+7;
ll pos[N],k[N],b[N],xx[N],yy[N],cc[N];
bool vis[N];
struct edge{ll v,next,c;}e[N*2];
ll n,m,num=0;
void add(ll x,ll y,ll c){e[num]=(edge){y,pos[x],c}; pos[x]=num++;}
void dfs(ll x,ll f){
	vis[x]=1;
	repG(i,x){
		if(e[i].v==f)continue;
		if(vis[e[i].v])continue;
		k[e[i].v]=-k[x];
		b[e[i].v]=e[i].c-b[x];
		dfs(e[i].v,x);
	}
}
int main(){
	memset(pos,-1,sizeof(pos));
	scanf("%lld%lld",&n,&m);
	rep(i,m){
		ll x,y,c; scanf("%lld%lld%lld",&x,&y,&c);
		add(x,y,c);
		add(y,x,c);
		xx[i]=x;
		yy[i]=y;
		cc[i]=c;
	}
	k[1]=1;
	b[1]=0;
	dfs(1,0);
	ll jx=-INF;
	rep(i,m){
		ll a=xx[i],e=yy[i];
		ll ks=k[a]+k[e],bs=b[a]+b[e];
		if(!ks){
			if(bs!=cc[i]){
				printf("0\n");
				return 0;
			}
		}
		else{
			ll j=cc[i]-bs;
			if(j%ks!=0){
				printf("0\n");
				return 0;
			}
			j/=ks;
			if(jx!=-INF&&j!=jx){
				printf("0\n");
				return 0;
			}
			jx=j;
		}
	}
	if(jx!=-INF){
		printf("1\n");
	}
	else{
		ll xj=0,sj=INF;
		rep(j,n){
			if(k[j]==1)xj=max(xj,-b[j]);
			else sj=min(sj,b[j]);
		}
		printf("%lld\n",max(0ll,sj-xj-1));
	}
	return 0;
}
