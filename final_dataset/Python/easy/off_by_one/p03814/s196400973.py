s = input()
aNum = s.index("A")
for i in range(len(s)):
    if s[-i] == "Z":
        zNum = len(s) - i
        break
print(zNum - aNum +1)