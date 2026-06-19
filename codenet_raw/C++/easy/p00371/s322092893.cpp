#include<functional>
#include<vector>
template<typename T> class SparseTable {
 public:
  explicit SparseTable(const std::vector<T>& v, const std::function<bool(T, T)>& F = std::less<T>()) : V(v), F(F), table_(v.size()) {
    for(auto i = 0; i < v.size(); ++i) table_[0].emplace_back(i);
    for(auto i = 1; pow2(i) <= v.size(); ++i) {
      for(auto j = 0; j + pow2(i) - 1 < v.size(); ++j) {
        auto a = table_[i - 1][j + pow2(i - 1)];
        auto b = table_[i - 1][j];
        table_[i].emplace_back(F(v[a], v[b]) ? a : b);
      }
    }
  }
  T index(int l, int r) const {
    auto d = leftmost(r - l + 1);
    auto a = table_[d][r - pow2(d) + 1];
    auto b = table_[d][l];
    return F(V[a], V[b]) ? a : b;
  }
  T find(int l, int r) const {
    return V[index(l, r)];
  }
 private:
  inline int pow2(int n) const {return 1 << n;}
  inline int leftmost(int n) const {return std::__lg(n);}
  const std::vector<T> V;
  const std::function<bool(T, T)> F;
  std::vector<std::vector<int>> table_;
};

#include<bits/stdc++.h>
using namespace std;

using LL = long long;

SparseTable<LL> solve(auto a, auto M, auto T) {
  unordered_map<LL, LL> q;
  for(auto i: a) q[i%T] = max(q[i%T], i/T);

  unordered_map<LL, LL> cur;
  cur[0] = 0;
  for(auto i = 0; i < M; ++i) {
    auto pre = cur;
    for(auto j: pre) {
      for(auto k: q) {
        auto l = (j.first + k.first) % T;
        cur[l] = max(cur[l], j.second + k.second);
      }
    }
  }

  vector<LL> dp(T, -1);
  for(auto i = 0; i < T; ++i) dp[i] = cur[i];
  return SparseTable<LL>(dp, greater<LL>());
}

int main() {
  int N, M, T;
  cin >> N >> M >> T;

  vector<LL> a(N);
  for(auto& i: a) cin >> i;

  auto RMQ = solve(a, M, T);

  int Q;
  cin >> Q;
  for(int i = 0; i < Q; ++i) {
    int A, B;
    cin >> A >> B;

    if(B <= RMQ.find(A, T-1)) cout << "yes" << endl;
    else                      cout << "no" << endl;
  }
}