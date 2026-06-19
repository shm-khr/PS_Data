while True:
  lst=[]
  pt=0
  H=int(input()) 
  for i in range(H):
   lst.append(list(map(int,input().split())))
  for s in lst:
    for s2 in range(0,3):
     if s[s2] != s and s[s2] == s[s2+1] == s[s2+2]:
       x=s[s2]
       pt += s[s2]*s.count(x)
       for h in range(0,s.count(x)):
         s[s.index(x)]=0
       for g in lst:
         for f in range(5):
           try:
             if g[f]==0:
                 lst.reverse()
                 g[f]=lst[lst.index(g)-1][f]
                 ls[ls.index(g)-1]
             else:
               pass
           except:
             break
  print(pt)
  
      