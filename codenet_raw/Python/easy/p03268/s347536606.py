

import math

n, k = map(int, input().split())
c = 0
if (n < k)&(k!=2):
    print(c)
    
elif k%2==0:
    if math.floor(2*n/k)%2==0:
        d=math.floor(2*n/k)
        c=2*d*d*d
    else:
        d=(math.floor(2*n/k)+1)/2
        c=d*d*d+(d-1)*(d-1)*(d-1)
    print(int(c))
else:
    d=math.floor(n/k)
    c=d*d*d
    print(int(c))

