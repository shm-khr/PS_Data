import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);
  static ArrayList<ArrayList<Edge>> g = new ArrayList<>();

  public static void main(String[] args) {
    int N = sc.nextInt();
    int M = sc.nextInt();
    for (int i = 0; i < N; i++) {
      g.add(new ArrayList<>());
    }
    for (int i = 0; i < M; i++) {
      int U = sc.nextInt() - 1;
      int V = sc.nextInt() - 1;
      int S = sc.nextInt();
      g.get(U).add(new Edge(V, S));
      g.get(V).add(new Edge(U, S));
    }
    final long INF = (long) 1e18;
    long[][] v = new long[2][N];
    for (long[] a : v) {
      Arrays.fill(a, INF);
    }
    ArrayList<Integer> cur = new ArrayList<>();
    cur.add(0);
    v[0][0] = 0;
    for (int i = 1; !cur.isEmpty(); i ^= 1) {
      ArrayList<Integer> next = new ArrayList<>();
      for (int c : cur) {
        for (Edge e : g.get(c)) {
          if (v[i][e.to] != INF) continue;
          v[i][e.to] = e.s - v[i ^ 1][c];
          next.add(e.to);
        }
      }
      cur = next;
    }
    if (v[1][0] != INF) {
      if (v[1][0] % 2 != 0 || v[1][0] <= 0) {
        System.out.println(0);
      } else {
        long x = v[1][0] / 2;
        for (int i = 0; i < N; i++) {
          if (v[1][i] - v[0][i] != x * 2) {
            System.out.println(0);
            return;
          }
          if (x + v[0][i] <= 0) {
            System.out.println(0);
            return;
          }
        }
        System.out.println(1);
      }
    } else {
      long min = 1;
      long max = INF;
      for (int i = 0; i < N; i++) {
        if (v[0][i] != INF) {
          min = Math.max(min, -v[0][i] + 1);
        } else {
          max = Math.min(max, v[1][i] - 1);
        }
      }
      System.out.println(Math.max(0, max - min + 1));
    }
  }


  static class Edge {
    int to, s;

    public Edge(int to, int s) {
      this.to = to;
      this.s = s;
    }
  }
}
