H,W,N = [int(input()) for i in range(3)]
for o in range(1,10000):
  if H < W and N / o <= W:
    break
  elif H > W and N / o <= H:
    break
print(o)
    
  
  

   
    
    
    





	

  
  
  

