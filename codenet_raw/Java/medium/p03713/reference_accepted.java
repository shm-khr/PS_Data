import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        ChocolateBar solver = new ChocolateBar();
        solver.solve(1, in, out);
        out.close();
    }

    static class ChocolateBar {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            long h = in.nextLong();
            long w = in.nextLong();

            long result = Long.MAX_VALUE;
            // 横割り
            for (long i = 0; i <= h; i++) {
                // 横割り
                long hh = h - i;
                long h2 = hh / 2;
                long h3 = hh - h2;
                long res = Math.max(Math.max(i * w, h2 * w), h3 * w) - Math.min(Math.min(i * w, h2 * w), h3 * w);
                result = Math.min(result, res);

                // 縦割り
                long w2 = w / 2;
                long w3 = w - w2;
                long res2 = Math.max(Math.max(i * w, hh * w2), hh * w3) - Math.min(Math.min(i * w, hh * w2), hh * w3);
                result = Math.min(result, res2);
            }
            // 縦割り
            for (long i = 0; i <= w; i++) {
                // 横割り
                long ww = w - i;
                long h2 = h / 2;
                long h3 = h - h2;
                long res = Math.max(Math.max(i * h, h2 * ww), h3 * ww) - Math.min(Math.min(i * h, h2 * ww), h3 * ww);
                result = Math.min(result, res);

                // 縦割り
                long w2 = ww / 2;
                long w3 = ww - w2;
                long res2 = Math.max(Math.max(i * h, h * w2), h * w3) - Math.min(Math.min(i * h, h * w2), h * w3);
                result = Math.min(result, res2);
            }
            out.println(result);
        }

    }
}

