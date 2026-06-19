n, k = [ int(v) for v in input().split() ]
mod_list = [6,4,2,0,9,7,5,3,1,10,8]
g = mod_list.index(k)
corumn_list = [ None for i in range(5) ]

for i in range(11):
    for j in range(1,6):
        if (7*i+j) % 11 == g and corumn_list[j-1] is None:
            corumn_list[j-1] = i

m = (n-2)%11
ans = (5*((n-2)//11)+sum([m >= i  for i in corumn_list]))
print(ans)
