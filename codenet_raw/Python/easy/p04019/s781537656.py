li = list(map(str, input()))
x=0
y=0

for i in range(len(li)):
  if li[i]=='N':
    x=x+1
  elif li[i]=='S':
    x=x-1
  elif li[i]=='E':
    y=y+1
  elif li[i]=='W':
    y=y-1

if x==0 and y==0:
  print('Yes')
else:
  print('No')