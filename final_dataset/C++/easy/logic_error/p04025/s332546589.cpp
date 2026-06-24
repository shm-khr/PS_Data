#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
  #ifdef GG
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  cin >> s; int n = (int) s.size();
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] == s[i + 1]) {
      cout << i + 1 << ' ' << i + 2;
      return 0;
    }
  }
  for (int i = 0; i < n - 2; ++i) {
    if (s[i] == s[i + 2]) {
      cout << i + 1 << ' ' << i + 3;
      return 0;
    }
  }
  cout << "-1 -1";
  return 0;
}
