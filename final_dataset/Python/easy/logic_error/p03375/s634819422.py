from collections import defaultdict, deque, Counter
from heapq import heappush, heappop, heapify
import math
import bisect
import random
from itertools import permutations, accumulate, combinations, product
import sys
import string
from bisect import bisect_left, bisect_right
from math import factorial, ceil, floor
from operator import mul
from functools import reduce
from pprint import pprint


INF = 10 ** 20
def LI(): return list(map(int, sys.stdin.readline().split()))
def I(): return int(sys.stdin.readline())
def LS(): return sys.stdin.readline().split()
def S(): return sys.stdin.readline().strip()
def IR(n): return [I() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): return [S() for i in range(n)]
def LSR(n): return [LS() for i in range(n)]
def SRL(n): return [list(S()) for i in range(n)]
def MSRL(n): return [[int(j) for j in list(S())] for i in range(n)]


n, mod = LI()


fac = [1] * (n + 1)
inv = [1] * (n + 1)
for j in range(1, n + 1):
    fac[j] = fac[j-1] * j % mod


inv[n] = pow(fac[n], mod-2, mod)
for j in range(n-1, -1, -1):
    inv[j] = inv[j+1] * (j+1) % mod


def comb(n, r):
    if r > n or n < 0 or r < 0:
        return 0
    return fac[n] * inv[n - r] * inv[r] % mod



sterling = [[0] * (n + 1) for _ in range(n + 1)]
sterling[0][0] = 1
# n個の区別できるものをk個の(n個以下)の区別不可能なグループに分けることに(i, j)が対応
# n >= k
for i in range(1, n + 1):
    for j in range(i + 1):
        sterling[i][j] = sterling[i - 1][j] * (j + 1)
        if j:
            sterling[i][j] += sterling[i - 1][j - 1]
        sterling[i][j] %= mod



ans = pow(2, pow(2, n, mod), mod)
for l in range(1, n + 1):
    ret = 0
    for k in range(l + 1):
        cumsum = (sterling[l - 1][k - 1] + (k + 1) * sterling[l - 1][k]) % mod
        cumsum = cumsum * pow(pow(2, n - l, mod), k, mod) % mod
        cumsum = cumsum * pow(2, pow(2, n - l, mod), mod) % mod
        cumsum = cumsum * comb(n, l) % mod
        ret += cumsum
    if l % 2:
        ans -= ret
    else:
        ans += ret
    ans %= mod

print(ans)
