a=input()
a1=input()
a2=input()
a=a.split()
a1=a1.split(" ")
a1=sorted(list(map(int,a1)))
a2=a2.split()
a2=sorted(list(map(int,a2)))
l=[]
v=a1[0]+a2[0]
l.append(v)

for i in range(int(a[2])):
    dis=input()
    dis=dis.split()
    dis=list(map(int,dis))
    c=a1[dis[0]-1]+a2[dis[1]-1]-dis[2]
    l.append(c)
l1=sorted(set(l))
print(l1[0])
