import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Knapsack solver = new Knapsack();
        solver.solve(1, in, out);
        out.close();
    }

    static class Knapsack {
        int N;
        int maxW = (int) (1e5);
        int[][] pre;
        int[] W;
        int[] V;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            N = in.nextInt();
            pre = new int[N + 1][];
            V = new int[N + 1];
            W = new int[N + 1];
            for (int i = 1; i <= N; i++) {
                V[i] = in.nextInt();
                W[i] = in.nextInt();
            }
            int Q = in.nextInt();
            preProcess(1, 0);
            while (Q-- > 0) {
                out.println(solve(in.nextInt(), in.nextInt()));
            }
        }

        void preProcess(int n, int d) {
            if (n > N) {
                return;
            }
            if (d > 8) {
                return;
            }
            pre[n] = new int[maxW + 1];
            int p = n / 2;
            if (p != 0) {
                for (int i = 0; i < W[n]; i++) {
                    pre[n][i] = pre[p][i];
                }
                for (int i = W[n]; i <= maxW; i++) {
                    pre[n][i] = Math.max(pre[n][i - 1], Math.max(pre[p][i], pre[p][i - W[n]] + V[n]));
                }
            } else {
                for (int i = W[n]; i <= maxW; i++) {
                    pre[n][i] = V[n];
                }
            }
            preProcess(2 * n, d + 1);
            preProcess(2 * n + 1, d + 1);
        }

        int solve(int n, int L) {
            if (L < 0) {
                return Integer.MIN_VALUE;
            }
            if (pre[n] != null) {
                return pre[n][L];
            }
            return Math.max(solve(n / 2, L), solve(n / 2, L - W[n]) + V[n]);
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}

