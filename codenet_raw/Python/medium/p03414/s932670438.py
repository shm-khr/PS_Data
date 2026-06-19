#!/usr/bin/env python3


class UnionFind():
    def __init__(self, size):
        self.table = [-1] * size

    def find(self, x):
        while 0 <= self.table[x]:
            x = self.table[x]
        return x

    def unite(self, x, y):
        rx = self.find(x)
        ry = self.find(y)
        if rx != ry:
            dx = -self.table[rx]
            dy = -self.table[ry]
            if dx != dy:
                if dx < dy:
                    self.table[rx] = ry
                else:
                    self.table[ry] = rx
            else:
                self.table[rx] -= 1
                self.table[ry] = rx
        return


e = None
re = None


post = None
rev = None
cc = None
scc = None

t = 1

def dfs0(u, r):
    global post, rev, t
    global cc

    cc.unite(u, r)
    post[u] = 1  # dummy
    for w in e[u]:
        if post[w] == 0:
            dfs0(w, r)
    post[u] = t
    rev[t] = u
    t += 1


def dfs1(u, r, cr, visited):
    global scc

    scc.unite(u, r)
    visited[u] = True
    for w in re[u]:
        if cc.find(w) != cr:
            continue
        if not visited[w]:
            dfs1(w, r, cr, visited)


def dfs2(u, r, first, rs, visited):

    visited[u] = True
    for w in e[u]:
        if not visited[w]:
            dfs2(w, r, first, rs, visited)
        elif w != r and w != first:
            rs.add((r, w))


def traverse(n, s, rs):
    visited = [False] * (n + 1)
    visited[s] = True
    for w in e[s]:
        visited[w] = True
    for w in e[s]:
        dfs2(w, s, w, rs, visited)


def solve(n, m, edges):
    global post, rev
    global cc, scc

    post = [0] * (n + 1)
    rev = [0] * (n + 1)
    cc = UnionFind(n + 1)
    scc = UnionFind(n + 1)

    visited = [False] * (n + 1)
    for r in range(1, n + 1):
        if post[r] == 0:
            cur = t
            dfs0(r, r)
            for v in range(t - 1, cur - 1, -1):
                r1 = rev[v]
                if not visited[r1]:
                    cr = cc.find(r1)
                    dfs1(r1, r1, cr, visited)

    visited = [False] * (n + 1)
    path_exists = set()
    for a, b in edges:
        if not visited[a]:
            visited[a] = True
            traverse(n, a, path_exists)


    for a, b in edges:
        scc_a = scc.find(a)
        scc_b = scc.find(b)
        exist = (a, b) in path_exists
        print('diff' if (scc_a == scc_b) ^ exist else 'same')


def main():
    global e, re

    n, m = input().split()
    n = int(n)
    m = int(m)
    edges = []
    e = [[] for _ in range(n + 1)]
    re = [[] for _ in range(n + 1)]
    for i in range(m):
        a, b = input().split()
        a = int(a)
        b = int(b)
        edges.append((a, b))
        e[a].append(b)
        re[b].append(a)


    solve(n, m, edges)


if __name__ == '__main__':
    main()

