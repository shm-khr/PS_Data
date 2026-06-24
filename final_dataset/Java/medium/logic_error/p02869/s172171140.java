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
        TreeSet<Integer> min = new TreeSet<>();
        TreeSet<Integer> sum = new TreeSet<>();
        for (int i = 0; i < N; i++) {
            min.add(K + i);
            sum.add(2 * N + K + i);
        }
        for (int i = 0; i < N; i++) {
            int max = 2 * N + K - 1 - i;
            int target = sum.first();
            int mf = min.first();
//            System.err.println(max + " " + target + " " + mf);
            if (mf + max > target) {
                int rt = sum.higher(mf + max - 1);
                mf = min.lower(rt - max + 1);
//                System.err.println("rt:" + rt + " mf:" + mf);
                min.remove(mf);
                sum.remove(rt);
                writer.printf("%d %d %d\n", mf, max, rt);
            } else {
                min.remove(mf);
                sum.remove(target);
                writer.printf("%d %d %d\n", mf, max, target);
            }
        }
        writer.flush();
    }

}
