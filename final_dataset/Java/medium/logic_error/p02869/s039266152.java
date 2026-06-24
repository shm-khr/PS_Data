import java.io.*;
import java.util.*;

public class Main {
  private static List<String> solve(int n, int k) {
    int[] as = new int[n];
    int[] bs = new int[n];
    int[] cs = new int[n];
    for (int i = 0; i < n; i++) {
      cs[i] = k + 2 * n + i;
    }
    
    TreeSet<Integer> pending = new TreeSet<>();
    for (int i = k; i < k + 2 * n; i++) {
      pending.add(i);
    }
    for (int i = n - 1; i >= 0; i--) {
      int max = pending.last();
      pending.remove(max);
      bs[i] = max;
      int c = cs[i] - bs[i];
      Integer floorValue = pending.floor(c);
      if (floorValue == null) {
        return Arrays.asList("-1");
      }
      as[i] = floorValue;
      pending.remove(floorValue);
    }
    List<String> output = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      output.add(String.format("%d %d %d", as[i], bs[i], cs[i]));
    }
    return output;
  }
  
  private static void execute(ContestReader reader, PrintWriter out) {
    int n = reader.nextInt();
    int k = reader.nextInt();
    for (String line : solve(n, k)) {
      out.println(line);
    }
  }
  
  public static void main(String[] args) {
    ContestReader reader = new ContestReader(System.in);
    PrintWriter out = new PrintWriter(System.out);
    execute(reader, out);
    out.flush();
  }
}

class ContestReader {
  private BufferedReader reader;
  private StringTokenizer tokenizer;
  
  ContestReader(InputStream in) {
    reader = new BufferedReader(new InputStreamReader(in));
  }
  
  public String next() {
    while (tokenizer == null || !tokenizer.hasMoreTokens()) {
      try {
        tokenizer = new java.util.StringTokenizer(reader.readLine());
      } catch (Exception e) {
        throw new RuntimeException(e);
      }
    }
    return tokenizer.nextToken();
  }
  
  public int nextInt() {
    return Integer.parseInt(next());
  }
  
  public long nextLong() {
    return Long.parseLong(next());
  }
  
  public double nextDouble() {
    return Double.parseDouble(next());
  }
  
  public String[] nextArray(int n) {
    String[] array = new String[n];
    for (int i = 0; i < n; i++) {
      array[i] = next();
    }
    return array;
  }
  
  public int[] nextIntArray(int n) {
    int[] array = new int[n];
    for (int i = 0; i < n; i++) {
      array[i] = nextInt();
    }
    return array;
  }
  
  public long[] nextLongArray(int n) {
    long[] array = new long[n];
    for (int i = 0; i < n; i++) {
      array[i] = nextLong();
    }
    return array;
  }
  
  public double[] nextDoubleArray(int n) {
    double[] array = new double[n];
    for (int i = 0; i < n; i++) {
      array[i] = nextDouble();
    }
    return array;
  }
  
  public int[][] nextIntMatrix(int n, int m) {
    int[][] matrix = new int[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        matrix[i][j] = nextInt();
      }
    }
    return matrix;
  }
  
  public long[][] nextLongMatrix(int n, int m) {
    long[][] matrix = new long[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        matrix[i][j] = nextLong();
      }
    }
    return matrix;
  }
  
  public double[][] nextDoubleMatrix(int n, int m) {
    double[][] matrix = new double[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        matrix[i][j] = nextDouble();
      }
    }
    return matrix;
  }
}
