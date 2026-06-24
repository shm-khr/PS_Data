n,m,t = map(int, input().split())
xy = [list(map(int, input().split())) for i in range(m)]
graph = [[] for i in range(n+1)]
vstble = [0]*(n+1)
visited = [0]*(n+1)
visited[0] = 1
for i in range(m):
    x = xy[i][0]
    y = xy[i][1]
    graph[x].append(y)
    graph[y].append(x)
stack = [1]
while stack:
    s = stack.pop()
    visited[s] = 1
    for t in graph[s]:
        if visited[t] == 0:
            stack.append(t)
if min(visited) == 0:
    print(-1)
    exit()
ans = []
for i in range(m-1,-1,-1):
    x = xy[i][0]
    y = xy[i][1]
    if vstble[x] == vstble[y] == 0:
        ans.append("^")
        vstble[x] = 1
        vstble[y] = 1      
    elif vstble[x] == 0 and vstble[y] == 1:
        ans.append("v")
        vstble[x] = 1
    elif vstble[x] == 1 and vstble[y] == 0:
        ans.append("^")
        vstble[y] = 1
    else:
        ans.append("^")
ans = ans[::-1]
print(*ans,sep = "")