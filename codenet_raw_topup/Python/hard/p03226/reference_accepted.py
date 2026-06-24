import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

from operator import itemgetter

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

# assert len(A) == N and A[0] == 1 and A[-1] != 1

L = [0] * (N+1)
R = [-1] * (N+1)
ctr = [0] * (N+1)
nums = []
prev = 0
for i,x in enumerate(A):
    ctr[x] += 1
    R[x] = i
    if prev != x:
        nums.append(x)
        L[x] = i
        prev = x

if any(y - x + 1 != z for x,y,z in zip(L,R,ctr)):
    print(0)
    exit()
if any(x > T for x in ctr[2:]):
    print(0)
    exit()

free = [0] * (N+1) # ある数値を書き込んだ時点で、死亡確定になってるマス数
answer = 1
for x,y,z in zip(nums,nums[1:],nums[2:]+[1]):
    if x > y < z:
        if ctr[y] != T:
            answer = 0
            break
    elif x < y < z:
        free[y] += ctr[y] - 1
    elif x > y > z:
        free[y] += ctr[y] - 1
    else:
        # x < y > z
        answer *= (T + 1 - ctr[y])
        answer %= MOD
        free[y] += ctr[y] + T - 2

f = 0
for n in range(1,N+1):
    if ctr[n] >= 1:
        f += free[n]
        continue
    answer *= f
    answer %= MOD
    f -= 1

print(answer)