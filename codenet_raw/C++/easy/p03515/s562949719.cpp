#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

static const int INF = 0x3f3f3f3f;

struct edge { int to, cost; }; 
vector<edge> g[1000];
long long ans;

void dfs(int u, int prev, int mind) {
        if (mind != INF) ans += mind;
        int past = mind;
        for (auto e : g[u]) if (e.to != prev) {
                mind = min(past, e.cost);
                dfs(e.to, u, mind);
        }
}

int main() {
        int n;
        scanf("%d", &n);
        assert(n <= 1000);
        for (int i = 0; i < n - 1; i ++) {
                int a, b, c;
                scanf("%d%d%d", &a, &b, &c);
                a --, b --;
                g[a].push_back({b, c});
                g[b].push_back({a, c});
        }
        for (int i = 0; i < n; i ++) {
                ans = 0;
                dfs(i, -1, INF);
                printf("%lld\n", ans);
        }
        return 0;
}

