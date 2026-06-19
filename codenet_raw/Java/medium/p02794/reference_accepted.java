import java.io.*;
import java.util.*;

public class Main {

	static ArrayList<Integer>[] adj;
	static int timer, par[], tin[], tout[];

	static int lca(int u, int v) {
		while (true) {
			if (tin[v] >= tin[u] && tin[v] <= tout[u])
				break;
			u = par[u];
		}
		return u;
	}

	static int[] prefix;

	static void update(int u, int lca) {
		prefix[u]++;
		prefix[lca]--;
	}

	static int dfs(int u, int p) {
		par[u] = p;
		tin[u] = timer++;
		int ans = 0;
		for (int v : adj[u])
			if (v != p) {
				ans += dfs(v, u);
				prefix[u] += prefix[v];
			} 
		if (prefix[u] > 0)
			ans++;
		tout[u] = timer - 1;
		return ans;
	}

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt();
		adj = new ArrayList[n];
		par = new int[n];
		tin = new int[n];
		prefix = new int[n];

		tout = new int[n];
		for (int i = 0; i < n; i++) {
			adj[i] = new ArrayList();
		}
		for (int i = 1; i < n; i++) {
			int u = sc.nextInt() - 1, v = sc.nextInt() - 1;
			adj[u].add(v);
			adj[v].add(u);
		}
		dfs(0, 0);
		
		int[][] lca = new int[n][n];
		int m = sc.nextInt();
		int[] a = new int[m], b = new int[m];
		for (int i = 0; i < m; i++) {
			a[i] = sc.nextInt() - 1;
			b[i] = sc.nextInt() - 1;
			lca[a[i]][b[i]] = lca(a[i], b[i]);
		}
		long ans = 0;
		for (int msk = 0; msk < 1 << m; msk++) {
			Arrays.fill(prefix, 0);
			for (int i = 0; i < m; i++) {
				if ((msk & 1 << i) == 0)
					continue;
				update(a[i], lca[a[i]][b[i]]);
				update(b[i], lca[a[i]][b[i]]);

			}
			int c = dfs(0, 0);  

			ans += (1L << (n - 1 - c)) * (Integer.bitCount(msk) % 2 == 0 ? 1 : -1);
		}
		out.println(ans);
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