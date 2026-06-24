#include <bits/stdc++.h>

#define mp make_pair
#define fst first
#define snd second

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;

template <typename T>
T id(T b) {return b;};
template <class It>
bool all(It f,It l){return std::all_of(f,l,id<bool>);}
template <class It>
bool any(It f,It l){return std::any_of(f,l,id<bool>);}

struct edge { int to; ll value; };

const int MAX_N = 100000;
int n,m;
vector<edge> g[MAX_N];
ll min_e[MAX_N];
ll cond[MAX_N][2];
ll INF = LLONG_MAX;

bool dfs(int u, int p, ll total, int odd) {
  if (cond[u][odd] != INF)
    return cond[u][odd] == total;

  cond[u][odd] = total;

  for (edge e : g[u]) {
    if (e.to == p) continue;
    if (!dfs(e.to, u, e.value - total, 1-odd))
      return false;
  }

  return true;
}

int main()
{
  cin >> n >> m;
  fill_n(min_e,n,LLONG_MAX);

  int u,v;
  ll s;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> s;
    u--,v--;
    g[u].push_back((edge){v, s});
    g[v].push_back((edge){u, s});
    min_e[u] = min(min_e[u], s);
    min_e[v] = min(min_e[v], s);
  }

  for (int i = 0; i < n; i++)
    cond[i][0] = cond[i][1] = INF;

  if (!dfs(0,-1,0,0)) {
    cout << 0 << endl;
    return 0;
  }

  ll t_min = 1, t_max = LLONG_MAX;
  for (int i = 0; i < n; i++) {
    if (cond[i][0] != INF && cond[i][1] != INF) {
      ll t = (cond[i][1] - cond[i][0]) / 2;
      if (t_min <= t && t <= t_max) {
        t_min = t_max = t;
      } else {
        t_min = LLONG_MAX;
        t_max = LLONG_MIN;
      }
    } else {
      if (cond[i][0] < INF) {
        t_min = max(t_min, 1-cond[i][0]);
        t_max = min(t_max, min_e[i]-1-cond[i][0]);
      }

      if (cond[i][1] < INF) {
        t_min = max(t_min, cond[i][1]-min_e[i]+1);
        t_max = min(t_max, cond[i][1]-1);
      }
    }
  }

  //printf("mx=%lld mn=%lld\n",t_min,t_max);

  if (t_max >= t_min)
    cout << t_max - t_min + 1 << endl;
  else
    cout << 0 << endl;

  return 0;
}
