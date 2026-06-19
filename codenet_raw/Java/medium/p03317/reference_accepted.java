

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        if(n == k) {
            System.out.println(1);
            return;
        } else if(k == 2) {
            System.out.println(n - 1);
        } else if(k == 3) {
            System.out.println(n / 2);
        } else {
            int ans = n / (k - 1);
            if(n % (k - 1) != 0) ans++;
            System.out.println(ans);
        }
    }
}