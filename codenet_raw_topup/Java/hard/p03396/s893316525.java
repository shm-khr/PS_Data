// package agc.agc022;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    private static final long INF = 1L<<60;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        long L = in.nextInt();
        if (n > 3000) {
            out.println("");
            return;
        }
        long[] x = new long[n];
        for (int i = 0; i < n ; i++) {
            x[i] = in.nextInt();
        }
        long[] t = new long[n];
        for (int i = 0; i < n ; i++) {
            t[i] = in.nextInt();
        }

        long[][][] rev = new long[2][2][n];
        for (int i = 0; i < n ; i++) {
            long pos0 = x[i];
            long pos1 = (2 * L - x[i]);

            long left = (x[i] + t[i]) % (2 * L);
            long right = (2 * L - x[i] + t[i]) % (2 * L);

            rev[0][0][i] = (left <= pos0) ? (pos0 - left) : (2 * L - left + pos0);
            rev[0][1][i] = (left <= pos1) ? (pos1 - left) : (2 * L - left + pos1);
            rev[1][0][i] = (right <= pos0) ? (pos0 - right) : (2 * L - right + pos0);
            rev[1][1][i] = (right <= pos1) ? (pos1 - right) : (2 * L - right + pos1);
        }

//        debug(rev[0][0]);
//        debug(rev[0][1]);
//        debug(rev[1][0]);
//        debug(rev[1][1]);

        long[][] dp = new long[2][n+1];
        Arrays.fill(dp[0], INF);
        Arrays.fill(dp[1], INF);
        dp[0][1] = x[0] * 2;

        for (int i = 0; i < n ; i++) {
            int fr = i % 2;
            int to = 1 - fr;
            long diff = ((i == n-1) ? L : x[i+1]) - x[i];
            Arrays.fill(dp[to], INF);
            for (int j = 0; j <= n; j++) {
                if (dp[fr][j] == INF) {
                    continue;
                }
                long base = dp[fr][j];

                dp[to][j] = Math.min(dp[to][j], base + Math.min(rev[0][0][i], rev[1][1][i]) + diff * j * 2);

                if ((j-1 >= 1) || (i == n-1 && j-1 == 0)) {
                    dp[to][j-1] = Math.min(dp[to][j-1], base + rev[0][1][i] + diff * (j-1) * 2);
                }
                if (j+1 <= n) {
                    dp[to][j+1] = Math.min(dp[to][j+1], base + rev[1][0][i] + diff * (j + 1) * 2);
                }
            }
        }
        long sum = dp[n%2][0];
        for (int i = 0; i < n ; i++) {
            sum += t[i];
        }
        out.println(sum);
        out.flush();
    }

    public static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }

    public static class InputReader {
        private static final int BUFFER_LENGTH = 1 << 12;
        private InputStream stream;
        private byte[] buf = new byte[BUFFER_LENGTH];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private int next() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public char nextChar() {
            return (char) skipWhileSpace();
        }

        public String nextToken() {
            int c = skipWhileSpace();
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = next();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public int nextInt() {
            return (int) nextLong();
        }

        public long nextLong() {
            int c = skipWhileSpace();
            long sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = next();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public double nextDouble() {
            return Double.valueOf(nextToken());
        }

        int skipWhileSpace() {
            int c = next();
            while (isSpaceChar(c)) {
                c = next();
            }
            return c;
        }

        boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    }
}