import java.util.Scanner;

/**
 * String Palindrome
 * 
 * https://atcoder.jp/contests/abc159/tasks/abc159_b
 */
public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        String S = sc.next();
        int N = S.length();

        for (int i = 1; i <= (N - 1) / 2; i++) {
            if (S.charAt(i - 1) != S.charAt(N - i)) {
                System.out.println("No");
                return;
            }

            if (S.charAt(i - 1) != S.charAt((N - 1) / 2 - i)) {
                System.out.println("No");
                return;
            }
        }

        System.out.println("Yes");
    }

}
