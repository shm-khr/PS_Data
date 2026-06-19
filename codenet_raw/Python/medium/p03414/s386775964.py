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

t_post = 1

def dfs0(u, r):
    global post, rev, t_post
    global cc

    cc.unite(u, r)
    post[u] = 1  # dummy
    for w in e[u]:
        if post[w] == 0:
            dfs0(w, r)
    post[u] = t_post
    rev[t_post] = u
    t_post += 1


def dfs1(u, r, cr, visited):
    global scc

    scc.unite(u, r)
    visited[u] = True
    for w in re[u]:
        if cc.find(w) != cr:
            continue
        if not visited[w]:
            dfs1(w, r, cr, visited)


def dfs2(u, t, visited):

    visited[u] = True
    for w in e[u]:
        if w == t:
            return True
        if not visited[w]:
            r = dfs2(w, t, visited)
            if r:
                return True

    return False


def find_another_path(n, s, t):
    visited = [False] * (n + 1)
    visited[s] = True
    for i in e[s]:
        if i != t:
            r = dfs2(i, t, visited)
            if r:
                return True

    return False


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
            cur = t_post
            dfs0(r, r)
            for v in range(t_post - 1, cur - 1, -1):
                r1 = rev[v]
                if not visited[r1]:
                    cr = cc.find(r1)
                    dfs1(r1, r1, cr, visited)

    for a, b in edges:
        scc_a = scc.find(a)
        scc_b = scc.find(b)
        pathf = find_another_path(n, a, b)
        print('diff' if (scc_a == scc_b) ^ pathf else 'same')


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

