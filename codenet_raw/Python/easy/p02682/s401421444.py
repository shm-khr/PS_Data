a, b, c, k = map(int, input().split())

lista = [1]*a
listb = [0]*b
listc = [-1]*c
list = lista + listb + listc
anslist = list[0:k]
ans = sum(anslist)

print(ans)