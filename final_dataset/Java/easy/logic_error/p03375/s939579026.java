import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.Solve(in, out);
        out.close();
    }

    static class TaskC {

        long modInverse(long a) {
            return power(a, m - 2);
        }

        long power(long x, long y) {
            if (y == 0)
                return 1;

            long p = power(x, y / 2) % m;
            p = (p * p) % m;

            if (y % 2 == 0)
                return p;
            else
                return (x * p) % m;
        }

        static long gcd(long a, long b) {
            if (a == 0)
                return b;
            return gcd(b % a, a);
        }


        HashMap<Long, Long> comb = new HashMap<>();
        HashMap<Long, Long> fact = new HashMap<>();

        long factorial(long a) {
            if (fact.containsKey(a)) return fact.get(a);
            if (a == 0) return 1;
            long v = ((factorial(a - 1) * a) % m);
            fact.put(a, v);
            return v;
        }

        long ifactorial(long a) {
            return modInverse(factorial(a));
        }

        long pow2(long a) {
            if (a == 0) return 1;
            if (a == 1) return 2;
            long res = pow2(a / 2);
            res = (res * res) % m;
            if (a % 2 != 0) res = (res * 2) % m;
            return res;
        }

        long choose(long c, long n) {
            return (((factorial(n) * ifactorial(c)) % m) * ifactorial(n - c)) % m;
        }

        long compinationWithA_withMoreThen2Topping(long A) {
            if (comb.containsKey(A)) return comb.get(A);
            long res;
            if (A == 1) {
                long opt = pow2(n - 1);
                long with1 = (pow2(opt) - 1 - n) % m;
                while (with1 < 0) with1 += m;
                res = (opt * with1) % m;
            } else {
                res = compinationWithA_withMoreThen2Topping(A - 1);
                long c = -1;
                if (A % 2 == 0) {
                    c *= -1;
                    res *= -1;
                }
                for (int i = 1; i < A; i++) {
                    res += (compinationWithA_withMoreThen2Topping(i) * choose(i, A) * c) % m;
                    res %= m;
                    c *= -1;
                }
            }
            comb.put(A, res);
            return res;
        }

        long m, n;

        void Solve(InputReader in, PrintWriter out) {
            n = in.NextInt();
            m = in.NextLong();
            long res = 0;
            long c = 1;
            for (int i = 1; i <= n; i++) {
                res += (compinationWithA_withMoreThen2Topping(i) * choose(i, n) * c) % m;
                res %= m;
                c *= -1;
            }
            while (res < 0) res += m;
            out.println(res);
        }
    }

    static int GetMax(int[] ar) {
        int max = Integer.MIN_VALUE;
        for (int a : ar) {
            max = Math.max(max, a);
        }
        return max;
    }

    static int GetMin(int[] ar) {
        int min = Integer.MAX_VALUE;
        for (int a : ar) {
            min = Math.min(min, a);
        }
        return min;
    }

    static long GetSum(int[] ar) {
        long s = 0;
        for (int a : ar) s += a;
        return s;
    }

    static int[] GetCount(int[] ar) {
        return GetCount(ar, GetMax(ar));
    }

    static int[] GetCount(int[] ar, int maxValue) {
        int[] dp = new int[maxValue + 1];
        for (int a : ar) {
            dp[a]++;
        }
        return dp;
    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        String Next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine(), " \t\n\r\f,");
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        int NextInt() {
            return Integer.parseInt(Next());
        }

        long NextLong() {
            return Long.parseLong(Next());
        }

        double NextDouble() {
            return Double.parseDouble(Next());
        }

        int[] NextIntArray(int n) {
            return NextIntArray(n, 0);
        }

        int[] NextIntArray(int n, int offset) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = NextInt() - offset;
            }
            return a;
        }

        int[][] NextIntMatrix(int n, int m) {
            return NextIntMatrix(n, m, 0);
        }

        int[][] NextIntMatrix(int n, int m, int offset) {
            int[][] a = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a[i][j] = NextInt() - offset;
                }
            }
            return a;
        }


        public long[] NextLongArray(int n) {
            return NextLongArray(n, 0);
        }

        long[] NextLongArray(int n, int offset) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = NextLong() - offset;
            }
            return a;
        }

        long[][] NextLongMatrix(int n, int m) {
            return NextLongMatrix(n, m, 0);
        }

        long[][] NextLongMatrix(int n, int m, int offset) {
            long[][] a = new long[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a[i][j] = NextLong() - offset;
                }
            }
            return a;
        }
    }
}