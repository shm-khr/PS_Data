n, knapsack = map(int, input().split())
dp = [-1] * (knapsack + 1)
dp[0] = 0
items = [map(int, input().split()) for _ in range(n)]

for value, weight, amount in items:
    k = 0
    while amount:
        take = 1 << k
        if take > amount:
            take = amount
        amount -= take
        gv, gw = value * take, weight * take
        for i, dpi in enumerate(dp[knapsack - gw::-1]):
            if dpi < 0:
                continue
            new_value = dpi + gv
            if dp[knapsack - i] < new_value:
                dp[knapsack - i] = new_value
        k += 1

print(max(dp))