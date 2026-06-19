#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;
using ll = long long;

namespace io {
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
  const int SIZE = (1 << 21) + 1;
  char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1;
  inline char getc () {return (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++);}
  inline void flush () {fwrite (obuf, 1, oS - obuf, stdout); oS = obuf;}
  inline void putc (char x) {*oS ++ = x; if (oS == oT) flush ();}
  template<class T>
  inline void read(T &x) {
    char ch; int f = 1;
    x = 0;
    while(isspace(ch = getc()));
    if(ch == '-') ch = getc(), f = -1;
    do x = x * 10 + ch - '0'; while(isdigit(ch = getc()));
    x *= f;
  }
  template<class T, class ...Args>
  inline void read(T &x, Args&... args) {read(x); read(args...);}
  template<class T>
  inline void write(T x) {
    static char stk[128];
    int top = 0;
    if(x == 0) {putc('0'); return;}
    if(x < 0) putc('-'), x = -x;
    while(x) stk[top++] = x % 10, x /= 10;
    while(top) putc(stk[--top] + '0');
  }
  template<class T, class ...Args>
  inline void write(T x, Args... args) {write(x); putc(' '); write(args...);}
  inline void space() {putc(' ');}
  inline void endl() {putc('\n');}
  struct _flush {~_flush() {flush();}} __flush;
};
using io::read; using io::write; using io::flush; using io::space; using io::endl; using io::getc; using io::putc;

const int M = 1000000007;
inline int add(int x, int y) {return x+y>=M ? x+y-M : x+y;}
template<class ...Args> inline int add(int x, int y, Args... args) {return add(add(x, y), args...);}
inline int sub(int x, int y) {return x-y<0 ? x-y+M : x-y;}
inline int mul(int x, int y) {return 1LL * x * y % M;}
template<class ...Args> inline int mul(int x, int y, Args... args) {return mul(mul(x, y), args...);}
inline void inc(int &x, int y=1) {x += y; if(x >= M) x -= M;}
inline void dec(int &x, int y=1) {x -= y; if(x < 0) x += M;}
inline int power(int x, int y){
  int res = 1;
  for(; y; y>>=1, x = mul(x, x)) if(y & 1) res = mul(res, x);
  return res;
}
inline int inv(int x){return power(x, M - 2);}

const int N = 400005;
vector<int> G[N];
int tfa[N];
int indeg[N], siz[N];
vector<int> circ, node;

namespace DSU {
int fa[N], rk[N];
bool circuit[N];
int find(int x) {
  if (!fa[x]) return x;
  return fa[x] = find(fa[x]);
}
bool merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) {
    if (circuit[x]) return false;
    circuit[x] = true;
    return true;
  }
  if (rk[x] < rk[y]) swap(x, y);
  fa[y] = x, rk[x] += rk[x] == rk[y];
  circuit[x] = circuit[x] || circuit[y];
  return true;
}
}; // namespace DSU

int fac[N], ifac[N];
void pre(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = mul(fac[i - 1], i);
  ifac[n] = inv(fac[n]);
  for (int i = n - 1; i >= 0; --i) ifac[i] = mul(ifac[i + 1], i + 1);
}

bool vis[N];
int from[N];

void dfs(int x) {
  vis[x] = true;
  node.push_back(x);
  for (int v : G[x]) {
    if (v == from[x]) continue;
    if (vis[v]) {
      if (!circ.empty()) continue;
      circ.push_back(v);
      circ.push_back(x);
      int t = from[x];
      while (t != v) {
        circ.push_back(t);
        t = from[t];
      }
      continue;
    }
    from[v] = x;
    dfs(v);
  }
}
int fa[N];
void dfs2(int x) {
  for (int v : G[x]) {
    if (fa[v]) continue;
    fa[v] = x;
    dfs2(v);
  }
}
int topo_cnt() {
  int res = 1;
  queue<int> q;
  for (int x : node) {
    siz[x] = 1;
    if (!indeg[x])
      q.push(x);
  }
  while (!q.empty()) {
    int x = q.front(); q.pop();
    res = mul(res, inv(siz[x]));
    if (!tfa[x]) continue;
    indeg[tfa[x]]--;
    siz[tfa[x]] += siz[x];
    if (indeg[tfa[x]] == 0)
      q.push(tfa[x]);
  }
  return res;
}

int main() {
  int n;
  read(n);
  pre(n * 2);
  for (int i = 1; i <= n * 2; ++i) {
    int x, y;
    read(x, y);
    G[x].push_back(n + y); G[n + y].push_back(x);
    if (!DSU::merge(x, n + y)) {
      puts("0");
      return 0;
    }
  }
  for (int i = 1; i <= 2 * n; ++i)
    sort(G[i].begin(), G[i].end());
  int res = fac[n * 2];
  for (int i = 1; i <= n * 2; ++i) {
    int now = 0;
    if (!vis[i]) {
      node.clear();
      circ.clear();
      dfs(i);
      int L = circ.size();
      fa[circ[0]] = circ[L - 1];
      for (int i = 1; i < L; ++i)
        fa[circ[i]] = circ[i - 1];
      for (int x : circ)
        dfs2(x);
      for (int x : node) {
        for (int v : G[x]) {
          if (v < fa[x])
            tfa[v] = x, ++indeg[x];
          else break;
        }
      }
      now += topo_cnt();
      for (int x : node)
        tfa[x] = 0, indeg[x] = 0;
      fa[circ[L - 1]] = circ[0];
      for (int i = 0; i < L - 1; ++i)
        fa[circ[i]] = circ[i + 1];
      for (int x : node) {
        for (int v : G[x])
          if (v < fa[x]) tfa[v] = x, ++indeg[x];
          else break;
      }
      now += topo_cnt();
      now %= M;
      res = mul(res, now);
    }
  }
  printf("%d\n", res);
  return 0;
}