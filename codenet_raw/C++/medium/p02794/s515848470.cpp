#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef int ll;
typedef long double ld;
const ll N = 55;
char en = '\n';
ll inf = 1e16;
ll mod = 1e9 + 7;
ll power(ll x, ll n, ll mod) {
  ll res = 1;
  x %= mod;
  while (n) {
    if (n & 1)
      res = (res * x) % mod;
    x = (x * x) % mod;
    n >>= 1;
  }
  return res;
}

ll n;
ll edges[10005][2];
ll depth[10005];
vector<ll> adj[10005];

vector<ll> values[10005];

bool dfs(ll curr, ll prev1, ll u, ll v, vector<ll> path, ll desired) {

  path.push_back(curr);
  if (curr == desired) {
    for (ll i = 0; i < (ll)path.size() - 1; i++) {
      if (path[i] == u && path[i + 1] == v)
        return true;
      if (path[i] == v && path[i + 1] == u)
        return true;
    }
    path.pop_back();
    return false;
  }
  for (ll &x : adj[curr]) {
    if (x != prev1) {
      bool val = dfs(x, curr, u, v, path, desired);
      if (val)
        return true;
    }
  }
  path.pop_back();
  return false;
}
ll op[10005][2];
ll m;

ll maskOp[10005];

ll dp[2][1 << 20];
ll recur(ll edge, ll mask) {
  if (edge == n) {
    return mask == ((1 << m) - 1);
  }
  ll ans = dp[(edge + 1) & 1][mask] + dp[(edge + 1) & 1][mask | (maskOp[edge])];
  if (ans >= mod)
    ans -= mod;
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  for (ll i = 1; i <= n; i++) {
    adj[i].clear();
  }
  for (ll i = 1; i < n; i++) {
    cin >> edges[i][0] >> edges[i][1];

    adj[edges[i][0]].push_back(edges[i][1]);
    adj[edges[i][1]].push_back(edges[i][0]);
  }

  cin >> m;
  for (ll i = 0; i < m; i++)
    cin >> op[i][0] >> op[i][1];

  for (ll i = 1; i < n; i++) {
    ll u = edges[i][0], v = edges[i][1];

    assert(u != v);

    if (depth[u] < depth[v])
      swap(u, v);

    ll mask = 0;
    for (ll j = 0; j < m; j++) {
      ll a = op[j][0];
      ll b = op[j][1];

      ll cnt = 0;

      vector<ll> path;
      if (dfs(a, -1, u, v, path, b)) {
        mask |= (1 << j);
      }
    }
    maskOp[i] = mask;
  }

  assert(recur(1, 0) >= 0 && recur(1, 0) < mod);

  memset(dp, 0, sizeof(dp));
  dp[n & 1][(1 << m) - 1] = 1;
  for (ll i = n - 1; i >= 1; i--) {
    ll it = i & 1;
    for (ll mask = 0; mask < (1 << m); mask++) {
      dp[it][mask] = recur(i, mask);
    }
  }

  cout << dp[1 & 1][0] << en;

  return 0;
}