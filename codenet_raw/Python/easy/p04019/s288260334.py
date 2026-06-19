s = input()
d = {'S':0,'N':0,'E':0,'W':0}
for i in s:
    d[i] += 1
ns = d['S'] > 0 ^ d['N'] > 0
ew = d['E'] > 0 ^ d['W'] > 0
if ns and ew:
    print('No')
else:
    print('Yes')