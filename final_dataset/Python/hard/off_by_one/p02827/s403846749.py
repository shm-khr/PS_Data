



from sys import exit

ii = lambda : int(input())
mi = lambda : map(int,input().split())
li = lambda : list(map(int,input().split()))


def main():
    n,m,t = mi()
    x = []
    y = []
    ansl = [0 for i in range(n+1)]
    for i in range(m):
        tmpl = li()
        xtmp,ytmp = min(tmpl),max(tmpl)
        x.append(xtmp)
        y.append(ytmp)
    if t == 2:
        print(-1)



    ans = ""
    tmp = [x[-1],y[-1]]
    del x[-1]
    del y[-1]

    ansl[tmp[0]] = 1
    ansl[tmp[1]] = 1
    ans+= '^'

    for i in range(m-1):
        tmp = [x[-1],y[-1]]
        del x[-1]
        del y[-1]
        flag = True
        if ansl[tmp[0]] == 1:
            ans = 'v'+ans
            ansl[tmp[1]] = 1
            flag = False
        elif ansl[tmp[1]] ==1:
            ans = '^'+ans
            ansl[tmp[0]] = 1
            flag = False
        
        if flag:
            print(-1)
            exit()
        
    for i in range(1,n+1):
        if ansl[i] == 0:
            print(-1)
            exit()

    print(ans)



    


    
main()
