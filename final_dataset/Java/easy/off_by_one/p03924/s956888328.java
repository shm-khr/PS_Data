import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public int n;
        public int m;
        public int mod = 1000000007;
        public long[][][] dp;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            dp = new long[m + 1][n + 1][n + 1];
            for (long[][] y : dp) for (long[] x : y) Arrays.fill(x, -1);
            long ans = count(m, 1, 0);
            out.println(ans);
        }

        public long count(int slots, int in, int out) {
            if (dp[slots][in][out] != -1) return dp[slots][in][out];
            if (slots == 0) return in == n ? 1 : 0;
            long ret = 0;
            // go inside
            if (in > 0) ret += in * count(slots - 1, in + out, 0);
            // go outside1
            if (out > 0) ret += out * count(slots - 1, in, out);
            // go outside2
            if (n - in - out > 0) ret += (n - in - out) * count(slots - 1, in, out + 1);

            return dp[slots][in][out] = ret % mod;
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

