n,k = int(input())
a = [0,5,10,4,9,3,8,2,7,1,6]
r = a[k]
s = 0
for i in range(2,n):
  for j in [2,3,4,5,6]:
    if (7*i + j - 7 - r)%11 == 0:
      s += 1
print(s)
      
    
    