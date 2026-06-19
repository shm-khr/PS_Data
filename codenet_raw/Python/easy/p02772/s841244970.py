N=int(input())
A=[int(s) for s in input().split()]

Ans="APPROVED"
for i in range(N):
    if A[i]//2==0:
        if A[i]//3!=0 and A[i]//5!=0:
            Ans="DENIED"
            break
print(Ans)