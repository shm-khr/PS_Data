N = int(input())
A = list(map(int , input().split()))
B = []
acount = 0
bcount = 0
for i in A:
    if i % 2 == 1:
         pass
    else:
        acount += 1
        B.append(i)
if len(B) > 0:
    for i in B:
        if i % 3 == 0 or i % 5 == 0:
             bcount += 1
if N == 0:
    print('DENIED')
elif N != len(A):
    print('DENIED')
elif N > 100:
    print('DENIED')
elif len(A) > 1000:
    print('DENIED')
elif acount == 0:
    print('DENIED')
elif bcount == 0:
    print('DENIED')
elif acount == bcount:
    print('APPROVED')
else:
    print('DENIED')