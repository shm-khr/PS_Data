A=input()
cnt={chr(code): 0 for code in range(ord('a'),ord('z')+1)}
for i in A:
  cnt[i]+=1

from math import factorial
def c(n,r):
  return factorial(n)/factorial(r)/factorial(n - r)
a=len(A)
if a==1:
  print(1)
  exit()
b=0
for i in cnt.values():
  if i>=2:
    b+=i*(i-1)//2
ans=int(c(a,2)-b)
print(ans+1)