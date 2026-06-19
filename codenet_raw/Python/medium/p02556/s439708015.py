N = int(input())
#i = 0
a_max = 2
a_min = 2*(10**9)
s_max = 0
s_min = 10**9

for i in N:
    x,y=map(int,input().split())
    add = x+y
    sub = x-y

    if add > a_max:
        a_max = add
    if add < a_min:
        a_min = add
    if sub > s_max:
        s_max = sub
    if sub < s_max:
        s_max = sub

d_add = a_max - a_min
d_sub = s_max - s_min

print(max(d_add,d_sub))