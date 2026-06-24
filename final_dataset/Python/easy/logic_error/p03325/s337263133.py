N = int(input())
a = list(map(int, input().split()))
answer = 0
def prime_decomposition(n):
  i = 2
  table = []
  while i * i <= n:
    while n % i == 0:
      n /= i
      table.append(i)
    i += 1
  if n > 1:
    table.append(n)
  return table

for ai in a:
    # print(prime_decomposition(ai))
    # # if 2 in prime_decomposition:
    # #     print('Yes')
    # print(prime_decomposition(ai).count(2))
    answer += prime_decomposition(ai).count(2)

print(answer)