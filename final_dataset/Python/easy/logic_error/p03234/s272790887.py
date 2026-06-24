import itertools
import sys
import socket
from functools import lru_cache, reduce
import random
import numpy as np
import pprint

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


def solve2(N, K, A, B):
    n = 2 * N
    abli = []
    for i in range(K):
        a, b = A[i], B[i]
        if a < b:
            abli.append((a, b))
        else:
            abli.append((b, a))
    flattenabli = itertools.chain.from_iterable(abli)

    cut = 10 ** 9 + 7

    unused = [1 for i in range(n + 1)]
    for a in flattenabli:
        unused[a] -= 1
    unusedacum = list(itertools.accumulate(unused))

    def modInverse(a, b, divmod=divmod):
        r0, r1, s0, s1 = a, b, 1, 0
        while r1 != 0:
            q, rtmp = divmod(r0, r1)
            stmp = s0 - q * s1
            r0, s0 = r1, s1
            r1, s1 = rtmp, stmp
        return s0 % cut

    @lru_cache(maxsize=None)
    def doubleFactorial(x):
        return reduce(lambda y, z: y * z % cut, range(x, 0, -2))

    @lru_cache(maxsize=None)
    def isSandwiched(i, j):
        return any(map(lambda k: abli[k][0] < i <= abli[k][1] <= j or i <= abli[k][0] <= j < abli[k][1], range(K)))

    nonSandwichedNums = [[] for i in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(i + 1, n + 1):
            if not isSandwiched(i, j):
                nonSandwichedNums[i].append(j)

    def numberUnderterminedBetween(i, j):
        return unusedacum[j] - unusedacum[i - 1]

    def pairCombinations(x):
        if x == 0:
            return 1
        elif x % 2 == 0:
            return doubleFactorial(x - 1)
        else:
            return 0

    def g(i, j):
        x = numberUnderterminedBetween(i, j)
        return pairCombinations(x)

    undetermined = numberUnderterminedBetween(1, n)

    ggg = [[0] * (i + 1) for i in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(i + 1, n + 1):
            ggg[i].append(g(i, j))

    ans = 0
    dp = [[0] * (n + 1) for i in range(n + 1)]
    for i in range(1, n + 1):
        for j in nonSandwichedNums[i]:
            gg = ggg[i][j]
            if gg != 0:
                dp[i][j] = (ggg[i][j] - sum(
                    [dp[i][kk] * ggg[kk + 1][j] for kk in nonSandwichedNums[i] if kk < j])) % cut
            else:
                dp[i][j] = 0
            ans = (ans + dp[i][j] * pairCombinations(undetermined - numberUnderterminedBetween(i, j))) % cut

    return ans


def solve1(N, K, a, b):
    n = 2 * N
    a = [u - 1 for u in a]
    b = [u - 1 for u in b]

    # print('N, n, K, a, b:', N, n, K, a, b)

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

    # print()
    # print('x')
    # pprint.pprint(x)
    # print()
    # print('y')
    # pprint.pprint(y)
    # print()
    # print('ok')
    # pprint.pprint(ok)

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

    # print()
    # print('dp')
    # pprint.pprint(dp)

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


def check():
    Nmax = 10
    steps = 10000
    best_N = None
    best_K = None
    best_a = None
    best_b = None

    for step in range(steps):
        N = random.randint(1, Nmax)
        K = random.randint(1, N)
        l = np.random.choice(range(1, 2 * N + 1), size=2 * K, replace=False)
        l = list(map(int, l))
        a, b = l[:K], l[K:]

        output = solve1(N, K, a, b)
        expected = solve2(N, K, a, b)
        if output == expected:
            continue
        if best_N is None or (N, K, a, b) < (best_N, best_K, best_a, best_b):
            best_N, best_K, best_a, best_b = N, K, a, b

            print(N, K, a, b)
            print('output, expected:', output, ',', expected)


if __name__ == '__main__':
    random.seed(2)
    # check()
    main()
