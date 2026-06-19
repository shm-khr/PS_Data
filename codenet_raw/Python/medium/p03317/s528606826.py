import math
N, K = list(map(int,input().split()))
A = list(map(int,input().split()))
for i in range(N):
    if A[i] == 1:
        ind = i
        break
left = ind
right = N - ind - 1
ans = 0
if left:
    temp = K - 1
    while(1):
        ans += 1
        if temp >= left:
            break
        temp += K - 1
if right:
    temp = K - 1
    while(1):
        ans += 1
        if temp >= right:
            break
        temp += K - 1

print(ans)