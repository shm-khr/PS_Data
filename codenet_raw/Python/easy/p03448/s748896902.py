a,b,c,x=map(int,input().split())
i=0
for s in range(1,a+1):
    for t in range(1,b+1):
         for r in range(1,c+1):
            if 500*a+100*b+50*c==x:
                i+=1
print(i)