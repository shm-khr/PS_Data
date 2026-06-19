from math import floor

a, b, n = map(int, input().split())

func = []
max = 0

for x in range(1, n+1):
#    if floor(a*x/b) < a*floor(x/b):
#        break
    func.append(floor(a*x/b) - a*floor(x/b))
    if max < func[-1]:
        max = func[-1]
    if x > 2:
        diff = func[-1] - func[-2]
    if diff < 0:
        break

print(max)