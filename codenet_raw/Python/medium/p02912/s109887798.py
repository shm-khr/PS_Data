n,m = map(int,input().split())
a_list = list(map(int,input().split()))

def maximum(list):
    sub = []
    for i,x in enumerate(list):
        if sub == [] or x > sub[0]:
            sub = [x,i]
    return sub[0],sub[1]

for i in range(m):
    x,idx = maximum(a_list)
    a_list[idx] = x//2

print(sum(a_list))