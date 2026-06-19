
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.util.Map.Entry;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {

	public static void main(String[] args) throws IOException {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskX solver = new TaskX();
		solver.solve(1, in, out);
		out.close();
	}

	static int INF = 1 << 30;
	static int MOD = 1000000007;
	static int[] mh4 = { 0, -1, 1, 0 };
	static int[] mw4 = { -1, 0, 0, 1 };
	static int[] mh8 = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int[] mw8 = { -1, 0, 1, -1, 1, -1, 0, 1 };

	static class TaskX {

		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int n = in.nextInt();
			long W = in.nextLong();
			long[] v1 = new long[n/2];
			long[] w1 = new long[n/2];
			long[] v2 = new long[n-n/2];
			long[] w2 = new long[n-n/2];

			for (int i = 0; i < n/2; i++) {
				v1[i] = in.nextLong();
				w1[i] = in.nextLong();
			}
			for (int i = 0; i < n-n/2; i++) {
				v2[i] = in.nextLong();
				w2[i] = in.nextLong();
			}


			TreeMap<Long, Long> t1 = new TreeMap<>();

			for (int i = 0; i < (1<<n/2); i++) {
				long wtmp = 0, vtmp = 0;
				for (int j = 0; j < n/2; j++) {
					if ((i >> j & 1) == 1) {
						vtmp += v1[j];
						wtmp += w1[j];
					}
				}
				if (wtmp <= W) {
					t1.put(wtmp, vtmp);
				}
			}

			TreeMap<Long, Long> t2 = new TreeMap<>();

			for (int i = 0; i < (1<<(n-n/2)); i++) {
				long wtmp = 0, vtmp = 0;
				for (int j = 0; j < n-n/2; j++) {
					if ((i >> j & 1) == 1) {
						vtmp += v2[j];
						wtmp += w2[j];
					}
				}
				if (wtmp <= W) {
					t2.put(wtmp, vtmp);
				}
			}

			long max = 0;

			TreeMap<Long, Long> m1 = new TreeMap<>();
			TreeMap<Long, Long> m2 = new TreeMap<>();

			for (Entry<Long, Long> e : t1.entrySet()) {
				if (e.getValue() < max) {
					continue;
				}
				max = e.getValue();
				m1.put(e.getKey(), e.getValue());
			}

			max = 0;
			for (Entry<Long, Long> e : t2.entrySet()) {
				if (e.getValue() < max) {
					continue;
				}
				max = e.getValue();
				m2.put(e.getKey(), e.getValue());
			}

			long ans = 0;
			for (Entry<Long, Long> e1 : m1.entrySet()) {
				for (Entry<Long, Long> e2 : m2.entrySet()) {
					if (e1.getKey()+e2.getKey() <= W) {
						ans = Math.max(ans, e1.getValue()+e2.getValue());
					}
				}
			}


			out.println(ans);

		}
	}

	static class InputReader {
		BufferedReader in;
		StringTokenizer tok;

		public String nextString() {
			while (!tok.hasMoreTokens()) {
				try {
					tok = new StringTokenizer(in.readLine(), " ");
				} catch (IOException e) {
					throw new InputMismatchException();
				}
			}
			return tok.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextString());
		}

		public long nextLong() {
			return Long.parseLong(nextString());
		}

		public double nextDouble() {
			return Double.parseDouble(nextString());
		}

		public int[] nextIntArray(int n) {
			int[] res = new int[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextInt();
			}
			return res;
		}

		public long[] nextLongArray(int n) {
			long[] res = new long[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextLong();
			}
			return res;
		}

		public InputReader(InputStream inputStream) {
			in = new BufferedReader(new InputStreamReader(inputStream));
			tok = new StringTokenizer("");
		}
	}

}

