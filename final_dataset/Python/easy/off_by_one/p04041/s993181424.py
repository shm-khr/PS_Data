mod = 10**9+7
N,X,Y,Z = map(int, input().split())
Num = 1<<(X+Y+Z-1)
ng = ((((1<<X)+1)<<Y)+1)<<(Z-1)

dp = [[0]*(1<<l) for i in range(N+1)]
dp[0][0] = 1
for i in range(N):
    for j in range(1, 11):
        for k in range(Num):
            a = (k<<j)|(1<<(j-1))
            if a&ng != ng:
                a &= Num-1
                dp[i+1][a] += dp[i][k]
                dp[i+1][1] %= mod
print((10**N-sum(dp[N]))%mod)