import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int k[] = new int[M];
		int s[][] = new int[M][N];
		for(int i = 0; i < M; i++) {
			Arrays.fill(s[i], -1);
		}
		for(int i = 0; i < M; i++) {
			k[i] = sc.nextInt();
			for(int j = 0; j < k[i]; j++) {
				s[i][j] = sc.nextInt() - 1;
			}
		}	
		int p[] = new int[M];
		for(int i = 0; i < M; i++) {
			p[i] = sc.nextInt();
		}

		int ans = 0;
		out : for (int i = 0; i < (Math.pow(2, N)); i++) {
			boolean flag[] = new boolean[N];
			for(int j = 0; j < M; j++) {
				if ((1&i>>j) == 1) {
					flag[j] = true;
				}
			}
			for(int j = 0; j < M; j++) {
				int cnt[] = new int[N];
				for(int a = 0; a < k[j]; a++) {
					if(flag[s[j][a]]) {
						cnt[j]++;
					}
				}
				if(cnt[j] % 2 != p[j]) {
					continue out;
				}
			}
			ans++;
		}
		System.out.println(ans);
	}
}
