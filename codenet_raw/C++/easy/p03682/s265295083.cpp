#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b); i >= (a); i--)
#define R0F(i, a) ROF(i, 0, a-1)
#define trav(x, a) for (auto& x: a)

const int MX  = 2e5+5;
const int MOD = 1e9+7;
const ll  INF = 1061109567; // 4557430888798830399LL
const ld  EPS = 1e-9;
const ld  PI  = acos(-1);

struct DSU {
    vi e; void init(int n) { e = vi(n,-1); }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) { // union by size
        x = get(x), y = get(y); if (x == y) return 0;
        if (e[x] > e[y]) swap(x,y);
        e[x] += e[y]; e[y] = x; return 1;
    }
};

int N; DSU DS;
vector<tuple<int,int,int>> adj;

ll Kruskal() {
    sort(all(adj)); DS.init(N); ll res = 0;
    trav(x,adj) {
        int u,v,w; tie(w,u,v) = x;s
        if (unite(u,v)) {
            res += w;
        }
    }
    return res;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    vector<tuple<int,int,int>> v;
    F0R(i,N) {
        int x,y; cin >> x >> y;
        v.pb(tie(x,y,i));
    }

    sort(all(v));

    F0R(i,N-1) {
        int x1,y1,ii,x2,y2,jj;
        tie(x1,y1,ii) = v[i];
        tie(x2,y2,jj) = v[i+1];

        int cost = min(abs(x1-x2),abs(y1-y2));
        adj.pb(tie(cost,ii,jj));
    }

    F0R(i,N) {
        int x1,y1,ii;
        tie(x1,y1,ii) = v[i];
        v[i] = tie(y1,x2,ii);
    }

    sort(all(v));

    F0R(i,N-1) {
        int x1,y1,ii,x2,y2,jj;
        tie(x1,y1,ii) = v[i];
        tie(x2,y2,jj) = v[i+1];

        int cost = min(abs(x1-x2),abs(y1-y2));
        adj.pb(tie(cost,ii,jj));
    }

    cout << Kruskal() << "\n";

}
