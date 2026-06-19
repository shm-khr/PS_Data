n = int(input())

a = 0

while (True):
    a += n % 10
    n = n // 10
    if n == 0:
        break

if a % 9 == 0:
    print("Yes")
else:
    print("No")
