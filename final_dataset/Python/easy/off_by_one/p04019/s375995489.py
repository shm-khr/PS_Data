n = list(input())
a = [0,0,0,0]
for i in range(len(n)):
  if n[i] =="W":
    a[0] += 1
  elif n[i] == "E":
    a[1] += 1
  elif n[i] == "N":
    a[2] += 1
  elif n[i] == "S":
    a[3] += 1
if a[0]*a[1] + a[2]*a[3] != 0:
  print("Yes")
else:
  print("No")