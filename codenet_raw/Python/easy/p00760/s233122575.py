n=int(input())
a=[]
for i in range(n):
    y,m,t=map(int,input().split())
    a.append([y,m,t])
for k in range(n):
    if a[k][0]%3!=0:
        if a[k][1]%2==0:
            a[k][2]=196-10*a[k][1]+19*(a[k][1]-2)/2-a[k][2]
        else:
            a[k][2]=196-39*(a[k][1]-1)/2-a[k][2]
    else:
        a[k][2]=201-20*(a[k][1]-1)-a[k][2]
    a[k][0]+=1
    while a[k][0]<1000:
        if a[k][0]%3==0:
            a[k][2]+=200
        else:
            a[k][2]+=195
        a[k][0]+=1
    print(a[k][2])
