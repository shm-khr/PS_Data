import java.util.Scanner;

class Main {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(); //個数
		int total = in.nextInt(); //許容量
		int[] v = new int[n];//価値
		int[] w = new int[n];//重さ
		int[] m = new int[n];//個数
		for (int i = 0; i < n; i++) {
			v[i] = in.nextInt();
			w[i] = in.nextInt();
			m[i] = in.nextInt();
		}
		int[][] t = new int[n][total + 1];

		for (int i = 0; i < n; i++) {
			for (int x = 1; x <= m[i]; x++) {
				if(w[i]*x>total) {
					break;
				}
				for (int j = 1; j <= total; j++) {
					if (i == 0) {
						if (j >= w[i]*x) {
							t[i][j] = v[i]*x;
						}

					} else {
						if(w[i]*x>j) {
							t[i][j] = Math.max(t[i - 1][j],t[i][j]);
						}else{
							t[i][j] =Math.max(t[i][j], Math.max(t[i - 1][j], t[i - 1][j - (w[i]*x)] + (v[i]*x)));
						}
					}
					//System.out.printf("t[%d][%d]=%d\n", i, j, t[i][j]);
				}
			}
		}
		System.out.println(t[n - 1][total]);
		in.close();
	}
}

