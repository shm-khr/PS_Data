#include <bits/stdc++.h>
using namespace std;

#define rep(ver,n) rep2(ver,0,n)
#define rep2(ver,m,n) for(int ver=m;ver<(n);ver++)
#define dup(x,y) (((x)+(y)-1)/(y))
#define vecadd emplace_back

typedef long long ll;

int main(){
  int n,m;
  int a[100010];
  cin>>n>>m;
  rep(i,n){
    cin>>a[i];
  }
  
  
  
  rep(i,m){
    sort(a,a+n,
       [](const int x, const int y) { return x > y;});
    a[0]/=2;
  }
  
  ll ans=0;
  rep(i,n){
    ans+=a[i];
  }
  
  cout<<ans;
  
  return 0;
}
