i = 0
N = int(input())
list = [int(input()) for i in range(N)]
print("before sort",list)

list.sort(reverse = True)
print("after sort",list)

j = 0
cnt = 1
temp = list[0]

for j in range(N):
    if(temp > list[j]):
        temp = list[j]
        cnt = cnt + 1

print(cnt)
