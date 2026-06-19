from collections import Counter,defaultdict,deque
import sys
import bisect
import math
import itertools
import string
import queue
import copy
# import numpy as np
# import scipy
from itertools import permutations, combinations
from heapq import heappop, heappush
# input = sys.stdin.readline
sys.setrecursionlimit(10**8)
mod = 10**9+7
 
def inp(): # n=1
    return int(input())
def inpm(): # x=1,y=2
    return map(int,input().split())
def inpl(): # a=[1,2,3,4,5,...,n]
    return list(map(int, input().split()))
def inpls(): # a=['1','2','3',...,'n']
    return list(input().split())
def inplm(n): # x=[] 複数行
    return list(int(input()) for _ in range(n))
def inpll(n): # [[1,1,1,1],[2,2,2,2],[3,3,3,3]]
    return [list(map(int, input().split())) for _ in range(n)]

def bfs(s,n,g,t): # 木構造の距離の算出 start, number, graph
    went = [False]*n
    dis = [0]*n
    que = deque([])
    que.append(s)
    went[s] = True
    while que:
        go = que.pop()
        for i in range(len(g[go])):
            if went[g[go][i]]:
                continue
            dis[g[go][i]] = dis[go] + 1
            went[g[go][i]] = True
            que.append(g[go][i])
    root = []
    root.append(t)
    x = dis[t]
    que1 = deque([])
    que1.append(t)
    while que1:
        go = que1.pop()
        for i in range(len(g[go])):
            if dis[g[go][i]] == x-1:
                que1.append(g[go][i])
                root.append(g[go][i])
                x -=1
                break
        if x == 0:
            break
    return root


def main():
    n = inp()
    g=[[] for _ in range(n)]
    path = defaultdict(int)
    for i in range(n-1):
        a,b = inpm()
        a -= 1
        b -= 1
        key = [str(a), ' ', str(b)]
        key = ''.join(key)        
        path[key] = i+1
        key = [str(b), ' ', str(a)]
        key = ''.join(key)     
        path[key] = i+1
        g[b].append(a)
        g[a].append(b)
    m = inp()
    ans = 0
    pre_root = [[] for _ in range(m)]
    for j in range(m):
        u,v = inpm()
        u -= 1
        v -= 1
        root1 = bfs(u,n,g,v)
        for i in range(len(root1)-1):
            a,b = root1[i],root1[i+1]
            key = [str(a), ' ', str(b)]
            key = ''.join(key)     
            x = path[key]
            pre_root[j].append(x)
    for k in range(pow(2,n-1)):
        flag = 1
        for i in range(m):
            flag1 = 0
            for j in range(len(pre_root[i])):
                go = pre_root[i][j]-1
                if (k>>go) & 1 == 1:
                    flag1 = 1
                    break
            if not flag1:
                flag = 0
                break           
        if flag:
            ans += 1
    print(ans)

if __name__ == "__main__":
    main()