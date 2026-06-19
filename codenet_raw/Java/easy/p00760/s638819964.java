import java.util.*;

class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int[][] Nissu = new int[1001][11];
        Arrays.fill(Nissu, 0);
        
        for(int i=1;i<=1000;i++){
            if((i%3)==0){
                for(int j=1;j<=10;j++){
                    Nissu[i][j]=20;
                }
            }else{
                for(int j=1;j<=10;j++){
                    if((j%2)==0){
                        Nissu[i][j]=19;
                    }else{
                        Nissu[i][j]=20;
                    }
                }
            }
        }
       
        int n=sc.nextInt();
        for(int i=0;i<n;i++){
            int Y = sc.nextInt();
            int M = sc.nextInt();
            int D = sc.nextInt();
            int count = 0;
            
            for(int j=999;j>Y;j--){
                for(int k=1;k<=10;k++){
                    count += Nissu[j][k];
                }
            }
            
            for(int j=10;j>M;j--){
                count += Nissu[Y][j];
            }
            
            if((Y%3)==0){
                count += (20-D);
            }else if((Y%3)!=0){
                if((M%2)==0){
                    count += (19-D);
                }else{
                    count += (20-D);
                }
            }
            System.out.println(count);
        }
        
    }
} 