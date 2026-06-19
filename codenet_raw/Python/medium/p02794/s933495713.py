# 解説AC
from collections import deque

N = int(input())
edge = [[] for _ in range(N)]
for n in range(N - 1):
    a,b = map(int, input().split())
    edge[a-1].append((b-1, n))
    edge[b-1].append((a-1, n))

def bfs(s:int, g:int):
    """ 始点sから終点gまでのパスを求める """
    path = [0] * N
    visited = [False] * N
    
    que = deque([s])
    visited[s] = True
    while que:
        v = que.popleft()
        for w, n in edge[v]:
            if visited[w]: continue
            path[w] = path[v] | (1 << n)
            if w == g: return path[g]
            que.append(w)
    return path[g]

def popcount(x:int):
    """ return bin(x).count('1') """
    x = x - ((x >> 1) & 0x5555555555555555)
    x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333)
    x = (x + (x >> 4)) & 0x0f0f0f0f0f0f0f0f
    x = x + (x >> 8)
    x = x + (x >> 16)
    x = x + (x >> 32)
    return x & 0x0000007f

M = int(input())
path = [0] * M # 各制約で使用するパス
for i in range(M):
    u,v = map(int, input().split())
    path[i] = bfs(u - 1, v - 1)

ans = 0
# 包除原理
for bit in range(1 << M):
    val = 0
    for i in range(M):
        if (bit >> i) & 1:
            val |= path[i]
    if popcount(bit) % 2 == 0:
        ans += 1 << (N - 1 - popcount(val))
    else:
        ans -= 1 << (N - 1 - popcount(val))

print(ans)