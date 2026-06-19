import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        int A, B, C;

        Scanner scanner = new Scanner(System.in);
        A = scanner.nextInt();
        B = scanner.nextInt();
        C = scanner.nextInt();

        if (C < (B / A)) {
            System.out.println(C);
        } else if ((B / A) < C) {
            System.out.println(B/A);
        }


    }
}
