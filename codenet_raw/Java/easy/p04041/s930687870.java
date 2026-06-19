import java.io.*;
import java.util.*;

public class Main {

	static int[][] memo;
	static int[] stages;
	static int MOD = (int) 1e9 + 7;

	static int dp(int idx, int msk) {
		if (check(msk))
			return 0;
		if (idx == 0)
			return 1;

		if (memo[msk][idx] != -1)
			return memo[msk][idx];
		long ans = 0;

		for (int d = 1; d <= 10; d++) {
			int newMsk = updMsk(msk, d);
			ans += dp(idx - 1, newMsk);
			ans %= MOD;
		}

		return memo[msk][idx] = (int) ans;
	}

	private static int updMsk(int msk, int d) {
//		String s = numToString(d);
//		String curr = Integer.toBinaryString(msk);
//		int take = Math.min(17 - s.length(), curr.length());
//		StringBuilder ans = new StringBuilder();
//		for (int i = curr.length() - take; i < curr.length(); i++)
//			ans.append(curr.charAt(i));
//		ans.append(s);
//		int ret = 0;
//		for (int i = ans.length() - 1, bit = 0; i >= 0; i--, bit++)
//			if (ans.charAt(i) == '1')
//				ret |= 1 << bit;
//		return ret;
		return (msk<<d | (1<<(d-1))) & ((1<<17)-1); 

	}

	static String numToString(int x) {
		StringBuilder sb = new StringBuilder("1");
		while (sb.length() < x)
			sb.append("0");
		return sb.toString();
	}

	private static boolean check(int msk) {
		char[] a = Integer.toBinaryString(msk).toCharArray();
		ArrayList<Integer> values = new ArrayList();
		for (int i = a.length - 1, len = 0; i >= 0; i--) {
			len++;
			if (a[i] == '1') {
				values.add(len);
				len = 0;
			}
		}
		int sum = 0, stage = 2;
		for (int x : values) {
			sum += x;
			if (sum > stages[stage])
				return false;
			if (sum == stages[stage]) {
				stage--;
				sum = 0;
			}
			if (stage == -1)
				return true;
		}
		return false;
	}

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt();
		stages = new int[3];
		memo=new int [1<<17][n+1];
		for(int []x:memo)
			Arrays.fill(x, -1);
		for (int i = 0; i < 3; i++)
			stages[i] = sc.nextInt();
		long ans=1;
		for(int i=0;i<n;i++)
			ans=ans*10%MOD;
		ans-=dp(n,0);
		if(ans<0)
			ans+=MOD;
		System.out.println(ans);
		out.close();

	}

	static class Scanner {
		BufferedReader br;
		StringTokenizer st;

		Scanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		Scanner(String fileName) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(fileName));
		}

		String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		String nextLine() throws IOException {
			return br.readLine();
		}

		int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		long nextLong() throws NumberFormatException, IOException {
			return Long.parseLong(next());
		}

		double nextDouble() throws NumberFormatException, IOException {
			return Double.parseDouble(next());
		}

		boolean ready() throws IOException {
			return br.ready();
		}

		int[] nxtArr(int n) throws IOException {
			int[] ans = new int[n];
			for (int i = 0; i < n; i++)
				ans[i] = nextInt();
			return ans;
		}

	}

	static void sort(int[] a) {
		shuffle(a);
		Arrays.sort(a);
	}

	static void shuffle(int[] a) {
		int n = a.length;
		Random rand = new Random();
		for (int i = 0; i < n; i++) {
			int tmpIdx = rand.nextInt(n);
			int tmp = a[i];
			a[i] = a[tmpIdx];
			a[tmpIdx] = tmp;
		}
	}

}