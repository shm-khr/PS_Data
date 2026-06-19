Haiku = list(map(int, input().split()))
Haiku.sort()

if Haiku[0] == 5 and Haiku[1] == 5 and Haiku[1] == 7:
    print('YES')
else:
    print('NO')