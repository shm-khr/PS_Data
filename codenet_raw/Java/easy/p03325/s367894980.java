import java.util.Scanner;
import java.util.Arrays;
import java.util.stream.Stream;
import java.util.stream.IntStream;
import java.lang.StringBuilder;

public class Main {
  public static void main(String[] args ){
    Scanner sc = new Scanner(System.in);

    int N = sc.nextInt();

    int[] a = new int[N];

    for (int i = 0; i < N; i++) {
      a[i] = sc.nextInt();
    }


    
    long opCnt = 0;
    for (int i = 0; i < N; i++) {
      if (a[i] % 2 == 0){
        opCnt += a[i] / 2;
      }
    }

    // 5 2 4
    // 1 + 2 = 15


    System.out.println(opCnt);
  }
}
