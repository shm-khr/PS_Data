import sys

input=sys.stdin.readline

L,N=map(int,input().split())
X=[int(input()) for i in range(N)]

accu1=[X[i] for i in range(N)]
accu2=[X[i] for i in range(N)]
for i in range(1,N):
    accu1[i]+=accu1[i-1]
for i in range(N-2,-1,-1):
    accu2[i]+=accu2[i+1]

ans=max(L-X[0],X[-1])
for i in range(1,N):
    j=N-i
    test=0
    if i<j:
        test1=2*accu1[i-1]-X[i-1]+2*i*L-2*(accu1[2*i-1]-accu1[i-1])
        test2=2*accu1[i-1]+2*(i+1)*L-2*(accu1[2*i]-accu1[i-1])-(L-X[i])
        ans=max(test1,test2,ans)
        #print(test1,test2)
        #print(test1,test2)
    elif j<i:
        test1=2*L*j-2*accu2[-j]-(L-X[-j])+2*(accu2[-2*j]-accu2[-j])
        test2=2*L*j-2*accu2[-j]+2*(accu2[-2*j-1]-accu2[-j])-X[-j-1]
        #test2=2*sum(L-X[-k-1] for k in range(j))+2*sum(X[-k-1] for k in range(j,2*j+1))
        ans=max(test1,test2,ans)
        #print(test1,test2)
        #print(test1,test2)
    else:
        test1=2*accu1[i-1]+2*i*L-2*(accu1[2*i-1]-accu1[i-1])-min(X[i-1],L-X[i])
        #test1=2*sum(X[k] for k in range(i))+2*sum(L-X[k] for k in range(i,2*i))-min(X[i-1],L-X[i])
        ans=max(ans,test1)

print(ans)
