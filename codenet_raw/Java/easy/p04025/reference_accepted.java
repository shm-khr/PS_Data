import java.util.*;

public class Main{
    void solve(){
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++) a[i] = scan.nextInt();
        int out = Integer.MAX_VALUE;
        for(int i = -100; i <= 100; i++){
            int r = 0;
            for(int j = 0; j < n; j++) r += (int)(Math.pow(a[j] - i, 2));
            out = Math.min(out, r);
        }
        System.out.println(out);
    }
    
    public static void main(String[] args){
        new Main().solve();
    }
}
