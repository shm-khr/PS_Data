s=input()

dp = [[0 for _ in range(4)] for _ in range(len(s)+1)]

dp[0][0] = 1

for i in range(len(s)):
    for j in range(4):
        dp[i][j] %= 10**9+7
        if s[i]=="?":
            dp[i+1][j] += (3*dp[i][j])
        else:
            dp[i+1][j] += dp[i][j]

    if s[i] == "A" or s[i] == "?":
        dp[i+1][1] += dp[i][0]
    if s[i] == "B" or s[i] == "?":
        dp[i+1][2] += dp[i][1]
    if s[i] == "C" or s[i] == "?":
        dp[i+1][3] += dp[i][2]

print(dp[-1][-1])