import sys
input = sys.stdin.readline

n,m=map(int,input().split())

E=[[] for i in range(n+1)]

for i in range(m):
    x,y,s=map(int,input().split())
    E[x].append((y,s))
    E[y].append((x,s))

Q=[1]
USE=[-1]*(n+1)
USE[1]=0
FROM=[-1]*(n+1)

flag=1
while Q and flag==1:
    x=Q.pop()
    for to,c in E[x]:
        if USE[to]==USE[x]:
            flag=0
            flagpoint=to
            break
        if USE[to]==-1:
            Q.append(to)
            USE[to]=1-USE[x]
            FROM[to]=x

if flag==0:
    Q=[flagpoint]
    FROM=[-1]*(n+1)
    FROM[flagpoint]=-5
    USE=[-1]*(n+1)
    USE[flagpoint]=0
    flag=1
    while Q and flag==1:
        x=Q.pop()

        for to,c in E[x]:
            if USE[to]==USE[x]:
                flag=0
                break

            if FROM[to]==-1:
                Q.append(to)
                FROM[to]=x
                USE[to]=1-USE[x]

    S1=[to,x]
    while S1[-1]!=flagpoint:
        S1.append((FROM[S1[-1]]))

    S2=[to]
    while S2[-1]!=flagpoint:
        S2.append((FROM[S2[-1]]))

    #print(S1,S2)

    ROOP=S1+S2[1:-1]
    #print(ROOP)

    score=0
    ind=0

    NOW=flagpoint
    for ind in range(len(ROOP)):
        for to,c in E[ROOP[ind-1]]:
            if to==ROOP[ind]:
                score+=c*(-1)**(ind%2)
                break
        #print(score)
    #print(score)

    if score%2!=0:
        print(0)
        sys.exit()

    ANS=[-1]*(n+1)
        
    ANS[flagpoint]=score//2

    Q=[flagpoint]
    USE=[0]*(n+1)

    while Q:
        x=Q.pop()
        for to,c in E[x]:
            if USE[to]==0:
                USE[to]=1
                ANS[to]=c-ANS[x]
                Q.append(to)

    flag=1
    for i in range(n+1):
        for to,c in E[i]:
            if ANS[to]+ANS[i]!=c:
                flag=0
                print(0)
                sys.exit()

    print(1)
    sys.exit()

Q=[1]
score=[-1<<31]*(n+1)
score[1]=0
while Q:
    x=Q.pop()
    for to,c in E[x]:
        if score[to]==-1<<31:
            score[to]=c-score[x]
            Q.append(to)
        else:
            if score[to]!=c-score[x]:
                print(0)
                sys.exit()

MIN0=0
MIN1=1<<31

for i in range(1,n+1):
    if USE[i]==0:
        MIN0=min(MIN0,score[i])
    else:
        MIN1=min(MIN1,score[i])

#print(MIN0,MIN1)
print(max(0,MIN1+MIN0-1))