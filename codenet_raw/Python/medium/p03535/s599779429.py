N = int(input())
D = list(map(int,input().split(" ")))

ans = D[:]


D.sort()

for i in range(N):
	if i % 2 == 0:
		D_1.append(24-D[i])
		D_2.appned(D[i])
	else:
		D_2.append(24-D[i])
		D_1.appned(D[i])


for i in range(N):
	for j in range(i+1,N):
		df1 = abs(D_1[j] - D_1[i])
		df2 = abs(D_2[j] - D_2[i])
		
		df1 = min([df1,24-df1])
		df2 = min([df2,24-df2])
			
		ans.append(df1)
		ans.append(df2)

print(min(df1))




