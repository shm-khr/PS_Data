import java.util.Scanner;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        new Main().solve();
    }

    void solve() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int[] A = new int[N];
        int ans = 0;
        int c = 0;
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
            if (A[i] == 1) {
                ans = i + 1;
            }
        }
        c = 1;
        for (int i = ans - 1; i > 1; i = i - (K - 1)) {
            c++;
        }
        for (int i = ans + 1; i < N; i = i + (K - 1)) {
            c++;
        }
        if (ans == 1 || ans == N) {
            c = N / K;
            if (N % K != 0) {
                c++;
            }
        }
        System.out.println(c);
    }

}