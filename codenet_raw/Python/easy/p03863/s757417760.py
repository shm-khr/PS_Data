s = input()
a = 1
while a < len(s) - 1 and s[a + 1] == s[0]:
    a += 2
print(a)

b = len(s) - 2
while b > 1 and s[b - 1] == s[-1]:
    b -= 2
print(b)

if a > b:
    print("Second")
else:
    print("First" if (b - a + 1) % 2 == 1 else "Second")