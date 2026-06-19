s = input()
c=0
n = list(map(str, s))

for i in n :
    if i == 'o' :
        c +=1
        
if c >= 8 or (8-c) == 15 - len(n) :
    print('YES')
else :
    print('NO')