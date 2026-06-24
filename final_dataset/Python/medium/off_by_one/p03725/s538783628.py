from collections import defaultdict,deque
from math import ceil
H,W,K=map(int,input().split())
grid=[input() for i in range(H)]
G=defaultdict(set)
                               
for i in range(H):
  for j in range(W):
    if grid[i][j]=="S":
      S=(i,j)
    if grid[i][j]!="#":
      if i>0:
        if grid[i-1][j]!="#":
          G[(i,j)].add((i-1,j))
      if i<H-1:
        if grid[i+1][j]!="#":
          G[(i,j)].add((i+1,j))
      if j>0:
        if grid[i][j-1]!="#":
          G[(i,j)].add((i,j-1))
      if j<W-1:
        if grid[i][j+1]!="#":
          G[(i,j)].add((i,j+1))

stack=deque([(S[0],S[1],0)])
visited=[[False]*(W) for i in range(H)]
visited[S[0]][S[1]]=True
a=float("inf")
while stack:
  y,x,m=stack.popleft()
  if m>K:
    break
  a=min(a,min(x,W-1-x,y,H-1-y))
  for k in G[(y,x)]:
    if not visited[k[0]][k[1]]:
      stack.append((k[0],k[1],m+1))
      visited[k[0]][k[1]]=True
ans=1+ceil(a/K)
print(ans)


    
        
        
          
  
