# coding: utf-8
# Here your code



N = int(input())
a = [int(i) for i in input().split()] 

result_1 = 0
before_sum =a[0]
after_sum =a[0]

for i in range(1,N):
    before_sum = after_sum
    after_sum = before_sum + a[i]
    if before_sum * after_sum > 0:
        if after_sum < 0:
            result_1 += 1 - after_sum
            after_sum = 1
        elif after_sum > 0:
            result_1 += 1 + after_sum
            after_sum = -1
    elif before_sum * after_sum == 0:
        result_1 += 1
        if before_sum < 0:
            after_sum = 1
        else:
            after_sum = -1

before_sum =int(-a[0]/abs(a[0]))
after_sum =before_sum
result_2 = 1 + abs(before_sum)


for i in range(1,N):
    before_sum = after_sum
    after_sum = before_sum + a[i]
    if before_sum * after_sum > 0:
        if after_sum < 0:
            result_2 += 1 - after_sum
            after_sum = 1
        elif after_sum > 0:
            result_2 += 1 + after_sum
            after_sum = -1
    elif before_sum * after_sum == 0:
        result_2 += 1
        if before_sum < 0:
            after_sum = 1
        else:
            after_sum = -1


print(min(result_1,result_2))
