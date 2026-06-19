import itertools

X = int(input())
A = int(input())
B = int(input())
C = int(input())

price = 0
count = 0
for i in range(A + 1):
    for j in range(B + 1):
        for k in range(C + 1):
            price = i * 500 + j * 100 + k * 50
            if price == X:
                count += 1
            price = 0

print(count)


