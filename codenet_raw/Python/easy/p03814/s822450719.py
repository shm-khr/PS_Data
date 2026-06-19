s = input()
A = None
Z = None
for i, c in enumerate(s):
  if c == 'A':
    A = i
  if c == 'Z':
    Z = i

print(Z-A+1)