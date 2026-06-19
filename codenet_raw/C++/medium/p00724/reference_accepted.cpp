//55
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<set>
#include<array>
#include<cstdlib>

using namespace std;
typedef pair<int,int> PII;
typedef array<PII,6> NARRAY;

NARRAY neighbor(PII p){
  static int dx[]={0,1,1,0,-1,-1};
  static int dy[]={-1,-1,0,1,1,0};
  NARRAY r;
  for(int i=0;i<6;i++){
    r[i]=PII(p.first+dx[i],p.second+dy[i]);
  }
  return r;
}

bool check(const vector<PII> &v,int d){
  //  auto nn=neighbor(v[d]);
  int nb=0;
  for(int i=0;i<d;i++){
    if(v[i]==v[d])return false;
    int yd=v[i].first-v[d].first;
    int xd=v[i].second-v[d].second;
    nb|=(max(abs(xd),abs(yd))==1&&xd*yd!=1)<<i;
    //    nb|=(find(begin(nn),end(nn),v[i])!=end(nn))<<i;
  }
  return nb==1<<d>>1;
}  

void dfs(vector<PII> v,int d,bool m,set<vector<PII> > &r){
  if(d==v.size()){
    r.insert(v);
    // for(auto e:v){
    //   cout<<'('<<e.first<<','<<e.second<<')'<<' ';
    // }
    // cout<<endl;
  }else{
    if(check(v,d)){
      dfs(v,d+1,false,r);
    }
    if(!m){
      auto n=neighbor(v[d]);
      for(auto e:n){
	vector<PII> nv=v;
	nv[d]=e;
	if(check(nv,d)){
	  dfs(nv,d+1,true,r);
	}
      }
    }
  }
}

int main(){
  for(int n;cin>>n,n;){
    vector<PII> iv;
    for(int i=0;i<n;i++){
      int x,y;
      cin>>x>>y;
      iv.emplace_back(x,y);
    }
    int k;
    cin>>k;
    int u[100],v[100];
    for(int i=0;i<k;i++){
      cin>>u[i]>>v[i];
    }
    int X,Y;
    cin>>X>>Y;
    set<vector<PII> > vs[22];
    vs[0].insert(iv);
    set<vector<PII> > s;
    for(int i=0;i<=20;i++){
      for(auto e:vs[i]){
	if(e[0].first==X&&e[0].second==Y){
	  cout<<i<<endl;
	  goto next;
	}
	if(!s.insert(e).second)continue;
	set<vector<PII> > res;
	dfs(e,0,false,res);
	for(auto f:res){
	  bool on_rock=false;
	  for(auto g:f){
	    for(int j=0;j<k;j++){
	      on_rock|=g.first==u[j]&&g.second==v[j];
	    }
	  }
	  if(!on_rock){
	    vs[i+1].insert(f);
	  }
	}
      }
      vs[i].clear();
    }
  next:
    ;
  }
}