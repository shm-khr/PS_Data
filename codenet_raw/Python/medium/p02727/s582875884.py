x,y,a,b,c = list(map(int, input().split()))

p = list(map(int, input().split()))
q = list(map(int, input().split()))
r = list(map(int, input().split()))

p_rev = sorted(p, reverse=True)
q_rev = sorted(q, reverse=True)
r_rev = sorted(r, reverse=True)
#print(p_rev[:x])
#print(q_rev[:y])
pq_rev = sorted(p_rev[:x] + q_rev[:y] , reverse=True)

num_r = len(r_rev)
start = len(pq_rev) - num_r
total = sum(pq_rev[:(-1)*num_r])
#print(total)
pq_cnt=0
r_cnt = 0
for i in range(num_r):
  if pq_rev[start + pq_cnt] > r_rev[r_cnt]:
    total += pq_rev[start + pq_cnt]
    pq_cnt += 1
  else:
    total += r_rev[r_cnt]
    r_cnt += 1
print(total)