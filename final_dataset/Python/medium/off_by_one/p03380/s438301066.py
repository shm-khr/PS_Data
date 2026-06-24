import bisect

N = int(input())
l = list(map(int,input().split()))

l.sort()

r = bisect.bisect_right(l, l[-1]/2)

a = l[r]
if r+1==N:
  b = l[r-1]
else:
  b = l[r+1]

a2 = min(a,l[-1]-a)
b2 = min(b,l[-1]-b)

if a2 >= b2:
  c = a
else:
  c = b

print( int( l[-1] ) ,int(c))
