N,A,B,C,D=map(int,input().split())
l=[]
for i in range(N+1):
    l.append(range(i*C-(N-i)*D,int(i*D-(N-i)*C/2)*2+2,2))
for _ in l:
    if B-A in _:
        print("YES")
        break
else:
    print("NO")

