def solve(H, W, N):
    c = 0
    b = 0
    L = max(H, W)
    while b < N:
        b += L
        c += 1
    return c
H = int(input())
W = int(input())
N = int(input())

        