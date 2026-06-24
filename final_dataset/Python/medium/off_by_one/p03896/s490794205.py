N = input()
if N == 2:
    print -1
    exit()
for i in xrange(1, N+1):
    for j in xrange(1, N):
        k = (i+j) % N
        if k == 0:
            k = N
        print k,
    print
