N = int(input())

sum = 0

while N:
  a = N%10
  sum += a
  N = N//10

if sum%9==0:
  print("Yes")
else:
  print("No")