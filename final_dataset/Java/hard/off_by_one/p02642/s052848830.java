import java.io.InputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

  public static void main(String[] args) {
    resolve(System.in, System.out);
  }

  static void resolve(InputStream is, PrintStream pw) {
    Scanner sc = new Scanner(is);
    int n = Integer.parseInt(sc.next());
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = Integer.parseInt(sc.next());
    }
    Arrays.sort(a);
    long ans = IntStream.range(0, n)
      .parallel()
      .filter(i -> meet(i, n, a))
      .count();
    pw.println(ans);
  }

  static boolean meet(int i, int n, int[] a) {
    int ai = a[i];
    if (i + 1 < n) {
      if (ai == a[i + 1]) {
        return false;
      }
    }
    for (int j = 0; j <= i - 1; j++) {
      if (ai % a[j] == 0) {
        return false;
      }
    }
    return true;
  }
}
