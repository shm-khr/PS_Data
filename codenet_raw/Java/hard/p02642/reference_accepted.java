import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] minfactor = new int[1000001];
        boolean[] ng = new boolean[1000001];
        for (int i = 0; i < n; i++) {
            int num = sc.nextInt();
            if (minfactor[num] == 0) {
                minfactor[num] = num;
            } else {
                ng[num] = true;
            }
        }
        
        int ans = 0;
        for (int i = 1; i < 1000001; i++) {
            if (minfactor[i] == i) {
                if (!ng[i]) ans ++;
                
                for (int j = i; j < 1000001; j += i) {
                    minfactor[j] = i;
                }
            }
        }
        System.out.println(ans);
    }
}
