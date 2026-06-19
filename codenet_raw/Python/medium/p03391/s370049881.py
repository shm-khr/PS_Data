n=int(input())
a,b=[],[]
for i in range(n):x,y=map(int,input().split());a.append(x);b.append(y)
c=10**10
for i in range(n):
 if a[i]>b[i]:c=min(c,b[i])
print(sum(a)-c)