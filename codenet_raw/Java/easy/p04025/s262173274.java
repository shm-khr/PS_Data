import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here! 
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = sc.nextInt();
        }
        
        int min = 1001001009;
        for (int i = 0; i <= 100; i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                tmp += (array[j] - i) * (array[j] - i);
            }
            
            min = Math.min(min, tmp);
        }
        System.out.println(min);
    }
}