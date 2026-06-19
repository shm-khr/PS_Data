n = int(input())
s = {}
for i in range(n):
    d = input()
    if d in s:
        s[d] += 1
    else:
        s.update({d:1}) 

m = int(input())
for j in range(m):
    t = input()
    if t in s:
        s[t] -= 1
    else:
        s.update({t:-1})

print("0" if max(d.values()) < 0 else max(d.values()))
