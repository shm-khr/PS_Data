n = int(raw_input())
while n > 0:
  a = int(raw_input())
  b = int(raw_input())
  if len(str(a+b))>80:
    print('overflow')
  else:
    print(a+b)
  n -= 1