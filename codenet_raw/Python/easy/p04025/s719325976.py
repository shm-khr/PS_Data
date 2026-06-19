n=int(input())
a=list(map(int,int,input().split()))
b=[]
ma=max(a)
mi=min(a)
for i in range(mi,ma+1):
  c=0
  for j in range(n):
    c+=(i-a[j]**2)
  b.append(c)

print(min(b))
    