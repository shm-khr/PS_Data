import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int q = scanner.nextInt();
    for (int i = 0; i < q; i++) {
      long a = scanner.nextLong();
      long b = scanner.nextLong();
      System.out.println(solve(a, b));
    }
  }

  private static long solve(long a, long b) {
    if (a > b) return solve(b, a);

    double ab = (double) a;
    ab = ab * b - 1;
    long i = (long) Math.floor(Math.sqrt(ab));
    long j = (long) Math.floor((ab) / i);

    long res = i * 2;
    if (i == j) res--;
    if (i >= a) res--;

    return res;
  }
}
