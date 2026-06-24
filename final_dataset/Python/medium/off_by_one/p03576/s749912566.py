from itertools import product
N, K = map(int, input().split())
XY = []
X, Y = [], []
for _ in range(N):
    x, y = map(int, input().split())
    X.append(x)
    Y.append(y)
    XY.append([x, y])
X.sort()
Y.sort()

ans = 10 ** 19
for l, r, t, b in product(X, X, Y, Y):
    if l > r or t > b:
        continue
    area = (r - l) * (b - t)
    if area >= ans:
        continue
    cnt = -K
    for x, y in XY:
        if l <= x <= r and t <= y <= b:
            cnt +=1
            if cnt >= 0:
                break
    if cnt >= 0:
        ans = area

print(ans)