public class Main{
  public void run(java.io.InputStream in, java.io.PrintStream out){
    java.util.Scanner sc = new java.util.Scanner(in);
/*answer*/
    int n, q;
    double p1x, p1y, p2x, p2y;
    double[] x, y;
    int i, j, k, a, b;
    double l1x, l1y, l2x, l2y, l3x, l3y, s1, s2, tmp;
    double[] lx, ly;

    n = sc.nextInt();
    x = new double[n + 1];
    y = new double[n + 1];
    lx = new double[n + 2];
    ly = new double[n + 2];

    for(i = 0;i < n;i++){
      x[i] = sc.nextDouble();
      y[i] = sc.nextDouble();
    }
    x[n] = x[0];
    y[n] = y[0];
    q = sc.nextInt();

    for(i = 0;i < q;i++){
      p1x = sc.nextDouble();
      p1y = sc.nextDouble();
      p2x = sc.nextDouble();
      p2y = sc.nextDouble();
      l1x = p2x - p1x;
      l1y = p2y - p1y;
      k = 0;
      a = 0;
      b = 0;
      s1 = 0;

      for(j = 0;j < n;j++){
        l2x = x[j] - p1x;
        l2y = y[j] - p1y;
        l3x = x[j + 1] - p1x;
        l3y = y[j + 1] - p1y;
        s1 = l1x * l2y - l2x * l1y;
        s2 = l1x * l3y - l3x * l1y;
        if(s1 * s2 <= 0 && s2 != 0){
          if(s2 >= 0)a = j + 1;
          if(s1 >= 0)b = j + 1;
          l2x = x[j + 1] - x[j];
          l2y = y[j + 1] - y[j];
          s1 = l1x * l2y - l2x * l1y;
          s2 = (l2y * (x[j] - p1x) - l2x * (y[j] - p1y)) / s1;
          lx[k] = p1x + s2 * l1x;
          ly[k] = p1y + s2 * l1y;
          k++;
        }
      }

      if(a < b){
        b = b - a;
      }else{
        b = a - b;
      }

      if(k == 0){
        if(s1 >= 0){
          for(j = 0;j < n;j++){
            lx[j] = x[j];
            ly[j] = y[j];
          }
          k = n;
        }else{
          k = 0;
        }
      }else if((lx[1] - lx[0]) * l1x <= 0 && (ly[1] - ly[0]) * l1y <= 0){
        tmp = lx[0];
        lx[0] = lx[1];
        lx[1] = tmp;
        tmp = ly[0];
        ly[0] = ly[1];
        ly[1] = tmp;
      }

      if(k != 0 && k != n){
        for(j = 0;j < b;j++){
          lx[k] = x[(j + a) % n];
          ly[k] = y[(j + a) % n];
          l1x = x[(j + a + 1) % n] - lx[k];
          l1y = y[(j + a + 1) % n] - ly[k];
          l2x = lx[0] - lx[k];
          l2y = ly[0] - ly[k];
          k++;
//          if(l1x * l2y - l2x * l1y == 0)break;
        }
      }

      System.out.println(area(lx, ly, k));

    }

/*fin*/
    sc.close();
  }
  public static void main(String[] args){
    (new Main()).run(System.in, System.out);
  }

  private static double area(double[] lx, double[] ly, int k){
    int i;
    double sum, ax, ay, bx, by;
    sum = 0.0;

    for(i = 0;i < k - 2;i++){
      ax = lx[i + 1] - lx[0];
      ay = ly[i + 1] - ly[0];
      bx = lx[i + 2] - lx[0];
      by = ly[i + 2] - ly[0];
      sum += (ax * by - ay * bx) / 2.0;
    }
    return sum;
  }

}