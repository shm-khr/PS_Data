import sys
MOD=10**9+7
N=int(input())
S=list(input())

if S[0]=="W" or S[-1]=="W":
  print(0)
  sys.exit(0)
elif S.count("B")!=S.count("W"):
  print(0)
  sys.exit(0)

answer=1
for i in range(2,N+1):
  answer*=i
  answer%=MOD
  
lrlist=["L"]
for i in range(1,2*N):
  if S[i]==S[i-1]:
    if lrlist[-1]=="L":
      lrlist.append("R")
    else:
      lrlist.append("L")
  else:
    if lrlist[-1]=="L":
      lrlist.append("L")
    else:
      lrlist.append("R")
#print(lrlist)
  
num_L=num_R=0
for i in range(2*N):
  x=lrlist[i]
  if x=="R":
    #print(num_L,num_R,num_L-num_R)
    answer*=num_L-num_R
    answer%=MOD    
  
  if x=="L":
    num_L+=1
  else:
    num_R+=1
    
print(answer)