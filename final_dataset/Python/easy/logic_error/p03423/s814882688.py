# --*-- encoding:utf-8 --*--

n = input()
list = input().split(" ")
result = []

for i in list:
  for x not in list:
    result.append(x)

print(len(result))