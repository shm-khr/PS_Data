import sys
input = sys.stdin.readline
n = int(input())
D = list(map(int,input().split()))

C = [0] * 13
C[0] = 1
for i in range(n):
    C[D[i]] += 1
for i in range(13):
    C[i] = min(2, C[i])

D = []
for i in range(13):
    for j in range(C[i]):
        D.append(i)

# D.append(0)
# n += 1
# D = list(set(D))
# print(D,n)
# if len(D) < n:
#     print(0)

n = len(D)
A = [0] * n
ans0 = 0
for i in range(2**n):
    ib = format(i, "b").zfill(n)
    for j in range(n):
        A[j] = D[j] * (-1) ** int(ib[j])
    ans = 30
    for j in range(n):
        for k in range(j+1, n):
            di = abs(A[k] - A[j])
            # print(ans)
            ans = min(ans, min(di, 24-di))
    # print(ib, ans0,ans)
    ans0 = max(ans0, ans)
print(ans0)