import sys
input = sys.stdin.readline
n = int(input())
D = list(map(int,input().split()))
# from random import randint

# n = randint(1, 50)
# D = [randint(0, 12) for i in range(n)]

C = [0] * 13
C[0] = 1
for i in range(n):
    C[D[i]] += 1

if C[0] >= 2 or C[12] >=2:
    print(0)
    sys.exit()

for i in range(13):
    if C[i] >= 3:
        print(0)
        sys.exit()

# D = []
# for i in range(13):
#     for j in range(C[i]):
#         D.append(i)
# n = len(D)
# A = [0] * n

# print(C)
ans0 = 0
for i in range(2**13):
    zero = 0
    ib = format(i, "b").zfill(13)
    A = []
    for j in range(13):
        if C[j] == 1:
            A.append(j * (-1) ** int(ib[j]))
        if C[j] == 2:
            if int(ib[j]) == 0:
                A.append(j)
                A.append(-j)
            else:
                zero = 1
    if zero == 1:
        continue
    # print("not cont")
    ans = 30
    # if len(A)>1:
        # print(A)
    # print(ib, A)
    for j in range(len(A)):
        for k in range(j+1, len(A)):
            di = abs(A[k] - A[j])
            # print(ans)
            ans = min(ans, min(di, 24-di))
            if ans <= ans0:
                break
        if ans <= ans0:
            break
    # print(ib, ans0,ans)
    ans0 = max(ans0, ans)
print(ans0)