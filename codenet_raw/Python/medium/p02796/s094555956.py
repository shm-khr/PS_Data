n = int(input())
x_l = {}
for i in range(n):
    x,l = map(int, input().split())
    x_l[l] = x
if n ==1 :
    print(1)
    exit()
del_num = 0
sort_key = sorted(x_l.keys())
min_max = [max(0, x_l[sort_key[0]] - sort_key[0]), min(10**9, x_l[sort_key[0]] + sort_key[0])]
for i in sort_key[1:]:
    if min_max[1] >  (x_l[i] - i):
        del_num+=1
    else:
        min_max[1] = (x_l[i] - i)
print(n-del_num)