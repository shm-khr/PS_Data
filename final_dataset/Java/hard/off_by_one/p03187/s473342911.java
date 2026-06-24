
import java.io.PrintStream;
import java.util.Scanner;
public class Main {
    private static final PrintStream so = System.out;
    private static final Scanner     sc = new Scanner(System.in);

    public static void main(String[] args) {
        int L = sc.nextInt();
        int N = sc.nextInt();
        int[] trees = new int[N];
        for (int i = 0; i < N; i++) {
            trees[i] = sc.nextInt();
        }
        if (N > 2000) {
            return;
        }
        if (N == 1)  {
            so.println(Math.max(d(0, trees[0], true, L), d(0, trees[0], false, L)));
            return;
        }
        
        long max = 0;
        for (int i = 1; i < N; i++) {
            
            int temp = d(0, trees[i], CLOCKWISE, L);
            long sum = calcMax(trees, i, i-1, 0, L);
            max = Math.max(max, sum+temp);
        }
        
        for (int i = 0; i < N-1; i++) {
            int temp = d(0, trees[i], COUNTER_CLOCKWISE, L);
            long sum = calcMax(trees, i, N-1, i+1, L);
            max = Math.max(max, sum+temp);
        }
        so.println(max);
    }
    
    static boolean CLOCKWISE = true;
    static boolean COUNTER_CLOCKWISE = false;
    public static long calcMax(int[] trees, int startI, int maxI, int minI, int L) {
        long sum_clockwise_start = 0;
        int current = startI;
        int next_max = maxI;
        int next_min = minI;
        while (true) {
            // 時計回りから
            sum_clockwise_start += d(trees[current], trees[next_max], CLOCKWISE, L);
//            so.println("sum = " + sum_clockwise_start);
            current = next_max;
            next_max--;
            if (next_max < next_min) break;
            
            sum_clockwise_start += d(trees[current], trees[next_min], COUNTER_CLOCKWISE, L);
//            so.println("sum = " + sum_clockwise_start);
            current = next_min;
            next_min++;
            if (next_max < next_min) break;
        }
        
        long sum_counterclockwise_start = 0;
        current = startI;
        next_max = maxI;
        next_min = minI;
        while (true) {
//            so.println("current = " + current + ", n_max = " + next_max + ", n_min = " + next_min);
            // 反時計周りから
            sum_counterclockwise_start += d(trees[current], trees[next_min], COUNTER_CLOCKWISE, L);
//            so.println("sum2 = " + sum_counterclockwise_start);
            current = next_min;
            next_min++;
            if (next_max < next_min) break;
            
//            so.println("current = " + current + ", n_max = " + next_max + ", n_min = " + next_min);
            sum_counterclockwise_start += d(trees[current], trees[next_max], CLOCKWISE, L);
//            so.println("sum2 = " + sum_counterclockwise_start);
            current = next_max;
            next_max--;
            if (next_max < next_min) break;
        }
        
        return Math.max(sum_clockwise_start, sum_counterclockwise_start);
    }
    
    public static int d(int from, int to, boolean clockwise, int L) {
        if (clockwise) {
            int temp = from - to;
            if (temp < 0) temp += L;
            return temp;
        } else {
            return d(to, from, CLOCKWISE, L);
        }
    }
}
