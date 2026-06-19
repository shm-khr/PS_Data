import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int n = sc.nextInt();
        long [] a = new long[n]; long [] b = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong(); b[i] = sc.nextLong();
        }
        boolean ok = true; long sum = 0;
        for (int i = 0; i <n; i++) {
            if (a[i] != b[i]) ok = false;
            sum += a[i];
        }
        if (ok) {
            out.println(0);
        } else {
            long res = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] > b[i]) {
                    res = Math.max(res, sum - b[i]);
                }
            }
            out.println(res);
        }
        out.close();
    }


    //-----------MyScanner class for faster input----------
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
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

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }


    }

}