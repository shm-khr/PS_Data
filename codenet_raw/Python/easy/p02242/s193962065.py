#coding:utf-8
def Dijkestra(G,n):
    d=[100000000000]*n
    pi=[None]*n
    d[0]=0
    C=[]
    for i in range(n):
        C.append(i)
    
    while len(C)!=0:
        u=C[0]
        for i in range(1,len(C)):
            if d[u]>d[i]:
                u=C[i]
        C.remove(u)
        for i in range(len(G[u])):
            if G[u][i]==-1:
                continue
            elif d[i]>d[u]+G[u][i]:
                d[i]=d[u]+G[u][i]
                pi[i]=u
                        
    for i in range(n):
        print(i,d[i])
    

if __name__=="__main__":
    n=int(input())
    G=[]
    for i in range(n):
        a=[]
        ele=list(map(int,input().split()))
        k=ele[1]
        t=ele[2:]
        v=c=[]
        for j in range(k):
            v=v+[t[2*j]]
            c=c+[t[2*j+1]]
        for j in range(n):
            if j in v:
                a.append(c[v.index(j)])
            else:
                a.append(-1)
        G.append(a)
    Dijkestra(G,n)