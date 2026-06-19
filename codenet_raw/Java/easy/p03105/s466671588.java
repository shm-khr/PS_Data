import java.util.*;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int c = sc.nextInt();

    for(int i = 0;;i++) {
      if(a > b) {
        System.out.println("0");
        break;
      }
      if(a * i >= b) {
        System.out.println(i);
        break;
      }
      if(i == c) {
        System.out.println(i);
        break;
      }
    }
  }

}
