N, M = map(int,input().split())

a = [str(i) for i in range(1,N+1)]
b = [str(i) for i in range(N,0,-1)]

if N%2 == 0:
    for i in range(M):
        print(a[i] + ' ' + b[i])
else:
    for i in range(M):
        print(a[i] + ' ' + b[i+1])