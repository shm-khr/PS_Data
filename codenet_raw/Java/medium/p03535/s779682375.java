import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[] D;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        D = sc.nextIntArray(N);
        System.out.println( solve() );
    }

    static int solve() {
        Arrays.sort(D);
        boolean[] R = new boolean[24];
        R[0] = true;

        boolean isFst = true;
        for (int i = 0; i < N; i++) {
            int d = D[i];
            if( d == 0 ) return 0;

            // 交互に置いていきたい
            if(isFst && !R[d]) {
                R[d] = true;
                isFst = false;

            } else {
                R[24-d] = true;
                isFst = true;
            }
        }

        int ans = 24;
        int prev = 0;
        for (int i = 1; i < 24; i++) {
            if( R[i] ) {
                ans = Math.min(i - prev, ans);
                prev = i;
            }
        }

        ans = Math.min(24-prev, ans);

        return ans;
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
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }
        long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
    }
}