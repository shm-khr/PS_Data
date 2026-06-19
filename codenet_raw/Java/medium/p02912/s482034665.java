
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		try (Scanner sc = new Scanner(System.in)) {
			int n = sc.nextInt();
			int m = sc.nextInt();
			Long[] aarr = new Long[n];
			for (int i = 0; i < n; i++) {
				aarr[i] = sc.nextLong();
			}

			for (int i = 0; i < m; i++) {
				Arrays.sort(aarr, Comparator.reverseOrder());
				if (aarr[0] == 0) {
					System.out.println(0);
					return;
				}
				aarr[0] /= 2;
			}

			long result = 0;
			for (long a : aarr) {
				result += a;
			}
			System.out.println(result);
		}
	}
}
