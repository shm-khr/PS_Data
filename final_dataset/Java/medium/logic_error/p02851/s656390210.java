import java.io.*;
import java.util.*;

public class Main {

    static int N, K;
    static int[] A;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();
        A = sc.nextIntArray(N);

        System.out.println(solve());
    }

    static long solve() {
        // [A1, A1+A2... A1...An]
        int[] C = new int[N];
        for (int i = 0; i < N; i++) {
            if( i == 0 ) {
                C[i] = A[i] % K;
            } else {
                C[i] = add(A[i], C[i-1], K);
            }
        }

        // [A1-1, A1+A2-2... A1...An-N]
        for (int i = 0; i < N; i++) {
            C[i] = sub(C[i], (i+1)%K, K);
        }

        // 長さがK以上のものは含めない
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int i = 0; i < Math.min(N, K-1); i++) {
            increment(cnt, C[i]);
        }
        // debug(cnt);

        long ans = 0;
        ans += cnt.getOrDefault(0, 0);

        // [A1-1, A1+A2-2, A1+A2+A3-3, ..., A1...An-N]
        // => [A2-1, A2+A3-2, ... (A2...An)-(N-1)] (全体に -A1+1)
        int delta = 0;
        for (int i = 0; i < N - 1; i++) {
            // 1. A1+...+Ai-(i+1) を消す
            int c = C[i];
            cnt.put(c, cnt.get(c)-1);

            // 2. 全体からAiを引き、+1する
            delta = sub(delta, A[i]%K, K);
            delta = add(delta, 1, K);

            // 3. もし制限されていたら追加する
            if( i + K-1 < N ) {
                increment(cnt, C[i+K-1]);
            }

            ans += cnt.getOrDefault(sub(0, delta, K), 0);
        }
        return ans;
    }

    static void increment(Map<Integer, Integer> cnt, int key) {
        if( cnt.containsKey(key) ) {
            cnt.put(key, cnt.get(key)+1);
        } else {
            cnt.put(key, 1);
        }
    }

    static int add(int a, int b, int K) {
        int c = a + b;
        if( c >= K ) c %= K;
        return c;
    }

    static int sub(int a, int b, int K) {
        int c = a - b;
        if( c < 0 ) c += K;
        return c;
    }

    @SuppressWarnings("unused")
    static class FastScanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        FastScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
            tokenizer = null;
        }

        String next() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        String nextLine() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    return reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken("\n");
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = nextInt();
            return a;
        }

        int[] nextIntArray(int n, int delta) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = nextInt() + delta;
            return a;
        }

        long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++) a[i] = nextLong();
            return a;
        }
    }

    static void writeLines(int[] as) {
        PrintWriter pw = new PrintWriter(System.out);
        for (int a : as) pw.println(a);
        pw.flush();
    }

    static void writeLines(long[] as) {
        PrintWriter pw = new PrintWriter(System.out);
        for (long a : as) pw.println(a);
        pw.flush();
    }

    static void writeSingleLine(int[] as) {
        PrintWriter pw = new PrintWriter(System.out);
        for (int i = 0; i < as.length; i++) {
            if (i != 0) pw.print(" ");
            pw.print(as[i]);
        }
        pw.println();
        pw.flush();
    }

    static int max(int... as) {
        int max = Integer.MIN_VALUE;
        for (int a : as) max = Math.max(a, max);
        return max;
    }

    static int min(int... as) {
        int min = Integer.MAX_VALUE;
        for (int a : as) min = Math.min(a, min);
        return min;
    }

    static void debug(Object... args) {
        StringJoiner j = new StringJoiner(" ");
        for (Object arg : args) {
            if (arg == null) j.add("null");
            else if (arg instanceof int[]) j.add(Arrays.toString((int[]) arg));
            else if (arg instanceof long[]) j.add(Arrays.toString((long[]) arg));
            else if (arg instanceof double[]) j.add(Arrays.toString((double[]) arg));
            else if (arg instanceof Object[]) j.add(Arrays.toString((Object[]) arg));
            else j.add(arg.toString());
        }
        System.err.println(j.toString());
    }

    static void printSingleLine(int[] array) {
        PrintWriter pw = new PrintWriter(System.out);
        for (int i = 0; i < array.length; i++) {
            if (i != 0) pw.print(" ");
            pw.print(array[i]);
        }
        pw.println();
        pw.flush();
    }

    static int lowerBound(int[] array, int value) {
        int lo = 0, hi = array.length, mid;
        while (lo < hi) {
            mid = (hi + lo) / 2;
            if (array[mid] < value) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }

    static int upperBound(int[] array, int value) {
        int lo = 0, hi = array.length, mid;
        while (lo < hi) {
            mid = (hi + lo) / 2;
            if (array[mid] <= value) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
}
