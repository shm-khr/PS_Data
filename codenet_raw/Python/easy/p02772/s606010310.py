N = int(input())
a_list = list(map(int, input().split()))

even_list = []
for a in a_list:
    if a%2==0:
        even_list.append(a)

ans = False
for e in even_list:
    if e%3==0 or e%5==0:
        ans = True
    else:
        ans = False
        break

if ans:
    print("APPROVED")
else:
    print("DENIED")
