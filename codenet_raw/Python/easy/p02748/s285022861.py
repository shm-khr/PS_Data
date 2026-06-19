A, B, M = map(int, raw_input().split())
a_s = sorted(enumerate(map(int, raw_input().split())), key=lambda t: t[1])
b_s = sorted(enumerate(map(int, raw_input().split())), key=lambda t: t[1])
min_b = min([b[1] for b in b_s])
w = [[0] * B] * A
max_w = 0
for _ in xrange(M):
    x, y, c = map(int, raw_input().split())
    w[x-1][y-1] = c
    max_w = max(max_w, c)

cost = 10 ** 20
for i, a in a_s:
    if a + min_b - max_w > cost:
        break
    for j, b in b_s:
        cost = min(cost, a + b - w[i][j])
        if a + b - max_w > cost:
            break

print cost