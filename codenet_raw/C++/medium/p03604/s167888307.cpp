#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<P,int> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<55;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

ll Pow(ll n,ll p){
	ll r=1;
	for(;p>0;p>>=1){
		if(p&1) r=(r*n)%mod;
		n=(n*n)%mod;
	}
	return r;
}

const int M=200005;
ll F[M];

void Init(){
	F[0]=1;
	for(int i=1;i<M;i++) F[i]=F[i-1]*i%mod;
}

ll Div(ll n,ll m){
	return n*Pow(m,mod-2)%mod;
}

int n,cnt=0,num=0;
vi x,y,ax,ay,vis,b,c,d,used;
vl dp;
vvi g,G;
vvp X,Y;

int dfs(int v,int w){
	b.push_back(v);
	vis[v]++;cnt++;
	if(!ax[x[v]]) num++,ax[x[v]]=1;
	if(!ay[y[v]]) num++,ay[y[v]]=1;
	int t=-1;
	for(auto u:g[v]) if(u!=-1&&u!=w){
		if(vis[u]&&w!=-1){
			int I=d.size()-1;
			pip p={{x[u],y[u]},u};
			while(I>=0&&d[I]!=u){
				int u_=d[I--];
				p=min(p,{{x[u_],y[u_]},u_});
			}
			t=p.second;
		}
		else if(!vis[u]){
			d.push_back(u);
			int t_=dfs(u,v);
			if(t_!=-1) t=t_;
			d.pop_back();
		}
	}
	return t;
}

void DFS(int v,int I){
	int u=g[v][I];
	if(u==-1||c[u]!=-1) return;
	c[u]=1-I%2;
	for(int i=0;i<4;i++){
		int w=g[u][i];
		if(w!=-1&&c[w]==-1) DFS(u,i);
	}
}

pll Rec(int v){
	ll res=1,S=0;
	for(auto u:G[v]){
		pll p=Rec(u);
		ll T=p.second;
		res=Div(res*p.first%mod,F[T]);
		S+=T;
	}
	(res*=F[S])%=mod;
	return {res,S+1};
}

ll f(int v,int t){
	c[v]=t;
	for(int i=0;i<4;i++) DFS(v,i%2*2+abs(i/2-t));
	for(auto i:b){
		int u=g[i][c[i]];
		while(u!=-1){
			G[i].push_back(u);
			used[u]=1;
			u=g[u][c[i]];
		}
	}
	for(auto i:b) if(!used[i]) G[n].push_back(i);
	ll res=Rec(n).first;
	for(auto i:b){
		c[i]=-1;
		used[i]=0;
		G[i].clear();
	}
	G[n].clear();
	return res;
}

int main(){
	Init();
	cin>>n;
	n*=2;
	x=y=ax=ay=vis=used=vi(n);
	c=vi(n,-1);
	X=Y=vvp(n);
	g=vvi(n,vi(4,-1));
	G=vvi(n+1);
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
		x[i]--;y[i]--;
		X[x[i]].push_back({y[i],i});
		Y[y[i]].push_back({x[i],i});
	}
	for(int i=0;i<n;i++){
		sort(X[i].begin(),X[i].end());
		sort(Y[i].begin(),Y[i].end());
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<X[i].size();j++){
			int u=X[i][j-1].second,v=X[i][j].second;
			g[u][3]=v;g[v][1]=u;
		}
		for(int j=1;j<Y[i].size();j++){
			int u=Y[i][j-1].second,v=Y[i][j].second;
			g[u][2]=v;g[v][0]=u;
		}
	}
	ll res=F[n];
	for(int i=0;i<n;i++) if(!vis[i]){
		cnt=0;num=0;
		b.clear();d.clear();
		d.push_back(i);
		int v=dfs(i,-1);
		d.pop_back();
		res=(cnt==num?Div(res*(f(v,0)+f(v,1))%mod,F[cnt]):0);
	}
	cout<<res<<endl;
}