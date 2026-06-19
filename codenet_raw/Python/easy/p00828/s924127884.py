mv=(((1,0,0)  ,(-1,0,0))  ,#move x direction                                                    
    ((0,1,0)  ,(0,-1,0))  ,#move y direction                                                    
    ((0,0,1)  ,(0,0,-1))  ,#move z direction                                                    
    ((1,1,0)  ,(-1,-1,0)) ,#move xy direction y=-x+a                                            
    ((1,-1,0) ,(-1,1,0))  ,#move xy direction y=x+b                                             
    ((1,0,1)  ,(-1,0,-1)) ,#move xz direction x z same increase                                 
    ((1,0,-1) ,(-1,0,1))  ,#move xz direction x increase z decrease                             
    ((0,1,1)  ,(0,-1,-1)) ,#move yz direction y z same increase                                 
    ((0,1,-1) ,(0,-1,1))  ,#move yz direction y increase z decrease                             
    ((1,1,1)  ,(-1,-1,-1)),
    ((1,1,-1) ,(-1,-1,1)) ,
    ((1,-1,1) ,(-1,1,-1)) ,
    ((1,-1,-1),(-1,1,1)))

def check(L,y,x,z,color):
    for line in mv:
        cnt=1
        tx,ty,tz=x,y,z
        for dx,dy,dz in line:
            while (0<=x+dx<n) and (0<=y+dy<n) and (0<=z+dz<len(L[y+dy][x+dx])) and L[y+dy][x+dx\
][z+dz]==color:
                cnt+=1
                x+=dx
                y+=dy
                z+=dz
            x,y,z=tx,ty,tz
        if cnt>=m:
            return True
    return False

while True:
    n,m,p=map(int,raw_input().split())
    if n==m==p==0:break
    L=[[[] for i in range(n)] for i in range(n)]
    data=[map(int,raw_input().split()) for i in range(p)]
    for i in range(len(data)):
        x,y=data[i][0],data[i][1]
        L[y-1][x-1].append(i%2)
        z=len(L[y-1][x-1])
        if check(L,y-1,x-1,z-1,i%2):
            if i%2:
                print "White",i+1
            else:
                print "Black",i+1
            break