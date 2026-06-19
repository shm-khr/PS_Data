def chk(x):
  y=0
  for i in range(1,n):
    if(a[i]>a[i-1]):
      y=y*pow(x,a[i]-a[i-1])
    elif(a[i]==a[i-1]):
      y=y+1
    else:
      y=y//pow(x,a[i-1]-a[i])+1
    if(y>=pow(x,a[i])):
       return 0
  return 1
n=int(input())
s=input()
a=[int(x) for x in s.split()]
lb=1
rb=int(1e18)
while lb<rb:
  md=(lb+rb)//2
  if(chk(md)):
    rb=md
  else:
    lb=md+1
print(lb)