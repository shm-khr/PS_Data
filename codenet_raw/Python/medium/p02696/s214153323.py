import math
from decimal import Decimal

a,b,n = map(int,input().split())
ans = 0
al = []
    
for i in range(n,-1,-1):
    ans = (Decimal(str(a))*Decimal(str(i))//b)-(a*(i//b))
    al.append(ans)
    if len(al) > 1:
        if al[-1] <= al[-2]:
            break
if max(al) < 0:
    print(0)
else:
    print(max(al))