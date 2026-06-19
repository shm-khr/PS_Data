#include <bits/stdc++.h>
typedef long long int ll;
#define FOR(i, a, b) for (ll i = (signed)(a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define EREP(i, n) for (int i = (n)-1; i >= 0; --i)
#define MOD 1000000007
#define pb push_back
#define INF 93193111451418101
#define MIN -93193111451418101
#define EPS 1e-11
#define tp(a, b, c) make_tuple(a, b, c)
using namespace std;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
template <typename T> void fill_all(T &arr, const T &v) { arr = v; }
template <typename T, typename ARR> void fill_all(ARR &arr, const T &v) {
  for (auto &i : arr) {
    fill_all(i, v);
  }
}
//------------------変数-----------------------//
//-------------------関数----------------------//

//-------------------??¢??°----------------------//

int main() {
  ll n;
  cin >> n;
  if (n >= 24) {
    cout << 0 << endl;
    return 0;
  }
  vector<ll> s;
  REP(i, n) {
    ll h;
    cin >> h;
    if (h == 0) {
      cout << 0 << endl;
      return 0;
    }
    s.pb(h);
  }
  sort(s.begin(), s.end());
  bool flag[1010] = {};
  REP(i, (signed)s.size() - 1) {
    if (s[i] == s[i + 1]) {
      if (flag[s[i]] == true || s[i] == 12) {
        cout << 0 << endl;
        return 0;
      }
      flag[s[i]] = true;
    }
  }
  s.erase(std::unique(s.begin(), s.end()), s.end());
  ll maxe = 0;
  REP(i, (1 << s.size())) {
    vector<ll> se;
    ll maxa = INF;
    se.pb(0);
    REP(j, s.size()) {
      if (flag[s[j]]) {
        se.pb(s[j]);
        se.pb(24 - s[j]);
      } else if ((i >> j) & 1) {
        se.pb(24 - s[j]);

      } else {
        se.pb(s[j]);
      }
    }
    sort(se.begin(), se.end());
    REP(i, se.size() - 1) {
      maxa = min({maxa, se[i + 1] - se[i], 24 - (se[i + 1] - se[i])});
    }
    if (maxa == INF || maxa == 24) {
      maxa = 0;
    }
    maxe = max(maxa, maxe);
  }

  cout << maxe << endl;
  return 0;
}
