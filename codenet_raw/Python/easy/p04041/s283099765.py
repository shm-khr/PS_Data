from heapq import heappush, heappop
from collections import deque,defaultdict,Counter
import itertools
from itertools import permutations,combinations
import sys
import bisect
import string
#import math
#import time
#import random
def I():
    return int(input())
def MI():
    return map(int,input().split())
def LI():
    return [int(i) for i in input().split()]
def LI_():
    return [int(i)-1 for i in input().split()]
def StoI():
    return [ord(i)-97 for i in input()]
def show(*inp,end='\n'):
    if show_flg:
        print(*inp,end=end)
YN=['Yes','No']
mo=10**9+7
#ts=time.time()
#sys.setrecursionlimit(10**6)
input=sys.stdin.readline
show_flg=False
#show_flg=True


n,X,Y,Z=MI()

pt=[[0]*11 for _ in range(11)]

for m in range(1,8):
    if m==1:
        for a in range(1,11):pt[m][a]=1
        continue
    for a in range(1,8):
        an=0
        for i in range(1,11):
            if a-i>=0:an+=pt[m-1][a-i]
        pt[m][a]=an
    
def cnt(m,a):
    if m==1:
        pt[1][a]=1
        return a
    if pt[m][a]!=-1:
        return pt[m][a]
    rt=0
    for i in range(1,11):
        if a-i<=0:
            break
        rt+=cnt(m-1,a-i)
    pt[m][a]=rt
    return rt

ans=0
for x in range(n+1):
    for y in range(x+1,n+1):
        for z in range(y+1,n+1):
            for w in range(z+1,n+1):
                p=1
                p*=pt[y-x][X]
                p*=pt[z-y][Y]
                p*=pt[w-z][Z]
                ans+=p*pow(10,n-(w-x),mo)
                show(x,y,z,w,p)

print(ans%mo)