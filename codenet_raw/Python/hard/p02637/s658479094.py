import sys
from itertools import chain


def solve(k, aaa):
    aaa_idx = [[a, i] for i, a in enumerate(aaa, start=1)]
    aaa_idx.sort()
    min_a = aaa_idx[0][0]
    if min_a * 2 < aaa_idx[-1][1]:
        return [-1]

    ans = []
    for _ in range(min_a):
        double = []
        single = []
        for j in range(k):
            a, i = aaa_idx[j]
            if a > min_a:
                double.append(i)
                aaa_idx[j][0] -= 2
            else:
                single.append(i)
                aaa_idx[j][0] -= 1
        double.sort()
        single.sort()
        single.extend(double)
        double.extend(single)
        ans.append(double)
        min_a -= 1
    ans.sort()

    return chain.from_iterable(ans)


k, *aaa = map(int, sys.stdin.buffer.read().split())
print(*solve(k, aaa))
