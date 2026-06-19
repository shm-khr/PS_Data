#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 2e9;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> p(n);
  rep(i, n) {
    pair<int, int> pa;
    int x, l;
    cin >> x >> l;
    pa.first = x-l;
    pa.second = x+l;
    p[i] = pa;
  }
  sort(p.begin(), p.end());
  int ans = 0;
  int cur = -INF;
  rep(i, n) {
    if(cur <= p[i].first) {
      ans++;
      cur = p[i].second;
    }
  }
  cout << ans << endl;
  return 0;
}