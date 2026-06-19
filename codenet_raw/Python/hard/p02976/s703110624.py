# -*- coding: utf-8 -*-
"""
Created on Thu Jul 18 12:05:59 2019

@author: ctiuser
"""
import sys

N, M = map(int,input().split())
A = [list(map(int,input().split())) for i in range(M)]

if M % 2 == 1:
    print(-1)
    sys.exit()

class UnionFind():
    def __init__(self,size):
        self.table = [-1 for i in range(size+1)]
    def find(self,x):
        if self.table[x] < 0:
            return x
        else:
            return self.find(self.table[x])
    def union(self,x,y):
        s1 = self.find(x)
        s2 = self.find(y)
        if s1 == s2:
            return False
        if self.table[s1] < self.table[s2]:
            self.table[s1] = self.table[s1] + self.table[s2]
            self.table[s2] = self.find(x)
        else:
            self.table[s2] = self.table[s1] + self.table[s2]
            self.table[s1] = self.find(y)
        return True

UF = UnionFind(N)
ans = []
T = [[-1] for i in range(N+1)]
color = [-1 for i in range(N+1)]
counta = [0 for i in range(N+1)]
B = []
C = [[] for i in range(N+1)]
for c in A:
    if UF.union(c[0],c[1]):
        B.append(c)
        C[c[0]].append(c[1])
        C[c[1]].append(c[0])
    else:
        ans.append(c)
        counta[c[0]] += 1

def b(x):
    color[x] = 1
    for c in C[x]:
        if color[c] == -1:
            T[c][0] = x
            T[x].append(c)
            b(c)
b(1)

edge_leaf = []
for i in range(1,N+1):
    if len(T[i]) == 1:
        edge_leaf.append(i)

def a(x):
    p = T[x][0]
    if p == -1:
        return 0
    if counta[x] % 2 == 0:
        ans.append([p,x])
        counta[p] += 1
    else:
        ans.append([x,p])
    return p

for c in edge_leaf:
    point = c
    while color[point] == len(T[point]):
        point = a(point)
        color[point] += 1


for c in ans:
    print(' '.join(map(str,c)))
