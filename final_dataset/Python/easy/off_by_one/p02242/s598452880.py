import sys

def dijkstra(W, n):
    U = [i for i in range(1, n)]
    D = [W[0][i] for i in range(n)]
    D[0] = 0

    while len(U) != 0:
        mind, minu = 100001, -1
        for u in U:
            if D[u] < mind:
                mind, minu = D[u], u
        U.remove(minu)
        for i in range(1, n):
            D[i] = min(D[i], D[minu] + W[minu][i])

    return D

lines = sys.stdin.readlines()
n = int(lines.pop(0))

W = [[100001] * n for _ in range(n)]
for line in lines:
    l = map(int, line.split())
    for i in range(l[1]):
        W[l[0]][l[2 * i + 2]] = l[2 * i + 3]

D = dijkstra(W, n)

for i in range(n):
    print i, D[i]