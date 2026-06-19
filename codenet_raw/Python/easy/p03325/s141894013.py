N = int(input())
A = list(map(int, input().split()))

seki = 1

for a_i in A:
        seki *= a_i

count = 0

while seki % 2 == 0:
        seki = seki // 2
        count += 1

print(count)