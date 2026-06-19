import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int k = sc.nextInt();

        int count=0;
        
        while(a>=b){
            b = b*2;
            count++;
        }

        while(b>=c){
            c = c*2;
            count++;
        }

        String res;
        
        if(count<=k){
            res = "Yes";
        }else{
            res = "No";
        }
        System.out.println(res);
        
        
        
        
        
        }
    }