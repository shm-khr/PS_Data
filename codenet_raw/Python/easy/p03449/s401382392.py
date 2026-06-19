n=int(input())
a1=[int(input()) for i in range(n)]
a2=[int(input()) for i in range(n)]
a=[a1,a2]
s=a[0][0]
t=sum(a1)
u=sum(a2)
for i in range(1,n):
  if t-a[0][0]>=u:
    s=s+a[0][i]
    t=t-a[0][i]
    u=u-a[1][i-1]
  else:
    s=s+sum(a2[(i-1):n])
print(s)