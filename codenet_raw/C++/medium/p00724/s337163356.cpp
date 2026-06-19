#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define pb push_back
#define mp make_pair
#define DIR 6

typedef pair<int,int> pii;
typedef vector<pii>   vpii;
typedef vector<int> vint;


int dx[]={1,1,0,-1,-1,0};
int dy[]={-1,0,1,1,0,-1};

vpii make_path(string & path,int stride){
  vpii ret;
  pii now(0,0);
  ret.pb(now);
  rep(i,path.size()){
    now.first = now.first + dx[((int)path[i] + stride) % DIR];
    now.second = now.second + dy[((int)path[i] + stride) % DIR];
    ret.pb(now);
  }
  return ret;
}

bool cmp(vpii *path){
  rep(i,path[0].size())
    if (path[0][i] != path[1][i])return false;
  return true;
}


bool solve(string *in){
  if (in[0].size() != in[1].size())return false;
  rep(i,in[0].size()){
    in[0][i] -= 'a';
    in[1][i] -= 'a';
  }

  vpii path[2];
  path[0] = make_path(in[0],0);
  sort(path[0].begin(),path[0].end());

  rep(i,DIR){
    path[1] = make_path(in[1],i);
    sort(path[1].begin(),path[1].end());
    if (cmp(path))return true;
  }
  return false;
}

main(){
  int te;
  string in[2];
  cin>>te;
  getline(cin,in[1]);
  while(te--){
    getline(cin,in[0]);
    getline(cin,in[1]);
    if (solve(in))puts("true");
    else puts("false");
    getline(cin,in[0]);
  }
}