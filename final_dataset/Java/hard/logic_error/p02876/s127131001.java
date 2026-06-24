
import java.util.Arrays;

public class Main {

  private static void solve() {
    int n = ni();
    int[][] p = ntable(n, 2);

    int[][] p1 = new int[n][2];
    int[][] p2 = new int[n][2];

    int ptr1 = 0;
    int ptr2 = 0;
    for (int[] v : p) {
      if (v[0] <= v[1]) {
        p1[ptr1++] = v;
      } else {
        p2[ptr2++] = v;
      }
    }

    if (ptr1 == 0) {
      System.out.println("0 1");
      return;
    }

    p1 = Arrays.copyOf(p1, ptr1);
    p2 = Arrays.copyOf(p2, ptr2);

    Arrays.sort(p1, (o1, o2) -> o1[1] - o2[1]);
    Arrays.sort(p2, (o1, o2) -> (o2[1] - o2[0]) - (o1[1] - o1[0]));


    int mod = 0;
    int d = ptr1;

    for (int i = 0; i < ptr1; i++) {
      while (mod < p1[i][0]) {
        mod += p1[--d][1];
      }
      mod -= p1[i][0];
    }

    long retP = (long) d * p1[d][1] + mod;
    long retQ = (long) n * p1[d][1];

    int e = -1;
    outer: for (int i = 0; i < ptr2; i++) {
      while (mod < p2[i][0]) {
        d--;
        if (d < 0) {
          e++;
          if (e >= ptr2) {
            break outer;
          }
          mod += p2[e][1];
        } else {
          mod += p1[d][1];
        }
      }
      mod -= p2[i][0];

      long nowP = (long) (d + i + 1) * (d < 0 ? p2[e][1] : p1[d][1]) + mod;
      long nowQ = (long) n * (d < 0 ? p2[e][1] : p1[d][1]);

      if (cmp(retP, retQ, nowP, nowQ) < 0) {
        retP = nowP;
        retQ = nowQ;
      }
    }

    long g = gcd(retP, retQ);
    System.out.println(retP / g + " " + retQ / g);
  }

  public static long gcd(long a, long b) {
    while (b > 0) {
      long c = a;
      a = b;
      b = c % b;
    }
    return a;
  }


  private static int cmp(long p1, long q1, long p2, long q2) {
    return Long.compare(p1 * q2, p2 * q1);
  }

  public static void main(String[] args) {
    new Thread(null, new Runnable() {
      @Override
      public void run() {
        long start = System.currentTimeMillis();
        String debug = args.length > 0 ? args[0] : null;
        if (debug != null) {
          try {
            is = java.nio.file.Files.newInputStream(java.nio.file.Paths.get(debug));
          } catch (Exception e) {
            throw new RuntimeException(e);
          }
        }
        reader = new java.io.BufferedReader(new java.io.InputStreamReader(is), 32768);
        solve();
        out.flush();
        tr((System.currentTimeMillis() - start) + "ms");
      }
    }, "", 64000000).start();
  }

  private static java.io.InputStream is = System.in;
  private static java.io.PrintWriter out = new java.io.PrintWriter(System.out);
  private static java.util.StringTokenizer tokenizer = null;
  private static java.io.BufferedReader reader;

  public static String next() {
    while (tokenizer == null || !tokenizer.hasMoreTokens()) {
      try {
        tokenizer = new java.util.StringTokenizer(reader.readLine());
      } catch (Exception e) {
        throw new RuntimeException(e);
      }
    }
    return tokenizer.nextToken();
  }

  private static double nd() {
    return Double.parseDouble(next());
  }

  private static long nl() {
    return Long.parseLong(next());
  }

  private static int[] na(int n) {
    int[] a = new int[n];
    for (int i = 0; i < n; i++)
      a[i] = ni();
    return a;
  }

  private static char[] ns() {
    return next().toCharArray();
  }

  private static long[] nal(int n) {
    long[] a = new long[n];
    for (int i = 0; i < n; i++)
      a[i] = nl();
    return a;
  }

  private static int[][] ntable(int n, int m) {
    int[][] table = new int[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        table[i][j] = ni();
      }
    }
    return table;
  }

  private static int[][] nlist(int n, int m) {
    int[][] table = new int[m][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        table[j][i] = ni();
      }
    }
    return table;
  }

  private static int ni() {
    return Integer.parseInt(next());
  }

  private static void tr(Object... o) {
    if (is != System.in)
      System.out.println(java.util.Arrays.deepToString(o));
  }
}

