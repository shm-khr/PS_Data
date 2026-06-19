import java.util.Scanner;

class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int h = sc.nextInt();
    int w = sc.nextInt();
    int n = sc.nextInt();
    int max = Math.max(h,w);
    
    int ans = (n / max) + 1;
    
    System.out.println(ans);
  }
}
