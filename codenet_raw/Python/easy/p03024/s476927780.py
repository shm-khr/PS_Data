S = input()
r = 0
for s in S:
    if s == "o":
        r += 1
if r >= 7:
    print("YES")
else:
    print("NO")
