n, k = map(int, input().split())

ans = 0
for i in range(1, n+1):
    a = ((i//k + 1)*k - i)
    if a <= n and (a * 2) % k == 0:
        p = (n - a) // k + 1
        ans = ans + p**2
print(ans)