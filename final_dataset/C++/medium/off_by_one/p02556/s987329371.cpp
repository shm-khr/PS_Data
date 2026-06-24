#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define pb push_back
#define mp make_pair
#define ll long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define testcase ll T; cin >> T; for (ll tc = 1; tc <= T; tc++)
#define M 1000000007
#define MM 2000000000000000000
#define eps 1e-8
#define eq(x,y) (fabs((x)-(y)) < eps)
#define r2 1.41421356237
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  //testcase {
  int n;
  cin>>n;
  vector<pair<ll,ll>>v1,v2;
  for(int i=0;i<n;i++) {
  	ll a,b;
  	cin>>a>>b;
  	v1.pb(mp(a,b));
  	v2.pb(mp(b,a));
  }
  sort(rall(v1));
  sort(rall(v2));
  ll ans1=abs(v1[0].first-v1[n-1].first)+abs(v1[0].second-v1[n-1].second);
  ll ans2=abs(v2[0].first-v2[n-1].first)+abs(v2[0].second-v2[n-1].second);
  ans1=max(ans1,ans2);
  cout<<ans1;
  //}
  return 0;
}