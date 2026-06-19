def floor(x):
    x=str(x)
    re=""
    for i in range(len(x)):
        if x[i]=='.':
            return int(re)
        re+=x[i]
    return int(re)
a,b,n=map(int,input().split())
ma=0
t=0
for x in range(1,n+1):
    t=floor(a*x/b)
    if t<=ma:
        continue
    t-=a*floor(x/b)
    if ma<t:
        ma=t
print(ma)