from math import ceil
N, K = map(int, input().split())
nums = list(map(int, input().split()))
index = nums.index(1)
print(ceil(index / K) + ceil((N - index - 1) / K))