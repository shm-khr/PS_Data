# -*- coding: utf-8 -*-

# Input#
n = int(input())
# n, k = map(int, input().split())
# a = list(map(int, input().split()))

sum = 0
while n > 9:
    sum += n % 10
    n = int(n / 10)

sum += int(n)
if sum % 9 == 0:
    print("Yes")
else:
    print("No")


# print("{}".format(ans))
