#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(ll (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

constexpr int INF = 1e9;
//constexpr ll INF = 1LL<<61;
// constexpr ll mod = 1e9+7;

bool cmp(pair<int, int> l, pair<int, int> r){
  return l.first < r.first;
}

bool cmp2(pair<int, int> l, pair<int, int> r){
  return l.second < r.second;
}
ll cal_cost(pair<int, int> a, pair<int, int> b){
  return min(abs(a.first-b.first), abs(a.second-b.second));
}
int main(){
  int N;
  cin >> N;
  vector<pair<int, int>> xy(N);
  REP(i, N){
    int x, y;
    cin >> x >> y;
    xy[i] = {x, y};
  }
  sort(xy.begin(), xy.end(), cmp);
  ll ans = 0;
  REP(i, N-1){
    ans = max(ans, cal_cost(xy[0], xy[i+1]));
  }
  sort(xy.begin(), xy.end(), cmp2);
  REP(i, N-1){
    ans = max(ans, cal_cost(xy[0], xy[i+1]));
  }
  cout << ans << endl;
  return 0;
}
