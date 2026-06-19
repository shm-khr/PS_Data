[a,b,c,d]=[int(input()) for i in range(1,4+1)]
a1 = d // 500
b1 = d// 100
c1 = d// 50
value = 0
count = 0
for i in range(0,a1+1):
    value = value + 500*i
    for j in range(0,b1+1-5*i):
        value = value + 100*j
        for k in range(0,c1+1-10*i-2*j):
            value = value + 50*k
            if value == d :
                count = count+1
                break
            value = 0
print(count)