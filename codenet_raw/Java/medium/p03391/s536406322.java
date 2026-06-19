import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] array = new int[n][3];
        for (int i = 0; i < n; i++) {
            array[i][0] = sc.nextInt();
            array[i][1] = sc.nextInt();
            array[i][2] = array[i][1] - array[i][0];
        }
        long ans = 0;
        for (int i = 0; i < n; i++) {
            if (array[i][0] < array[i][1]) ans += array[i][1];
        }
        System.out.println(ans);
    }
}
