N,L=map(int,input().split())
x=[int(i) for i in input().split()]
t=[int(i) for i in input().split()]
l=[0 for i in range(N)]
for i in range(N):
    p=t[i]//L
    l[i]+=2*p
    if 2*(t[i]-2*p)<=max([2*L-abs(L-2*x[i]),abs(L-2*x[i])]):
        l[i]+=1
    else:
        l[i]+=2
print(int(round(sum(l)+0.5,0))*L)
