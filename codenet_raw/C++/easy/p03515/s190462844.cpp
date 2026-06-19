#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;
const int mx=1e5+10;
int idx[mx];
uli sz[mx];
uli val[mx];
uli inc[mx];
vector<int>bag[mx];
int main(){
  int n;
  scanf("%d",&n);
  vector<tuple<uli,int,int> >edges;
  for(int i=0;i<n-1;i++){
    int u,v;
    uli c;
    scanf("%d %d %lld",&u,&v,&c);  
    edges.push_back(make_tuple(c,--u,--v));
  }
  sort(edges.begin(),edges.end(),greater<tuple<uli,int,int> >());
  for(int i=0;i<n;i++){
    idx[i]=i;
    sz[i]=1;
    inc[i]=0;
    bag[i]={i};
  }
  for(auto e:edges){
    int u,v;
    uli w;
    tie(w,u,v)=e;
    if(sz[u]<sz[v])swap(u,v);
    int x=idx[u],y=idx[v];
    inc[x]+=w*sz[y];
    inc[y]+=w*sz[x];
    for(int z:bag[y]){
      bag[x].push_back(z);
      idx[z]=x;
      val[z]+=inc[y]-inc[x];
    }
    sz[x]+=sz[y];
  }
  int x=idx[0];
  for(int i=0;i<n;i++)val[i]+=inc[x];
  for(int i=0;i<n;i++){
    printf("%lld\n",val[i]);
  }
  return 0;
}
