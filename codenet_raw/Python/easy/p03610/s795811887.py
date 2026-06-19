s = input()

s = "".join([i for i in s if s.index(i) % 2 == 0])

print(s)