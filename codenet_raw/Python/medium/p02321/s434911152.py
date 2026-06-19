import bisect

n, knapsack = map(int, input().split())
items = [tuple(map(int, input().split())) for _ in range(n)]


def make_half_knapsack(hn, items):
    hk = {}
    for i in range(1, 1 << hn):
        vs, ws = 0, 0
        j, k = i, 0
        while j:
            if j & 1:
                v, w = items[k]
                vs += v
                ws += w
            j >>= 1
            k += 1
        if ws <= knapsack and (ws not in hk or hk[ws] < vs):
            hk[ws] = vs
    return hk


hn = n // 2
hk = make_half_knapsack(hn, items[:hn])
hk1w = sorted(hk.keys())
hk1v = [hk[w] for w in hk1w]

hk = make_half_knapsack(n - hn, items[hn:])
ans = 0

for w2, v2 in hk.items():
    i = bisect.bisect(hk1w, knapsack - w2)
    ans = max(ans, max(hk1v[:i], default=0) + v2)

print(ans)