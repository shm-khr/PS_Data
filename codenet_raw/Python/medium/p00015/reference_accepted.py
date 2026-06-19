n = int(raw_input())
for i in range(n):
    a = long(raw_input())
    b = long(raw_input())
    tmp = str(a+b)
    if len(tmp) > 80:
        print "overflow"
    else:
        print tmp
