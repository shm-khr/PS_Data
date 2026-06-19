N=int(input())
aBsum=[0,0]
ABsum=[0,0]
Absum=[0,0]
ans=0
for i in range(N):
  a,b=map(int,input().split())
  if a<b:
    aBsum[0]+=a
    aBsum[1]+=b
  elif a==b:
    ABsum[0]+=a
    ABsum[1]+=b
  else:
    Absum[0]+=a
    Absum[1]+=b
ans+=aBsum[0]
aBsum[1]-=aBsum[0]
aBsum[0]=0
if ans>0:
  ans+=ABsum[0]
  ABsum[1]=aBsum[1]
  aBsum[0]=0
  ans+=ABsum[1]
print(ans)
