N= int(input())

price = [int(input()) for i in range(N)]
price.sort()

total = sum(price)-price(-1)/2
print(int(total))