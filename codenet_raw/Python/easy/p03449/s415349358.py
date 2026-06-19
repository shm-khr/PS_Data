N=int(input_[0])
A1 =  list(map(int,input().split()))
A2 =  list(map(int,input().split()))

A2.reverse()

# 累積和
A1_=[]
A2_=[]

a1_=0
a2_=0
for n in range(N):
    a1_ = a1_+A1[n]
    a2_ = a2_+A2[n]
    
    A1_.append(a1_)
    A2_.append(a2_)
    
A2_.reverse()

ans=0
for n in range(N):
    if ans < A1_[n]+A2_[n]:
        ans = A1_[n]+A2_[n]
print(ans)