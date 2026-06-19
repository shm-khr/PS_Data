import sys
from collections import defaultdict

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

def main():
    def dfs0(u, st=-1, en=-1):
        if en == -1:
            for i, ku in enumerate(to[u]):
                if can[u][ku][0] != -1: continue
                can[u][ku][0] = i
                dfs0(ku, u, i)
            return
        for ku in to[u]:
            if ku == st: continue
            if can[st][ku][0] != -1: continue
            can[st][ku][0] = en
            dfs0(ku, st, en)

    def dfs1(u, st=-1, en=-1):
        if en == -1:
            sz = len(to[u])
            for i, ku in enumerate(to[u][::-1]):
                if can[u][ku][1] != -1: continue
                can[u][ku][1] = sz - 1 - i
                dfs1(ku, u, sz - 1 - i)
            return
        for ku in to[u]:
            if ku == st: continue
            if can[st][ku][1] != -1: continue
            can[st][ku][1] = en
            dfs1(ku, st, en)

    to = defaultdict(list)
    n, m = map(int, input().split())
    ee = []
    for _ in range(m):
        a, b = map(int, input().split())
        a, b = a - 1, b - 1
        to[a].append(b)
        ee.append([a, b])
    for v in to.values():
        v.sort()
    #print(to)
    can = [[[-1] * 2 for _ in range(n)] for _ in range(n)]
    fin = [False] * n
    for u, v in ee:
        for w in [u, v]:
            if not fin[w]:
                fin[w] = True
                dfs0(w)
                dfs1(w)
        # print(u,v)
        # print(can[u][v][0] == can[u][v][1])
        # print(sum(can[v][u]) == -2)
        if (can[u][v][0] == can[u][v][1]) == (sum(can[v][u]) == -2):
            print("same")
        else:
            print("diff")
    #for x in can:
    #    print(x)

main()
