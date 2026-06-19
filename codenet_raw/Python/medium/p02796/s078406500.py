 int(input())
A = [list(map(int,input().split())) for i in list(range(N))]
B = [[i[0]+i[1], i[0]-i[1]] for i in A]
B.sort()
prev=B[0]
cnt=N
for i in range(1,N):
  if prev[0]<B[i][1]:
    nt-=1
  else:
    prev=B[i]
print(cnt)  