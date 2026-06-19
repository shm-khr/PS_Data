import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		InputReader r = new InputReader(System.in);
		int n = r.nextInt();
		int k = r.nextInt();
		ArrayList<Integer> adj[] = new ArrayList[n];
		for (int i = 0; i < adj.length; i++) {
			adj[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < n - 1; i++) {
			int from = r.nextInt() - 1;
			int to = r.nextInt() - 1;
			adj[from].add(to);
			adj[to].add(from);
		}
		int res = 1 << 28;
		for (int i = 0; i < n; i++) {
			LinkedList<Integer> q = new LinkedList<Integer>();
			q.add(i);
			q.add(0);
			boolean[] vis = new boolean[n];
			vis[i] = true;
			HashSet<Integer> set = new HashSet<Integer>();
			int last = -1;
			while (!q.isEmpty()) {
				int front = q.remove();
				set.add(front);
				last = front;
				int cost = q.remove();
				if (cost == k) {
					continue;
				}
				for (int x : adj[front]) {
					if (!vis[x]) {
						q.add(x);
						q.add(cost + 1);
						vis[x] = true;
					}
				}
			}
			vis = new boolean[n];
			vis[last] = true;
			q.add(last);
			q.add(0);
			int diameter = -1;
			int reached = 0;
			HashSet<Integer> set2 = new HashSet<Integer>();
			while (!q.isEmpty()) {
				int front = q.remove();
				int cost = q.remove();
				reached++;
				diameter = cost;
				if (diameter <= k) {
					last = front;
					set2.add(front);
					res = Math.min(res, n - reached);
				}
				for (int x : adj[front]) {
					if (!vis[x] && set.contains(x)) {
						q.add(x);
						q.add(cost + 1);
						vis[x] = true;
					}
				}
			}
			vis = new boolean[n];
			vis[last] = true;
			q.add(last);
			q.add(0);
			reached = 0;
			diameter = -1;
			while (!q.isEmpty()) {
				int front = q.remove();
				int cost = q.remove();
				reached++;
				diameter = cost;
				if (diameter <= k) {
					last = front;
					res = Math.min(res, n - reached);
				}
				for (int x : adj[front]) {
					if (!vis[x] && set2.contains(x)) {
						q.add(x);
						q.add(cost + 1);
						vis[x] = true;
					}
				}
			}
		}
		System.out.println(res);
	}

	static class InputReader {
		private BufferedReader reader;
		private StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream));
			tokenizer = null;
		}

		public InputReader(FileReader stream) {
			reader = new BufferedReader(stream);
			tokenizer = null;
		}

		public String nextLine() {
			try {
				return reader.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				return null;
			}
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}
	}
}
