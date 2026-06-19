N,M = map(int,input().split())
if N%2 == 0:
    exit()
a = 1
b = 2*M

for i in range(M):
    print(a,b)
    a += 1
    b -= 1

