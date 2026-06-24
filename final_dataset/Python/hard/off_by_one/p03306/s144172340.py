import sys
input = sys.stdin.readline

def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def main():
    mod=10**9+7
    N,M=MI()
    adj=[[]for _ in range(N)]
    for i in range(M):
        u,v,s=MI()
        u-=1
        v-=1
        adj[u].append((v,s))
        adj[v].append((u,s))
    
    #　頂点0を根として，ここの値aとする，各頂点Xa+Cの形で表して，最大値と最小値の候補を絞っていく．ループがあるかをしっかり判断
    
    # Xはaの係数，1orー１が入る．0ならまだ見ていない
    X=[0]*N
    C=[0]*N
    
    X[0]=1
    
    floor=1
    ceil=10**9
    
    import queue
    q=queue.Queue()
    q.put((0,-1))#v,p
    
    while not q.empty():
        v,p=q.get()
        
        
        for nv,s in adj[v]:
            if nv!=p:
                if X[nv]==0:
                    q.put((nv,v))
                nx=X[v]*(-1)
                nc=s-C[v]
                
                #見巡回の頂点なら
                if X[nv]==0 and C[nv]==0:
                    X[nv]=nx
                    C[nv]=nc
                    
                    # aの係数が正ならば，下限を更新
                    if nx==1:
                        floor=max(floor,-1*nc)
                        
                    #aの係数が負ならば上限を更新
                    else:
                        ceil=min(ceil,nc-1)
                        
                else:
                    # 既存のものと変わらなければ何もしない
                    if nx==X[nv] and nc==C[nv]:
                        pass
                    #係数が同じで定数部分が違えば無理
                    elif nx==X[nv]:
                        ceil=-1
                    #係数が違う場合，一意に決まる
                    else:
                        ac=0#係数が正の方の定数
                        bc=0#係数が負の方の定数
                        if nx==1:
                            ac=nc
                            bc=C[nv]
                        else:
                            ac=C[nv]
                            bc=nc
                        
                        # 2*aの値
                        aa=bc-ac
                        
                        if aa<=0 or aa%2==1:
                            ceil=-1
                        else:
                            ceil=ceil=min(ceil,aa//2)
                            floor=max(floor,aa//2)
                #print(nv,floor,ceil)
                            
    ans=ceil-floor+1
    if ans<=0:
        ans=0
    print(ans)
    
    
                            

                        
    

main()
