#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
#include <stack>
#include <set>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define all(v) v.begin(), v.end()

const int N = (int)3e5;

ll mpow(ll a, ll b){
  if(b==0) return 1;
  else if(b%2==0){ll memo = mpow(a,b/2); return memo*memo%MOD;}
  else return mpow(a,b-1) * a % MOD;
}
ll lpow(ll a, ll b){
  if(b==0) return 1;
  else if(b%2==0){ll memo = lpow(a,b/2); return memo*memo;}
  else return lpow(a,b-1) * a;
}
ll gcd(ll a, ll b){
  if(b==0) return a;
  else return gcd(b, a%b);
}
vector<ll> kaijo_memo;
ll kaijo(ll n){
  if(kaijo_memo.size() > n) return kaijo_memo[n];
  if(kaijo_memo.size() == 0) kaijo_memo.push_back(1);
  while(kaijo_memo.size() <= n) kaijo_memo.push_back(kaijo_memo[kaijo_memo.size()-1] * kaijo_memo.size() % MOD);
  return kaijo_memo[n];
}
vector<ll> gyaku_kaijo_memo;
ll gyaku_kaijo(ll n){
  if(gyaku_kaijo_memo.size() > n) return gyaku_kaijo_memo[n];
  if(gyaku_kaijo_memo.size() == 0) gyaku_kaijo_memo.push_back(1);
  while(gyaku_kaijo_memo.size() <= n) gyaku_kaijo_memo.push_back(gyaku_kaijo_memo[gyaku_kaijo_memo.size()-1] * mpow(gyaku_kaijo_memo.size(), MOD-2) % MOD);
  return gyaku_kaijo_memo[n];
}

ll nCr(ll n, ll r){
  if(n == r) return 1;//0個の丸と-1個の棒みたいな時に時に効く？不安.
  if(n < r || r < 0) return 0;
  ll ret = 1;
  ret *= kaijo(n); ret %= MOD;
  ret *= gyaku_kaijo(r); ret %= MOD;
  ret *= gyaku_kaijo(n-r); ret %= MOD;
  return ret;
}


int main(void){
  ll n;cin>>n;
  vector<pair<ll,ll>> C;
  vector<ll> A,B;
  ll sum = 0, maxB = 0, bi = -1;
  rep(i,n){
    ll a,b;
    cin>>a>>b;
    A.push_back(a);
    B.push_back(b);
    sum += a;
    if(a <= b){
      C.push_back({b,i});
      if(maxB < b){
        maxB = b;
        bi = i;
      }
    }else{
      C.push_back({a,i});
    }
  }
  if(bi == -1){
    cout<<0<<" "<<1<<endl;
    return 0;
  }
  vector<ll> used;
  C.erase(C.begin() + bi);
  used.push_back(bi);
  sort(all(C));
  reverse(all(C));
  sum -= maxB;
  ll ci = 0;
  while(sum > 0){
    sum -= C[ci].first;
    used.push_back(C[ci].second);
    ci++;
    if(sum >= 0 && ci == C.size()){
      cout<<0<<" "<<1<<endl;
      return 0;
    }
  }
  //sum += maxB;
  //cout<<sum<<endl;
  double minCost = LINF; ll minUi=-1;
  ll minCoBunbo = INF*10000, minCoBunsi = 1;
  ll bestBunbi = -1;
  ll bestScore = -1;
  sort(all(used));
  int hi = 0;
  vector<ll> unused;
  rep(i, n){
    if(hi < used.size() && used[hi] == i){
      hi++;
      continue;
    }
    unused.push_back(B[i]);
  }
  sort(all(unused));
  reverse(all(unused));
  rep(i, used.size()){
    int ui = used[i];
    double cost;
    if(bestBunbi == -1){
      bestScore = B[ui];
    }
    if((sum + B[ui]) <= 0) continue;
    ll costBunsi,costBunbo;
    if(A[ui] < B[ui]){
      costBunsi = 1.0 * (sum + B[ui]);
    }else{
      costBunsi = 1.0 * (sum + A[ui]);//bestScore
    }
    unused.push_back(0);
    costBunbo = max(unused[0], B[ui]);

    if(costBunsi <= 0) continue;
    if(minCoBunsi * costBunbo > minCoBunbo * costBunsi){
      minCoBunsi = costBunsi;
      minCoBunbo = costBunbo;
      minUi = ui;
    }
  }
  if(A[minUi] < B[minUi]){
    sum += B[minUi];
  }else{
    sum += A[minUi];
  }
  
  maxB = B[minUi];

  //cout<<maxB<<endl;
  //cout<<n<<" "<<maxB<<" "<<ci<<" "<<sum<<endl;
  ll bunsi = n*maxB - maxB*ci - sum, bunbo = n*maxB;
  //cout<<bunsi<<" "<<bunbo<<endl;
  ll yaku = gcd(bunsi,bunbo);
  cout<<bunsi / yaku << " " << bunbo / yaku<<endl;

  return 0;
}
