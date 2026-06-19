#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
vector<vector<ll>> num(100010);
vector<queue<ll>> cl(100010);
vector<ll> c(100010);
vector<ll> itr(100010);

void dfs(ll x, vector<vector<ll>> &g, vector<bool> &see,vector<ll> &numc)
{
  //点xに対する処理
  if(!cl[c[x]].empty()){
    ll p=cl[c[x]].front();
    num[p][itr[p]]-=numc[x]+1;
  }
  cl[c[x]].push(x);
  see[x] = 1;
  for (auto p : g[x])
  {
    if (see[p])
        continue;
    //進む辺に対する処理（これは木構造でオイラーツアーするために使う）
    dfs(p, g, see,numc);
    itr[x]++;
    //戻る辺に対する処理
  }
  //点xの親に戻る時の処理
  cl[c[x]].pop();
}

int main()
{
ll n;
cin >> n ;
vector<ll> ans(n,0);
rep(i, n){
  cin >> c[i];
}
vector<vector<ll>> g(n);
rep(i, n-1)
{
  ll a, b;
  cin >> a >> b;
  g[a - 1].push_back(b - 1);
  g[b - 1].push_back(a - 1); 
}

vector<vector<ll>> child(n);
vector<ll> numc(n);
vector<ll> par(n);
queue<ll> q;
queue<ll> qq;
ll root=0;
q.push(root);
par[root]=-1;
//親の定義と葉を見つける
while(!q.empty()){
  ll p=q.front();
  q.pop();
  if(g[p].size()==1 && p!=root){qq.push(p);}
  for(auto r:g[p]){
    if(r==par[p])continue;
    par[r]=p;
    q.push(r);
  }
}
while(!qq.empty()){
  ll p=qq.front();
  qq.pop();
  child[par[p]].push_back(p);//親に値を追加する
  //根の時は例外処理
  if(child[par[p]].size()==g[par[p]].size()){
    //child[par[p]]に子の値が入ってる

    ll tm=0;
    for(auto r:child[par[p]]){
      tm+=1+numc[r];
      num[par[p]].push_back(1+numc[r]);
    }
    numc[par[p]]=tm;

  }
  //全ての葉が親に追加し終わった
  if(child[par[p]].size()==g[par[p]].size()-1 && par[p]!=root){
    //child[par[p]]に子の値が入ってる

    ll tm=0;
    for(auto r:child[par[p]]){
      tm+=1+numc[r];
      num[par[p]].push_back(1+numc[r]);
    }
    numc[par[p]]=tm;

    qq.push(par[p]);
  }
}
rep(i,n){
  num[i].push_back(n-1-numc[i]);
}

vector<bool> see(n);
dfs(0,g,see,numc);

rep(i,n){
  ll sum=0;
  for(auto r:num[i]){
    sum+=r;
  }
  for(auto r:num[i]){
    ans[c[i]-1]+=r*(sum-r);
  }
}
rep(i,n)ans[i]/=2;
rep(i,n){
  ll sum=0;
  for(auto r:num[i]){
    sum+=r;
  }
  ans[c[i]-1]+=sum+1;
}

for(auto an:ans)cout << an << endl;
return 0;
}