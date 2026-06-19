import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		C_LexicographicConstraints solver = new C_LexicographicConstraints();
		solver.solve(1, in, out);
		out.close();
	}

	static class C_LexicographicConstraints {
		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			int n = in.nextInt();
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = in.nextInt();
			}

			int[] stackVal = new int[n];
			int[] stackAm = new int[n];
			int stackPtr = 0;
			for (int x : a) {
				if (stackPtr == 0 || stackVal[stackPtr - 1] < x) {
					stackVal[stackPtr] = x;
					stackAm[stackPtr] = 1;
					++stackPtr;
				} else if (stackVal[stackPtr - 1] == x) {
					++stackAm[stackPtr];
				}
			}

			Arrays.sort(a);
			int l = 0;
			int r = a[n - 1] + 1;
			while (r - l > 1) {
				int m = (l + r) / 2;
				boolean ok = true;
				int carry = 0;
				for (int i = 0; i < stackPtr; i++) {
					if (i == 0 || stackVal[i - 1] - 1 != stackVal[i]) {
						carry = 0;
					}
					carry += stackAm[i];
					carry /= m;
					if (carry >= m) {
						ok = false;
						break;
					}
				}
				if (ok) {
					r = m;
				} else {
					l = m;
				}
			}
			out.println(r);
		}

	}

	static class FastScanner {
		private BufferedReader in;
		private StringTokenizer st;

		public FastScanner(InputStream stream) {
			in = new BufferedReader(new InputStreamReader(stream));
		}

		public String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					String rl = in.readLine();
					if (rl == null) {
						return null;
					}
					st = new StringTokenizer(rl);
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

	}
}

