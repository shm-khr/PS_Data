#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) ((x).size()))
typedef long long ll;
typedef long double ld;

ll gcd(ll a, ll b) {
  return a == 0 ? b : gcd(b % a, a);
}

struct frac {
  ll a, b, m = 0;
  frac(ll aa, ll bb) : a(aa), b(bb) {
    ll g = gcd(a, b);
    if (g == 0)
      g = 1;
    a /= g, b /= g;
    if (b < 0)
      a *= -1, b *= -1;
  }
  frac(ll a, ll b, ll mm) : frac(a, b) { m = mm; }
  bool operator<(frac & o) {
    if (m != o.m)
      return m < o.m;
    return a * o.b < o.a * b;
  }
  frac operator/(ll n) {
    return frac(a + m * b, b * n);
  }
};

int n;
ll p[200000];
pair<ll, ll> d[200000];

bool cmp(const pair<ll, ll> & pa, const pair<ll, ll> & pb) {
  return 2 * pa.first + pb.second < 2 * pb.first + pa.second;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> n;
  int a, b;
  for (int i = 0; i < n; i++)
    cin >> a >> b, d[i] = {a - b, a};
  sort(d, d + n, cmp);
  int pos = -1;
  for (int i = 0; i < n && d[i].first < 0; i++)
    p[i + 1] = -d[i].first + p[i], pos = i;
  ll t = 0, m = 0;
  multiset<ll> ut;
  for (int i = n - 1; i > pos; i--) {
    ut.insert(d[i].second);
    t += d[i].second;
    m++;
  }
  frac opt(0, 1);
  for (int i = pos; i >= 0; i--) {
    while (sz(ut) > 0 && m > 0 && t > p[i + 1]) {
      auto it = ut.end();
      it--;
      ll v = *(it);
      t -= v;
      m--;
      ut.erase(it);
    }
    a = -d[i].first;
    b = d[i].second;
    while (sz(ut) > 0 && m > 0 && t > p[i]) {
      frac here(p[i] - t + a, a + b, m);
      if (opt < here)
        opt = here;
      auto it = ut.end();
      it--;
      ll v = *(it);
      t -= v;
      m--;
      ut.erase(it);
    }
    frac here(p[i] - t + a, a + b, m);
    frac herem(1, 1, m);
    if (herem < here)
      swap(here, herem);
    if (opt < here)
      opt = here;
    ut.insert(d[i].second);
    t += d[i].second;
    m++;
  }
  opt = opt / n;
  cout << opt.a << " " << opt.b << "\n";
}
