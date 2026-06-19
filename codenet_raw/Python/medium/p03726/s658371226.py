def main():
    n = int(input())
    ab = [list(map(int, input().split())) for _ in [0]*(n-1)]

    g = [[] for _ in [0]*n]
    [g[a-1].append(b-1) for a, b in ab]
    [g[b-1].append(a-1) for a, b in ab]
    for root in range(n):
        if len(g[root]) > 2:
            break
    else:
        if n % 2:
            print("First")
        else:
            print("Second")
        return

    d = [-1]*n  # 根からの距離
    d[root] = 0
    q = [root]
    cnt = 0
    while q:  # BFS
        cnt += 1
        qq = []
        while q:
            i = q.pop()
            for j in g[i]:
                if d[j] == -1:
                    d[j] = cnt
                    qq.append(j)
        q = qq
    d2 = sorted([(j, i) for i, j in enumerate(d)])[::-1]
    end = [False]*n
    dp = [[] for _ in [0]*n]
    for _, i in d2:
        if len(g[i]) > 2:
            continue
        elif len(g[i]) == 1:
            dp[g[i][0]].append(1)
            if len(dp[g[i][0]]) > 1:
                end[g[i][0]] = True
        elif not end[i] and dp[i]:
            dist = dp[i][0]
            for j in g[i]:
                if d[j] < d[i]:
                    dp[j].append(dist+1)
    dp = [[j % 2 for j in i] for i in dp]
    for i in dp:
        if i.count(1) > 1:
            print("First")
            return
    print("Second")


main()
