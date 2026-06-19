*a=map(int,open(0))
m=max(a)
t=m*3-sum(a)
if t%2==1:t+=3
print(t//2)