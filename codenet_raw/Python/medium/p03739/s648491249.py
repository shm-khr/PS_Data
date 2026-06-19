n = int(input())
A = [int(x) for x in input().split()]

flag = True if A[0] > 0 else False

count = 0
for i in range(n):
    if i == 0:
        continue
    sum_for_i = sum(A[:i])
    sum_for_next = sum(A[:i+1])
    if (sum_for_i != 0 and ((sum_for_i > 0 and sum_for_next <0) or (sum_for_i < 0 and sum_for_next >0))):
        continue
    else:
        #print("needs to be changed: A[{}] ({})".format(i, A[i]))
        while not (sum_for_i != 0 and ((sum_for_i > 0 and sum_for_next <0) or (sum_for_i < 0 and sum_for_next >0))):
            if (sum_for_i < 0):
                A[i] += 1
                count += 1
            else:
                A[i] -= 1
                count += 1
            sum_for_i = sum(A[:i])
            sum_for_next = sum(A[:i+1])

print(count)