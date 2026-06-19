N, W = map(int, input().split())
dp = [0]*(W+1)
max_weight = 0
for i in range(N):
    v, w, m = map(int, input().split())
    # log2(10000) = 13.2... ????????§ 1<<0 ??? 1<<12
    for j in range(13):
        n = 1 << j
        if m < n:
            break
        m -= n
        _v, _w = v*n, w*n
        max_weight = min(W, max_weight + _w)
        for k in range(max_weight, _w-1, -1):
            if dp[k] < dp[k-_w] + _v:
                dp[k] = dp[k-_w] + _v

    if m > 0:
        _v, _w = v*m, w*m
        max_weight = min(W, max_weight + _w)
        for j in range(max_weight, _w-1, -1):
            if dp[j] < dp[j-_w] + _v:
                dp[j] = dp[j-_w] + _v

print(max(dp))