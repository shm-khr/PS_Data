Blist = {}
chkedSquare = {}
result = {}
#sA,sBを左上にもつ３×３の四角に■が何個あるか
#■は{'a,b',四角の数}であらわされている
def chkAreaCount(sA,sB):
	count = 0
	if str(sA) + ',' + str(sB) not in chkedSquare:
		for i in range(3):
			chkA = sA + i
			for j in range(3):
				chkB = sB + j
				if str(chkA) + ',' + str(chkB) in Blist:
					count = count + 1
					#print('check' + str(chkA) + ':' + str(chkB) + ':' + str(count))
		#print(str(sA) + ':' + str(sB) + ':' + str(count))
		chkedSquare[str(sA) + ',' + str(sB)] = count

def chkOneBlackSquare(a,b):
	#print('PARENT' + str(a) +','+ str(b))
	for i in range(3):
		sA = a - i
		if sA < 1 :
			continue
		if sA + 2 > H:
			continue
		for j in range(3):
			sB = b - j
			if sB < 1:
				continue
			if sB + 2 > W:
				continue
			#print(str(sA) +','+ str(sB))
			chkAreaCount(sA,sB)
				
	
if __name__ == '__main__':
	H,W,N = map(int,list(input().split())) 
	for i in range(N):
		a,b = map(int,list(input().split())) 
		Blist[str(a) + ',' + str(b)] = 0
	for key in Blist.keys():
		#print(key)
		a,b = key.split(',')
		chkOneBlackSquare(int(a),int(b))
	for v in chkedSquare.values():
		if v in result:
			result[v] = result[v] + 1
		else:
			result[v] = 1
	for i in range(10):
		if i == 0:
			wholeS = (H-2)*(W-2)
			ZeroS = wholeS - len(chkedSquare)
			print(str(ZeroS))
		elif i in result:
			print(str(result[i]))
			#print('')
		else:
			print('0')
			#print('')