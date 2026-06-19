
import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();

		long[] S_A = new long[N];
		long min = Long.MAX_VALUE;

		S_A[0] = sc.nextLong();

		for (int i = 1; i < N; i++) {
			S_A[i] = sc.nextLong() + S_A[i-1];
		}

		for (int i = 0; i < N; i++) {
			min = Math.min(Math.abs(S_A[N-1]-S_A[i]*2),min);
		}

		System.out.println(min);

	}
}
