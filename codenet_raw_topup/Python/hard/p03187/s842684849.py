import numpy as np
import sys

L, N = map(int, input().split())
X = np.array([int(sys.stdin.readline()) for _ in range(N)])
Y1 = np.concatenate(([X[0]], X[1:] - X[:-1], [L - X[-1]]))
Y2 = Y1[::-1]
Z = np.concatenate((np.arange(N, -1, -2), np.arange(N - 1, -1, -2)[::-1]))


def myfunc(n, Y):
    return np.sum(Y[n:n + (N - n + 1)//2]) - np.sum(Y[:n]) - np.sum(Y[-((N - n + 1)//2):])


len1 = np.dot(Z, Y1)
len2 = np.dot(Z, Y2)
if len1 >= len2:
    Y = Y1
    len_ = len1
else:
    Y = Y2
    len_ = len2
ans = len_
for n in range(1, (N + 1) // 2):
    len_ += myfunc(n, Y)
    ans = max(ans, len_)

print(ans)