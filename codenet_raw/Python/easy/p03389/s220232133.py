a=list(map(int,input().split()))
t=max(a)*3-sum(a)
print(t+(t%2)*3)