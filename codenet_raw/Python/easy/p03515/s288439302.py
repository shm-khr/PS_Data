import sys

sys.setrecursionlimit(10**7)

def solve():
    n = int(sys.stdin.readline())
    adj = [[] for i in range(n + 1)]

    dp = [dict() for i in range(n + 1)]
    cnt = [dict() for i in range(n + 1)]

    for i in range(n - 1):
        ai, bi, ci = map(int, sys.stdin.readline().split())

        if ci > 2:
            return

        adj[ai].append((bi, ci))
        adj[bi].append((ai, ci))

    def cnt_node(v, p):
        if p in cnt[v]:
            return cnt[v][p]

        cnt[v][p] = 1

        for (u, c) in adj[v]:
            if u == p:
                continue

            cnt[v][p] += cnt_node(u, v)

        return cnt[v][p]

    def dfs(v, p):
        if p in dp[v]:
            return dp[v][p]

        dp[v][p] = 0

        for (u, c) in adj[v]:
            if u == p:
                continue

            if c == 1:
                dp[v][p] += cnt_node(u, v)
            else:
                dp[v][p] += dfs(u, v) + 2

        return dp[v][p]

    for i in range(1, n + 1):
        # print(dp)
        # print(cnt)
        ans = dfs(i, -1)
        print(ans)



if __name__ == '__main__':
    solve()