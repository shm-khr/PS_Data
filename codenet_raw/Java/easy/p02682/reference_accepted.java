import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int k = sc.nextInt();
        
        int ans = 0;
        if (k >= a){
            ans += a;
            k = k - a;
        }else{
            ans += k;
            k = 0;
            System.out.println(ans);
            return;
        }
        
        if (k >= b){
            k = k - b;
        }else{
            k = 0;
            System.out.println(ans);
            return;
        }
        
        if (k >= c){
            ans -= c;            
        }else{
            ans -= k;
        }

        System.out.println(ans);

    }
}
