/*
    Author: Nguyen Tan Bao
    Status:
    Idea:
*/
 
#include <bits/stdc++.h>
#define FI first
#define SE second
#define EPS 1e-9
#define ALL(a) a.begin(),a.end()
#define SZ(a) int((a).size())
#define MS(s, n) memset(s, n, sizeof(s))
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORE(i,a,b) for (int i = (a); i >= (b); i--)
#define FORALL(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
//__builtin_ffs(x) return 1 + index of least significant 1-bit of x
//__builtin_clz(x) return number of leading zeros of x
//__builtin_ctz(x) return number of trailing zeros of x
 
using namespace std;
using ll = long long;
using ld = double;
typedef pair<int, int> II;
typedef pair<II, int> III;
typedef complex<ld> cd;
typedef vector<cd> vcd;
 
const ll MODBASE = 1000000007LL;
const int MAXN = 200010;
const int MAXM = 1000;
const int MAXK = 16;
const int MAXQ = 200010;

int n, c[MAXN], num[MAXN], x[MAXN], par[MAXN][20], d[MAXN];
vector<int> a[MAXN * 2];
vector<int> b[MAXN * 2];
ll res;

void dfs(int u, int p) {
    num[u] = 1;
    FOR(i,0,SZ(a[u])-1) {
        int v = a[u][i];
        if (v == p) continue;
        par[v][0] = u;
        d[v] = d[u]+1;
        dfs(v, u);
        num[u] += num[v];
    }
}

int lca(int u, int v) {
    if (u > n) return u;
    if (v > n) return v;
    if (d[v] < d[u]) FORE(i,19,0) if (d[par[u][i]] >= d[v]) u = par[u][i];
    if (d[u] < d[v]) FORE(i,19,0) if (d[par[v][i]] >= d[u]) v = par[v][i];
    FORE(i,19,0) if (par[u][i] != par[v][i]) { u = par[u][i]; v = par[v][i]; }
    while (u != v) { u = par[u][0]; v = par[v][0]; }
    return u;
}

void dfs2(int u, int p) {
    FOR(i,0,SZ(a[u])-1) {
        int v = a[u][i];
        if (v == p) continue;
        int col = c[v];
        int tmp = x[col];
        b[tmp].push_back(v);
        // cout << tmp << ' ' << v << endl;
        x[col] = v;
        dfs2(v, u);
        x[col] = tmp;
    }
}

void dfs3(int u, int p) {
    // cout << "------- " << u << endl;
    int itr = 0;
    FOR(i,0,SZ(a[u])-1) {
        int v = a[u][i];
        if (v == par[u][0]) continue;
        int e = num[v];
        // cout << v << ' ' << e << endl;
        while (itr < SZ(b[u])) {
            int V = b[u][itr];
            // cout << V << endl;
            if (lca(v, V) != v) break;
            e -= num[V];
            itr++;
        }
        
        res += (ll) e * (e + 1) / 2;
    }
    FOR(i,0,SZ(b[u])-1) {
        int v = b[u][i];
        dfs3(v, u);
    }
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    FOR(i,1,n) cin >> c[i];
    FOR(i,1,n-1) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    a[0].push_back(1);

    par[1][0] = 1;
    dfs(1, 0);
    FOR(j,1,19)
        FOR(i,1,n) par[i][j] = par[par[i][j-1]][j-1];

    FOR(i,1,n) {
        x[i] = i+n;
        a[i+n].push_back(1);
        num[x[i]] = n+1;
    }
    dfs2(0, -1);

    FOR(i,1,n) {
        int root = n + i;
        res = 0;
        dfs3(root, 0);
        res = (ll) n * (n+1) / 2 - res;
        cout << res << "\n";
    }
    return 0;
}
