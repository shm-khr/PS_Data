import java.io.*;
import java.util.*;

class Solver {
  final int n, m, t;
  final int[][] xys;
  
  Solver(int n, int m, int t, int[][] xys) {
    this.n = n;
    this.m = m;
    this.t = t;
    this.xys = xys;
  }
  
  public String solve() {
    UnionFind unionFind = new UnionFind(n + 1);
    Deque<Character> deque = new ArrayDeque<>();
    
    int lastX = xys[m - 1][0];
    for (int i = m - 1; i >= 0; i--) {
      int x = xys[i][0];
      int y = xys[i][1];
      if (unionFind.sameGroup(x, lastX) && unionFind.sameGroup(y, lastX)) {
        deque.addFirst('v');
      } else if (!unionFind.sameGroup(y, lastX) && unionFind.sameGroup(x, lastX)) {
        deque.addFirst('^');
        unionFind.merge(y, lastX);
//        System.err.printf("%d %d\n", y, lastX);
      } else if (!unionFind.sameGroup(x, lastX) && unionFind.sameGroup(y, lastX)) {
        deque.addFirst('v');
        unionFind.merge(x, lastX);
//        System.err.printf("%d %d\n", x, lastX);
      } else {
        deque.addFirst('v');
      }
    }
    
    for (int i = 1; i <= n; i++) {
      if (!unionFind.sameGroup(i, lastX)) {
        return "-1";
      }
    }
    
    StringBuffer sb = new StringBuffer();
    for (char c : deque) {
      sb.append(c);
    }
    return sb.toString();
  }
}

public class Main {
  private static void execute(ContestReader reader, PrintWriter out) {
    int n = reader.nextInt();
    int m = reader.nextInt();
    int t = reader.nextInt();
    if (t == 2) {
      throw new RuntimeException();
    }
    int[][] xys = reader.nextInt(m, 2);
    out.println(new Solver(n, m, t, xys).solve());
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
  
  public String[] next(int n) {
    String[] array = new String[n];
    for (int i = 0; i < n; i++) {
      array[i] = next();
    }
    return array;
  }
  
  public int[] nextInt(int n) {
    int[] array = new int[n];
    for (int i = 0; i < n; i++) {
      array[i] = nextInt();
    }
    return array;
  }
  
  public long[] nextLong(int n) {
    long[] array = new long[n];
    for (int i = 0; i < n; i++) {
      array[i] = nextLong();
    }
    return array;
  }
  
  public double[] nextDouble(int n) {
    double[] array = new double[n];
    for (int i = 0; i < n; i++) {
      array[i] = nextDouble();
    }
    return array;
  }
  
  public char[] nextCharArray() {
    return next().toCharArray();
  }
  
  public int[][] nextInt(int n, int m) {
    int[][] matrix = new int[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        matrix[i][j] = nextInt();
      }
    }
    return matrix;
  }
  
  public long[][] nextLong(int n, int m) {
    long[][] matrix = new long[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        matrix[i][j] = nextLong();
      }
    }
    return matrix;
  }
  
  public double[][] nextDouble(int n, int m) {
    double[][] matrix = new double[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        matrix[i][j] = nextDouble();
      }
    }
    return matrix;
  }
  
  public char[][] nextCharArray(int n) {
    char[][] matrix = new char[n][];
    for (int i = 0; i < n; i++) {
      matrix[i] = next().toCharArray();
    }
    return matrix;
  }
}

class UnionFind {
  int[] parents;
  int[] ranks;

  UnionFind(int n) {
    parents = new int[n];
    ranks = new int[n];

    for (int i = 0; i < n; i++) {
      parents[i] = i;
    }
  }

  public int getRoot(int index) {
    if (parents[index] == index) {
      return index;
    } else {
      parents[index] = getRoot(parents[index]);
      return parents[index];
    }
  }

  public boolean sameGroup(int a, int b) {
    return getRoot(a) == getRoot(b);
  }

  public void merge(int a, int b) {
    int rootA = getRoot(a);
    int rootB = getRoot(b);
    if (rootA == rootB) {
      return;
    }
    if (ranks[rootA] < ranks[rootB]) {
      parents[rootA] = rootB;
    } else if (ranks[rootB] < ranks[rootA]) {
      parents[rootB] = rootA;
    } else {
      parents[rootA] = rootB;
      ranks[rootB]++;
    }
  }
}
