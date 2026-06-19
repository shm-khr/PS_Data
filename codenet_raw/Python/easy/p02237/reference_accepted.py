# -*- coding: utf-8 -*-
"""
Created on Sun Jul  8 09:32:48 2018

@author: maezawa
"""

n = int(input())
adj = [[] for _ in range(n)]
a  = [[0 for _ in range(n)] for _ in range(n)]

for j in range(n):
    ain = list(map(int, input().split()))
    u = ain[0]
    k = ain[1]
    for i in range(k):
        adj[u-1].append(ain[i+2]-1)
    #print(*adj[u-1])
    
for j in range(n):
    for k in adj[j]:
        a[j][k] = 1
for i in range(n):
    print(*a[i], sep=' ')

