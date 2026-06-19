while 1:
    r,n = map(int,raw_input().split())
    if r == 0: break

    h = [0]*43
    for loop in xrange(n):
        xl,xr,hi = map(int,raw_input().split())
        for i in xrange(xl+21,xr+21): h[i] = max(h[i],hi)
    hu,hd = h[:],h[:]
    for i in xrange(1,43):
        if h[i-1] != h[i]:
            hu[i] = max(h[i-1],h[i])
            hd[i] = min(h[i-1],h[i])
            
    y,d,u = 0.,-r,r
    for loop in xrange(30):
        if any((x-21)**2+min((y-hd[x])**2,(y-hu[x]))**2 < r**2 for x in xrange(1,42)):
            u = y
        else:
            d = y
        y = (u+d)/2
    print "%.5f"%(y+r)