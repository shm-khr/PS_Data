x = str(input())

res=1
st=0
while st<=len(x)-2:
    la=len(x)-1
    while la>=st:

        i=st
        j=la
        flg=False
        while (i<j):
            if x[i]==x[j]:break    
            if x[i]!=x[j]:
                flg=True
                break
            i=i+1
            j=j-1
        if flg==True:
            res=res+1
        
        la=la-1
    st=st+1

print(res)