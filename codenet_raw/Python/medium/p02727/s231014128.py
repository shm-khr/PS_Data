X, Y, A, B, C = input().split(" ")
Xa = input().split(" ")
Ya = input().split(" ")
Notra = input().split(" ")
def toint(a):
	for i in range(len(a)):
		a[i]=int(a[i])
toint(Xa)
toint(Ya)
toint(Notra)
Notrmax = 0
Notra.sort(reverse=True)
Xa.sort(reverse=True)
Ya.sort(reverse=True)
Xa = Xa[0:int(X)]
Ya = Ya[0:int(Y)]
def change():
	answer = 0
	while True:
		Notra.sort(reverse=True)
		Xa.sort()
		Ya.sort()
		if Xa[0] > Ya[0]:
			try:
				if Ya[0] < Notra[0]:
					Ya[0] = Notra[0]
					Notra.remove(Notra[0])
				else:
					break;
			except:
				break;
		elif Xa[0] < Ya[0]:
			try:
				if Xa[0] < Notra[0]:
					Xa[0] = Notra[0]
					Notra.remove(Notra[0])
				else:
					break;
			except:
				break;
		elif Xa[0] == Ya[0]:
			try:
				if Xa[0] < Notra[0]:
					Xa[0] = Notra[0]
					Notra.remove(Notra[0])
				else:
					break;
			except:
				break;
	for i in Xa:
		answer += i
	for i in Ya:
		answer += i
	print(answer)
change()