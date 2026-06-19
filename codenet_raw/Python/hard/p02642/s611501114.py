import sys
from collections import Counter
sys.setrecursionlimit(10 ** 7)
input = sys.stdin.readline
f_inf = float('inf')
mod = 10 ** 9 + 7


def resolve():
    n = int(input())
    A = sorted(list(map(int, input().split())))
    D = Counter(A)

    B = []
    W = set()
    for k, v in D.items():
        if v == 1:
            B.append(k)
        else:
            W.add(k)

    res = 0
    for a in A:
        for i in range(1, int(pow(a, 0.5)) + 1):
            if a % i == 0:
                if i in W or a // i in W:
                    break
        else:
            res += 1
        W.add(a)
    print(res)


if __name__ == '__main__':
    resolve()
