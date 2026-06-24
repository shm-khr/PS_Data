#!/usr/bin/env python3
import bisect
import collections
import sys

sys.setrecursionlimit(1000000)
ACMOD = 1000000007
INF = 1 << 62


def solve(N: int, V: "List[int]", W: "List[int]", Q: int, v: "List[int]", L: "List[int]"):
    memo = {0: {0: 0, W[0]: V[0]}}

    def calc(i):
        if i in memo:
            return
        # handled in memo
        # if i == 0:
        #     return
        cw = W[i]
        cv = V[i]
        memo[i] = {}
        cur = memo[i]
        calc((i - 1) // 2)
        for w, v in memo[(i - 1) // 2].items():
            if w in cur:
                cur[w] = max(cur[w],v)
            else:
                cur[w] = v
            if w + cw <= 10 ** 5:
                if w + cw in cur:
                    cur[w + cw] = max(cur[w + cw], v + cv)
                else:
                    cur[w + cw] = v + cv

    for i in range(Q):
        target = v[i] - 1
        calc(target)
        # print(max(v for w, v in memo[target].items() if w <= L[i]))


def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word

    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    V = [int()] * (N)  # type: "List[int]"
    W = [int()] * (N)  # type: "List[int]"
    for i in range(N):
        V[i] = int(next(tokens))
        W[i] = int(next(tokens))
    Q = int(next(tokens))  # type: int
    v = [int()] * (Q)  # type: "List[int]"
    L = [int()] * (Q)  # type: "List[int]"
    for i in range(Q):
        v[i] = int(next(tokens))
        L[i] = int(next(tokens))
    solve(N, V, W, Q, v, L)


if __name__ == '__main__':
    main()
