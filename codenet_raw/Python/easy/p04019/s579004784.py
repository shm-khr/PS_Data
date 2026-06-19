s=input()
ans=[0]*4
check='NWSE'
for i in range(len(s)):
  for j in range(len(check)):
    if s[i]==check[j]:
      ans[j]+=1
if ans[0]!=0 and ans[1]!=0 and ans[2]!=0 and ans[3]!=0:
  print('Yes')
else:
  print('No')