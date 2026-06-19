
n = int(input())
a = list(map(int, input().split()))

l = sum(a)
half = l // 2
odd = True
if l % 2 == 0:
    odd = False

cnt = 0
for i in range(n):
    cnt += a[i]
    if cnt == half:
        if odd:
            ans = 2
        else:
            ans = 0
        break    
    if cnt > half:
        if cnt - half > half - (cnt-a[i]):
            #print(1, half - (cnt-a[i]))
            ans = (half - (cnt-a[i]))*2
            break
        else:
            #print(2, (cnt - half))
            ans = (cnt - half)*2
            break
            
if odd:
    ans -= 1
    
print(ans)