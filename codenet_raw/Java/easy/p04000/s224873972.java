import java.util.HashMap;
import java.util.HashSet;
import java.util.Objects;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int H = scanner.nextInt();
    int W = scanner.nextInt();
    int N = scanner.nextInt();
    HashSet<Point> colored = new HashSet<>();
    for (int i = 0; i < N; i++) {
      colored.add(new Point(scanner.nextInt(), scanner.nextInt()));
    }

    HashSet<Point> points = new HashSet<>();
    for (Point c : colored) {
      for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
          int x = c.x + i;
          int y = c.y + j;
          if (x > 1 && x < H && y > 1 && y < W) {
            points.add(new Point(x, y));
          }
        }
      }
    }

    HashMap<Point, Integer> freq = new HashMap<>();
    for (Point p : points) {
      for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
          int x = p.x + i;
          int y = p.y + j;
          if (colored.contains(new Point(x, y))) {
            freq.put(p, freq.getOrDefault(p, 0) + 1);
          }
        }
      }
    }

    long[] total = new long[10];
    total[0] = (long) (H - 2) * (W - 2) - points.size();
    for (Point p : points) total[freq.get(p)]++;
    for (long t : total) {
      System.out.println(t);
    }
  }

  private static class Point {
    public final int x;
    public final int y;

    private Point(int x, int y) {
      this.x = x;
      this.y = y;
    }

    @Override public boolean equals(Object o) {
      if (this == o) return true;
      if (o == null || getClass() != o.getClass()) return false;
      Point point = (Point) o;
      return x == point.x &&
          y == point.y;
    }

    @Override public int hashCode() {
      return Objects.hash(x, y);
    }
  }
}
