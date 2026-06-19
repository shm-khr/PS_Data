import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();
        int K = sc.nextInt();
        if (N + 1 < 2 * K) {
            System.out.println(-1);
            return;
        }
        PrintWriter writer = new PrintWriter(System.out);
//        int[] lo = new int[N];
//        int[] hi = new int[N];
//        for (int i = 0; i < N; i++) {
//            lo[i] = i;
//            hi[i] = N + i;
//        }
//        for (int i = 0; i < N / 2 / 2; i++) {
//            int tmp = lo[i];
//            lo[i] = lo[(N - 1) / 2 - i];
//            lo[(N - 1) / 2 - i] = tmp;
//            tmp = lo[N - 1 - i];
//            lo[N - 1 - i] = lo[(N + 1) / 2 + i];
//            lo[(N + 1) / 2 + i] = tmp;
//        }
//        for (int i = 0; i < N / 2; i++) {
//            int tmp = hi[i];
//            hi[i] = hi[N / 2 + i];
//            hi[N / 2 + i] = tmp;
//        }
//        for (int i = 0; i < N; i++) {
//            writer.printf("%d %d %d\n", lo[i] + K, hi[i] + K, 2 * N + K + i);
//        }

        TreeSet<Integer> min = new TreeSet<>();
        TreeSet<Integer> max = new TreeSet<>();
        for (int i = 0; i < N; i++) {
            min.add(K + i);
            max.add(N + K + i);
        }
        for (int i = 0; i < N; i++) {
            int sum = 2 * N + K + i;
            int lo = min.last();
            int hi = max.first();
//            System.err.println(max + " " + target + " " + mf);
            if (hi + lo > sum) {
                lo = min.lower(sum - hi + 1);
                min.remove(lo);
                hi = max.lower(sum - lo + 1);
                max.remove(hi);
                writer.printf("%d %d %d\n", lo, hi, sum);
            } else {
                hi = max.lower(sum - lo + 1);
                max.remove(hi);
                lo = min.lower(sum - hi + 1);
                min.remove(lo);
                writer.printf("%d %d %d\n", lo, hi, sum);
            }
        }
        writer.flush();
    }

}
