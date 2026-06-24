#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <complex>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <bitset>
#include <ctime>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cassert>
#include <cstddef>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <sstream>
#include <fstream>

using namespace std;
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define RREP(i, a) for(int (i) = (a) - 1; (i) >= 0; (i)--)
#define FORR(i, a, b) for(int (i) = (a) - 1; (i) >= (b); (i)--)
#define DEBUG(C) cerr << #C << " = " << C << endl;
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<LL>;
using VVL = vector<VL>;
using VD = vector<double>;
using VVD = vector<VD>;
using PII = pair<int, int>;
using PDD = pair<double, double>;
using PLL = pair<LL, LL>;
using VPII = vector<PII>;
template<typename T> using VT = vector<T>;
#define ALL(a) begin((a)), end((a))
#define RALL(a) rbegin((a)), rend((a))
#define SORT(a) sort(ALL((a)))
#define RSORT(a) sort(RALL((a)))
#define REVERSE(a) reverse(ALL((a)))
#define MP make_pair
#define FORE(a, b) for (auto &&a : (b))
#define FIND(s, e) ((s).find(e) != (s).end())
#define EB emplace_back
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

template<typename T = int>
vector<T> dijkstra(vector<pair<int, T>> G[], int size, int st, const T inf) {
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
    pq.push({0, st});
    vector<T> dist(size, inf);
    dist[st] = 0;
    while (!pq.empty()) {
        const auto now = pq.top();
        pq.pop();
        for (auto nxt : G[now.second]) {
            const T nextCost = dist[now.second] + nxt.second;
            if (dist[nxt.first] <= nextCost) {
                continue;
            }

            dist[nxt.first] = nextCost;
            pq.push(make_pair(nextCost, nxt.first));
        }
    }
    return dist;
}

const int MAX = 1e5 + 10;
int N, M;
int S, T;
LL min_cost;
VL min_s, min_t;
vector<pair<int, LL>> G[MAX];
map<PII, int> route_cnt[2];
int node_cnt[MAX][2];
int min_cost_cnt[2];

// ぶつかる可能性があるのは一箇所(二所以上あったら最短路にならないはず)
// && ちょうど半分のところ(どっちかに時間が偏ってたらそれも最短路にはならないはず)

int main(void) {
    scanf("%d%d", &N, &M);
    scanf("%d%d", &S, &T);
    S--;T--;
    REP(i, M) {
        int u, v;
        LL d;
        scanf("%d%d%lld", &u, &v, &d);
        u--;v--;
        G[u].EB(MP(v, d));
        G[v].EB(MP(u, d));
    }
    min_s = dijkstra<LL>(G, N, S, LLINF);
    min_t = dijkstra<LL>(G, N, T, LLINF);
    assert(min_s[T] == min_t[S]);
    min_cost = min_s[T];
    {
        {// S - T count
            const int idx = 0;
            queue<pair<int, LL>> q;
            q.emplace(MP(T, min_cost));
            while (!q.empty()) {
                int now;
                LL now_cost;
                tie(now, now_cost) = q.front();
                q.pop();
                if (now_cost == 0) {
                    min_cost_cnt[idx]++;
                }
                if (now_cost * 2 == min_cost) {
                    node_cnt[now][idx]++;
                }
                FORE(e, G[now]) {
                    if (now_cost - e.second == min_s[e.first]) {
                        q.emplace(MP(e.first, now_cost - e.second));
                        if (now_cost * 2 > min_cost && (now_cost - e.second) * 2 < min_cost) {
                            route_cnt[idx][MP(min(e.first, now), max(e.first, now))]++;
                        }
                    }
                }
            }
        }
        {// T - S count
            const int idx = 1;
            queue<pair<int, LL>> q;
            q.emplace(MP(S, min_cost));
            while (!q.empty()) {
                int now;
                LL now_cost;
                tie(now, now_cost) = q.front();
                q.pop();
                if (now_cost == 0) {
                    min_cost_cnt[idx]++;
                }
                if (now_cost * 2 == min_cost) {
                    node_cnt[now][idx]++;
                }
                FORE(e, G[now]) {
                    if (now_cost - e.second == min_t[e.first]) {
                        q.emplace(MP(e.first, now_cost - e.second));
                        if (now_cost * 2 > min_cost && (now_cost - e.second) * 2 < min_cost) {
                            route_cnt[idx][MP(min(e.first, now), max(e.first, now))]++;
                        }
                    }
                }
            }
        }
        LL ans = 1ll * min_cost_cnt[0] * min_cost_cnt[1] % MOD;
        REP(i, N) {
            ans = ans - 1ll * node_cnt[i][0] * node_cnt[i][1] + MOD;
            ans %= MOD;
        }
        FORE(e, route_cnt[0]) {
            if (route_cnt[1].count(e.first)) {
                ans = ans - 1ll * e.second * route_cnt[1][e.first] + MOD;
                ans %= MOD;
            }
        }
        cout << ans << endl;
    }
}
