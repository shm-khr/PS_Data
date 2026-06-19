x,y,a,b,c = map(int,input().split())
p = list(map(int,input().split()))
q = list(map(int,input().split()))
r = list(map(int,input().split()))

p.sort(reverse=True)
q.sort(reverse=True)
apples = p[:x] + q[:y] + r
apples.sort(reverse=True)
print(sum(apples[:x+y]))