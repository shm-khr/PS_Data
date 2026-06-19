n,k=map(int,input().split())
count=0
for i in range(n-2):
    for i2 in range(5):
        if ((9*(7*i+i2+8+1))%11) == k:
            count+=1
print(count)
