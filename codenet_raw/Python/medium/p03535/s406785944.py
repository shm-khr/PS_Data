from fractions import gcd
from datetime import date, timedelta
from heapq import*
import math
from collections import defaultdict, Counter, deque
import sys
from bisect import *
import itertools
import copy
sys.setrecursionlimit(10 ** 7)
MOD = 10 ** 9 + 7


def main():
    n = int(input())
    d = list(map(int, input().split()))
    if n == 1:
        print(d[0])
        exit()
    d2 = []
    dc = defaultdict(int)
    for i in range(n):
        v = min(d[i], 24 - d[i])
        if dc[v] > 2 or (dc[v] == 1 and (v == 0 or v == 12)):
            print(0)
            exit()
        dc[v] += 1
        d2.append(v)
    
    ans = 0
    for i in range(1 << len(d2)):
        d3 = []
        for j in range(len(d2)):
            if (i & (1 << j)):
                d3.append(d2[j])
            else:
                d3.append(24 - d2[j])
        
        d3 = sorted(d3)
        t = float("inf")
        for i in range(len(d3) - 1):
            t = min(t, d3[i + 1] - d3[i])
        ans = max(t, ans)
    print(ans)


if __name__ == '__main__':
    main()
