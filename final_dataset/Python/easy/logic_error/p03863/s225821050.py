s = raw_input()
i = 0
counter = 0
flag = True
while(True):
    if flag == False or len(s) == 2:
        break
    for i in range(len(s)-2):
        if s[i] != s[i+2]:
            s = s[:x] + s[x+1:]
#             print s
            counter += 1
            flag = True
            break
        else:
            flag = False
if counter % 2 == 0:
    print "Second"
else:
    print "First"