from collections import deque
import sys
input = sys.stdin.readline


def is_bipartite(graph):
    """二部グラフ判定する"""
    n = len(graph)
    col = [-1] * n
    q = deque([0])
    col[0] = 0
    while q:
        v = q.pop()
        for nxt_v, _ in graph[v]:
            if col[nxt_v] == -1:
                col[nxt_v] = col[v] ^ 1
                q.append(nxt_v)
            elif col[nxt_v] ^ col[v] == 0:
                return False
    return True


def color_bipartite(graph):
    """二部グラフを彩色する"""
    n = len(graph)
    col = [-1] * n
    q = deque([0])
    col[0] = 0
    while q:
        v = q.pop()
        for nxt_v, _ in graph[v]:
            if col[nxt_v] == -1:
                col[nxt_v] = col[v] ^ 1
                q.append(nxt_v)
    return col
             

def make_spanning_tree(graph, root):
    """与えられたグラフから全域木をつくり、二部グラフとして彩色する"""
    n = len(graph)
    col = [-1] * n
    tree = [set() for i in range(n)]

    q = deque([root])
    col[root] = 0
    while q:
        v = q.pop()
        for nxt_v, _ in graph[v]:
            if col[nxt_v] != -1:
                continue
            col[nxt_v] = col[v] ^ 1
            tree[v].add(nxt_v)
            tree[nxt_v].add(v)
            q.append(nxt_v)

    return col, tree
  

def trace_path(tree, s, t):
    """木のsからtへのパスの頂点を出力する"""
    n = len(tree)
    dist = [-1] * n
    dist[t] = 0
    q = deque([t])
    while q:        
        v = q.popleft()
        for nxt_v in tree[v]:
            if dist[nxt_v] != -1:
                continue
            dist[nxt_v] = dist[v] + 1 
            q.append(nxt_v)

    trace_path = [s]
    v = s
    while True:
        if dist[v] == 0:
            break
        for nxt_v in tree[v]:
            if dist[nxt_v] + 1 == dist[v]:
                v = nxt_v
                trace_path.append(v)
                break

    return trace_path


n, m = map(int, input().split())
info = [list(map(int, input().split())) for i in range(m)]

graph = [[] for i in range(n)]
e_cost = {}
for a, b, cost in info:
    a, b = a - 1, b - 1
    graph[a].append((b, cost))
    graph[b].append((a, cost))
    e_cost[a, b] = cost
    e_cost[b, a] = cost

if is_bipartite(graph):
    col = color_bipartite(graph)
    ans = [-1] * n
    ans[0] = 1
    q = deque([0])
    while q:
        v = q.pop()
        for nxt_v, cost in graph[v]:
            if ans[nxt_v] == -1:
                ans[nxt_v] = cost - ans[v]
                q.append(nxt_v)
    min_w = 10 ** 18
    min_b = 10 ** 18
    for i, c in enumerate(col):
        if c == 0:
            min_w = min(min_w, ans[i])
        else:
            min_b = min(min_b, ans[i])
    if min_w < 1:
        min_b += -1 + min_w
        min_w -= -1 + min_w
    print(max(min_b, 0))
    
else:
    col, tree = make_bipartite(graph, 0)
    for v in range(n):
        for nxt_v, _ in graph[v]:
            if nxt_v in tree[v]:
                continue
            if col[v] == col[nxt_v]:
                path = trace_path(tree, v, nxt_v)
                break
        else:
            continue
        break
    res = e_cost[path[0], path[-1]]
    for i in range(len(path) - 1):
        res += e_cost[path[i], path[i + 1]]
    if res % 2 == 1:
        print(0)
        exit()
    res //= 2
    for i in range(len(path) // 2):
        res -= e_cost[path[2 * i], path[2 * i + 1]]

    ans = [-1] * n
    ans[path[-1]] = res
    q = deque([path[-1]])
    while q:
        v = q.pop()
        for nxt_v, cost in graph[v]:
            if ans[nxt_v] == -1:
                ans[nxt_v] = cost - ans[v]
                q.append(nxt_v)
            else:
                if ans[nxt_v] == cost - ans[v]:
                    continue
                else:
                    print(0)
                    exit()
    if min(ans) >= 1:
        print(1)
    else:
        print(0)