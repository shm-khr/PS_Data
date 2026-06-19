n = int(input()))
for i in range(n):
    M = [0] * n
    u = list(map(int, input().split()))
    v = u[0]
    for j in u[2:]:
        M[v - 1][j - 1] = 1

for i in M:
    print(*i)