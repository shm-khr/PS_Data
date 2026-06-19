import java.util.Scanner;

public class Main {
  static Scanner in = new Scanner(System.in);
  public static void main(String[] args) {
    String str = in.nextLine();
    if (str.endsWith("s")) {
      str = str.substring(0, str.length() - 1) + "es";
    } else {
      str = str + "s";
    }
    System.out.println(str);

  }
}
