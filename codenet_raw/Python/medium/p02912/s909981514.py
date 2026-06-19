sn,sm = input().split(" ")
n = int(sn)
m = int(sm)
sa = input().split(" ")
l = len(sa)
a = []
 
for i in range(l):
  a.append(int(sa[i]))
 
for i in range(m):  
  ind = a.index(max(a))
  a[ind] = a[ind] //2
  
print(sum(a))