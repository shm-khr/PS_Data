H,W,N=map(int,input().split())
ab=[list(map(int,input().split())) for i in range(N)]
ab.sort()

r_b=[0]
rows=[]
for i in range(1,N):
  if ab[i][0]!=ab[i-1][0]:
    r_b.append(i)
    rows.append(ab[i-1][0])

if N>0:
  rows.append(ab[N-1][0])
  r_b.append(N)

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
  
  dic_cn=[dict(zip(cols[rn],list(range(cN))))]
  if (rows[rn+1]==row+1 if rn<rN-1 else False):
    row1=row+1
    cN1=len(cols[rn+1])
    dic_cn.append(dict(zip(cols[rn+1],list(range(cN1)))))
    if (rows[rn+2]==row+2 if rn<rN-2 else False):
      row2=row+2
      cN2=len(cols[rn+2])
      dic_cn.append(dict(zip(cols[rn+2],list(range(cN2)))))
    else:
      row2=None
  elif (rows[rn+1]==row+2 if rn<rN-1 else False):
    row1=row+2
    cN1=len(cols[rn+1])
    dic_cn.append(dict(zip(cols[rn+1],list(range(cN1)))))
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
    find_rowcol=[]
    for ch_row in range(row,min(row+3,H+1)):
      if ch_row==row:
        for ch_col in range(col+1,min(col+3,W+1)):
          if ch_col in dic_cn[0]:
            find_rowcol.append([row,ch_col])
      elif ch_row==row1:
        for ch_col in range(max(col-2,1),min(col+3,W+1)):
          if ch_col in dic_cn[1]:
            find_rowcol.append([row1,ch_col])
      elif ch_row==row2:
        for ch_col in range(max(col-2,1),min(col+3,W+1)):
          if ch_col in dic_cn[2]:
            find_rowcol.append([row2,ch_col])
            
    count=[[1]*3 for i in range(3)]

    for [find_row,find_col] in find_rowcol:

      if find_row==row:
        ch_rn=0
        ch_cn=dic_cn[0][find_col]
      elif find_row==row1:
        ch_rn=1
        ch_cn=dic_cn[1][find_col]
      elif find_row==row2:
        ch_rn=2
        ch_cn=dic_cn[2][find_col]
      for box_row in range(find_row-row,3):
        for box_col in range(max(find_col-col,0),min(3,3+find_col-col)):
          if not ched_box[0][cn][box_row][box_col]:
            count[box_row][box_col]+=1
            ched_box[ch_rn][ch_cn][box_row-find_row+row][box_col-find_col+col]=True
    for box_row in range(3):
      for box_col in range(3):
        if not ched_box[0][cn][box_row][box_col]:
          area_n[count[box_row][box_col]-1]+=1



print((W-2)*(H-2)-sum(area_n))
for i in range(9):
  print(area_n[i])


