n, knapsack = map(int, input().split())
dp = [-1] * (knapsack + 1)
dp[0] = 0

for _ in range(n):
    value, weight, amount = map(int, input().split())
    for i in range(knapsack - weight, -1, -1):
        if dp[i] < 0:
            continue
        for j in range(1, amount + 1):
            new_index = i + weight * j
            if new_index > knapsack:
                break
            new_value = dp[i] + value * j
            if dp[new_index] < new_value:
                dp[new_index] = new_value

print(max(dp))