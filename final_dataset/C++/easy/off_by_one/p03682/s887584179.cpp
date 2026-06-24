#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define REPP(i,n) for(int i=1;i<=n;i++)
const double PI = acos(-1);
const double EPS = 1e-15;
long long INF=(long long)1E17;
#define i_7 (long long)(1E9+7)
long mod(long a){
    long long c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
using namespace std;

int n;//頂点数
int parent[100010];//iの親parent[i]を格納する配列
int rank[100010];//iを根とする部分木の高さみたいな量?
void init(int n){
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }
}
int root(int x){
    if(parent[x]==x)return x;
    else return root(parent[x]);
}
void unite(int x,int y){
    x=root(x);
    y=root(y);
    if(x==y)return ;
    if(rank[x]<rank[y])parent[x]=y;
    else{
        parent[y]=x;
        if(rank[x]==rank[y])rank[x]++;
    }
}
bool same(int x,int y){
    return root(x)==root(y);
}
struct edge {int u,v,cost;};
bool comp(const edge& e1,const edge& e2){
    return e1.cost<e2.cost;
}

vector <edge> edges;
//vector <pair<int,int>>p1,p2;
int kruskal(){
    sort(edges.begin(),edges.end(),comp);
    init(n);
    long long res=0;
    rep(i,edges.size()){
        edge e=edges[i];
        if(!same(e.u,e.v)){
            unite(e.u,e.v);
            res += (long long)e.cost;
        }
    }
    return res;
}

int main(){
  cin>>n;
  
  int x,y;
  vector<pair<int,int>> xs,ys;
  REP(i,n){
    cin>>x>>y;
    xs.push_back(make_pair(x,i));
    ys.push_back(make_pair(y,i));
  }
  
  sort(xs.begin(),xs.end());
  sort(ys.begin(),ys.end());
  
  REP(i,n-1){
    edge e;
    e.u = xs[i].second;
    e.v = xs[i+1].second;
    e.cost = xs[i+1].first - xs[i].first;
    edges.push_back(e);
  }
  REP(i,n-1){
    edge e;
    e.u = ys[i].second;
    e.v = ys[i+1].second;
    e.cost = ys[i+1].first - ys[i].first;
    edges.push_back(e);
  }
  
  long long ans;
  ans = kruskal();
  cout<<ans<<endl;
  return 0;
}
