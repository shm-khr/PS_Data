#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <random>
#include <stack>
#include <set>
#include <unordered_set>

#define bug(x) cout<<"zdongdebug1: "<<x<<endl;
#define bug2(x, y) cout<<"zdongdebug2: "<<x<<" "<<y<<endl;
#define bug3(x, y, z) cout<<"zdongdebug3: "<<x<<" "<<y<<" "<<z<<endl;
using namespace std;
typedef long long ll;
const int maxn = 55;
const int mod = 1000000007;

int n,m;
ll mask[maxn];
vector<int>e[maxn],id[maxn];

ll ttmask;
bool dfs(int x,int fa, int y){
  if(x == y) return true;
  for(int i=0;i<e[x].size();i++){
    int v = e[x][i];
    if(v==fa)continue;
    if(dfs(v, x, y)){
      ttmask|=(1LL<<id[x][i]);
      return true;
    }
  }
  return false;
}

int main() {
#ifdef suiyuan2009
  freopen("/Users/suiyuan2009/CLionProjects/icpc/input.txt", "r", stdin);
  //freopen("/Users/suiyuan2009/CLionProjects/icpc/output.txt", "w", stdout);
#endif
  cin>>n;
  for(int i=0;i<n-1;i++){
    int x,y;
    cin>>x>>y;
    e[x].push_back(y);
    id[x].push_back(i);
    e[y].push_back(x);
    id[y].push_back(i);
  }
  cin>>m;
  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    ttmask = 0;
    dfs(x, 0, y);
    mask[i] = ttmask;
  }
  ll ret = 0;
  for(int i=0;i<(1<<m);i++){
    ll am = 0;
    int cnt2 = 0;
    for(int j=0;j<m;j++)if(i&(1LL<<j)){am|=mask[j];cnt2++;}
    int cnt =0;
    for(int j=0;j<n-1;j++)if(am&(1LL<<j))cnt++;
    ll tmp = 1LL<<(n-1-cnt);
    tmp%=mod;
    if(cnt2&1)ret = (ret +mod-tmp)%mod;
    else ret =(ret+tmp)%mod;
  }
  cout<<ret<<endl;
  return 0;
}