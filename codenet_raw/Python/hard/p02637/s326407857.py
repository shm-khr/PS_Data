import sys
from heapq import heappop, heapreplace
from itertools import chain


def solve(k, aaa):
    aaa_idx = [(-a, i) for i, a in enumerate(aaa, start=1)]
    aaa_idx.sort()
    min_a = -aaa_idx[-1][0]
    max_a = -aaa_idx[0][0]
    if min_a * 2 < max_a:
        return [-1]

    ans = []
    for _ in range(min_a):
        double = set()

        while True:
            while aaa[aaa_idx[0][1] - 1] != -aaa_idx[0][0]:
                heapreplace(aaa_idx, (-aaa[aaa_idx[0][1] - 1], aaa_idx[0][1]))
            if (min_a - 1) * 2 < (-aaa_idx[0][0] - 1):
                a, i = aaa_idx[0]
                double.add(i)
                aaa[i - 1] -= 2
                heapreplace(aaa_idx, (a + 2, i))
            else:
                break

        if aaa[0] > min_a and 1 not in double:
            double.add(1)
            aaa[0] -= 2

        double_sorted = sorted(double)

        ans.extend(double_sorted)
        for i in range(1, k + 1):
            if i in double:
                continue
            ans.append(i)
            aaa[i - 1] -= 1
        ans.extend(double_sorted)

        min_a -= 1

    return ans


k, *aaa = map(int, sys.stdin.buffer.read().split())
print(*solve(k, aaa))
