n, m = map(int,raw_input().split())
mod = 10 ** 9 + 7
dp=[[[0] * (n + 1) for _ in xrange(n + 1)] for _ in xrange(m + 1)]
dp[0][1][1] = 1
for i in xrange(m):
    for j in xrange(1, n + 1):
        for k in xrange(1, j + 1):
            dp[i+1][min(j+1,n)][k] += dp[i][j][k] * (n - j)  % mod
            dp[i+1][j][k] += dp[i][j][k] * (j - k) % mod
            dp[i+1][j][j] += dp[i][j][k] * k % mod
print dp[m][n][n] % mod
