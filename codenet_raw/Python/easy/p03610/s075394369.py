s = input()
print(''.join([x[2*i+1] for x,i in zip(s, range(0,(len(s)+1)/2))])