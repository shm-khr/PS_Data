N = int(input())
A = list(map(int,input().split()))
tmp = 0
std = sum(A)/2
index = 0
while tmp < std:
    tmp += A[index]
    index += 1
print(int(abs(tmp-std)))