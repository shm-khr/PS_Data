"""
b > g > r

"""

r, g, b = list(map(int, input().split()))
k = int(input())
flag = False
for i in range(k):
    if r >= b and g > b:
        b *= 2
    elif r >= g:
        g *= 2
    if b > g > r:
        flag = True

print("Yes") if flag else print("No")