import java.util.Arrays;
import java.util.Scanner;

public class Main {
  Scanner sc;


  static final int MID = 20;

  void run() {
    for (; ; ) {
      int r = ni();
      int n = ni();

      if ( (r | n) == 0 ) {
        break;
      }

      boolean[][] field = new boolean[ 32 ][ 64 ];
      for ( int i = 0; i < n; ++i ) {
        int xl = ni();
        int xr = ni();
        int h = ni();

        for ( int k = 1; k <= h; ++k ) {
          for ( int j = xl; j < xr; ++j ) {
            field[ k ][ j + MID ] = true;
          }
        }
      }
      int[] hs = new int[ 32 ];
      for ( int i = 1; i <= 20; ++i ) {
        for ( int w = 1; field[ i ][ MID + w - 1 ] && field[ i ][ MID - w ]; ++w ) {
          hs[ i ] = w;
        }
      }

      // p1
//      debug(hs);
      int h = 0;
      for ( int i = 1; i <= 20; ++i ) {
        if ( hs[ i ] < r ) {
          break;
        }
        ++h;
      }
      // p2
      double dh = 0;
      double right = r;
      while ( right - dh > 1e-6 ) {
        double mid = (dh + right) / 2;
        double theta = Math.acos((r - mid) / r);
        double w = r * Math.sin(theta);
        boolean flag = true;

//        debug(mid, w);
        for ( int i = 0; i <= mid; ++i ) {
          flag &= hs[ h + i + 1 ] >= w;
        }

        if ( flag ) {
          dh = mid;
        } else {
          right = mid;
        }
      }

//      debug(h, dh);

      System.out.printf("%.4f\n", h + dh);
    }
  }

  Main() {
    sc = new Scanner(System.in);
  }

  int ni() {
    return sc.nextInt();
  }

  public static void main(String[] args) {
    new Main().run();
  }

  void debug(Object... os) {
    System.err.println(Arrays.deepToString(os));
  }
}