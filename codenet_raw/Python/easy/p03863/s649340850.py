line = list(input())
count = 0
for i, s in enumerate(line[0:-2]):
  if line[i] != line[i+2]:
    count+=1
 
if count % 2 == 0:
  print("Second")
else:
  print("First")