import java.util.Scanner;
public class Main {
   public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int x = scan.nextInt();
        int a = ( x % 2 + x / 2 ) * x / 2 );
        System.out.println(a);
        scan.close();
    }
}
