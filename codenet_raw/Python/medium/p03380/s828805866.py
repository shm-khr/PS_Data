import math
import bisect


def cmb(n, r):
    if n - r < r:
        r = n - r
    if r == 0:
        return 1
    if r == 1:
        return n

    numerator = [n - r + k + 1 for k in range(r)]
    denominator = [k + 1 for k in range(r)]

    for p in range(2, r+1):
        pivot = denominator[p - 1]
        if pivot > 1:
            offset = (n - r) % p
            for k in range(p-1, r, p):
                numerator[k - offset] /= pivot
                denominator[k] /= pivot

    result = 1
    for k in range(r):
        if numerator[k] > 1:
            result *= int(numerator[k])

    return result


n = int(input())

a = list(map(int, input().split()))
a.sort()

ncr = 0
ans = [0, 0]

id = bisect.bisect_left(a[:n-1], a[n-1]//2)
if abs(a[-1]/2 - a[id]) <= abs(a[-1] - a[id+1]):
    ans = id
else:
    ans = id+1

print(a[-1], a[ans])
