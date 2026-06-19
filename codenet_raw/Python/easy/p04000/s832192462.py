H,W,N=map(int,input().split())
ab=[list(map(int,input().split())) for i in range(N)]
ab.sort()

r_b=[0]
rows=[]
for i in range(1,N):
  if ab[i][0]!=ab[i-1][0]:
    r_b.append(i)
    rows.append(ab[i-1][0])
  if i==N-1:
    r_b.append(N)
    rows.append(ab[N-1][0])

cols=[[ab[j][1] for j in range(r_b[i],r_b[i+1])] for i in range(len(r_b)-1)]

rN=len(cols)

ched_box=[[[[False]*3 for k in range(3)] for j in range((len(cols[i]) if i<rN else 0))] for i in range(3)]

area_n=[0]*9

for rn in range(rN):
  cN=len(cols[rn])
  row=rows[rn]

  if rn!=0:
    ched_box[0]=ched_box[1]
    ched_box[1]=ched_box[2]
    if rn<rN-2:
      ched_box[2]=[[[False]*3 for k in range(3)] for j in range(len(cols[rn+2]))]
  
  setcol=[]
  if (rows[rn+1]==row+1 if rn<rN-1 else False):
    row1=row+1
    setcol.append(set(cols[rn+1]))
    if (rows[rn+2]==row+2 if rn<rN-2 else False):
      row2=row+2
      setcol.append(set(cols[rn+2]))
    else:
      row2=None
  elif (rows[rn+1]==row+2 if rn<rN-1 else False):
    row1=row+2
    setcol.append(set(cols[rn+1]))
    row2=None
  else:
    row1=None
    row2=None
  
  for cn in range(cN):
    col=cols[rn][cn]
       
    for boxr in range(3):
      for boxc in range(3):
        if col-2+boxc<1 or col+boxc>W or row-2+boxr<1 or row+boxr>H:
          ched_box[0][cn][boxr][boxc]=True
    find_ab=[]
    for chr in range(row,min(row+3,H+1)):
      if chr==row:
        ch_col=set(cols[rn][cn+1:min(cn+3,cN)])
        for chc in range(min(col+1,W),min(col+3,W+1)):
          if chc in ch_col:
            find_ab.append([row,chc])
      elif chr in [row+1,row+2]:
        if chr==row1:
          ch_col=setcol[0]
        elif chr==row2:
          ch_col=setcol[1]
        else:
          ch_col=[]
        for chc in range(max(col-2,1),min(col+3,W+1)):
          if chc in ch_col:
            find_ab.append([chr,chc])

    
    for boxr in range(3):
      for boxc in range(3):
        if not ched_box[0][cn][boxr][boxc]:
          count=1
          for i in range(3):
            for j in range(3):
              if [row-2+boxr+i,col-2+boxc+j] in find_ab:
                count+=1
                if row-2+boxr+i==row1:
                  rn_tmp=rn+1
                elif row-2+boxr+i==row2:
                  rn_tmp=rn+2
                else:
                  rn_tmp=rn
                ched_box[rn_tmp-rn][cols[rn_tmp].index(col-2+boxc+j)][2-i][2-j]=True
          area_n[count-1]+=1

print((W-2)*(H-2)-sum(area_n))
for i in range(9):
  print(area_n[i])
    