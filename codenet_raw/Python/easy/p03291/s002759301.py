import numpy as np
s=input()
A=np.array([0,0,0,0])
B=np.array([0,0,0,0])
C=np.array([0,0,0,0])
t=0
for c in s:
	if c=="A":
		A[0]+=1
	if c=="B":
		B+=A
	if c=='C':
		C+=B
	if c=='?':
		C+=np.roll(B,1)
		B+=np.roll(A,1)
		A[1]+=1
		t+=1
ans=0
for i in range(4):
	ans+=pow(3,t-i)*C[i]
print(int(ans%1000000007))