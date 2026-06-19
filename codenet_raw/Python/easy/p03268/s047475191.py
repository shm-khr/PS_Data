n,k=[int(k) for k in raw_input().split(" ")]


nbc=[0]

nbk=[0]*k

for i in range(1,n):
    nbk[i%k]+=1

res=0
for i in range(k):
    if (i+i)%k==0:
        res+=nbk[i]**3

print res
