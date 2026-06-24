import sys
sys.setrecursionlimit(10**6)

MOD = 1000000007

def func(n):
	if n <= 1:
		return 1
	return n * func(n-1)%MOD

def main():
	n,k = map(int, input().split())
	if n > k:
		print(0)
	else:
		print(int(func(k)/func(k-n)) % MOD)
	return

main()
