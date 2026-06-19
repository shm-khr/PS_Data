import sys
sys.setrecursionlimit(10**6)

N = int(input())
G = [[] for i in range(N)]
mc = 100
for i in range(N-1):
    a, b, c = map(int, input().split())
    G[a-1].append((b-1, c))
    G[b-1].append((a-1, c))
    mc = min(c, mc)

if N <= 1000:
    memo = {}
    def dfs(u, p, co):
        if (u, p, co) in memo:
            return memo[u, p, co]
        res = co
        for v, c in G[u]:
            if v == p:
                continue
            res += dfs(v, u, min(co, c))
        memo[u, p, co] = res
        return res
    for i in range(N):
        INF = 10**18
        print(dfs(i, -1, INF) - INF)
elif mc <= 2:
    used = [0]*N
    gu = 0
    g = [-1]
    def dfs(u, p):
        used[i] = gu
        res = 1
        for v, c in G[v]:
            if c == 2:
                res += dfs(v, u)
        return res
    for i in range(N):
        if not used[i]:
            gu += 1
            nn = dfs(i, -1)
            g.append(nn)
        else:
            nn = g[used[i]]
        print(N + nn)
else:
    exit(1)
