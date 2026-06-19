#include <iostream>

using namespace std;

const long long INF = 9223372036854775807;

struct datum {
  long long min, max;

  datum &update(long long x) {
    if (x < min) min = x;
    if (x > max) max = x;
    return *this;
  }

  long long diff() const { return max - min; }
};

datum operator^(const datum &a, const datum &b) {
  return a.diff() <= b.diff() ? a : b;
}

datum dfs(long long h, long long w, int n) {
  if (n == 1) {
    long long S = h * w;
    return {S, S};
  }

  return dfs(h - h / n, w, n - 1).update(h / n * w) ^
         dfs(h - (h / n + 1), w, n - 1).update((h / n + 1) * w) ^
         dfs(h, w - w / n, n - 1).update(h * (w / n)) ^
         dfs(h, w - (w / n + 1), n - 1).update(h * (w / n + 1));
}

int main() {
  int H, W;
  cin >> H >> W;

  cout << dfs(H, W, 3).diff() << endl;
}
