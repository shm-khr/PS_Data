import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

MOD = 998244353

N,*A = map(int,read().split())

T = A.count(1)
if T == 0:
    print(0)
    exit()
if T == 1:
    answer = 1 if len(set(A)) == N else 0
    print(answer)
    exit()
if T == N:
    answer = 1
    for n in range(1,N+1):
        answer *= n
        answer %= MOD
    print(answer)
    exit()

n = A.index(1)
while A[n-1] == 1:
    n -= 1
A = A[n:] + A[:n]

assert len(A) == N and A[0] == 1 and A[-1] != 1
print(0)