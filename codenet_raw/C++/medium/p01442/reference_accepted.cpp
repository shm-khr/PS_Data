#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define resz(v, ...) (v).clear(), (v).resize(__VA_ARGS__)
#define reps(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep(i, n) reps(i, 0, n)

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

using Pi = pair<int, int>;
using Tapris = tuple<int, int, int>;
using vint = vector<int>;

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

int H, W, N;
string s;
string c[1001];
int nex[4][1001000];
int mincost[1001][1001];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

struct State {
  int y, x, cost;
  State(){}
  State(int y, int x, int cost):y(y), x(x), cost(cost){}
  bool operator < (const State& s) const {
    return cost > s.cost;
  }
};

bool in(int y, int x) {
  return 0<=y&&y<H&&0<=x&&x<W&&c[y][x]!='#';
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  while(cin >> H >> W >> N, H) {
    cin >> s;
    rep(i, H) cin >> c[i];

    vint sum(N+1);
    rep(i, N) {
      if(s[i] == 'L') sum[i+1] = sum[i]+1;
      else sum[i+1] = sum[i]+3;
      sum[i+1] %= 4;
    }
    memset(nex, -1, sizeof(nex));
    rep(i, 4) {
      int p = -1;
      for(int j = N; j >= 0; --j) {
	if(sum[j] == i) p = j;
	if(~p) nex[i][j] = p-j;
      }
    }

    int sy, sx, gy, gx;
    rep(i, H) rep(j, W) {
      if(c[i][j] == 'S') sy = i, sx = j;
      else if(c[i][j] == 'G') gy = i, gx = j;
    }

    priority_queue<State> que;
    fill(mincost[0], mincost[1001], inf);
    mincost[sy][sx] = 0;
    que.push(State(sy, sx, 0));
    while(!que.empty()) {
      State st = que.top(); que.pop();
      if(st.y == gy && st.x == gx) break;
      if(mincost[st.y][st.x] < st.cost) continue;
      rep(i, 4) {
	int ny = st.y + dy[i], nx = st.x + dx[i];
	if(!in(ny, nx)) continue;
	if(nex[i][st.cost] == -1) continue;
	if(st.cost+nex[i][st.cost] < mincost[ny][nx]) {
	  mincost[ny][nx] = st.cost + nex[i][st.cost];
	  que.push(State(ny, nx, mincost[ny][nx]));
	}
      }
    }
    cout << (mincost[gy][gx] == inf ? "No" : "Yes") << endl;
  }

  return 0;
}

