N ,M = map(int,input().split())
array = []
if N % 2 == 1:
    for i in range(1,(N-1)//2 + 1):
        array.append([i,N-i])
    for i in range(M):
        print(*array[i])
else:
    for i in range(1,N//2):
        if i <= N//4:
            array.append([i,N+1-i])
        else:
            array.append([i,N-i])
    for i in range(M):
        print(*array[i])