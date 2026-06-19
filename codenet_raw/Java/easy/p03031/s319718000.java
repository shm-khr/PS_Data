import java.util.*;

public class Main {
    static boolean[] bits;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        boolean[][] input=new boolean[m][n];
        bits=new boolean[n];
        int[] p=new int[m];
        int k;
        for(int i=0;i<m;i++){
          k=sc.nextInt();
          for(int j=0;j<k;j++){
            input[i][sc.nextInt()-1]=true;
          }
        }
        for(int i=0;i<m;i++){
          p[i]=sc.nextInt();
        }
        int tmp1;
        boolean tmp2;
        int ans=0;
        for(int i=0;i<Math.pow(2,n);i++){
          tmp2=false;
          for(int j=0;j<m;j++){
            tmp1=0;
            for(int l=0;l<n;l++){
              if(input[j][l]&&bits[l])tmp1++;
            }
            tmp2&=tmp1%2==p[j];
          }
          if(tmp2)ans++;
          if(i!=Math.pow(2,n)-1)update(0);
        }
        System.out.println(ans);

    }
    static void update(int pointer){
        if(!bits[pointer]){
            bits[pointer]=true;
        }else{
            bits[pointer]=false;
            update(pointer+1);
        }
    }
}
