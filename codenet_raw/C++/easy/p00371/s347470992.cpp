#include<bits/stdc++.h>
using namespace std;

using LL = long long;

const LL INF = 1e18;

vector<LL> solve(auto a, auto M, auto T) {
  auto mul = [&](auto v, auto w) {
    auto r = v;
    for(auto i = 0; i < T - 1; ++i) for(auto j = 0; j < T - 1; ++j) r[(i + j) % T] = max(r[(i + j) % T], v[i] + w[j]);
    return r;
  };

  function<vector<LL>(vector<LL>, int)> pow = [&](auto v, auto m) {
    if(!m) return vector<LL>(T - 1, -INF);
    if(m & 1) return mul(v, pow(v, m - 1));
    return pow(mul(v, v), m >> 1);
  };

  vector<LL> v(T - 1, -INF);
  v[0] = 0;
  for(auto i: a) v[i % T] = max(v[i % T], i);
  return pow(v, M);
}

int main() {
  int N, M, T;
  cin >> N >> M >> T;

  vector<LL> a(N);
  for(auto& i: a) cin >> i;

  auto dp = solve(a, M, T);
  for(auto i = T-1; 0 < i; --i) dp[i-1] = max(dp[i-1], dp[i]);

  int Q;
  cin >> Q;
  for(int i = 0; i < Q; ++i) {
    int A, B;
    cin >> A >> B;

    if(B <= dp[A] / T) cout << "yes" << endl;
    else               cout << "no" << endl;
  }
}