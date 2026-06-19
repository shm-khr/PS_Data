import java.util.Scanner;

/**
 * 解説通り実装したソースコード
 */
public class Main {

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			char[] s = scanner.next().toCharArray();
			if ((0 == (s.length & 1)) == (s[0] == s[s.length - 1])) {
				System.out.println("First");
			} else {
				System.out.println("Second");
			}
		}
	}
}
