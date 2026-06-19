import copy

def op(v1,v2):
    vr=(v1[1]*v2[2]-v1[2]*v2[1], v1[2]*v2[0]-v1[0]*v2[2],  v1[0]*v2[1]-v1[1]*v2[0])
    if vr==(0,0,0):
        return v1
    else:
        return vr

class Dice:
    def __init__(self):
        self.vlist=[(1,0,0),(-1,0,0),(0,1,0),(0,-1,0),(0,0,1),(0,0,-1)]
        self.face={}
        self.nums=[]
        for i in (-1,1):
            self.face[(i,0,0)]=0
            self.face[(0,i,0)]=0
            self.face[(0,0,i)]=0
    def rotate(self,v2):
        Nd=copy.deepcopy(self.face)
        for v in self.vlist:
            nv=op(v,v2)
            Nd[nv]=self.face[v]
        self.face=copy.deepcopy(Nd)
        #self.top=op(self.top,v2)
    def fill(self,n):
        self.face[(1,0,0)]=n
        self.nums.append(n)
    def check(self):
        ans=1
        if len(self.nums)!=6:
            ans=0
        else:
            for i in range(1,7):
                if i not in self.nums:
                    ans=0
            if (self.face[(-1,0,0)]+self.face[(1,0,0)]!=7 or self.face[(0,-1,0)]+self.face[(0,1,0)]!=7 or self.face[(0,0,-1)]+self.face[(0,0,1)]!=7):
                ans=0
        return ans
        
def fd(D,A,i,j):
    if A[i][j]!=0:
        D.fill(A[i][j])
        dt=D.vlist
        A[i][j]=0
        if A[i-1][j]!=0:
            D.rotate((0,-1,0))
            fd(D,A,i-1,j)
        if A[i+1][j]!=0:
            D.rotate((0,1,0))
            fd(D,A,i+1,j)    
        if A[i][j-1]!=0:
            D.rotate((0,0,1))
            fd(D,A,i,j-1)
        if A[i][j+1]!=0:
            D.rotate((0,0,-1))
            fd(D,A,i,j+1)
        D.vlist=dt

    
N=int(raw_input())
for p in range(N):
    A=[[0 for i in range(7)] for j in range(7)]
    D=Dice()
    for i in range(1,6):
        A[i][1:6]=[int(x) for x in raw_input().split()]
    for i in range(7):
        for j in range(7):
            if A[i][j]!=0:
                fd(D,A,i,j)
    if D.check():
        print 'true'
    else:
        print 'false'