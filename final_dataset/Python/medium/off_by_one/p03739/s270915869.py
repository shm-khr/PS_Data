import numpy as np

n = input()
a_s = [int(x) for x in input().split()]

sum_i = 0
manipulate_num = 0
for a in a_s:
    new_sum_i = sum_i + a
#     print(f"a:{a}, sum_i:{sum_i}, new_sum_i:{new_sum_i}")
    if new_sum_i == 0:
        manipulate_num += 1
    if new_sum_i * sum_i > 0:
        manipulate_num += abs(new_sum_i)+1
        new_sum_i -= np.sign(new_sum_i)*(abs(new_sum_i)+1)
    sum_i = new_sum_i
#     print(f"a:{a}, sum_i:{sum_i}")
#     print()
    
print(manipulate_num)