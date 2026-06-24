import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {

  private static void solve() {
    int n = ni();
    int[] v = new int[n];
    int[] w = new int[n];
    for (int i = 0; i < n; i++) {
      v[i] = ni();
      w[i] = ni();
    }

    int qq = ni();
    Map<Integer, List<int[]>> map = new HashMap<>();

    for (int i = 0; i < qq; i++) {
      int vv = ni() - 1;
      if (!map.containsKey(vv)) {
        map.put(vv, new ArrayList<>());
      }
      List<int[]> list = map.get(vv);
      list.add(new int[] { i, ni(), 0 });
    }

    dfs(0, new int[30], new int[30], 0, n, map, v, w);
    int[] ret = new int[qq];
    for (List<int[]> list : map.values()) {
      for (int[] x : list) {
        ret[x[0]] = x[2];
      }
    }

    for (int x : ret) {
      out.println(x);
    }
  }

  private static void dfs(int cur, int[] vc, int[] wc, int dep, int n, Map<Integer, List<int[]>> map, int[] v,
      int[] w) {
    vc[dep] = v[cur];
    wc[dep] = w[cur];

    if (map.containsKey(cur)) {
      for (int[] x : map.get(cur)) {
        x[2] = solve(dep + 1, vc, wc, x[1]);
      }
    }

    int nex1 = cur * 2 + 1;
    int nex2 = cur * 2 + 2;
    if (nex1 < n) {
      dfs(nex1, vc, wc, dep + 1, n, map, v, w);
    }
    if (nex2 < n) {
      dfs(nex2, vc, wc, dep + 1, n, map, v, w);
    }
  }

  private static int solve(int n, int[] v, int[] w, int l) {
    int m1 = (n + 1) / 2;
    int m2 = n / 2;

    int[][] a1 = new int[1 << m1][2];
    int[][] a2 = new int[1 << m2][2];
    for (int i = 0; i < (1 << m1); i++) {
      for (int j = 0; j < m1; j++) {
        if (((i >> j) & 1) == 1) {
          a1[i][0] += v[j];
          a1[i][1] += w[j];
        }
      }
    }
    for (int i = 0; i < (1 << m2); i++) {
      for (int j = 0; j < m2; j++) {
        if (((i >> j) & 1) == 1) {
          a2[i][0] += v[m1 + j];
          a2[i][1] += w[m1 + j];
        }
      }
    }
    Arrays.sort(a1, (o1, o2) -> o1[1] - o2[1]);
    for (int i = 1; i < (1 << m1); i++) {
      a1[i][0] = Math.max(a1[i][0], a1[i - 1][0]);
    }

    int ret = 0;
    for (int i = 0; i < (1 << m2); i++) {
      int ok = 0;
      int ng = 1 << m1;
      while (ng - ok > 1) {
        int k = (ok + ng) / 2;
        if (a1[k][1] + a2[i][1] <= l) {
          ok = k;
        } else {
          ng = k;
        }
      }
      ret = Math.max(ret, a1[ok][0] + a2[i][0]);
    }
    return ret;
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
