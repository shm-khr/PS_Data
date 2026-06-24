package abc087;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		try (Scanner sc = new Scanner(System.in)) {
			int n = sc.nextInt();
			Integer[] a1 = new Integer[n];
			Integer[] a2 = new Integer[n];
			
			int sum1 = 0;
			int sum2 = 0;
			for (int i = 0; i < n; i++) {
				a1[i] = sc.nextInt();
				sum1 += a1[i];
			}
			for (int i = 0; i < n; i++) {
				a2[i] = sc.nextInt();
				sum2 += a2[i];
			}
			
			int result = 0;
			int now = 0;
			for (int i = 0; i < n; i++) {
				sum1 -= a1[i];
				sum2 -= a2[i];
				if (sum1 <= sum2) {
					now = i;
					result += a1[i];
					break;
				} else {
					now = i;
					result += a1[i];
				}
			}
			for (int i = now; i < n; i++) {
				result += a2[i];
			}
			System.out.println(result);		
		}
	}
}
