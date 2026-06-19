N,A,B,C,D=map(int,input().split())


#print("target:", abs(A-B))
#print("range: ", D-C)
#print("target is larger than D: " ,
#     abs(A-B)>D)
#target=abs(A-B)
#print("next target is: ", target-D)
#print("how many? : ", (target-D)//(D-C))

ans=False
def g(a,b,c,d,n):
  if (n-1)%2==0:
    target=abs(a-b) #スタートは0
    gain=d-c
    if ((n-1)//2)*gain>=target:
      return True
    else:
      return False
  else:
    target=abs(a-b)
    gain=d-c
    if target>d:
      if (n-2)//2 * gain >=target-d:
        return True
      else:
        return False
    elif target<c:
      if (n-2)//2 *gain >= c- target:
        return True
      else:
        return False
    elif c<=target<=d:
      return True
      
A,B=min(A,B),max(A,B)
target=B-A
pos=0
print("NO")
for i in range(N+1):
  if target>0:
    if C*(N-i)<=target<=D*(N-i):
      print("YES")
      exit(0)
    if  g(pos, target, C,D, N-i):
      print("YES")
      exit(0)
  if target >D:
    target-=D
  elif C <=target<=D:
    print("YES")
    exit(0)
  else:
    target=C-target
print("NO")
exit(0)      
  
if g(A,B,C,D,N):
  print("YES")
else:
  print("NO")
    
