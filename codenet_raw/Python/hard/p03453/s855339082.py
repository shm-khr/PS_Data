# 参考: https://qiita.com/y-tsutsu/items/aa7e8e809d6ac167d6a1

from heapq import heappush, heappop

# 多次元配列
# dp = [[0] * 3 for _ in range(5)


INF = 1 << 28
MOD = int(1e9) + 7


def dijkstra(graph, s: int, t: int):
    n = len(graph)
    dist = [INF for _ in range(n)]
    cnts = [0 for _ in range(n)]

    pq = []
    heappush(pq, (0, s))
    dist[s] = 0
    cnts[s] = 1

    while pq:
        (cost, cur) = heappop(pq)

        if dist[cur] != cost:
            continue
        
        if cur == t:
            return dist, cnts

        for next_idx, next_cost in graph[cur]:
            if dist[next_idx] > cost + next_cost:
                heappush(pq, (cost + next_cost, next_idx))
                dist[next_idx] = cost + next_cost
                cnts[next_idx] = cnts[cur]
            elif dist[next_idx] == cost + next_cost:
                cnts[next_idx] = (cnts[next_idx] + cnts[cur]) % MOD

    return dist, cnts


# 入力を受け取る
n, m = map(int, input().split())

s, t = map(lambda i: int(i) - 1, input().split())

g = [[] for _ in range(n)]

es = [list(map(int, input().split())) for _ in range(m)]

for e in es:
    u, v, d = e
    g[u - 1].append((v - 1, d))
    g[v - 1].append((u - 1, d))

dst1, cnt1 = dijkstra(g, s, t)
dst2, cnt2 = dijkstra(g, t, s)

ret = cnt1[t] * cnt1[t] % MOD

for i in range(n):
    if 2 * dst1[i] == dst1[t] == 2 * dst2[i]:
        sub = cnt1[i] * cnt2[i] % MOD
        sub = sub ** 2 % MOD
        ret = (ret + MOD - sub) % MOD

sum_sub = 0

for e in es:
    u, v, d = e
    u -= 1
    v -= 1

    if cnt1[u] > cnt1[v]:
        v, u = u, v

    if 2 * dst1[u] < dst1[t] < 2 * dst1[v] and dst1[u] + d + dst2[v] == dst1[t]:
        sub = cnt1[u] * cnt2[v] % MOD
        sub = sub ** 2 % MOD
        ret = (ret + MOD - sub) % MOD

print(ret)
