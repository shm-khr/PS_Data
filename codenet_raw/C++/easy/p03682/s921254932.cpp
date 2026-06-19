#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct edge{ int to,cost ;};
vector<edge> G[100000];

typedef pair<int,int> p;
typedef pair<p,int> toshi;

vector<toshi> cityx(100000);
vector<toshi> cityy(100000);

int N;

vector<ll> mincost(100000);
vector<bool> used(100000);
ll INF=1000000000000;

ll prim(){
  for(int i=0;i<N;i++){
    mincost[i]=INF;
    used[i]=false;
  }
  mincost[0]=0;
  ll res=0;
  while(true){
    int v=-1;
    for(int u=0;u<N;u++){
      if(!used[u] && (v==-1 || mincost[u]<mincost[v])) v=u;
    }
    if(v==-1) break;
    used[v]=true;
    res+=mincost[v];
    vector<edge> edges = G[v];
    for(auto e:edges){
      int u = e.to;
      int c = e.cost;
      mincost[u]=min(mincost[u],(ll)c);
    }
  }
  return res;
}

int main(){
  cin >> N;
  for(int i=0;i<N;i++){
    int x,y;
    cin >> x >> y;
    p xy(x,y);
    p yx(y,x);
    toshi toshix(xy,i);
    toshi toshiy(yx,i);
    cityx.at(i)=toshix;
    cityy.at(i)=toshiy;
  }
  sort(cityx.begin(),cityx.begin()+N);
  sort(cityy.begin(),cityy.begin()+N);
  for(int i=0;i<N-1;i++){
    toshi a=cityx.at(i);
    toshi b=cityx.at(i+1);
    p zahyou1=a.first;
    p zahyou2=b.first;
    int city_num1=a.second;
    int city_num2=b.second;
    int sub_x=abs(zahyou1.first-zahyou2.first);
    int sub_y=abs(zahyou1.second-zahyou2.second);
    int co = min(sub_x,sub_y);
    edge e={city_num2,co};
    edge e2={city_num1,co};
    G[city_num1].push_back(e);
    G[city_num2].push_back(e2);
  }
  for(int i=0;i<N-1;i++){
    toshi a=cityy.at(i);
    toshi b=cityy.at(i+1);
    p zahyou1=a.first;
    p zahyou2=b.first;
    int city_num1=a.second;
    int city_num2=b.second;
    int sub_x=abs(zahyou1.first-zahyou2.first);
    int sub_y=abs(zahyou1.second-zahyou2.second);
    int co = min(sub_x,sub_y);
    edge e={city_num2,co};
    edge e2={city_num1,co};
    G[city_num1].push_back(e);
    G[city_num2].push_back(e2);
  }
  ll res = prim();
  cout << res << endl;
}