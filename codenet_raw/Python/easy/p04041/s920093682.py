N, X, Y, Z = [int(_) for _ in input().split()]
mod = 10**9 + 7
dp = [0] * (2**(X + Y + Z))
al = (2**(X + Y + Z)) - 1
for i in range(1, 11):
    if i - 1 < X + Y + Z:
        dp[1 << (i - 1)] = 1
ng = (2**Z + 2**(Y + Z) + 2**(X + Y + Z)) // 2
for _ in range(N - 1):
    dpn = [0] * (2**(X + Y + Z))
    for i in range(1, 11):
        for b in range(2**(X + Y + Z)):
            nb = (b << i | 1 << (i - 1)) & al
            if ng & nb == ng:
                continue
            dpn[nb] += dp[b]
            dpn[nb] %= mod
    dp = dpn
ans = 10**N - sum(dp)
ans %= mod
print(ans)
