import numpy as np

N, M = [int(x) for x in input().split(' ')]

price = [int(x) for x in input().split(' ')]
  
for m in range(M):
  index = np.argmax(price)
  price[index] = price[index]/2.

price = [int(x) for x in price]
print(sum(price))