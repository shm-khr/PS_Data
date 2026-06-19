n,k=map(int,input().split())
a=[int(i) for i in input().split()]
chk=a.index(1)
k-=1
l=chk
r=n-(chk+1)
t1=k-l%k
t2=k-r%k
print(min(((l+k-1)//k)+((r+k-1)//k),((l-t2)//k)+((r+k-1)//k), ((l+k-1)//k)+((r-t1)//k)))
