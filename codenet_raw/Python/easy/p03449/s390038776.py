N=int(input())
A=[]
for i in range(2):
    A_ = list(map(int, input().split()))
    A.append(A_)
    A[i].append(0)
A.append([0]*(N+1))
# A=[[0]*(N+1),[0]*(N+1),[0]*(N+1)]
# A[0]=list(map(int,input().split()))
# A[1]=list(map(int,input().split()))

max_candidate=[]
x=0
y=0
ans=A[0][0]
for i in range(N):
  if A[y][x+1]>=A[y+1][x]:
    ans+=A[0][x+1]
    x+=1
  #下方向移動の方が値が大きい場合、最大値の候補としてリストに追加
  else:
    ans_can=ans
    for j in range(x,N):
      ans_can+=A[1][j]
    max_candidate.append(ans_can)7
    x+=1
print(max(max_candidate))
