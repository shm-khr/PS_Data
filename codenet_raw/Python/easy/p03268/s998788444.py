N,K=map(int,input().split())
u1, u2=divmod(N,K)
ans=u1*3

A=[u1]*K
for i in range(u2):
    A[i+1]+=1
if K%2==0:
    ans+=A[K//2+1]*3
print(ans)