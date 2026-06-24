import sys
stdin = sys.stdin
 
sys.setrecursionlimit(10**6) 
 
def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x)-1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())

n,m = li()

INF = float("inf")
graph = [[] for _ in range(n)]

for _ in range(m):
    u,v,s = li()
    u -= 1
    v -= 1
    graph[u].append((v, s))
    graph[v].append((u, s))
    
a = [INF]*n
b = [INF]*n
a[0] = 1
b[0] = 0

def dfs(graph, cur, x):
    for nex, edge in graph[cur]:
        if a[nex] == INF:
            a[nex] = -a[cur]
            b[nex] = edge - b[cur]
            
            res, x = dfs(graph, nex, x)
            
            if not res:
                return False, None
            
        else:
            atemp = -a[cur]
            btemp = edge - b[cur]
            
            if atemp == a[nex]:
                if btemp != b[nex]:
                    return False, None
                
            else:
                if x is not None:
                    if (atemp * x + btemp != a[nex] * x + b[nex])\
                    or (atemp * x + btemp) <= 0:
                        return False, None
                    
                else:
                    if (btemp-b[nex])%(a[nex]-atemp) > 0\
                    or (btemp-b[nex])//(a[nex]-atemp) <= 0:
                        return False, None
                    
                    else:
                        x = (btemp-b[nex])//(a[nex]-atemp)

    return True, x

def find_range(a, b):
    upper = INF
    lower = -INF
    for ai, bi in zip(a,b):
        if ai < 0:
            upper = min(upper, bi)
        else:
            lower = max(lower, -bi)
            
    return max(0, upper-lower-1)

res, x = dfs(graph, 0, None)

if not res:
    print(0)
    
elif x is not None:
    print(1)
    
else:
    print(find_range(a,b))

