x1,y1,x2,y2=map(float,raw_input().split(" "))
for i in xrange(int(raw_input())):
    px,py=map(float,raw_input().split(" "))
    dxa=(x2-x1)
    dya=(y2-y1)
    da=dxa**2+dya**2
    dxb=(px-x1)
    dyb=(py-y1)
    ip=dxb*dxa+dya*dyb
    r=ip/da
    kouten_x=x1+r*dxa
    kouten_y=y1+r*dya
    ref_x=px+2.0*(kouten_x-px)
    ref_y=py+2.0*(kouten_y-py)
    print "{0:.10f} {1:.10f}".format(ref_x,ref_y)