a, b, c, k = map(int, input().split())

num_list = [1] * a + [0] * b + [-1] * c

count = sum(num_list[:k])
print(count)