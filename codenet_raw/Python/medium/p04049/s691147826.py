import sys
stdin = sys.stdin

def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x)-1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())

from collections import deque

def bfs(graph:list, node:int, start:int, k:int) -> list:
    # 未探索のノードは距離INF
    INF = float("inf")
    dist = [INF]*node
    
    # 始点ノードの距離を0とし、dfsのためのstackを作成
    dist[start] = 0
    que = deque([(0,start)])
    
    # 未探索のノードをqueueに入れる
    # kより大きいの距離のものを数える
    cnt = 0
    while que:
        cost, cur_node = que.popleft()
        
        if cost > k:
            cnt += 1
        
        
        for nex_cost, nex_node in graph[cur_node]:
            if dist[nex_node] != INF:
                continue
            else:
                dist[nex_node] = dist[cur_node] + nex_cost
                que.append((dist[nex_node], nex_node))
                
    return dist,cnt


# 入力, グラフ作成
n,k = li()
adj_list = [[] for _ in range(n)]
for _ in range(n-1):
    a,b = li_()
    adj_list[a].append((1,b))
    adj_list[b].append((1,a))


# bfs
ans = n
if k%2 == 0:
    for st in range(n):
        _, cnt = bfs(adj_list, n, st, k//2)
        ans = min(ans, cnt)
        
else:
    for st in range(n):
        for cost, to in adj_list[st]:
            if to <= st:
                continue
            
            dist1, _ = bfs(adj_list, n, st, (k-1)//2)
            dist2, _ = bfs(adj_list, n, to, (k-1)//2)
            cnt = 0
            
            for d1, d2 in zip(dist1, dist2):
                if min(d1,d2) > (k-1)//2:
                    cnt += 1
                    
            ans = min(ans, cnt)
        
print(ans)