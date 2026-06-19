n=input();print-(n==2)or"\n".join(" ".join(str((i+(j^1)if n>i*2and n%2<1 and j<n-2 else i+j)%n)for j in range(n-1))for i in range(1,n+1))
