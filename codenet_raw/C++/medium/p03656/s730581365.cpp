#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif


    int n;
    while (scanf("%d", &n) == 1) {
        vector<vector<int> > p(2, vector<int>(n));
        vector<vector<vector<int> > > e(2, vector<vector<int> >(n));
        vector<int> root(2);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &p[i][j]);
                if (p[i][j] != -1) e[i][--p[i][j]].push_back(j);
                else root[i] = j;
            }
        }

        bool ok = 1;
        for (int i = 0; i < n; i++) {
            ok &= e[0][i].size() % 2 == e[1][i].size() % 2;
        }
        if (!ok) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        printf("POSSIBLE\n");

        vector<int> ans(n + 1, -999);
        vector<vector<vector<int> > > g(2, vector<vector<int> >(n + 1));
        for (int i = 0; i < 2; i++) {
            function<void(int, int)> dfs = [&](int v, int pr) {
                if (e[i][v].size() % 2 == 0) {
                    g[i][pr].push_back(v);
                    p[i][v] = pr;
                    pr = v;
                } else ans[v] = 0;
                for (int to : e[i][v]) {
                    dfs(to, pr);
                }
            };
            dfs(root[i], n);
        }

        vector<vector<char> > vis(2, vector<char>(n + 1));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < n; i++) {
                if (ans[i] == -999) {
                    int cur = 0;
                    int v = i;
                    while (!vis[cur][v]) {
                        vis[cur][v] = 1;
                        ans[v] = cur == 0 ? +1 : -1;
                        while (!g[cur][p[cur][v]].empty() && vis[cur][g[cur][p[cur][v]].back()]) {
                            g[cur][p[cur][v]].pop_back();
                        }
                        if (g[cur][p[cur][v]].empty()) {
                            cur ^= 1;
                            if (vis[cur][v]) break;
                            else continue;
                        }
                        v = g[cur][p[cur][v]].back();
                        vis[cur][v] = 1;
                        cur ^= 1;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) printf("%d%c", ans[i], " \n"[i + 1 == n]);
    }


#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}