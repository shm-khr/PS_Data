#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<cstdio>
#include<sstream>
#include<iomanip>
#define loop(i,a,b) for(long long i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef pair<ll,pii> pip;
typedef vector<pip>vip;
const double PI=acos(-1);
const double EPS=1e-8;
const ll inf=1e18;
struct edge{
	ll to,cap,cost,rev;
};
typedef vector<edge> ve;
typedef vector<ve> vve;
class MCF{	//Minimum Cost Flow
	public:
	ll n;
	vve G;
	vi h,dist,prev,pree;
	MCF(ll size){
		n=size;
		G=vve(n);
		h=dist=prev=pree=vi(n);
	}
	void add_edge(ll s,ll t,ll ca,ll co){
		edge e={t,ca,co,G[t].size()};
		G[s].pb(e);
		edge ee={s,0,-co,G[s].size()-1};
		G[t].pb(ee);
	}
	ll mcf(ll s,ll t,ll f){
		ll out=0;
		h=vi(n);
		while(f>0){			
			priority_queue<pii,vector<pii> >q;
			dist=vi(n,inf);
			dist[s]=0;
			q.push(pii(0,s));
			while(!q.empty()){
				pii p=q.top();q.pop();
				ll v=p.second;
				if(dist[v]<-p.first)continue;
				rep(i,G[v].size()){
					edge &e=G[v][i];
					if(e.cap>0&&dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
						dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
						prev[e.to]=v;
						pree[e.to]=i;
						q.push(pii(-dist[e.to],e.to));
					}
				}
			}
			if(dist[t]==inf)return -1;
			rep(i,n)h[i]+=dist[i];
			ll d=f;
			for(ll v=t;v!=s;v=prev[v])d=min(d,G[prev[v]][pree[v]].cap);
			f-=d;
			out+=d*h[t];
			for(ll v=t;v!=s;v=prev[v]){
				edge &e=G[prev[v]][pree[v]];
				e.cap-=d;
				G[v][e.rev].cap+=d;
			}
		}
		return out;	
	}
	void tmp(){
		rep(i,G.size())rep(j,G[i].size())cout<<i<<" "<<G[i][j].to<<endl;
	}
};
int main(){
	ll n,f=0;
	cin>>n;
	vi in(n);
	rep(i,n)cin>>in[i];
	rep(i,n){
		ll a;
		cin>>a;
		in[i]-=a;
	}
	MCF mcf(n+2);
	ll s=n,t=s+1;
	rep(i,n)if(in[i]<0)f-=in[i];
	rep(i,n-1){
		mcf.add_edge(i,i+1,inf,1);
		mcf.add_edge(i+1,i,inf,1);
	}
	rep(i,n){
		if(in[i]>0)mcf.add_edge(s,i,in[i],0);
		if(in[i]<0)mcf.add_edge(i,t,-in[i],0);
	}
//	mcf.tmp();
	cout<<mcf.mcf(s,t,f)<<endl;
}