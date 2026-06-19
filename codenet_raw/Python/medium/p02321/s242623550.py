def solve():
    from bisect import bisect_left
    N, W = map(int, input().split())
    n1 = N//2
    n2 = N-n1
    a = [[tuple(map(int, input().split())) for _ in [0]*n1], [tuple(map(int, input().split())) for _ in [0]*n2]]
    dp = [[(0, 0) for _ in [0]*(2**n1)], [(0, 0) for _ in [0]*(2**n2)]]

    for i in range(2):
        n = len(a[i])
        cdp = dp[i]
        ca = a[i]
        for j in range(n):
            _v, _w = ca[j]
            if _w > W:
                continue
            for bitset in range(2**j, 2**(j+1)):
                v, w = _v, _w
                j = 1
                for k in range(j-1):
                    if 2**k & bitset:
                        v += ca[k][0]
                        w += ca[k][1]
                if w <= W:
                    cdp[bitset] = (w, v)
            cdp = sorted(cdp)
        dp[i] = [pair for w in [[-1]] for sa in [w.__setitem__] for pair in cdp if pair[1] > w[0] and not sa(0, pair[1])]

    result = 0
    inf = float("inf")
    l = len(dp[1])
    for w, v in dp[0]:
        i = bisect_left(dp[1], (W-w, inf))
        newv = v + dp[1][i-1][1] if i > 0 else 0
        #print(w, v, i, newv)

        if newv > result:
            result = newv

    print(result)

if __name__ == "__main__":
    solve()