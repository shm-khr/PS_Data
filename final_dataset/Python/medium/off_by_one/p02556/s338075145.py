import sys
input=sys.stdin.readline
n=int(input())
ab=[]
A=0
B=0
C=1e18
D=1e18
for i in range(n):
	x,y=map(int,input().split())
	A=max(A,x+y)
	B=max(B,x-y)
	C=min(C,x+y)
	D=min(D,x-y)
print(max(A-C,B-D))