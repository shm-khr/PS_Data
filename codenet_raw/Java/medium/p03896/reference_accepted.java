import java.util.*;
import java.lang.*;

public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		if (n == 2) {
			System.out.println(-1);
		} else {
			int[][] a = new int[n][n - 1];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n - 1; j++) {
					a[i][j] = (i + 2 + j) % n;
					if (a[i][j] == 0) {
						a[i][j] = n;
					}
				}
			}
			if (n % 2 == 0) {
				for (int i = 0; i < n / 2; i++) {
					int tmp = a[i][n / 2];
					a[i][n / 2] = a[i][n / 2 - 1];
					a[i][n / 2 - 1] = tmp;
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n - 2; j++) {
					System.out.print(a[i][j] + " ");
				}
				System.out.println(a[i][n - 2]);
			}
		}
	}
}