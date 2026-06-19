import sys

EPS = 1e-9

def normalize(x):
    return 2 * (x + 20)

def check(seg, r, t):

    for x in range(40 - r, 40 + r + 1):
        ok = False
        for s in seg:
            if s[2] < t - r:
                #print("over!!!! x:{}, s[2]:{}, t-r:{}",x,s[2],t-r)
                return False
            if s[0] <= x and x <= s[1]:
                k1 = (s[0] - 40)**2 + (s[2] - (t - r))**2
                k2 = (s[1] - 40)**2 + (s[2] - (t - r))**2
                #print("\tx:{}\ts[2]:{}\tt/2:{}\tr:{}\tk1:{}\tk2:{}\tkk:{}".format(x, s[2], t/2, r, k1, k2,kk))
                if k1 >= r*r and k2 >= r*r:
                    ok = True
                    break

        if not ok:
            return False

    return True

def main():

    while True:
        r,n = map(int, sys.stdin.readline().split())
        if r == 0 and n == 0:
            break

        seq = [0] * 100 # 2?????§?¨??????????
        for i in range(n):
            x1,x2,h = map(int, sys.stdin.readline().split())
            for x in range(normalize(x1), normalize(x2) + 1):
                seq[x] = max(seq[x], 2*h)

        prev = 0
        st = 0
        seg = []
        for i in range(100):
            if prev != seq[i]:
                if i % 2 == 0 :
                    seg.append( [st, i, prev] )
                    st = i
                else:
                    seg.append( [st, i - 1, prev] )
                    st = i - 1
                prev = seq[i]

        # ????????????????????¨?????????????????????????????????????????§?????????append?????????
        # ??????1??\?????????????????\???
        r *= 2
        seg = [ x for x in seg if x[2] > 0 and (40 - r <= x[0] or x[1] <= 40 + r)]

        # ????????§?¨???????????????????????????????????????????????????????
        for i in range(len(seg) - 1):
            if seg[i][1] == seg[i + 1][0]:
                if seg[i][2] > seg[i + 1][2]:
                    seg[i + 1][0] += EPS
                elif seg[i][2] < seg[i + 1][2]:
                    seg[i][1] -= EPS
        
        #print(seg)

        tl = 0.0
        tr = 40.0
        for k in range(60):
            tm = (tr + tl) / 2.0
            if check(seg, r, tm):
                tl = tm
            else:
                tr = tm

        print("{0:.4f}".format(tl / 2))




if __name__ == '__main__':
    main()