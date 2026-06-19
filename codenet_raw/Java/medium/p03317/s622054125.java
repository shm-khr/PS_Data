import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int K = sc.nextInt();

		if (K == 2) {
			System.out.println((N / (K - 1)) + 1);
		} else {
			if (N == K) {
				System.out.println(1);
			} else if (N % (K - 1) == 0) {
				System.out.println((N / (K - 1)));
			} else {
				System.out.println((N / (K - 1)) + 1);
			}
		}
	}

}
