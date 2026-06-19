from bisect import *
from collections import *

N, M = map(int, input().split())
if (N-2*M) & 1 == 0:
    for i in range(M-1):
        print(i+1, 2*M-i+2)
    print(M, M+3)
else:
    for i in range(M):
        print(i+1, 2*M-i)