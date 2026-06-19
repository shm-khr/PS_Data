N = int(input())
A = [int(a) for a in input().split()]

sumh = sum(A)
h = sumh// 2
preS = 0
S= A[0]
for ii in range(1, N):
    print ("aa", ii, S)
    if (S >= h and preS >= h):
        print (S - h)
        # print (1)
        break
    elif (preS <= h and S >= h):
        print (min(2 * S - sumh, sumh- 2 * preS))
        # print (2)
        break
    preS = S
    S += A[ii]
