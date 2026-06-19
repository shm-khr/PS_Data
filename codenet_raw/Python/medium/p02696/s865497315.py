import math

A, B, N = map(int, input().split())


ans1 = 0
if B > N:
    x = 0
    while x <= N and x <= A:
        ans = int((A * x) / B) - A * int(x / B)
        ans1 = max(ans1, ans)
        x += 1
    print(ans1)

else:
    x = N
    while x > A and x <= B:
        ans = int((A * x) / B) - A * int(x / B)
        ans1 = max(ans1, ans)
        x -= 1
    print(ans1)
