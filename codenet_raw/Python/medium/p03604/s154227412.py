import sys
input = sys.stdin.readline

from scipy.sparse import csr_matrix
from scipy.sparse.csgraph import connected_components

MOD = 10**9 + 7

N = int(input())
ball = (tuple(int(x) for x in row.split()) for row in sys.stdin.readlines())

# x座標を1,2,...,N
# y座標をN+1,N+2,...,N+N

graph = [set() for _ in range(N+N+1)]
for x,y in ball:
    graph[x].add(y+N)
    graph[y+N].add(x)

visited = [False] * (N+N+1)
components = []
for x in range(1,N+N+1):
    if visited[x]:
        continue
    V = set([x])
    E = []
    q = [x]
    visited[x] = True
    while q:
        y = q.pop()
        for z in graph[y]:
            if y < z:
                E.append((y,z))
            if visited[z]:
                continue
            V.add(z)
            visited[z] = True
            q.append(z)
    components.append((V,E))

def make_get_patterns(V):
    deg1 = [x for x in V if len(graph[x]) == 1]
    get = {},{}
    while deg1:
        x = deg1.pop()
        if not graph[x]:
            continue
        y = graph[x].pop()
        se = graph[y]; se.remove(x)
        if len(se) == 1: deg1.append(y)
        if x < y:
            get[0][(x,y)] = 0; get[1][(x,y)] = 0
        else:
            pass
            get[0][(y,x)] = 1; get[1][(y,x)] = 1
    for x in V:
        if graph[x]:
            y = graph[x].pop()
            break
    # 残りはサイクル
    graph[y].remove(x)
    if x > y: x,y = y,x
    get[0][(x,y)] = 0; get[1][(x,y)] = 1
    while graph[x]:
        y = graph[x].pop()
        graph[y].remove(x)
        if x < y:
            get[0][(x,y)] = 1; get[1][(x,y)] = 0
        else:
            get[0][(y,x)] = 0; get[1][(y,x)] = 1
        x = y
    return get

def F(V,E):
    # V is connected
    if len(E) != len(V):
        return 0
    ret = 0
    E.sort()
    for get in make_get_patterns(V):
        den = 1
        dp = {x:0 for x in V}
        for x,y in E:
            if get[(x,y)] == 0:
                k = dp[x] + 1
            else:
                k = dp[y] + 1
            dp[x] += k
            dp[y] += k
            den *= k
            den %= MOD
        ret += pow(den,MOD-2,MOD)
    return ret % MOD

prob = 1
for c in components:
    prob *= F(*c)
    prob %= MOD

answer = prob
for n in range(1,N+N+1):
    answer *= n
    answer %= MOD
print(answer)