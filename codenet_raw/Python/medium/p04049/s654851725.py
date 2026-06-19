import sys
from collections import deque


def bfs(links, s, limit, bits):
    not_reachable = (1 << len(links)) - 1
    q = deque([(0, s, -1)])
    while q:
        cost, v, p = q.popleft()
        if cost > limit:
            break
        not_reachable ^= bits[v]
        cost += 1
        q.extend((cost, u, v) for u in links[v] if u != p)
    return not_reachable


def solve(n, k, ab):
    if k == 1:
        return n - 2

    links = [set() for _ in range(n)]
    for a, b in ab:
        a -= 1
        b -= 1
        links[a].add(b)
        links[b].add(a)

    limit = k // 2
    bits = [1 << i for i in range(n)]
    if k % 2 == 0:
        ans = min(bin(bfs(links, v, limit, bits)).count('1') for v in range(n))
    else:
        dists = [bfs(links, v, limit, bits) for v in range(n)]
        ans = min(bin(dists[a - 1] & dists[b - 1]).count('1') for a, b in ab)
    return ans


n, k = map(int, sys.stdin.buffer.readline().split())
ab = map(int, sys.stdin.buffer.read().split())
ab = list(zip(ab, ab))
print(solve(n, k, ab))
