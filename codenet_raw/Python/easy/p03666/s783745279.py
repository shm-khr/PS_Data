N,A,B,C,D = map(int,input().split())
if N > 30 and D > 1:
	flag = 10 **9
else:
	flag = pow(D,N -1)
B -= A
if N % 2 == 1:
	if (B % (C + D) <= (N - 1) * (D - C) / 2 or abs(B % (C + D) - (C + D)) <= (N - 1) * (D - C) / 2) and B <= flag and B >= -flag:
		print("YES")
	else:
		print("NO")
else:
	if abs(B % (C + D) - (D + C) / 2) < (N - 1) * (D - C) / 2 and B <= flag and B >= -flag:
		print("YES")
	else:
		print("NO")