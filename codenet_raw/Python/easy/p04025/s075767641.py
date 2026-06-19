N=int(input())
A=(list(map(int,input().split())))
ans=200*100
for b in range(min(A),max(A)+1):
    cnt=0
    for a in A:
        cnt+=(b-a)**2
    ans=min(ans,cnt)
print(ans)