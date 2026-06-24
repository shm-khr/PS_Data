
import java.io.*;
import java.util.*;

public class Main {
    public static class Task {
        int k;
        public int BronKerbosch(long[] g, long cur, long allowed, long forbidden) {
            if (allowed == 0 && forbidden == 0) {
                int res = 0;
                for (int u = Long.numberOfTrailingZeros(cur); u < g.length; u += Long.numberOfTrailingZeros(cur >> (u + 1)) + 1)
                    res++;
                return res;
            }
            if (allowed == 0)
                return -1;
            int res = -1;
            int pivot = Long.numberOfTrailingZeros(allowed | forbidden);
            long z = allowed & ~g[pivot];
            for (int u = Long.numberOfTrailingZeros(z); u < g.length; u += Long.numberOfTrailingZeros(z >> (u + 1)) + 1) {
                res = Math.max(res, BronKerbosch(g, cur | (1L << u), allowed & g[u], forbidden & g[u]));
                if (res >= k) return res;
                allowed ^= 1L << u;
                forbidden |= 1L << u;
            }
            return res;
        }

        boolean con(int[][] point, int i, int j, double x) {
            double dx = point[i][0] - point[j][0];
            double dy = point[i][1] - point[j][1];
            return dx * dx + dy * dy <= (x / point[i][2] + x / point[j][2]) * (x / point[i][2] + x / point[j][2]);
        }

        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            int n = sc.nextInt();
            k = sc.nextInt();
            int[][] point = new int[n][3];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 3; j++) {
                    point[i][j] = sc.nextInt();
                }
            }
            double lo = 0.0, hi = 2e6;
            while (lo < hi - 1e-8) {
                double mid = (lo + hi) / 2;
                long[] g = new long[n];
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) if(i != j) {
                        if (con(point, i, j, mid)) {
                            g[i] |= 1L << j;
                        }
                    }
                }
                if (BronKerbosch(g, 0, (1L << n) - 1, 0) >= k) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }
            pw.println(lo);
        }
    }

    static long TIME_START, TIME_END;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
//        Scanner sc = new Scanner(new FileInputStream("input"));
        PrintWriter pw = new PrintWriter(new BufferedOutputStream(System.out));
//        PrintWriter pw = new PrintWriter(new FileOutputStream("input"));

        Runtime runtime = Runtime.getRuntime();
        long usedMemoryBefore = runtime.totalMemory() - runtime.freeMemory();
        TIME_START = System.currentTimeMillis();
        Task t = new Task();
        t.solve(sc, pw);
        TIME_END = System.currentTimeMillis();
        long usedMemoryAfter = runtime.totalMemory() - runtime.freeMemory();
        pw.close();
        System.err.println("Memory increased: " + (usedMemoryAfter - usedMemoryBefore) / 1000000);
        System.err.println("Time used: " + (TIME_END - TIME_START) + ".");
    }

    static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }

        public Scanner(FileReader s) throws FileNotFoundException {
            br = new BufferedReader(s);
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public String nextLine() throws IOException {
            return br.readLine();
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        public boolean ready() throws IOException {
            return br.ready();
        }
    }
}