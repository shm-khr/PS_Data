#include<bits/stdc++.h>
using namespace std;
struct _IO{_IO(){ios::sync_with_stdio(0);cin.tie(0);}}_io;
typedef long long ll; typedef long double db;
const int N = 5e5 + 5, M = 1e9 + 7;

int main() {
  string s;
  cin >> s;
  int l, r, w = 0, b = 0;
  for (int i = 0; i < s.size(); i++) {
    if (i == 0) l = s[i] == 'B';
    if (!i || s[i] != s[i-1]) {
      if (s[i] == 'B') b++;
      else w++;
    }
    r = s[i] == 'B';
  }
  int ans = 0;
  if (!b) {
    cout << 0;
    return 0;
  }
  if (!w) {
    cout << 2;
    return 0;
  }
  if (l == r && l == 1) {
    b--, ans++;
    l = 0;
  }
  if (l == r && l == 0) {
    w--, ans++;
    l = 1;
  }
  cout << ans + 1 + ((b - 1) * 2);
}
