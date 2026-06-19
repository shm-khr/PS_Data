A=input()
n=len(A)
from collections import defaultdict
d = defaultdict(int)
for i in A:
    d[i]+=1
a=0
for i in d.values():
    a+=i*(i-1)//2
print(n*(n-1)//2+1-a)