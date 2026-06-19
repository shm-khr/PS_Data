def gcd(a, b):
    x, y = [a, b] if a > b else [b, a]
    while y:
        x, y = y, x%y
    return x

a, b = list(map(int, input().split(' ')))
c = gcd(a, b)
a, b = a//c, b//c

x = 0
y = None
while True:
    tmp = (1-a*x)/b
    if tmp == int(tmp):
        y = int(tmp)
        break
    x += 1

print(x, y)
