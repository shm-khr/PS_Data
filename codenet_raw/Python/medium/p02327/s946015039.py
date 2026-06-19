import sys
file = sys.stdin
H,W = map(int, file.readline().split())
C = [list(map(int,i.split())) for i in file.readlines()]

def height(C):
    P = []
    for i in range(W):
        p = 0
        for j in range(len(C)):
            if C[j][i] == 1:
                p = 0
            else: p += 1
        P.append(p)
    return P

def square(C):
    P = height(C)
    G = []
    L = []
    for i,v in enumerate(P):
        if not L:
            L.append((i, v))
            continue
        if v > L[-1][1]:
            L.append((i, v))
        elif v < L[-1][1]:
            k = i - 1
            while L and v < L[-1][1]:
                a = L.pop()
                G.append((k - a[0] + 1) * a[1])
            L.append((a[0], v))
    while L:
        a = L.pop()
        G.append((len(P) - a[0]) * a[1])
    return max(G)

def ans(C):
    ans = []
    for i in range(H):
        currentC = C[:i+1]
        ans.append(square(currentC))
    return str(max(ans))
print(ans(C))