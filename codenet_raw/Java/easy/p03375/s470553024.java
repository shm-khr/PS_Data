import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;

public class Main {

	static PrintWriter out;
	static InputReader ir;

	static void solve() {
		int n = ir.nextInt();
		mod = ir.nextLong();
		long[] p = new long[n * n + 1];
		long[] q = new long[n + 1];
		p[0] = 1;
		q[0] = 2;
		for (int i = 0; i < n * n; i++) {
			p[i + 1] = p[i] * 2;
			p[i + 1] %= mod;
		}
		for (int i = 0; i < n; i++) {
			q[i + 1] = q[i] * q[i];
			q[i + 1] %= mod;
		}
		long[] f = fact(n), fi = factInv(n);
		long[][] s = stirling(n);
		long res = 0;
		for (int i = 0; i <= n; i++) {
			int k = n - i;
			long t = 0;
			for (int j = 0; j <= i; j++) {
				t += ((s[i][j] + (i == j ? 0 : s[i][j + 1] * (j + 1))) % mod * p[j * k]) % mod;
			}
			if (i % 2 == 0)
				res += t * comb(n, i, f, fi) * q[k];
			else
				res -= (t * comb(n, i, f, fi) * q[k] % mod) - mod;
			res %= mod;
		}
		out.println(res);
	}

	static long mod;

	private static long[] fact(int n) {
		long[] ret = new long[n + 1];
		ret[0] = 1 % mod;
		for (int i = 1; i <= n; i++) {
			ret[i] = ret[i - 1] * i;
			ret[i] %= mod;
		}
		return ret;
	}

	private static long[] factInv(int n) {
		long[] ret = new long[n + 1];
		ret[0] = 1;
		for (int i = 1; i <= n; i++) {
			ret[i] = ret[i - 1] * mod_inverse((long) i) % mod;
		}
		return ret;
	}

	public static long comb(int n, int m, long[] fact, long[] factInv) {
		long ret = fact[n];
		ret *= factInv[m];
		ret %= mod;
		ret *= factInv[n - m];
		ret %= mod;
		return ret;
	}

	public static long[][] stirling(int n) {
		long[][] ret = new long[n + 1][n + 1];
		ret[0][0] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= i; j++)
				ret[i][j] = (ret[i - 1][j - 1] + ret[i - 1][j] * j) % mod;
		return ret;
	}

	public static long mod_inverse(long a) {
		long[] ret = extgcd(a, mod);
		return (mod + ret[0] % mod) % mod;
	}

	public static long[] extgcd(long a, long b) {
		long[] ret = new long[3];
		ret[2] = _extgcd(a, b, ret);
		return ret;
	}

	private static long _extgcd(long a, long b, long[] x) {
		long g = a;
		x[0] = 1;
		x[1] = 0;
		if (b != 0) {
			g = _extgcd(b, a % b, x);
			long temp = x[0];
			x[0] = x[1];
			x[1] = temp;
			x[1] -= (a / b) * x[0];
		}
		return g;
	}

	public static void main(String[] args) {
		ir = new InputReader(System.in);
		out = new PrintWriter(System.out);
		solve();
		out.flush();
	}

	static class InputReader {

		private InputStream in;
		private byte[] buffer = new byte[1024];
		private int curbuf;
		private int lenbuf;

		public InputReader(InputStream in) {
			this.in = in;
			this.curbuf = this.lenbuf = 0;
		}

		public boolean hasNextByte() {
			if (curbuf >= lenbuf) {
				curbuf = 0;
				try {
					lenbuf = in.read(buffer);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (lenbuf <= 0)
					return false;
			}
			return true;
		}

		private int readByte() {
			if (hasNextByte())
				return buffer[curbuf++];
			else
				return -1;
		}

		private boolean isSpaceChar(int c) {
			return !(c >= 33 && c <= 126);
		}

		private void skip() {
			while (hasNextByte() && isSpaceChar(buffer[curbuf]))
				curbuf++;
		}

		public boolean hasNext() {
			skip();
			return hasNextByte();
		}

		public String next() {
			if (!hasNext())
				throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while (!isSpaceChar(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}

		public int nextInt() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}

		public long nextLong() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

		public int[] nextIntArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		public long[] nextLongArray(int n) {
			long[] a = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}

		public char[][] nextCharMap(int n, int m) {
			char[][] map = new char[n][m];
			for (int i = 0; i < n; i++)
				map[i] = next().toCharArray();
			return map;
		}
	}

	static void tr(Object... o) {
		out.println(Arrays.deepToString(o));
	}
}
