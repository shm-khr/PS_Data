#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

struct M {
  using T = struct mms { lint min, max, sum; mms(lint a = numeric_limits<lint>::max(), lint b = numeric_limits<lint>::min(), lint c = 0) : min(a), max(b), sum(c) {} };
  using U = struct lf { lint a, b; lf(lint a = 1, lint b = 0) : a(a), b(b) {} };
  static T op(const T& a, const T& b) { return T{min(a.min, b.min), max(a.max, b.max), a.sum + b.sum}; }
  static void ap(T& a, const U& g, lint k) {
    a.min = g.a * a.min + g.b;
    a.max = g.a * a.max + g.b;
    if (g.a < 0) swap(a.min, a.max);
    a.sum = g.a * a.sum + k * g.b;
  }
  static void ap(U& f, const U& g) { f.a *= g.a; f.b = g.a * f.b + g.b; }
};

template<class M> struct ST {
  using T = typename M::T;
  using U = typename M::U;
  lint n;
  unordered_map<lint, T> t;
  unordered_map<lint, U> u;

  ST(lint n) : n(1LL << 8 * sizeof(lint) - __builtin_clzll(max(n - 1, 1LL))) {}

  void _ap(lint i, const U& f) {
    M::ap(t[i], f, 1 << __builtin_clzll(i) - __builtin_clzll(n));
    if (i < n) M::ap(u[i], f);
  }

  T get(lint l, lint r) {
    _push(l, r);
    T resl, resr;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = M::op(resl, t[l++]);
      if (r & 1) resr = M::op(t[--r], resr);
    }
    return M::op(resl, resr);
  }

  void _push(lint l, lint r) {
    for (lint hl = 8 * sizeof(lint) - __builtin_clzll(l + n) - 1, hr = 8 * sizeof(lint) - __builtin_clzll(r - 1 + n) - 1; hr > 0; hl--, hr--) {
      lint i = r - 1 + n >> hr;
      _ap(2 * i, u[i]);
      _ap(2 * i + 1, u[i]);
      u.erase(i);
      i = l + n >> hl;
      if (i == r - 1 + n >> hr or i >= n) continue;
      _ap(2 * i, u[i]);
      _ap(2 * i + 1, u[i]);
      u.erase(i);
    }
  }

  void set(lint l, lint r, const U& f) {
    _push(l, r);
    for (lint i = l + n, j = r + n; i < j; i >>= 1, j >>= 1) {
      if (i & 1) _ap(i++, f);
      if (j & 1) _ap(--j, f);
    }
    for (l += n; !(l & 1);) l >>= 1;
    while (l >>= 1) t[l] = M::op(t[2 * l], t[2 * l + 1]);
    for (r += n; !(r & 1);) r >>= 1;
    while (r >>= 1) t[r] = M::op(t[2 * r], t[2 * r + 1]);
  }
};

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n, q; cin >> n >> q;
  ST<M> st(1e10);
  st.set(0, n, M::U(0, 0));
  for (int i = 0; i < q; i++) {
    int t; cin >> t;
    if (t) {
      int l, r; cin >> l >> r;
      cout << st.get(l, r + 1).min << '\n';
    } else {
      int l, r, x; cin >> l >> r >> x;
      st.set(l, r + 1, M::U(1, x));
    }
  }
}
