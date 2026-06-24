#import random
n=int(input())

pnt=[]
for i in range(n):
  pnt.append(list(map(int,input().split())))
  #pnt.append([random.randint(int(-1e9),int(1e9)),random.randint(int(-1e9),int(1e9))])
pnt.sort(key=lambda x:abs(x[0])+abs(x[1]),reverse=True)
mn=list(reversed(pnt))
mx=0

for i in range(min(n,5000)):
  for j in range(i+1,min(n,5000)):
    mx=max(abs(pnt[i][0]-pnt[j][0])+abs(pnt[i][1]-pnt[j][1]),mx)
    mx=max(abs(pnt[i][0]-mn[j][0])+abs(pnt[i][1]-mn[j][1]),mx)
print(mx)
