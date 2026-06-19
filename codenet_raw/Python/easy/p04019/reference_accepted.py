s = input()
flag = [0] * 4
for i in range(len(s)):
  if s[i] == "N":
    flag[0] = 1
  elif s[i] == "S":
    flag[1] = 1
  elif s[i] == "W":
    flag[2] = 1
  else:
    flag[3] = 1
if flag[0] == flag[1] and flag[2] == flag[3]:
  print("Yes")
else:
  print("No")