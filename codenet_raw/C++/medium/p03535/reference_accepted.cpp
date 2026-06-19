#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 13;

int cnt [MAX_N];

vector<int> build (int mask) {
  vector<int> has (24, 0);
  if (cnt[0]) has[0] = 1;
  if (cnt[12]) has[12] = 1;
  for (int i = 1; i < 12; i++) {
    if (cnt[i] == 2) {
      has[i] = 1;
      has[24 - i] = 1;
    } else if (cnt[i] == 1) {
      if (mask & 1 << i) {
        has[i] = 1;
      } else {
        has[24 - i] = 1;
      }
    }
  }
  return has;
}

int dist (int u, int v) {
  return min((v - u + 24) % 24, (u - v + 24) % 24);
}

int eval (vector<int> table) {
  int ans = 100;
  for (int i = 0; i < 24; i++) {
    for (int j = i + 1; j < 24; j++) {
      if (table[i] && table[j]) {
        ans = min(ans, dist(i, j));
      }
    }
  }
  return ans;
}

int main () {
  int n;
  cin >> n;

  cnt[0]++;
  for (int i = 0; i < n; i++) {
    int D;
    cin >> D;

    cnt[D]++;
  }

  if (cnt[0] > 1 || cnt[12] > 1) {
    cout << 0 << endl;
    return 0;
  }

  for (int i = 1; i < 12; i++) {
    if (cnt[i] > 2) {
      cout << 0 << endl;
      return 0;
    }
  }

  int ans = 0;
  for (int mask = 0; mask < 1 << MAX_N; mask++) {
    ans = max(ans, eval(build(mask)));
  }
  cout << ans << endl;
}
