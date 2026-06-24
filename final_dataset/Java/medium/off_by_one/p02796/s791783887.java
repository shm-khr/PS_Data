import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main implements Runnable {

    private static int MOD = 1_000_000_007;

    public static void main(String[] args) {
        // Run with 32MB stack
        Thread thread = new Thread(null, new Main(), "", 32 * 1024 * 1024);
        thread.start();
    }

    @Override
    public void run() {
        final Scanner scanner = new Scanner(System.in);
        solve(scanner);
    }

    static void solve(Scanner scanner) {
        int N = Integer.parseInt(scanner.next());
        long[][] XL = new long[N][2];
        for (int i = 0; i < N; i++) {
            XL[i][0] = Integer.parseInt(scanner.next());
            XL[i][1] = Integer.parseInt(scanner.next());
        }
        Arrays.sort(XL, Comparator.comparingLong(x -> x[0]));

        int cnt1 = 0;
        int prev = 0;
        for (int i = 1; i < N; i++) {
            if (XL[prev][0] + XL[prev][1] - 1 >= XL[i][0] - XL[i][1] + 1) {
                cnt1++;
                if (XL[prev][0] + XL[prev][1] > XL[i][0] + XL[i][1]) {
                    prev = i;
                }
            } else {
                prev = i;
            }
        }

        int cnt2 = 0;
        prev = N - 1;
        for (int i = N - 2; i >= 0; i--) {
            if (XL[i][0] + XL[i][1] - 1 >= XL[prev][0] - XL[prev][1] + 1) {
                cnt2++;
                if (XL[i][0] - XL[i][1] > XL[prev][0] - XL[prev][1]) {
                    prev = i;
                }
            } else {
                prev = i;
            }
        }
        System.out.println(N - Math.min(cnt1, cnt2));
    }
}

