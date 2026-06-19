import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

	String fileName = "prizes";

	public void solve() throws IOException {
		int n = nextInt();
		int ans = 0;
		int ans2 = 0;
		int[][] a = new int[2][n];
		int[][] sum = new int[2][n];
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++) {
				a[i][j] = nextInt();
				if (j == 0)
					sum[i][j] = a[i][j];
				else
					sum[i][j] = sum[i][j - 1] + a[i][j];
			}
		int i = 0;
		int j = 0;

		while (i < 1 && j < n - 1) {
			ans += a[i][j];
			if (sum[i + 1][n - 1] - sum[i + 1][j] + a[i + 1][j] > sum[i][n - 1] - sum[i][j] + a[1][n - 1])
				i++;
			else
				j++;

		}
		if (i == 1)
			for (; j < n; j++)
				ans += a[i][j];
		else {
			ans += a[0][n - 1];
			ans += a[1][n - 1];
		}
		i = 0;
		j = 0;

		while (i < 1 && j < n - 1) {
			ans2 += a[i][j];
			if (a[i + 1][j] > a[i][j + 1])
				i++;
			else
				j++;

		}
		if (i == 1)
			for (; j < n; j++)
				ans2 += a[i][j];
		else {
			ans2 += a[0][n - 1];
			ans2 += a[1][n - 1];
		}

		out.println(Math.max(ans, ans2));

	}

	public void run() {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out, true);
			solve();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	BufferedReader br;
	StringTokenizer in;
	static PrintWriter out;

	public String nextToken() throws IOException {
		while (in == null || !in.hasMoreTokens()) {
			in = new StringTokenizer(br.readLine());
		}
		return in.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public static void main(String[] args) throws IOException {
		new Main().run();
	}

}