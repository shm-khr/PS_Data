import sys
import math

N, K = list(map(int, input().split()))
A = list(map(int, input().split()))

if N == K:
    print(1)
    sys.exit()
for i in range(N):
    if A[i] == 1:
        print(math.floor((i+1)/(K-1)) + math.ceil((N-i-1)/(K-1)))
        break