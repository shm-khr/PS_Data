S = input()
x = 15 - len(S)
y = 8 - S.count("o")
ans = "Yes" if x - y >= 0 else "No"
print(ans)