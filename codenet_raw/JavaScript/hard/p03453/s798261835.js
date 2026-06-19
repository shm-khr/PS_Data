import java.io.*; 
  
class Gift  
{ 
    static void point(int a, int b, int c, int d, int n) 
    { 
        int x , flag = 0; 
  
        for (int i = 0; i < n; i++) 
        { 
              
        
            x = b + i * a;  
              
        
            if ((x - d) % c == 0 && x - d >= 0) 
            { 
                System.out.println( x ) ; //input//
                flag = 1; 
                break; 
            } 
          
        } 
      
 
        if(flag == 0) 
        { 
            System.out.println ("No collision point"); 
        } 
      
          
    }