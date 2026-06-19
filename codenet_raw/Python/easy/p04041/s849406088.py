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
show_flg=True

n,X,Y,Z=MI()
t=2**16
dp=[0]*t
dp[0]=1

for i in range(n):
    tm=[i for i in dp]
    for k in range(t):
        for d in range(1,10):
            m=bin(k)[2:]+'1'+'0'*(d-1)
            if len(m)>=X+Y+Z and (m[-Z],m[-Y-Z],m[-X-Y-Z])==(1,1,1):
                continue
            else:
                dp[int(m)%t]+=tm[k]
                dp[int(m)%t]%=mo
sub=0
for i in range(t):
    sub+=dp[i]
ans=pow(10,n,mo)-sub
print(ans%mo)
