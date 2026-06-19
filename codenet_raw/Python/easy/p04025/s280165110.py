# https://atcoder.jp/contests/arc059/tasks/arc059_a

n = int(input())
nums = [int(i) for i in input().split()]

ave = (sum(nums) + 1) // n

ans = 0
for num in nums:
    ans += (num - ave) ** 2

print(ans)