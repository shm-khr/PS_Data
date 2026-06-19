import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long N,K;
    N = sc.nextLong();
    K = sc.nextLong();
    long a,b;
    a = N / K;
    long ans;
    ans = a * a * a;
    if(K % 2 == 0){
      b = (N - K/2) / K + 1L;
      ans += b * b * b;
    }
    System.out.println(ans);
  }

  public static int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
  }
}