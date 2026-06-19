from math import sqrt
def calc(x, h):
    return max(h+r-sqrt(r**2 - x**2), 0)
while 1:
    r, n = map(int, raw_input().split())
    if r == 0:
        break
    H = [0]*41
    for i in xrange(n):
        xl, xr, h = map(int, raw_input().split())
        for j in xrange(xl, xr):
            H[j] = max(H[j], h)
    ans = 10**9
    for i in xrange(-r, r):
        print i, H[i], calc(i, H[i]), calc(i+1, H[i])
        ans = min(ans, calc(i, H[i]), calc(i+1, H[i]))
    print "%.6f" % ans