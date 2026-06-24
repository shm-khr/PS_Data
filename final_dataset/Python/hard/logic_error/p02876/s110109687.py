import sys
input = sys.stdin.readline
def gcd(a, b):
    while b: a, b = b, a % b
    return abs(a)

N = int(input())
S = 0
Y = []
for i in range(N):
    a, b = map(int, input().split())
    if b > a:
        S += b-a
        Y.append((b, b, b-a))
    else:
        Y.append((a, b, 0))

Y = sorted(Y)
YY = [0] * (N+1)
for i in range(N):
    YY[i+1] = YY[i] + Y[i][0]

maa, mab = 0, 1
for i in range(N):
    if Y[i][2] == 0: continue
    l = 0
    r = N
    while r - l > 1:
        m = (l+r) // 2
        rem = S - YY[m] if m < i else S - (YY[m+1] - Y[i][0])
        if rem >= 0:
            l = m
        else:
            r = m

    aa = l * Y[i][1] + S - (YY[l] if l < i else YY[l+1] - Y[i][0])
    bb = N * Y[i][1]
    if aa * mab > bb * maa:
        maa, mab = aa, bb

g = gcd(maa, mab)
print(maa//g, mab//g)