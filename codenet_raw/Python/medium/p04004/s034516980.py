mod=int(1E9+7)
JS=[1]
for i in range(1,5000):
    JS.append(JS[-1]*i%mod)
Cs=lambda x,y:js(x)*inv(js(y))*inv(js(x-y))%mod
inv =lambda x:pow(x,mod-2,mod)
js=lambda x:JS[x]
#while True:
A,B,C=map(int,input().split())
A-=1;B+=1;C+=1;
ans=0
for x in range(1,B+1):
    for y in range(1,C+1):
        ans+=Cs(A+B-x+C-y,A)*Cs(B-x+C-y,B-x)*pow(3,x-1+y-1,mod)%mod
        ans%=mod
print(ans)
