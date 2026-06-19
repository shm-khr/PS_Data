#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  int n = s.length();

  for (int i = 0; i < n / 2; ++i) {
    if (s[i] != s[n - 1 - i]) {
      cout << "No\n";
      return 0;
    }
  }

  for (int i = 0; i < n / 2; ++i) {
    if (s[i] != s[n / 2 - 1 - i]) {
      cout << "No\n";
      return 0;
    }
  }

  for (int i = n / 2 + 1; i < n; ++i) {
    if (s[i] != s[n - 1 - i]) {
      cout << "No\n";
      return 0;
    }
  }

  cout << "Yes\n";
}
