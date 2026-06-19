dx = [1, 1, 0, -1, 0, 0, 0, 0, 1, 1, 0, -1, 1, 1, 0, -1, 1, 1, 0, -1]
dy = [0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1]
dz = [0, 0, 0, 0, 1, 1, 0, -1, 0, 1, 1, 1, 1, 1, 0, -1, 1, 1, 0, -1]


def check(i, col, x, y, z):
    if not(0 <= x < n and 0 <= y < n and 0 <= z < n):
        return 0
    if col != d[z][y][x]:
        return 0
    return check(i, col, x + dx[i], y + dy[i], z + dz[i]) + 1

from itertools import product

while True:
    n, m, p = map(int, input().split())
    if not n:
        break
    d = [[[0 for z in range(n)] for y in range(n)] for x in range(n)]
    done = False

    for i in range(p):
        x, y = map(int, input().split())
        if done:
            continue
        x, y, z = x - 1, y - 1, n - 1
        while z > 0 and not d[z - 1][y][x]:
            z -= 1

        d[z][y][x] = i % 2 + 1
        for x, y, z in product(range(n), repeat=3):
            for j in range(len(dx)):
                if check(j, 1, x, y, z) >= m:
                    print('Black', i + 1)
                    done = True
                    break
                if check(j, 2, x, y, z) >= m:
                    print('White', i + 1)
                    done = True
                    break
            if done:
                break
    if not done:
        print('Draw')