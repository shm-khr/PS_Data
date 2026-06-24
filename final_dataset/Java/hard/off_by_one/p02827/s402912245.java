import java.io.*;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class Main {
    FastScanner in;
    PrintWriter out;

    public static void main(String[] args) {
        new Main().runIO();
    }

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        int type = in.nextInt();
        if (type == 2) {
            throw new AssertionError();
        }
        long START = System.currentTimeMillis();
        int[] x = new int[m];
        int[] y = new int[m];
        for (int i = 0; i < m; i++) {
            x[i] = in.nextInt() - 1;
            y[i] = in.nextInt() - 1;
        }
        Random rnd = new Random(123);
        int[] sizes = new int[n];
        char[] res= new char[m];
        boolean[] end= new boolean[n];
        while (System.currentTimeMillis() - START < 1000) {
            Arrays.fill(sizes, 1);
            for (int i = 0; i < m; i++) {
                if (rnd.nextBoolean()) {
                    sizes[x[i]] += sizes[y[i]];
                    sizes[y[i]] = 0;
                } else {
                    sizes[y[i]] += sizes[x[i]];
                    sizes[x[i]] = 0;
                }
            }
            int id = rnd.nextInt(n);
            int toCheck = -1;
            for (int i = 0; i < n; i++) {
                id -= sizes[i];
                if (id < 0) {
                    toCheck = i;
                    break;
                }
            }
            if (toCheck == -1) {
                throw new AssertionError();
            }
            Arrays.fill(end,false);
            end[toCheck] = true;
            for (int i = m - 1; i >= 0; i--) {
                if (end[x[i]]) {
                    res[i] = '^';
                    end[y[i]]= true;
                } else if (end[y[i]]) {
                    end[x[i]] = true;
                    res[i] = 'v';
                } else {
                    res[i] = 'v';
                }
            }
            boolean allOk = true;
            for (boolean z  : end) {
                if (!z) {
                    allOk = false;
                    break;
                }
            }
            if (allOk) {
//                System.err.println(toCheck);
                out.println(new String(res));
                return;
            }
        }
        out.println(-1);
    }


    void run() {
        try {
            in = new FastScanner(new File("Main.in"));
            out = new PrintWriter(new File("Main.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}
