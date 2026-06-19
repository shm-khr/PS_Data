#!/usr/bin/env python

import sys
import math
import itertools as it
from collections import deque

sys.setrecursionlimit(10000000)

MOD = 10 ** 9 + 7
n, k = map(int, raw_input().split())

def fact(N):
    if N <= 1:
        return 1
    return fact(N - 1) * N

if n < k:
    print 0
else:
    print (fact(n - 1) / fact(n - k) / fact(k - 1)) % MOD
