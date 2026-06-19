a = map(int, input().split())
if a.endswith('e'):
 print(a+'s')
elif  a.endswith('s'):
 print(a+'es')
else:
 print(a)