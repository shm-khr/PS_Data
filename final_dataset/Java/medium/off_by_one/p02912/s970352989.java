import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		//		long start = System.currentTimeMillis();
		try (Scanner scanner = new Scanner(System.in)) {
			int n = scanner.nextInt();
			int m = scanner.nextInt();

			Long[] costs = new Long[n];
			for (int i = 0; i < n; i++) {
				costs[i] = scanner.nextLong();
			}
			Arrays.sort(costs, Collections.reverseOrder());

			for (int i = 0; i < n; i++) {
				double y;
				if (m > 0) {
					y = Math.pow(2, m % 2 == 1 ? m / 2 + 1 : m / 2);
					m = m / 2;
					costs[i] = (long) Math.floor(costs[i] / y);
				} else {
					break;
				}
			}

			long ans = 0;
			for (int i = 0; i < n; i++) {
				ans += costs[i];
			}

			System.out.println(ans);
		}
	}
}