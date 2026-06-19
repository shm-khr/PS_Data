import java.io.*;
import java.util.*;

/**
 * Created by Katushka on 11.03.2020.
 */
public class Main {

    static int[] readArray(int size, InputReader in) {
        int[] a = new int[size];
        for (int i = 0; i < size; i++) {
            a[i] = in.nextInt();
        }
        return a;
    }

    static long[] readLongArray(int size, InputReader in) {
        long[] a = new long[size];
        for (int i = 0; i < size; i++) {
            a[i] = in.nextLong();
        }
        return a;
    }

    private static long fastPow(long x, long y, long mod) {
        if (x == 1) {
            return 1;
        }
        if (y == 0) {
            return 1;
        }
        long p = fastPow(x, y / 2, mod) % mod;
        p = p * p % mod;
        if (y % 2 == 1) {
            p = p * x % mod;
        }
        return p;
    }

    private static final long MOD = 1000000007;

    public static void main(String[] args) throws FileNotFoundException {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

        int n = in.nextInt();
        int x = in.nextInt();
        int y = in.nextInt();
        int z = in.nextInt();

//        long startTime = System.currentTimeMillis();

        int xyz = x + y + z;

        long total = fastPow(2, xyz, Integer.MAX_VALUE);
        long[][] dp = new long[n + 1][(int) total];

        String[] bits = fillBits(xyz);

        long[] pows2 = new long[11];
        pows2[0] = 1;

        int d = 1;
        for (int i = 1; i <= 10; i++) {
            if (i > xyz) {
                dp[1][0]++;
            } else {
                dp[1][d]++;
            }
            d *= 2;
            pows2[i] = d;
        }

        for (int i = 2; i <= n; i++) {
            for (int bitStringNum = 0; bitStringNum < total; bitStringNum++) {
                if (dp[i - 1][bitStringNum] == 0) {
                    continue;
                }
                for (int a = 1; a <= 10; a++) {
                    String bitString = bits[bitStringNum];
                    int newFullLength = bitString.length() + a;

                    boolean passed = a > z || newFullLength < xyz;
                    if (!passed) {
                        passed = a < z && bitString.charAt(newFullLength - z) == '0';
                        passed = passed || bitString.charAt(newFullLength - z - y) == '0';
                        passed = passed || bitString.charAt(newFullLength - xyz) == '0';
                    }

                    if (passed) {
                        int key;
                        if (a > xyz) {
                            key = 0;
                        } else if (a == xyz) {
                            key = (int) pows2[a - 1];
                        } else {
                            key = (int) ((pows2[a] * bitStringNum + pows2[a - 1]) % total);
                        }
                        dp[i][key] = (dp[i][key] + dp[i - 1][bitStringNum]) % MOD;
                    }
                }
            }
        }

        long ans = 0;
        for (int bitString = 0; bitString < total; bitString++) {
            ans = (ans + dp[n][bitString]) % MOD;
        }
        out.println((fastPow(10, n, MOD) + MOD - ans) % MOD);

//        out.println("Time: " + (System.currentTimeMillis() - startTime));

        out.close();
    }


    private static String[] fillBits(int n) {
        String[] bits = new String[(int) fastPow(2, n, Integer.MAX_VALUE)];
        for (int i = 0; i < bits.length; i++) {
            bits[i] = Integer.toBinaryString(i);
        }
        return bits;
    }


    private static void outputArray(long[] ans, PrintWriter out) {
        StringBuilder str = new StringBuilder();
        for (long an : ans) {
            str.append(an).append(' ');
        }
        out.println(str);
    }

    private static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                createTokenizer();
            }
            return tokenizer.nextToken();
        }

        private void createTokenizer() {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        public String nextWord() {
            return next();
        }

        public String nextString() {
            try {
                return reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public char nextChar() {
            return next().charAt(0);
        }

        public int[] nextInts() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                createTokenizer();
            }
            List<Integer> res = new ArrayList<>();
            while (tokenizer.hasMoreElements()) {
                res.add(Integer.parseInt(tokenizer.nextToken()));
            }
            int[] resArray = new int[res.size()];
            for (int i = 0; i < res.size(); i++) {
                resArray[i] = res.get(i);
            }
            return resArray;
        }
    }
}