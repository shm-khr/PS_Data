import java.util.Scanner;

public class Main{
	public static void main(String args[]) {
		Scanner scn = new Scanner(System.in);
		int N = scn.nextInt();
		int W = scn.nextInt();
		int[] DP = new int[W + 1];
		for (int i = 0; i < N; i++) {
			int val = scn.nextInt(), w = scn.nextInt(), m = scn.nextInt();
			for (int k = 0; k < m; k++) {
				for (int j = W; j > 0; j--) {
					if (j >= w) {
						DP[j] = Math.max(DP[j], DP[j - w] + val);
					}
				}
			}
		}
		System.out.println(DP[W]);
		scn.close();
	}
}
