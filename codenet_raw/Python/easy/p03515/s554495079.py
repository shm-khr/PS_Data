N = int(input())
G = [[] for i in range(N)]
for i in range(N-1):
    a, b, c = map(int, input().split())
    G[a-1].append((b-1, c))
    G[b-1].append((a-1, c))

if N <= 1000:
    def dfs(u, p, co):
        res = co
        for v, c in G[u]:
            if v == p:
                continue
            res += dfs(v, u, min(co, c))
        return res
    for i in range(N):
        INF = 10**18
        print(dfs(i, -1, INF) - INF)




