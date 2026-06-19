import math
while True:
    n=int(input())
    a=list(map(int,input().split()))
    if n==0:
        break
    else:
        m=sum(a)/float(n)
        print("{0:.8f}".format(math.sqrt(sum([(x-m)**2/n for x in a]))))