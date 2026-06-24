k=int(input())
a=list(map(int,input().split()))
sum_a=sum(a)
max_a=max(a)
min_a=min(a)
if max_a>min_a+2:
  print(-1)
  exit()
p=[None]*sum_a
temp0=[]
temp1=[]
if max_a == min_a+2:
  for i in range(k):
    if a[i] ==max_a:
      temp0.append(i+1)
    else:
      temp1.append(i+1)
  fronts=(temp0+temp1+temp0)
  #print(fronts)
  len_f=len(fronts)
  p[:len_f]=fronts
  temp2=[]
  temp3=[]
  for j in range(k):
    if a[j] ==min_a:
      temp2.append(j+1)
    else:
      temp3.append(j+1)
  ends=(temp3+temp2+temp3)
  #print(ends)
  len_e=len(ends)
  p[-len_e:]=ends
  index_i=len_f-k
  if sum(temp1) < sum(temp3):
    for l in range(len_f,sum_a-len_e):
      p[l]=fronts[index_i]
      index_i+=1
      if index_i >=len_f:
        index_i=len_f-k
  else:
    index_i=0
    for l in range(len_e,sum_a-len_e):
      p[l]=ends[index_i]
      index_i+=1
      if index_i >=len_e:
        index_i=0  
elif max_a==min_a:
  fronts=[i for i in range(1,k+1)]
  index_i=0
  p=fronts*min_a
else:
  fronts=[i for i in range(1,k+1)]
  #print(fronts)
  p[:k]=fronts
  temp2=[i for i in range(1,k//2+1)]
  temp3=[]
  for j in range(k//2,k):
    if a[j] ==min_a:
      temp2.append(j+1)
    else:
      temp3.append(j+1)
  ends=(temp3+temp2+temp3)
  #print(ends)
  len_e=len(ends)
  p[-len_e:]=ends
  index_i=0
  for l in range(k,sum_a-len_e):
    p[l]=fronts[index_i]
    index_i+=1
    if index_i >=k:
      index_i=0
print(" ".join((str(x) for x in p)))