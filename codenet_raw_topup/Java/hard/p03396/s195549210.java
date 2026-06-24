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

        long[][][] next = new long[2][2][n];
        for (int si = 0; si < n ; si++) {
            long X = x[si];
            for (int i = 0; i < 2; i++) {
                // i=0: from left, i=1: from right
                long leftTime = X;
                long rightTime = L * 2 - X;
                long fromTime = ((i == 0) ? leftTime : rightTime);
                long shopFinish = fromTime + t[si];
                for (int j = 0; j < 2 ; j++) {
                    long toTime = j == 0 ? leftTime : rightTime;
                    while (toTime < shopFinish) {
                        toTime += 2 * L;
                    }
                    next[i][j][si] = toTime - shopFinish;
                }
            }
        }

        long[][][][] dp = new long[2][2][n][n];
        for (int ni = 0; ni < 2 ; ni++) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < n; j++) {
                    Arrays.fill(dp[ni][i][j], INF);
                }
            }
        }
        for (int di = 0; di < 2 ; di++) {
            for (int si = 0; si < n ; si++) {
                long time = (di == 0) ? x[si] : L * 2 - x[si];
                dp[0][di][si][si] = dp[1][di][si][si] = time + t[si];
            }
        }
        
        long ans = INF;
        for (int len = 1 ; len < n ; len++) {
            for (int l = 0 ; l+len <= n ; l++) {
                int r = l+len-1;
                for (int di = 0 ; di <= 1 ; di++) {
                    for (int nw = 0 ; nw <= 1 ; nw++) {
                        long base = dp[nw][di][l][r];
                        if (base == INF) {
                            continue;
                        }
                        int now = nw == 1 ? r : l;
                        if (l >= 1) {
                            long ne = base + next[di][1][now] + (x[now] - x[l-1]) + t[l-1];
                            dp[0][1][l-1][r] = Math.min(dp[0][1][l-1][r], ne);
                            dp[0][0][l-1][r] = Math.min(dp[0][0][l-1][r], ne + x[l-1] * 2);
                        }
                        if (r + 1 < n) {
                            long ne = base + next[di][0][now] + (x[r+1] - x[now]) + t[r+1];
                            dp[1][0][l][r+1] = Math.min(dp[1][0][l][r+1], ne);
                            dp[1][1][l][r+1] = Math.min(dp[1][1][l][r+1], ne + (L - x[r+1]) * 2);
                        }
                    }
                }
            }
        }

        for (int nw = 0; nw <= 1; nw++) {
            int now = nw == 0 ? 0 : n-1;
            for (int di = 0 ; di <= 1 ; di++) {
                long base = dp[nw][di][0][n-1];
                long ne = base + next[di][1][now] + x[now];
                ans = Math.min(ans, ne);
            }
        }

        // debug(0, 0, 1, dp);


        out.println(ans);
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