import sys
import socket

if socket.gethostname() in ['N551J', 'F551C']:
    sys.stdin = open('d1.in')


def read_int_list():
    return list(map(int, input().split()))


def read_int():
    return int(input())


def read_str_list():
    return input().split()


def read_str():
    return input()



def solve1(N, K, a, b):
    n = 2 * N
    a = [u - 1 for u in a]
    b = [u - 1 for u in b]

    M = 10 ** 9 + 7
    g = [0] * (n + 1)
    g[0] = 1
    for x in range(2, n + 1, 2):
        g[x] = (x - 1) * g[x - 2]

    # Number of paired points inside the interval [i, j]
    x = [[0] * n for i in range(n)]
    # Number of paired points strictly outside [i, j]
    y = [[0] * n for i in range(n)]
    ok = [[True] * n for i in range(n)]
    for i in range(n):
        for j in range(i + 1, n):
            for l in range(K):
                inside = (i <= a[l] <= j) + (i <= b[l] <= j)
                outside = 2 - inside
                ok[i][j] &= inside == 2 or outside == 2
                x[i][j] += inside
                y[i][j] += outside


    dp = [[0] * n for i in range(n)]
    for k in range(1, n):
        for i in range(n):
            j = i + k
            if j < n:
                if ok[i][j]:
                    rem_x = j - i + 1 - x[i][j]
                    dp[i][j] = g[rem_x] % M
                    for l in range(i + 1, j):
                        rem_z = j - l - x[l + 1][j]
                        dp[i][j] -= dp[i][l] * g[rem_z]
                        dp[i][j] %= M

    res = 0
    for i in range(n):
        for j in range(i + 1, n):
            rem_y = n - j + i - 1 - y[i][j]
            res += dp[i][j] * g[rem_y]
            res %= M

    return res


def solve():
    N, K = read_int_list()
    rows = [read_int_list() for i in range(K)]
    a = []
    b = []
    if rows:
        a, b = map(list, zip(*rows))
    return solve1(N, K, a, b)


def main():
    res = solve()
    print(res)

if __name__ == '__main__':
    main()
