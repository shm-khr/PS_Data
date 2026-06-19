import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.NoSuchElementException;
import java.util.PriorityQueue;

class Main implements Runnable {

	public static void main(String[] args) {
		new Thread(null, new Main(), "", Runtime.getRuntime().maxMemory()).start();
	}

	class Edge {
		int src, dst;
		long s;

		public Edge(int src_, int dst_, long s_) {
			src = src_;
			dst = dst_;
			s = s_;
		}
	}

	public void run() {
		Scanner sc = new Scanner();
		int n = sc.nextInt();// 1e5
		int m = sc.nextInt();// 1e5
		int[] u = new int[m];
		int[] v = new int[m];
		long[] s = new long[m];// 1e9
		ArrayList<Edge>[] g = new ArrayList[n];
		for (int i = 0; i < n; ++i) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; ++i) {
			u[i] = sc.nextInt();
			v[i] = sc.nextInt();
			s[i] = sc.nextLong();
			--u[i];
			--v[i];
			g[u[i]].add(new Edge(u[i], v[i], s[i]));
			g[v[i]].add(new Edge(v[i], u[i], s[i]));
		}
		int[] col = new int[n];
		long[] cnt = new long[n];
		Arrays.fill(col, -1);
		col[0] = 1;
		dfs(0, -1, col, g, cnt);
		if (Math.abs(max % 1 - 0.5) < 1e-3)
			max = (int) max + 1;
		if (Math.abs(min % 1 - 0.5) < 1e-3)
			min = (int) min;
		max = Math.round(max);
		min = Math.round(min);
		System.out.println((int) Math.max(0, max - min - 1));
	}

	double min = 0;// min < v < max
	double max = Double.MAX_VALUE / 3;

	void dfs(int cur, int par, int[] col, ArrayList<Edge>[] g, long[] cnt) {
		if (col[cur] == 1) {
			min = Math.max(min, -cnt[cur]);
		} else if (col[cur] == 0) {
			max = Math.min(max, cnt[cur]);
		}
		for (Edge e : g[cur]) {
			if (e.dst == par)
				continue;
			if (col[e.dst] != -1) {
				if (col[e.src] != col[e.dst] && Math.abs(cnt[e.dst] + cnt[e.src] - e.s) > 1e-3) {
					min = Double.MAX_VALUE / 3;
					max = -Double.MAX_VALUE / 3;
				} else if (col[e.src] == col[e.dst] && col[e.src] == 1) {
					// cnt[src]+cnt[dst]+2v=e.s
					min = Math.max(min, (e.s - cnt[e.src] - cnt[e.dst]) / 2 - 1);
					max = Math.min(max, (e.s - cnt[e.src] - cnt[e.dst]) / 2) + 1;
				} else if (col[e.src] == col[e.dst] && col[e.src] == -1) {
					// cnt[src]+cnt[dst]-2v>0
					min = Math.max(min, (-e.s + cnt[e.src] + cnt[e.dst]) / 2 - 1);
					max = Math.min(max, (-e.s + cnt[e.src] + cnt[e.dst]) / 2) + 1;
				}
			} else {
				col[e.dst] = col[cur] ^ 1;
				cnt[e.dst] = e.s - cnt[e.src];
				dfs(e.dst, e.src, col, g, cnt);
			}
		}
	}

	class Scanner {
		private final InputStream in = System.in;
		private final byte[] buffer = new byte[1024];
		private int ptr = 0;
		private int buflen = 0;

		private boolean hasNextByte() {
			if (ptr < buflen) {
				return true;
			} else {
				ptr = 0;
				try {
					buflen = in.read(buffer);
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (buflen <= 0) {
					return false;
				}
			}
			return true;
		}

		private int readByte() {
			if (hasNextByte())
				return buffer[ptr++];
			else
				return -1;
		}

		private boolean isPrintableChar(int c) {
			return 33 <= c && c <= 126;
		}

		private void skipUnprintable() {
			while (hasNextByte() && !isPrintableChar(buffer[ptr]))
				ptr++;
		}

		public boolean hasNext() {
			skipUnprintable();
			return hasNextByte();
		}

		public String next() {
			if (!hasNext())
				throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while (isPrintableChar(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}

		public long nextLong() {
			if (!hasNext())
				throw new NoSuchElementException();
			long n = 0;
			boolean minus = false;
			int b = readByte();
			if (b == '-') {
				minus = true;
				b = readByte();
			}
			if (b < '0' || '9' < b) {
				throw new NumberFormatException();
			}
			while (true) {
				if ('0' <= b && b <= '9') {
					n *= 10;
					n += b - '0';
				} else if (b == -1 || !isPrintableChar(b)) {
					return minus ? -n : n;
				} else {
					throw new NumberFormatException();
				}
				b = readByte();
			}
		}

		int nextInt() {
			return (int) nextLong();
		}
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}