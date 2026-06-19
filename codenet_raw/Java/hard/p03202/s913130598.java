
import java.util.Arrays;
import java.util.TreeMap;


public class Main {


  private static void solve() {
    int n = ni();
    int[] a = na(n);
    int[] b = shrink(a);

    int max = Arrays.stream(b).max().getAsInt();
    int[] now = new int[max + 1];
    
    int left = 0;
    int right = Integer.MAX_VALUE / 3;
    
    while (right - left > 1) {
      int k = (left + right) / 2;

      if (ok(k, b, now)) {
        right = k;
      } else {
        left = k;
      }
    }
    System.out.println(right);
  }
  
  public static int[] shrink(int[] a)
  {
      TreeMap<Integer, Integer> map = new TreeMap<>();
      for (int v : a) {
        map.put(v, 0);
      }
      int now = 0;
      int pre = map.firstKey();
      for (int v : map.keySet()) {
        now += Math.min(v - pre, 20);

        map.put(v, now);
        pre = v;
      }
      int n = a.length;
      int[] ret = new int[n];
      for (int i = 0; i < n; i ++) {
        ret[i] = map.get(a[i]);
      }
      return ret;
  }
  
  private static boolean ok(int k, int[] a, int[] now) {
    int n = a.length;
    for (int i = 1; i < n; i ++) {
      if (a[i - 1] < a[i])
        continue;
      
      int j = a[i];
      while (true) {
        now[j] ++;
        if (now[j] >= k) {
          now[j] = 0;
          j --;
          if (j < 0) return false;
        } else {
          break;
        }
      }
    }
    Arrays.fill(now, 0);
    return true;
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
