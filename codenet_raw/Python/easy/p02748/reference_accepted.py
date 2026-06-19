a, b, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

# cheapest price without using discount ticket
min_price = min(a) + min(b)

for i in range(m):
    arr = list(map(int, input().split()))
    discounted_price = a[arr[0] - 1] + b[arr[1] - 1] - arr[2]
    min_price = min(min_price, discounted_price)
print(min_price)