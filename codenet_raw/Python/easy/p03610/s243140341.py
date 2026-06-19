string = input()
i = 1
ans = "
for s in string:
  if i % 2 != 0:
    ans += s

print(ans)