import math

N = int(input())
sum = 0

while N > 0:
    sum = sum + N % 10
    N = math.floor(N / 10)

if sum % 9 == 0:
    print("yes")
else:
    print("No")