s=list(input())
l=len(s)
m=10**9 +7
def ck(X):
  a=[]
  an=0
  for i in s:
    if i==X:
      an+=1
    a+=[an]
  return a
a=ck("A")
c=ck("C")
x=ck("?")

ans=0
for i in range(1,l-1):
  if s[i] in ('B','?'):
    aa=a[i-1]
    cc=c[l-1]-c[i]
    if x[i-1] !=0:
      aa=max(aa,1)
    if x[l-1]-x[i] !=0:
      cc=max(cc,1)      
    ac=aa * cc
    xa=x[i-1] if a[i-1] !=0 else max(x[i-1]-1,0)
    xc=x[l-1]-x[i] if c[l-1]-c[i]!=0 else max(x[l-1]-x[i]-1,0) 
    if xa!=0:
      ans += 3**xa
    if xc!=0:
      ans += 3**xc
    ans += ac 
print(ans%m)