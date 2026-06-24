import numpy as np
import sys

M = 998244353
N = int(input())
A = np.empty(N, dtype=np.int64)
for i in range(N):
    A[i] = int(input()) - 1
    # A[i]: 0,1,...,(N-1)

s=0
if A[0]==A[N-1]:
    while (s <= N-1) and (A[s]==A[0]):
        s = s+1
if s == N:
    if A[0] == 0:
        result = 1
        for i in range(1,N):
            result = (result*i) % M
        print(result)
    else:
        print(0)

    sys.exit()

lengths = np.zeros(N, dtype=np.int64)
heads = np.zeros(N, dtype=np.int64)
tails = np.zeros(N, dtype=np.int64)

if s > 0:
    tail = A[0]
else:
    tail = A[N-1]

l = 1
for i in range(s,N):
    if (i < N-1) and (A[i+1] == A[i]):
        l = l+1
    else:
        if i < N-1:
            if lengths[A[i+1]] > 0:
                print(0)
                sys.exit()
            else:
                heads[A[i]] = A[i+1]
        else:
            heads[A[i]] = A[0]

        lengths[A[i]] = l
        l=1
        tails[A[i]] = tail
        tail = A[i]
if s > 0:
    heads[A[0]] = A[s]
    lengths[A[0]] = lengths[A[0]] + s

k = lengths[0]
if k == 0:
    print(0)
    sys.exit()

result = 1
killed = 0
for i in range(1,N):
    if lengths[i] == 0:
        result = (result * killed) % M
        killed = killed - 1
    elif lengths[i] > k:
        print(0)
        exit()
    elif heads[i] > i and tails[i] > i:
        if lengths[i] != k:
            print(0)
            exit()
    elif heads[i] < i and tails[i] < i:
        result = (result * (k-lengths[i]+1)) % M
        killed = killed + (lengths[i]+k-2)
    else:
        # head < i and tail > i
        # head > i and tail < i
        killed = killed + (lengths[i]-1)

print(result)