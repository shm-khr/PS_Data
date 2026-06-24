N,K = map(int, input().split())
A = list(map(int, input().split()))

cnt = 0
for i in range(N):
    temp = 0
    for j in range(i,N):
        temp += A[j]
        if temp%K == j-i+1:
            cnt += 1
            
print (cnt)