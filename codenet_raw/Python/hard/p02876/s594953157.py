from fractions import Fraction

lst = []

n = int(input())
s = 0

for i in range (n) :
    (a, b) = input().split(" ")
    a = int(a)
    b = int(b)
    s += a
    lst.append(a-b)

lst.sort()

ans = Fraction(0, 1)

for i in range(n) :
    if s > 0 && s + lst[i] < 0 :
        ans += Fraction(-lst[i]-s,-lst[i]*n)
    elif s < 0 && s + lst[i] > 0 :
        ans += Fraction(-s, lst[i]*n)
    elif s < 0 :
        ans += Fraction(1, n)

print(ans)
