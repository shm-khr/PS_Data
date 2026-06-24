from math import factorial

n = int(input())
s = input()


MOD = 10**9+7


lr = ''
for i, x in enumerate(s):
    if i % 2 == 0:
        if x == 'B':
            lr += 'L'
        else:
            lr += 'R'
    else:
        if x == 'B':
            lr += 'R'
        else:
            lr += 'L'

cnt = 0
point = 1
for x in lr:
    if x == 'L':
        cnt += 1
    else:
        point *= cnt
        cnt -= 1


print(point*factorial(n) % MOD)