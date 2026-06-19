import java.util.Scanner;
class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    String s = sc.next();

    int ans = 0;
    for(int i = s.length(); i > 0; i--) {
      ans += Integer.parseInt(s.substring(i-1, i));
    }
    
    if(a%9 == 0) {
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }
  }
}
