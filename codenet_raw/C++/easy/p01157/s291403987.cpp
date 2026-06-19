#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <stack>
#include <climits>
#include <deque>
#include <bitset>
#include <cassert>
#include <ctime>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int dy[]={-1,0,1,0},dx[]={0,1,0,-1};
// adjust problem by problem
const double EPS=1e-8;
const double PI=acos(-1.0);
#ifdef __GNUC__
int popcount(int n){return __builtin_popcount(n);}
int popcount(ll n){return __builtin_popcountll(n);}
#endif
#ifndef __GNUC__
template<class T> int popcount(T n){int cnt=0;while(n){if(n%2)cnt++;n/=2;}return cnt;}
#endif
template<class T>int SIZE(T a){return a.size();}
template<class T>string IntToString(T num){string res;stringstream ss;ss<<num;return ss.str();}
template<class T>T StringToInt(string str){T res=0;for(int i=0;i<SIZE(str);i++)res=(res*10+str[i]-'0');return res;}
template<class T>T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template<class T>T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T> void PrintSeq(T &a,int sz){for(int i=0;i<sz;i++){cout<<a[i];if(sz==i+1)cout<<endl;else cout<<' ';}}
bool EQ(double a,double b){return abs(a-b)<EPS;}
void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}
vector<string> split(string str,char del){
  vector<string> res;
  for(int i=0,s=0;i<SIZE(str);i++){
    if(str[i]==del){if(i-s!=0)res.push_back(str.substr(s,i-s));s=i+1;}
    else if(i==SIZE(str)-1){res.push_back(str.substr(s));}
  }
  return res;
}

class Dinic{
private:
  static const int MAX_V=200001;
  static const ll INF=1000000000000000LL;
  class edge{
  public:
    int to,rev;
    ll cap;
    edge(int to_,ll cap_,int rev_){
      to=to_;
      cap=cap_;
      rev=rev_;
    }
  };
public:
  vector<edge> G[MAX_V];
  // sからの距離
  int level[MAX_V];
  // どこまで調べ終わったか
  int iter[MAX_V];
  void add_edge(int from,int to,ll cap){
    G[from].push_back(edge(to,cap,G[to].size()));
    G[to].push_back(edge(from,0,G[from].size()-1));
  }
  void init(){
    for(int i=0;i<MAX_V;i++)G[i].clear();
  }
private:
  // sからの最短距離を求める
  void bfs(int s){
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty()){
      int v=que.front();que.pop();
      for(int i=0;i<(int)G[v].size();i++){
        edge &e=G[v][i];
        if(e.cap>0&&level[e.to]<0){
          level[e.to]=level[v]+1;
          que.push(e.to);
        }
      }
    }
  }
  // 増加パスをdfsで探す
  ll dfs(int v,int t,ll f){
    if(v==t)return f;
    for(int &i=iter[v];i<(int)G[v].size();i++){
      edge &e=G[v][i];
      if(e.cap>0&&level[v]<level[e.to]){
        ll d=dfs(e.to,t,min(f,e.cap));
        if(d>0){
          e.cap-=d;
          G[e.to][e.rev].cap+=d;
          return d;
        }
      }
    }
    return 0;
  }
public:
  // sからtへの最大流を求める
  ll max_flow(int s,int t){
    ll flow=0;
    while(1){
      bfs(s);
      if(level[t]<0)return flow;
      memset(iter,0,sizeof(iter));
      ll f;
      while((f=dfs(s,t,INF))>0)flow+=f;
    }
  }
};


Dinic dinic;
int main(){
  int N;
  while(cin>>N&&N){
    dinic.init();
    vector<ll> ss;
    map<ll,int> dayIdx;
    int daySize=0;
    vector<ll> fs[1001];
    {
      set<ll> found;
      int M;
      cin>>M;
      for(int i=0;i<M;i++){
        ll a;
        cin>>a;
        if(found.count(a))continue;
        ss.push_back(a);
        if(dayIdx.count(a)==0)dayIdx[a]=daySize++;
        ss[(int)ss.size()-1]=dayIdx[a];
      }
    }
    for(int i=0;i<N;i++){
      set<ll> found;
      int M;
      cin>>M;
      for(int j=0;j<M;j++){
        ll a;
        cin>>a;
        if(found.count(a))continue;
        fs[i].push_back(a);
        if(dayIdx.count(a)==0)dayIdx[a]=daySize++;
        fs[i][(int)fs[i].size()-1]=dayIdx[a];
      }
    }
    int node=(int)dayIdx.size();
    const int st=node++;
    const int ed=node++;
    for(int j=0;j<(int)ss.size();j++){
      int a=ss[j];
      dinic.add_edge(st,a,1);
    }
    for(int i=0;i<N;i++){
      const int to=i+node;
      for(int j=0;j<(int)fs[i].size();j++){
        const int from=fs[i][j];
        dinic.add_edge(from,to,1);
      }
      dinic.add_edge(to,ed,1);
    }
    node+=N;
    cout<<dinic.max_flow(st,ed)<<endl;
  }
  return 0;
}