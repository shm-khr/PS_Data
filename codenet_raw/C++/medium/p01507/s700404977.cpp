#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <deque>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

typedef vector<ll> Array;
typedef vector<Array> Matrix;
const ll MOD = 1e+9 + 7;

void PrintMatrix(const Matrix &mat) {
  REP(y, mat.size()) {
    REP(x, mat[0].size()) {
      printf("%lld ", mat[y][x]);
    }
    puts("");
  }
  puts("");
}

//a x + b y = gcd(a, b)
long long extgcd(long long a, long long b, long long &x, long long &y) {
  long long g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}

long long InvMod(long long a, long long mod) {
  long long x, y;
  if (extgcd(a, mod, x, y) == 1) { return (x + mod) % mod; }
  return 0;
}


Matrix BandGaussElimination(Matrix mat) {
  int h = mat.size();
  if (h == 0) { return mat; }
  int w = mat[0].size() / 2;
  REP(fy, h) {
    if (mat[fy][w] == 0) { continue; }
    FOR(ty, fy + 1, min(h, fy + w + 1)) {
      ll ratio = (MOD - mat[ty][w - (ty - fy)]) * InvMod(mat[fy][w], MOD) % MOD;
      FOR(dx, 0, w + 1) {
        int fx = w + dx;
        int tx = w - (ty - fy) + dx;
        mat[ty][tx] = (mat[ty][tx] + mat[fy][fx] * ratio) % MOD;
      }
    }
  }
  return mat;
}

char field[600][600];
int indexes[600][20];
int main() {
  int w, h;
  int test_case = 0;
  while (scanf("%d %d", &h, &w), h|w) {
    MEMSET(indexes, -1);
    test_case++;
    REP(y, h) {
      scanf("%s", field[y]);
    }
    int m = 0;
    REP(y, h) {
      REP(x, w) {
        if (field[y][x] == '#' && m == 0) { continue; }
        indexes[y][x] = m++;
      }
    }
    Matrix mat(m, Array(2 * w + 1, 0));
    REP(y, h) {
      REP(x, w) {
        if (indexes[y][x] == -1) { continue; }
        if (field[y][x] == '#') {
          mat[indexes[y][x]][w] = 1;
          continue;
        }
        REP(dir, 4) {
          const int dx[4] = { 1, 0, -1, 0 };
          const int dy[4] = { 0, 1, 0, -1 };
          int nx = x + dx[dir];
          int ny = y + dy[dir];
          if (nx < 0 || nx >= w || ny < 0 || ny >= h) { continue; }
          if (field[ny][nx] == '#') { continue; }
          mat[indexes[y][x]][w]++;
          int offset = ny *  w + nx - y * w - x;
          mat[indexes[y][x]][w + offset] = MOD - 1;
          assert(abs(offset) <= w);
        }
      }
    }
    mat.erase(mat.begin());
    REP(dx, min(w, (int)mat.size())) {
      mat[dx][w - dx - 1] = 0;
    }
    mat = BandGaussElimination(mat);
    REP(y, mat.size() / 2) REP(x, w * 2 + 1) { swap(mat[y][x], mat[mat.size() - y - 1][x]); }
    REP(y, mat.size()) REP(x, w) { swap(mat[y][x], mat[y][2 * w - x]); }
    mat = BandGaussElimination(mat);
    ll ans = 1;
    REP(i, mat.size()) { ans = (ans * mat[i][w]) % MOD; }
    printf("Case %d: %lld\n", test_case, ans);
  }
}