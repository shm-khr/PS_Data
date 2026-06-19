# -*- coding: utf-8 -*-

import sys


lineNumber = 0
out = False
#for line in [ "2", "1000", "800", "9999999999", "1" ]:
for line in sys.stdin.readlines():
    lineNumber += 1

    # line exception
    if lineNumber == 1:
        continue
    
    # get data
    List = map(int, line.strip().split())

    # set data
    if lineNumber % 2 == 0: a = line.strip()
    else                  : b = line.strip()


    # sum
    if lineNumber % 2 == 1:
        if not out: out = True
        else      : print

        maxlen = max(len(a), len(b))
        if maxlen > 80:
            print "overflow",
            continue

        upper = 0
        c = ""
        for i in xrange(1, maxlen+1):
            try:
                buf = int(a[-i]) + int(b[-i]) + upper
                upper = buf / 10
                buf %= 10
            except:
                try:
                    buf = int(a[-i]) + upper
                    upper = buf / 10
                    buf %= 10
                except:
                    buf = int(b[-i]) + upper
                    upper = buf / 10
                    buf %= 10
            c = str(buf) + c

        if upper != 0: c = str(upper) + c

        if len(c) > 80: print "overflow",
        else          : print int(c),