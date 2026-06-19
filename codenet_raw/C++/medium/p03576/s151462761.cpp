// 2020-08-28 16:52:33
// clang-format off
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = long long;
using ld = long double;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
using P = pair<ll, ll>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

// clang-format on
void answer() {
  int n, k;
  cin >> n >> k;
  vector<P> p(n);
  rep(i, n) cin >> p[i].first >> p[i].second;
  sort(ALL(p));
  ll ans = 5e18;
  rep(i, n - k + 1) {
    ll x = 0, b = 1e9 + 5, t = -b;
    rep(j, k) {
      if (j > 0) x += p[i + j].first - p[i + j - 1].first;
      chmin(b, p[i + j].second);
      chmax(t, p[i + j].second);
    }
    chmin(ans, x * (t - b));
  }
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}