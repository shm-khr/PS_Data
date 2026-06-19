class RadixHeap:
    # from https://ikatakos.com/pot/programming_algorithm/data_structure/radix_heap
    v = [[] for _ in range(70)]

    def __init__(self):
        self.last = 0

    def push(self, x):
        self.v[(x ^ self.last).bit_length()].append(x)

    def pop(self):
        if not self.v[0]:
            cv = next(x for x in self.v if x)
            self.last = min(cv)
            for x in cv:
                self.push(x)
            cv.clear()
        return self.v[0].pop()


def main():
    import sys
    sys.setrecursionlimit(500000)
    input = sys.stdin.readline
    from heapq import heappop, heappush
    mod = 10**9+7
    INF = 1<<60
    N, M = map(int, input().split())
    S, T = map(int, input().split())
    E = [[] for _ in range(N+1)]
    edges = []
    for _ in range(M):
        u, v, d = map(int, input().split())
        E[u].append((v, d))
        E[v].append((u, d))
        edges.append((u, v, d))

    def dijksrtra(start):
        Dist = [INF] * (N+1)
        Dist[start] = 0
        #q = [0<<20 | start]
        q = RadixHeap()
        q.push(1<<68)  # 番兵
        q.push(0<<20 | start)
        mask = (1<<20)-1
        while True:
            #dist_v = heappop(q)
            dist_v = q.pop()
            if dist_v == 1<<68:
                break
            v = dist_v & mask
            dist = dist_v >> 20
            if Dist[v] != dist:
                continue
            for u, d in E[v]:
                new_dist = dist + d
                if Dist[u] > new_dist:
                    Dist[u] = new_dist
                    #heappush(q, new_dist<<20 | u)
                    q.push(new_dist<<20 | u)
        return Dist

    Dist_S = dijksrtra(S)
    Dist_T = dijksrtra(T)
    dist_st = Dist_S[T]

    DAG_edges = []  # S -> T
    DAG = [[] for _ in range(N+1)]
    DAG_rev = [[] for _ in range(N+1)]
    for u, v, d in edges:
        if Dist_S[u] + Dist_T[v] + d == dist_st:
            DAG_edges.append((u, v))
            DAG[u].append(v)
            DAG_rev[v].append(u)
        elif Dist_T[u] + Dist_S[v] + d == dist_st:
            DAG_edges.append((v, u))
            DAG[v].append(u)
            DAG_rev[u].append(v)

    n_paths_S = [-1] * (N+1)
    n_paths_T = [-1] * (N+1)
    n_paths_S[S] = 1
    n_paths_T[T] = 1
    def calc_n_paths_S(v):
        if n_paths_S[v] != -1:
            return n_paths_S[v]
        res = 0
        for u in DAG_rev[v]:
            res = (res + calc_n_paths_S(u)) % mod
        n_paths_S[v] = res
        return res
    def calc_n_paths_T(v):
        if n_paths_T[v] != -1:
            return n_paths_T[v]
        res = 0
        for u in DAG[v]:
            res = (res + calc_n_paths_T(u)) % mod
        n_paths_T[v] = res
        return res

    ans = calc_n_paths_S(T)  # 全経路数
    calc_n_paths_T(S)

    ans = ans * ans % mod

    for v, u in DAG_edges:  # 辺ですれ違う場合
        if Dist_S[v]*2 < dist_st and dist_st < Dist_S[u]*2:
            ans = (ans - (n_paths_S[v]*n_paths_T[u])**2) % mod

    # 頂点ですれ違う場合
    for v, (dist, ns, nt) in enumerate(zip(Dist_S, n_paths_S, n_paths_T)):
        if dist*2 == dist_st:
            ans = (ans - (ns*nt)**2) % mod

    print(ans)

main()
