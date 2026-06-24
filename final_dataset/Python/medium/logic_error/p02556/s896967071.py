from sys import stdin
input = stdin.readline

N = int(input())

xy = [list(map(int, input().split())) for _ in range(N)]

for i in range(N):
    xy[i].append(sum(xy[i]))

xy.sort(key=lambda x: x[2])

x, y, tmp = xy[0]
ans = 0

for i in range(1, N):
    ans = max(ans, abs(x - xy[i][0]) + abs(y - xy[i][1]))

print(ans)
