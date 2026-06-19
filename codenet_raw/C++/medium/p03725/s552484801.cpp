#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define FORR(i, a, b) for(ll i = (a); i > (b); --i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOREACH(x, a) for(auto &(x) : (a))
#define VECCIN(x)                                                              \
    for(auto &youso_ : (x)) cin >> youso_
#define bitcnt __builtin_popcount
#define SZ(x) ((ll)(x).size())
#define fi first
#define se second
#define All(a) (a).begin(), (a).end()
template <typename T = long long> inline T IN() {
    T x;
    cin >> x;
    return (x);
}
inline void CIN() {}
template <class Head, class... Tail>
inline void CIN(Head &&head, Tail &&... tail) {
    cin >> head;
    CIN(move(tail)...);
}
#define CCIN(...)                                                              \
    char __VA_ARGS__;                                                          \
    CIN(__VA_ARGS__)
#define DCIN(...)                                                              \
    double __VA_ARGS__;                                                        \
    CIN(__VA_ARGS__)
#define LCIN(...)                                                              \
    ll __VA_ARGS__;                                                            \
    CIN(__VA_ARGS__)
#define SCIN(...)                                                              \
    string __VA_ARGS__;                                                        \
    CIN(__VA_ARGS__)
#define Yes(a) cout << (a ? "Yes" : "No") << "\n"
#define YES(a) cout << (a ? "YES" : "NO") << "\n"
#define Printv(v)                                                              \
    {                                                                          \
        FOREACH(x, v) { cout << x << " "; }                                    \
        cout << "\n";                                                          \
    }
template <typename T = string> inline void eputs(T s) {
    cout << s << "\n";
    exit(0);
}
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
    std::fill((T *)array, (T *)(array + N), val);
}
template <typename T> using PQG = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using PQ = priority_queue<T>;

typedef long long ll;
typedef pair<ll, ll> PL;
typedef vector<PL> VPL;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<double> VD;

const int INF = 1e9;
const int MOD = 1e9 + 7;
const double PI = atan(1.0) * 4.0;
// const int MOD = 998244353;
const ll LINF = 9e18;
const ll dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

void cinfast() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

string S[800];

ll H, W, sx, sy, gx, gy, K;
vector<VL> d;

void bfs(PL s) {
    queue<PL> q;
    q.emplace(s);
    d.assign(H, VL(W, LINF));
    d[s.fi][s.se] = 0;
    while(!q.empty()) {
        PL now = q.front();
        q.pop();
        ll y = now.fi, x = now.se;
        REP(i, 4) {
            ll ny = y + dy[2 * i], nx = x + dx[2 * i];
            if(nx < 0 || nx > W - 1 || ny < 0 || ny > H - 1) continue;
            if(S[ny][nx] == '.' && d[ny][nx] == LINF) {
                d[ny][nx] = d[y][x] + 1;
                q.emplace(ny, nx);
            }
        }
    }
}

void bfs2(VPL s) {
    queue<PL> q;
    d.assign(H, VL(W, LINF));
    FOREACH(x, s) {
        d[x.fi][x.se] = 0;
        q.emplace(x);
    }
    while(!q.empty()) {
        PL now = q.front();
        q.pop();
        ll y = now.fi, x = now.se;
        REP(i, 4) {
            ll ny = y + dy[2 * i], nx = x + dx[2 * i];
            if(nx < 0 || nx > W - 1 || ny < 0 || ny > H - 1) continue;
            if(d[ny][nx] == LINF) {
                d[ny][nx] = d[y][x] + 1;
                q.emplace(ny, nx);
            }
        }
    }
}

signed main() {
    cin >> H >> W >> K;
    ll sh, sw;
    REP(i, H) {
        cin >> S[i];
        REP(j, W) if(S[i][j] == 'S') {
            S[i][j] = '.';
            sh = i, sw = j;
        }
    }
    bfs(PL(sh, sw));
    VPL start;
    REP(i, H) REP(j, W) if(d[i][j] <= K) start.emplace_back(PL(i, j));
    bfs2(start);
    ll md = LINF;
    REP(i, W) md = min({d[0][i], d[H - 1][i], md});
    REP(i, H) md = min({d[i][0], d[i][W - 1], md});
    cout << md / K + md % K + 1 << "\n";
}