def ds1(here, (dx,dy,dz), lb, ub, field,label):
	result = 0
	if field[here[1]][here[0]][here[2]] == label :
		result += 1 
		next = (here[0]+dx,here[1]+dy,here[2]+dz)
		if lb[0] <= next[0] <= ub[0] and lb[1] <= next[1] <= ub[1] and lb[2] <= next[2] <= ub[2]:
			result += ds1((next[0],next[1],next[2]), (dx,dy,dz), lb, ub, field, label)	
	return result
def ds26(here, delta, lb, ub, field, label):
	length = 0
	field[here[1]][here[0]][here[2]] = label
	for dx, dy, dz in delta:
		tmplen = 0
		next_p = (here[0]+dx,here[1]+dy,here[2]+dz)
		next_n = (here[0]-dx,here[1]-dy,here[2]-dz)
		if lb[0] <= next_p[0] <= ub[0] and lb[1] <= next_p[1] <= ub[1] and lb[2] <= next_p[2] <= ub[2]:
			tmplen += ds1(next_p, (dx,dy,dz), lb, ub, field, label)
		if lb[0] <= next_n[0] <= ub[0] and lb[1] <= next_n[1] <= ub[1] and lb[2] <= next_n[2] <= ub[2]:
			tmplen += ds1(next_n, (-dx,-dy,-dz), lb, ub, field, label)
		length = max(length, tmplen)
	return 1 + length
	
delta = ((1,1,1), (1,0,1), (1,-1,1),
		 (1,1,0), (1,0,0), (1,-1,0),  
		 (1,1,-1), (1,0,-1), (1,-1,-1), 
		 (0,1,0),(0,1,1),(0,0,1),(0,-1,1))

while 1:
	n,m,p = map(int,raw_input().split(" "))
	if (n,m,p) == (0,0,0):
		break
	pegs = [[[-1 for k in range(n+1)] for j in range(n+1)] for i in range(n+1)]
	moves = [map(int,raw_input().split(" ")) for i in range(p)]
	MAX = [0,0]
	lb = (1,1,1)
	ub = (n,n,n)
	for i in range(p):
		label = i % 2
		x, y = moves[i]
		z = pegs[y][x][0] + 2
		MAX[label] = max(MAX[label],ds26((x,y,z), delta, lb, ub, pegs, label))
		pegs[y][x][0] += 1
		if MAX[label] >= m:
			print "Black" if label == 0 else "White", i + 1
			break
	else :
		if MAX[0] == MAX[1]:
			print "Draw"
		else:
			print "Black" if MAX[0] > MAX[1] else "White", i+1 