// package arc.arc096;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        MOD = in.nextInt();

        prec(12000);


        long[] any2 = new long[n+1];
        any2[0] = 2;
        for (int i = 1 ; i <= n; i++) {
            any2[i] = (any2[i-1] * any2[i-1]) % MOD;
        }

        long[] pow2 = new long[n+1];
        pow2[0] = 1;
        for (int i = 1 ; i <= n; i++) {
            pow2[i] = pow2[i-1] * 2 % MOD;
        }

        long all = any2[n];

        if (n > 300) {
            throw new RuntimeException("");
        }

        for (int c = 1 ; c <= n ; c++) {
            long way = comb(n, c);

            long zero = any2[n-c];
            long variant = pow2[n-c];
            long[] dp = new long[n+10];
            dp[0] = 1;
            for (int i = 1 ; i <= c ; i++) {
                long sum = dp[i-1];
                for (int use = 1 ; use <= i ; use++) {
                    sum += comb(i-1, use-1) % MOD * variant % MOD * dp[i-use] % MOD;
                }
                dp[i] = sum % MOD;
            }

            debug(dp);

            // debug("[]", c, way, zero, dp[c]);
            zero *= dp[c];
            zero %= MOD;

            way *= zero;
            way %= MOD;
            if (c % 2 == 0) {
                all += way;
            } else {
                all += MOD - way;
            }

            // debug("->", c, way);
            all %= MOD;
        }

        out.println(all);
        out.flush();
    }

    static int MOD = 1000000007;

    static long pow(long a, long x) {
        long res = 1;
        while (x > 0) {
            if (x % 2 != 0) {
                res = (res * a) % MOD;
            }
            a = (a * a) % MOD;
            x /= 2;
        }
        return res;
    }

    static long inv(long a) {
        return pow(a, MOD - 2) % MOD;
    }

    static long[] _fact;
    static long[] _invfact;

    static long comb(long ln, long lr) {
        int n = (int) ln;
        int r = (int) lr;
        if (n < 0 || r < 0 || r > n) {
            return 0;
        }
        if (r > n / 2) {
            r = n - r;
        }
        return (((_fact[n] * _invfact[n - r]) % MOD) * _invfact[r]) % MOD;
    }

    static void prec(int n) {
        _fact = new long[n + 1];
        _invfact = new long[n + 1];
        _fact[0] = 1;
        _invfact[0] = 1;
        for (int i = 1; i <= n; i++) {
            _fact[i] = _fact[i - 1] * i % MOD;
            _invfact[i] = inv(_fact[i]);
        }
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