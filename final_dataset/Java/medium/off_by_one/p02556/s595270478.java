

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Random;
import java.util.StringTokenizer;

public final class Main {

    public static void main(String[] args) {
        final FastScanner fs = new FastScanner();
        final int n = fs.nextInt();
        int[][] byX = new int[n][2];
        int[][] byY = new int[n][2];
        for (int i = 0; i < n; i++) {
            int l = fs.nextInt();
            int r = fs.nextInt();
            byX[i] = new int[] { l, r };
            byY[i] = new int[] { l, r };
        }
        Arrays.sort(byX, Comparator.comparingInt(a -> a[0]));
        Arrays.sort(byY, Comparator.comparingInt(a -> a[1]));
        long max = (long) -5e18;
        max = Math.max(max, dist(byX[0], byX[n - 1]));
        max = Math.max(max, dist(byX[0], byY[n - 1]));
        max = Math.max(max, dist(byY[0], byY[n - 1]));
        max = Math.max(max, dist(byY[0], byX[n - 1]));
        System.out.println(max);
    }

    private static long dist(int[] l, int[] r) {
        return Math.abs((long) l[0] - r[0]) + Math.abs((long) l[1] - r[1]);
    }

    static final class Util {
        public static void shuffleSort(int[] x) {
            shuffle(x);
            Arrays.sort(x);
        }

        public static void shuffleSort(long[] x) {
            shuffle(x);
            Arrays.sort(x);
        }

        public static void shuffle(int[] x) {
            final Random r = new Random();

            for (int i = 0; i <= x.length - 2; i++) {
                final int j = i + r.nextInt(x.length - i);
                swap(x, i, j);
            }
        }

        public static void shuffle(long[] x) {
            final Random r = new Random();

            for (int i = 0; i <= x.length - 2; i++) {
                final int j = i + r.nextInt(x.length - i);
                swap(x, i, j);
            }
        }

        public static void swap(int[] x, int i, int j) {
            final int t = x[i];
            x[i] = x[j];
            x[j] = t;
        }

        public static void swap(long[] x, int i, int j) {
            final long t = x[i];
            x[i] = x[j];
            x[j] = t;
        }

        private Util() {}
    }

    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        private String next() {
            while (!st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    //noinspection CallToPrintStackTrace
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        int[] nextIntArray(int n) {
            final int[] a = new int[n];
            for (int i = 0; i < n; i++) { a[i] = nextInt(); }
            return a;
        }

        long[] nextLongArray(int n) {
            final long[] a = new long[n];
            for (int i = 0; i < n; i++) { a[i] = nextLong(); }
            return a;
        }
    }
}
