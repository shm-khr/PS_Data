
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Main main = new Main();
		main.run();
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int a[][] = new int[2][n];
		int sum[][] = new int[2][n+1];
		for(int i=0; i<2; i++) {
			for(int j=0; j<n; j++) {
				a[i][j]=sc.nextInt();
				sum[i][j+1] = sum[i][j] + a[i][j];
			}
		}
		int ans = 0;
		for(int i=1; i<=n; i++) {
			int sum1 = sum[0][i];
			int sum2 = sum[1][n] - sum[1][i-1];
			ans = Math.max(ans, sum1+sum2);
		}
		System.out.println(ans);
		sc.close();
	}
}
