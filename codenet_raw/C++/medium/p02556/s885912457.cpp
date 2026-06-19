#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
int vector_finder(std::vector<ll> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}
struct edge {
  ll to, cost;
};

int main() {
  int N; cin >> N;
  vector<ll> x(N), y(N); REP(i, N) cin >> x[i] >> y[i];
  ll max_v = 0, min_v = pow(10, 17), max_u = 0, min_u = pow(10, 17);
  REP(i, N) {
    ll v = x[i] - y[i];
    ll u = x[i] + y[i];
    if(max_v < v) max_v = v;
    if(min_v > v) min_v = v;
    if(max_u < u) max_u = u;
    if(min_u > u) min_u = u;
  }
  cout << max(max_v - min_v, max_u - min_u) << endl;
}