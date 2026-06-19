n, m = map(int, input().split())
x = (m-2*n)//4
a = min(n+x, (m-2*x)//2)
b = min(n+x-1, (m-2*(x-1))//2)
c = min(n+x+1, (m-2*(x+1))//2)
print(max(a, b, c))
