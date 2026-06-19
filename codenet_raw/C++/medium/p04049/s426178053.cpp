#include<bits/stdc++.h>
using namespace std;
using ii=tuple<int,int>;
using vi=vector<int>;
using vvi=vector<vi>;
int main(){
  int n,k,u,v;
  cin>>n>>k;
  vvi g(n);
  for(int i=0;i<n-1;i++){
    cin>>u>>v;
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  function<ii(int,int,int)>dfs=[&](int u,int p,int d){
    if(d>k/2)return make_tuple(0,int(g[u].size())-1);
    int r=1,m=0,x,y;
    for(int v:g[u])
      if (v!=p){
        tie(x,y)=dfs(v,u,d+1);
        r+=x;
        if(p<0)m=max(m,y);
        else m+=y;
      }
    return make_tuple(r,m);
  };
  int m=0,r,e;
  for(int i=0;i<n;i++){
    tie(r,e)=dfs(i,-1,0);
    m=max(m,r+(k%2?e:0));
  }
  cout<<n-m<<"\n";
}
