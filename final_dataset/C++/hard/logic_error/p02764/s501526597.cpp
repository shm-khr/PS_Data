#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
const int inf = 1e9 + 7;
const ll INF = 1e18;
#define abs(x) (x >= 0 ? x : -(x))
#define lb(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define ub(v, x) (int)(upper_bound(all(v), x) - v.begin())
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T> T pow(T a, int b) { return b ? pow(a * a, b / 2) * (b % 2 ? a : 1) : 1; }
const int mod = 1000000007;
ll modpow(ll a, int b) { return b ? modpow(a * a % mod, b / 2) * (b % 2 ? a : 1) % mod : 1; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& vec) { rep(i, sz(vec)) { if (i) os << " "; os << vec[i]; } return os; }
template<class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p) { os << p.F << " " << p.S; return os; }
template<class T> inline void add(T &a, int b) { a += b; if (a >= mod) a -= mod; }



void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);

  int T;
  // cin >> T;
  T = 1;

  while (T--) {
      solve();
  }
}

const double eps = 1e-8;
int n, k;
using t = tuple<double, double, double>;
vector<t> v;

double g(double X, double Y) {
  vector<double> r(n);
  rep(i, n) {
    double x, y, c;
    tie(x, y, c) = v[i];
    r[i] = c * sqrt((X - x) * (X - x) + (Y - y) * (Y - y));
  }
  sort(all(r));
  return r[k - 1];
}
double f(double X) {
  // y に関しても三分探索
  double l = -1005, r = 1005;
  while (abs(l - r) > eps) {
    double l2 = (l * 2 + r) / 3;
    double r2 = (l + 2 * r) / 3;
    if (g(X, l2) > g(X, r2)) l = l2;
    else r = r2;
  }
  return g(X, l);
}
void solve() {
  cin >> n >> k;
  v.resize(n);
  rep(i, n) {
    double x, y, c;
    cin >> x >> y >> c;
    v[i] = make_tuple(x, y, c);
  }
  double l = -1005, r = 1005;
  while (1) {
    double l2 = (l * 2 + r) / 3;
    double r2 = (l + 2 * r) / 3;
    if (f(l2) > f(r2)) l = l2;
    else r = r2;
    if (abs(l - r) < eps) {
      cout << f(l) << endl;
      return;
    }
  }
}
