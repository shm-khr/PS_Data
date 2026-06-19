a = input().split()

pura = int(a[0])     #1
zero = int(a[1])     #0
mai  = int(a[2])     #-1
num  = int(a[3])     #枚数
total = 0
k = num-pura-zero

if pura <= num:
    total = pura
if zero <= num - pura:
    total = total
else:
    print(pura)
if k > 0:
    total = pura-(k)
print(total)