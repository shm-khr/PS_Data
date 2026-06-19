N=int(input())
A=list(map(int,input().split()))

ans1 = 0
cum1 = 0
for i in range(N):
    cum1 += A[i]
    if i % 2 == 0:
        if cum1 <= 0:
            ans1 += abs(cum1) + 1
            cum1 += abs(cum1) + 1
    else:
        if cum1 >= 0:
            ans1 += abs(cum1) + 1
            cum1 -= abs(cum1) + 1

ans2 = 0
cum2 = 0
for i in range(N):
    cum2 += A[i]
    if i % 2 == 1:
        if cum2 <= 0:
            ans2 += abs(cum2) + 1
            cum2 += abs(cum2) + 1
    else:
        if cum2 >= 0:
            ans2 += abs(cum2) + 1
            cum2 -= abs(cum2) + 1

print(min(ans1, ans2))