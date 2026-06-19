n=int(input())
if n==1:print("First")
graph=[[] for i in range(n)]
for i in range(n-1):
    a,b=map(int,input().split())
    a-=1;b-=1
    graph[a].append(b)
    graph[b].append(a)
leaves=0
leafcnt=[0]*n
for i in range(n):
    if len(graph[i])==1:
        leaves+=1
        leafcnt[graph[i][0]]+=1
for i in range(n):
    if leafcnt[i]>=2:
        print("First")
        exit()
if n%2 == 0 and leaves== n//2:print("Second")
else:print("First")