n =int(input())
x =[]
l =[]

for i in range(n):
    x1,l1 = [int(i) for i in input().split()]
    x.append(x1)
    l.append(l1)

min = []
max = []
for i in range(n):
    min1, max1 = (x[i]-l[i],x[i]+l[i])
    min.append(min1)
    max.append(max1)

min_sort = sorted(min)
max_sort = sorted(max)
ans = 0
T =-100000000
for i in range(n):
    if T<=min_sort[i]:
        ans +=1
        T = max_sort[i]
print(ans)