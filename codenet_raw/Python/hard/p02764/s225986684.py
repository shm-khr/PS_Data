def i1():
 return int(input())
def i2():
 return [int(i) for i in input().split()]
import math
[n,k]=i2()
d=[]
for i in range(n):
 d.append(i2())

def check(t):
 for x1,y1,c1 in d:
  for x2,y2,c2 in d:
   if x1==x2 and y1==y2:
      continue
   aa=2*(x1-x2)
   bb=2*(y1-y2)
   cc=t**2*(1/c2**2-1/c1**2)+x1**2-x2**2+y1**2-y2**2
   if aa==0:
      continue
   ss=bb**2/aa**2+1
   tt=bb/aa*(x1-cc/aa)-y1
   uu=(x1-cc/aa)**2+y1**2-(t/c1)**2
   if tt**2-ss*uu<0 or ss==0:
      continue
   Y1=-tt-math.sqrt(tt**2-ss*uu)
   Y1/=ss
   X1=(cc-bb*Y1)/aa
   count=0
   for x,y,c in d:
    if c*math.sqrt((X1-x)**2+(Y1-y)**2)<=t:
      count+=1
   if count>=k:
    return True
   Y2=-tt+math.sqrt(tt**2-ss*uu)
   Y2/=ss
   X2=(cc-bb*Y2)/aa
   count=0
   for x,y,c in d:
    if c*math.sqrt((X2-x)**2+(Y2-y)**2)<=t:
      count+=1
   if count>=k:
    return True
 for X,Y,C in d:
   count=0
   for x,y,c in d:
    if c*math.sqrt((X-x)**2+(Y-y)**2)<=t:
      count+=1
   if count>=k:
    return True
 return False

low=0
high=100*3000
eps=10**(-7)
while high-low>eps:
  mid=(low+high)/2
  if check(mid):
     high=mid
  else:
     low=mid
print(high)