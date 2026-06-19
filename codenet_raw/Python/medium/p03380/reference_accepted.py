n,a=open(0)
*a,=map(int,a.split())
m=max(a)
print(m,min((abs(m-2*i),i)for i in a)[1])
