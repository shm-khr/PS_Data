n=int(raw_input())
a=map(int,raw_input().split())
b=map(int,raw_input().split())
sa=sb=0
for i in range(n):
	sa=sa+a[i]
	sb=sb+b[i]

sal=[sa]
sbl=[sb]

for i in range(1,n+1):
	sal.append(sal[i-1]-a[i-1])
	sbl.append(sbl[i-1]-b[i-1])

op=a[0]
flag=0
for i in range(n):
	if flag==0:
		if sal[i+1]>=sbl[i]:
			x=a[i+1]
		else:
			x=b[i]
			flag=1
	else:
		x=b[i]
	op=op+x

print op