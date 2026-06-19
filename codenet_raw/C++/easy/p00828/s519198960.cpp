#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define all(c) begin(c), end(c)
const int INF =
    sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T> bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
#define N 10
#define B 1
#define W -1
int n, m, p;
int cube[N][N][N];
int h[N][N];
int dx[] = {1, 0, 0, 1, -1, 0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {0, 1, 0, 1, 1, 1, -1, 0, 0, 1, 1, 1, 1};
int dz[] = {0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, -1, -1};

int inrange(int x, int y, int z) {
  return 0 <= x < n && 0 <= y < n && 0 <= z < n;
}
int check() {
  rep(i, 0, n) rep(j, 0, n) rep(k, 0, n) {
    rep(l, 0, 13) {
      map<int, int> color;
      rep(u, 0, m) {
        int x = i + u * dx[l], y = j + u * dy[l], z = k + u * dz[l];
        if (inrange(x, y, z))
          color[cube[x][y][z]]++;
      }
      if (color[B] == m)
        return B;
      else if (color[W] == m)
        return W;
    }
  }
  return 0;
}
signed main() {

  while (cin >> n >> m >> p, p) {
    memset(cube, 0, sizeof(cube));
    memset(h, 0, sizeof(h));
    int winner = 0;
    int fin = 0;
    for (int i = 0; i < p; i++) {
      int x, y;
      cin >> x >> y;
      x--,y--;
      if (i & 1)
        cube[x][y][h[x][y]++] = W;
      else
        cube[x][y][h[x][y]++] = B;

      if (winner == 0) {
        winner = check();
        fin++;
      }
    }
    if (winner == B)
      cout << "Black " << fin << endl;
    else if (winner == W)
      cout << "White " << fin << endl;
    else
      cout << "Draw" << endl;
  }

  return 0;
}