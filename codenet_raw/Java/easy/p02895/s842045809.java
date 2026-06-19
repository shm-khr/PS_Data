import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

	static int n;
	static long a[];
	static Map<Long, long[]> res;

	static void solve() throws Exception {
		n = scanInt();
		a = new long[2 * n];
		for (int i = 0; i < 2 * n; i++) {
			String l = scanString();
			long cur = 0;
			for (int j = 0; j < 2 * n; j++) {
				if (l.charAt(j) == '1') {
					cur |= 1L << j;
				}
			}
			a[i] = cur;
		}
		res = new HashMap<>();
		for (int i = 0; i < 2 * n; i++) {
			for (int j = i + 1; j < 2 * n; j++) {
				if ((a[i] & (1L << j)) != 0) {
					res.put((1L << i) | (1L << j), new long[] {1});
				}
			}
		}
		out.print(solve((1L << (2 * n)) - 1)[0]);
	}

	static long[] solve(long set) {
		long r[] = res.get(set);
		if (r == null) {
			int s = Long.bitCount(set), p = 0;
			r = new long[s - 1];
			for (int i = 2 * n - 1, i2 = -1, i3 = -1, j = s - 1; i >= 0; i--) {
				if ((set & (1L << i)) == 0) {
					continue;
				}
				if (j < s - 3) {
					if ((a[i] & (1L << i3)) != 0) {
						p += solve(set ^ (1L << i) ^ (1L << i3))[max(j - 2, 0)];
					}
					r[j] = p;
				}
				i3 = i2;
				i2 = i;
				--j;
			}
			res.put(set, r);
		}
		return r;
	}

	static int scanInt() throws IOException {
		return parseInt(scanString());
	}

	static long scanLong() throws IOException {
		return parseLong(scanString());
	}

	static String scanString() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}