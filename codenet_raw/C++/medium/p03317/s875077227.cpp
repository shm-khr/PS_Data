#include<string>
#include<iostream>
#include<algorithm>
#include<set>
#include<math.h>
#include<vector>
#include<sstream>
#include<queue>
#include<functional>
#include<bitset>
#include<cstdio>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include <string.h>
using ll = long long;
 
#define rep(i, n) for(ll i = 0; i < (int)(n); i++)
#define reps(i,x) for(ll i=1;i<=(int)(x);i++)
#define rrep(i,x) for(ll i=((int)(x)-1);i>=0;i--)
#define rreps(i,x) for(ll i=(int)(x);i>0;i--)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
#define vll vector<ll>
#define vi vector<int>
#define mp make_pair
#define vpll vector<pair<ll,ll>>
#define vpi vector<pair<int,int>>
#define mod 1000000007 
using namespace std;
int a[100000];
int main() {
  int n,k;
  cin >> n >> k;
  int mn = 1 << 30, ix=0;
  set<int> d;
  rep(i, n){
    cin >> a[i];
    mn = min(mn, a[i]);
    d.insert(a[i]);
  }
  int cnt = 0, ans = 0;
  rep(i,n){
    if(a[i] == mn){
      if(cnt)
        ans += (int)ceil(cnt*1.0/(k-1));
      cnt = 0;
    }
    else if(i == n -1){
      if(!(a[i]==mn&&a[i-1]==mn))
        ans +=(int)ceil((1+cnt)*1.0/(k-1));
      cnt = 0;
    }
    else{
      cnt++;
    }
  }
  cout << ans << endl;
}
