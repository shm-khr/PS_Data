H, W, K = map(int, input().split())
items = []

start = []
diff = float("inf")
p = []
prev = [[False] * W for _ in range(H)]
for i in range(H):
    items.append(list(input()))
    for j in range(W):
        s = items[i][j]
        if s == "S":
            start = [i, j]
            diff = min(diff, min(i, H - 1 - i, min(j, W - 1 - j)))
            p = [i, j]
            prev[i][j] = True

from collections import deque

que = deque([])

dx = [-1, 0, 0, 1]
dy = [0, 1, -1, 0]

for i in range(4):
    x = dx[i]
    y = dy[i]
    if 0 <= start[1] + y <= H - 1 and 0 <= start[0] + x <= W - 1:
        tmp = items[start[1] + y][start[0] + x]
        if tmp == ".":
            que.append((start[1] + y, start[0] + x))
k = K
while len(que) != 0 and k != 0:
    que2 = deque([])
    while len(que) != 0:
        q = que.popleft()
        prev[q[0]][q[1]] = True
        if min(diff, min(q[0], H - 1 - q[0], min(q[1], W - 1 - q[1]))) < diff:
            diff = min(diff, min(q[0], H - 1 - q[0], min(q[1], W - 1 - q[1])))
            p = (q[0], q[1])

        for i in range(4):
            x = dx[i]
            y = dy[i]
            if 0 <= q[0] + y <= H - 1 and 0 <= q[1] + x <= W - 1:
                if prev[q[0] + y][q[1] + x]:
                    continue
                tmp = items[q[0] + y][q[1] + x]
                if tmp == ".":
                    que2.append((q[0] + y, q[1] + x))
    k -= 1
    que = que2


ans = 1
if diff == 0:
    print(ans)
else:
    print(ans + (K - 1 + diff) // K)
