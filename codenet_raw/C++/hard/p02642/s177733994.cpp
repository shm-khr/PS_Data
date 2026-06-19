/* Author: $%U%$
 * Time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
**/
#include <bits/stdc++.h>
using namespace std;
#define fore(i, a, b) for (int i = a, to = b; i < to; i++)
#define foref(i, a, b) for (int i = b - 1, to = a; i >= to; i--)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define SZ(v) (int)v.size()
#define pb push_back
typedef long long Long;
typedef pair<int, int> Pair;
const int MX = (1e6);
Long vis[MX + 2];
void update(Long x) {
  for (Long i = x; i <= MX; i += x) {
    vis[i]++;
  }
}
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  fore(i, 0, n) cin >> v[i];
  fore(i, 0, n) update(v[i]);
  int ans = 0;
  fore(i, 0, n) {
    if (vis[v[i]] == 1) {
      ans++;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int t = 1;
  //cin >> t;
  while (t--) solve();

  return 0;
}