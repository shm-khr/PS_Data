
def abc_3() :
	H, W = map(int, input().split())
	print (min(div_3(H, W), div_3(W, H), div_s(H, W), div_s(W, H)))

def div_3(H, W) :
	if W % 3 == 0 :
		return 0
	else :
		return 10000000000

def div_s(H, W) :
	min_diff = 10000000000
	for w in range(1, W) :
		s1 = w * H
		s2 = (W - w) * (H // 2)
		s3 = W * H - s2 - s1
		diff = max(s1, s2, s3) - min(s1, s2, s3)
		if diff < min_diff :
			min_diff = diff
	return min_diff

#for i in range(5) :
#	abc_3()
#	print ('input:', end = '')
#	if input() == 'q' :
#		exit()

abc_3()