#include <bits/stdc++.h>
 
using namespace std;
 
#define range(i, m, n) for(int i = m; i < n; i++)
#define husk(i, m, n) for(int i = m; i > n; i--)
 
class segtree {
  public:
  struct node {
 
    long long sum = 0;
    int p = 0;
 
    void apply(int l, int r, int v) {
      assert(l == r);
      if(v > 0) {
        sum = v;
        p = 1;
        return;
      }
      sum = 0;
      p = 0;
    }
  };
 
  node unite(const node &a, const node &b) const {
    node res;
    res.sum = a.sum + b.sum;
    res.p = a.p + b.p;
    return res;
  }
 
  inline void push(int x, int l, int r) {
 
  }
 
  inline void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }
 
  int n;
  vector<node> tree;
 
  void build(int x, int l, int r) {
    if (l == r) {
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y);
    build(z, y + 1, r);
    pull(x, z);
  }
 
  template <typename M, typename... T>
  void build(int x, int l, int r, const vector<M> &v, const T&... t) {
    if (l == r) {
      tree[x].apply(l, r, v[l], t...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y, v, t...);
    build(z, y + 1, r, v, t...);
    pull(x, z);
  }
 
  node get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    node res{};
    if (rr <= y) {
      res = get(x + 1, l, y, ll, rr);
    } else {
      if (ll > y) {
        res = get(z, y + 1, r, ll, rr);
      } else {
        res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
      }
    }
    pull(x, z);
    return res;
  }
 
  template <typename... M>
  void modify(int x, int l, int r, int ll, int rr, const M&... v) {
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (ll <= y) {
      modify(x + 1, l, y, ll, rr, v...);
    }
    if (rr > y) {
      modify(z, y + 1, r, ll, rr, v...);
    }
    pull(x, z);
  }
 
  int find_first_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[x + 1])) {
      res = find_first_knowingly(x + 1, l, y, f);
    } else {
      res = find_first_knowingly(z, y + 1, r, f);
    }
    pull(x, z);
    return res;
  }
 
  int find_first(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_first_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (ll <= y) {
      res = find_first(x + 1, l, y, ll, rr, f);
    }
    if (rr > y && res == -1) {
      res = find_first(z, y + 1, r, ll, rr, f);
    }
    pull(x, z);
    return res;
  }
 
  int find_last_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[z])) {
      res = find_last_knowingly(z, y + 1, r, f);
    } else {
      res = find_last_knowingly(x + 1, l, y, f);
    }
    pull(x, z);
    return res;
  }
 
  int find_last(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_last_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (rr > y) {
      res = find_last(z, y + 1, r, ll, rr, f);
    }
    if (ll <= y && res == -1) {
      res = find_last(x + 1, l, y, ll, rr, f);
    }
    pull(x, z);
    return res;
  }
 
  segtree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
  }
 
  template <typename M, typename... T>
  segtree(const vector<M> &v, const T&... t) {
    n = v.size();
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, v, t...);
  }
 
  node get(int ll, int rr) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return get(0, 0, n - 1, ll, rr);
  }
 
  node get(int p) {
    assert(0 <= p && p <= n - 1);
    return get(0, 0, n - 1, p, p);
  }
 
  template <typename... M>
  void modify(int ll, int rr, const M&... v) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    modify(0, 0, n - 1, ll, rr, v...);
  }
 
  int find_first(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_first(0, 0, n - 1, ll, rr, f);
  }
 
  int find_last(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_last(0, 0, n - 1, ll, rr, f);
  }
 
};
 
int n;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  range(i, 0, n) {
    cin >> a[i] >> b[i];
  }
  long long cur = 0;
  long long sum = 0;
  vector<int> id;
  vector<int> pr;
  range(i, 0, n) {
    if(b[i] >= a[i]) {
      cur += b[i] - a[i];
      pr.push_back(b[i]);
    } else id.push_back(i);
  }
  if(cur == 0) {
    cout << "0 1\n";
    return 0;
  }
  sort(pr.begin(), pr.end());
  int pos = 0;
  while(sum + pr[pos] <= cur) {
    sum += pr[pos];
    pos++;
  }
  long long u = 1LL * pos * pr[pos] + cur - sum;
  long long v = pr[pos];
  if(id.empty()) {
    v *= n;
    long long g = __gcd(u, v);
    cout << u / g << " " << v / g;
    return 0;
  }
  sort(id.begin(), id.end(), [&](int x, int y){return a[x] < a[y];});
  vector<int> _a, _b;
  map<int, vector<int>> pb;
  range(i, 0, (int) id.size()) {
    _a.push_back(a[id[i]]);
    _b.push_back(b[id[i]]);
    if(b[id[i]] < pr[pos]) pb[b[id[i]]].push_back(i);
  }
  vector<long long> pref(pr.size());
  range(i, 0, (int) pr.size()) {
    pref[i] = pr[i];
    if(i > 0) pref[i] += pref[i - 1];
  }
  segtree sa(_a);
  segtree sb(_b);
  while(!pb.empty()) {
    auto it = prev(pb.end());
    int x = it->first;
    int y = it->second.front();
    sa.modify(y, y, 0);
    sb.modify(y, y, 0);
    long long c = cur + x - _a[y];
    int p = lower_bound(pr.begin(), pr.end(), x) - pr.begin();
    long long csum = c - (p > 0 ? pref[p - 1] : 0);
    if(csum <= 0) {
      for(int i : it->second) {
        sa.modify(i, i, 0);
        sb.modify(i, i, 0);
      }
      pb.erase(it);
      continue;
    }
    long long ss = 0;
    int sz = sa.find_first(0, id.size() - 1, [&](const segtree::node z){
      if(z.sum + ss >= csum) return true;
      ss += z.sum;
      return false;
    });
    if(sz == -1) sz = id.size() - 1;
    else sz--;
    segtree::node s;
    segtree::node d;
    if(sz >= 0) {
      s = sa.get(0, sz);
      d = sb.get(0, sz);
    }
    long long zsum = (p > 0 ? pref[p - 1] : 0LL) + d.sum;
    c += d.sum - s.sum;
    assert(zsum <= c);
    long long su, sv;
    if(zsum + x > c) {
      su = 1LL * (p + s.p) * x + c - zsum;
      sv = x;
    } else {
      int ap = upper_bound(pref.begin(), pref.end(), c - d.sum - x) - pref.begin();
      //assert(ap >= p);
      su = 1LL * (ap + s.p + 1) * pr[ap] + c - d.sum - x - (ap > 0 ? pref[ap - 1] : 0);
      sv = pr[ap];
    }
    if(su / sv > u / v || (su / sv == u / v && (su % sv) * v > (u % v) * sv)) {
      u = su;
      v = sv;
    }
    for(int i : it->second) {
      sa.modify(i, i, 0);
      sb.modify(i, i, 0);
    }
    pb.erase(it);
  }
  v *= n;
  long long g = __gcd(u, v);
  u /= g; v /= g;
  cout << u << " " << v;
  return 0;
}
