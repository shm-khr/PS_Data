import math

while 1:

    # input the students number
    n = input()
    if n == 0:
        break
    # input the points
    s = map(int, raw_input().split())
    # get the average of points
    ave = 0
    for i in s:
        ave += i
    ave = ave / len(s)
    # get the standard deviation
    alpha = 0
    for i in s:
        alpha += (i - ave)*(i - ave)
    alpha = math.sqrt( alpha/len(s) )
    # print
    print alpha