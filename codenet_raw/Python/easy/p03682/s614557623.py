import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

import heapq
n = int(input())
l = [[0, 0] for i in range(n)]
for i in range(n):
  x, y = map(int, input().split())
  l[i][0] = x
  l[i][1] = y
  
graph = []
for i in range(n-1):
  x1, y1 = l[i]
  for j in range(i, n):
    x2, y2 = l[j]
    graph.append((min(abs(x1-x2), abs(y1-y2)), i, j))
    graph.append((min(abs(x1-x2), abs(y1-y2)), j, i))

#union find
def Find(x, par):
  if par[x] < 0:
    return x
  else:
    # 経路圧縮
    par[x] = Find(par[x], par)
    return par[x]

def Unite(x, y, par, rank):
  x = Find(x, par)
  y = Find(y, par)
  
  if x != y:
    # rankの低い方を高い方につなげる
    if rank[x] < rank[y]:
      par[y] += par[x]
      par[x] = y
    else:
      par[x] += par[y]
      par[y] = x
      if rank[x] == rank[y]:
        rank[x] += 1
    
def Same(x, y, par):
  return Find(x, par) == Find(y, par)
 
def Size(x, par):
  return -par[Find(x)]

#print(graph)
graph.sort()
par = [-1]*n
rank = [0]*n

cost = 0

for d, p, q in graph:
  if not Same(p, q, par):
    cost += d
    Unite(p, q, par, rank)

print(cost)