#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//#include<boost/multiprecision/cpp_dec_float.hpp>
//namespace mp=boost::multiprecision;
//#define mulint mp::cpp_int
//#define mulfloat mp::cpp_dec_float_100
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
constexpr int MOD=1000000007;
//constexpr int MOD=998244353;
#define INF (1<<30)
#define LINF (lint)(1LL<<56)
#define endl "\n"
#define rep(i,n) for(lint (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(lint (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcount(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
#define plint pair<lint,lint>
#define fi first
#define se second
typedef long long lint;
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
const int MAX_N=2e5+5;
//struct edge{lint to,num;};

vector<lint> G[200050]; // MAX_V,隣接リスト
lint root;

lint parent[20][200050]; // logMAX_V,MAX_V
lint depth[200050];

void LCAdfs(lint v,lint p,lint d){
    parent[0][v]=p;
    depth[v]=d;
    rep(i,G[v].size()) if(G[v][i]!=p) LCAdfs(G[v][i],v,d+1);
}

void LCAinit(lint V){
    LCAdfs(root,-1,0);
    for(int k=0;k+1<20;k++){
        for(int v=0;v<V;v++){
            if(parent[k][v]<0) parent[k+1][v]=-1;
            else parent[k+1][v]=parent[k][parent[k][v]];
        }
    }
}

lint LCA(lint u,lint v){
    if(depth[u]>depth[v]) swap(u,v);
    for(int k=0;k<20;k++){
        if((depth[v]-depth[u])>>k&1) v=parent[k][v];
    }
    if(u==v) return u;
    for(int k=20-1;k>=0;k--){
        if(parent[k][u]!=parent[k][v]){
            u=parent[k][u];
            v=parent[k][v];
        }
    }
    return parent[0][u];
}

vector<int> path(int s,int t){
    int lca=LCA(s,t);
    vector<int> ps,pt;
    int now=s;
    while(true){
        if(now==lca) break;
        ps.push_back(now);
        now=parent[0][now];
    }
    now=t;
    while(true){
        pt.push_back(now);
        if(now==lca) break;
        now=parent[0][now];
    }
    reverse(pt.begin(),pt.end());
    ps.insert(ps.end(),pt.begin(),pt.end());
    return ps;
}

map<pint,int> edge;

int main(void){
    int N;
    cin >> N;
    rep(i,N-1){
        int u,v;
        cin >> u >> v;
        u--,v--;
        G[u].push_back(v);
        G[v].push_back(u);
        edge[pint(u,v)]=i;
        edge[pint(v,u)]=i;
    }
    LCAinit(N);
    lint ans=(1LL<<(N-1));
    lint minus=0;
    int M;
    cin >> M;
    int u[M],v[M];
    rep(i,M) cin >> u[i] >> v[i];
    rep(i,M) u[i]--,v[i]--;
    rep(i,(1<<M)){
        if(i==0) continue;
        int pick=Flagcount(i);
        set<int> vtx;
        rep(j,M) if(i&(1<<j)){
            vector<int> way=path(u[j],v[j]);
            rep(k,way.size()-1) vtx.insert(edge[pint(way[k],way[k+1])]);
        }
        lint cnt=(1LL<<(N-1-vtx.size()));
        if(pick%2) minus+=cnt;
        else minus-=cnt;
    }
    cout << ans-minus << endl;
}