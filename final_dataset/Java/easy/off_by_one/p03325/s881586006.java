import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            solve(sc);
        }
    }

    public static void solve(Scanner sc) {
        int n = sc.nextInt();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int num = sc.nextInt();
            if (num % 2 == 0) {
                ans += num / 2;
            }
        }
        System.out.println(ans);
    }
}