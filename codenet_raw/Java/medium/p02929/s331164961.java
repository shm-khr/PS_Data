import java.io.*;
import java.util.NoSuchElementException;


public class Main {

	private static Scanner sc;
	private static Printer pr;

	private static void solve() {
		final int MOD = 1_000_000_007;

		int n = sc.nextInt();

		char[] s = sc.next().toCharArray();

		int[] p1 = new int[2 * n + 1];
		int[] p2 = new int[2 * n + 1];
		int[] p = new int[2 * n];
		long ans = 1;
		for (int i = 0; i < 2 * n; i++) {
			int tmp = p1[i] - p2[i];
			if (tmp % 2 == 0 && s[i] == 'B') {
				p1[i + 1]++;
				p[i] = 1;
			} else if (tmp % 2 == 0 && s[i] == 'W') {
				p2[i + 1]++;
				p[i] = 2;
			} else if (tmp % 2 == 1 && s[i] == 'B') {
				p2[i + 1]++;
				p[i] = 2;
			} else if (tmp % 2 == 1 && s[i] == 'W') {
				p1[i + 1]++;
				p[i] = 1;
			}
			
			p1[i + 1] += p1[i];
			p2[i + 1] += p2[i];
			if (p[i] == 1) {
			} else {
				ans *= p1[i] - p2[i];
				ans %= MOD;
			}
		}

		if (p1[n] != p2[n]) {
			pr.println(0);
		} else {
			for (int i = 2; i <= n; i++) {
				ans *= i;
				ans %= MOD;
			}
		
			pr.println(ans);
		}
	}

	// ---------------------------------------------------
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		pr = new Printer(System.out);
			
		solve();
			
		pr.close();
		sc.close();
	}

	static class Scanner {
		BufferedReader br;

		Scanner (InputStream in) {
			br = new BufferedReader(new InputStreamReader(in));
		}

		private boolean isPrintable(int ch) {
			return ch >= '!' && ch <= '~';
		}

		private boolean isCRLF(int ch) {
			return ch == '\n' || ch == '\r' || ch == -1;
		}

		private int nextPrintable() {
			try {
				int ch;
				while (!isPrintable(ch = br.read())) {
					if (ch == -1) {
						throw new NoSuchElementException();
					}
				}

				return ch;
			} catch (IOException e) {
				throw new NoSuchElementException();
			}
		}

		String next() {
			try {
				int ch = nextPrintable();
				StringBuilder sb = new StringBuilder();
				do {
					sb.appendCodePoint(ch);
				} while (isPrintable(ch = br.read()));

				return sb.toString();
			} catch (IOException e) {
				throw new NoSuchElementException();
			}
		}

		int nextInt() {
			try {
				// parseInt from Integer.parseInt()
				boolean negative = false;
				int res = 0;
				int limit = -Integer.MAX_VALUE;
				int radix = 10;

				int fc = nextPrintable();
				if (fc < '0') {
					if (fc == '-') {
						negative = true;
						limit = Integer.MIN_VALUE;
					} else if (fc != '+') {
						throw new NumberFormatException();
					}
					fc = br.read();
				}
				int multmin = limit / radix;

				int ch = fc;
				do {
					int digit = ch - '0';
					if (digit < 0 || digit >= radix) {
						throw new NumberFormatException();
					}
					if (res < multmin) {
						throw new NumberFormatException();
					}
					res *= radix;
					if (res < limit + digit) {
						throw new NumberFormatException();
					}
					res -= digit;

				} while (isPrintable(ch = br.read()));

				return negative ? res : -res;
			} catch (IOException e) {
				throw new NoSuchElementException();
			}
		}

		long nextLong() {
			try {
				// parseLong from Long.parseLong()
				boolean negative = false;
				long res = 0;
				long limit = -Long.MAX_VALUE;
				int radix = 10;

				int fc = nextPrintable();
				if (fc < '0') {
					if (fc == '-') {
						negative = true;
						limit = Long.MIN_VALUE;
					} else if (fc != '+') {
						throw new NumberFormatException();
					}
					fc = br.read();
				}
				long multmin = limit / radix;

				int ch = fc;
				do {
					int digit = ch - '0';
					if (digit < 0 || digit >= radix) {
						throw new NumberFormatException();
					}
					if (res < multmin) {
						throw new NumberFormatException();
					}
					res *= radix;
					if (res < limit + digit) {
						throw new NumberFormatException();
					}
					res -= digit;

				} while (isPrintable(ch = br.read()));

				return negative ? res : -res;
			} catch (IOException e) {
				throw new NoSuchElementException();
			}
		}

		float nextFloat() {
			return Float.parseFloat(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			try {
				int ch;
				while (isCRLF(ch = br.read())) {
					if (ch == -1) {
						throw new NoSuchElementException();
					}
				}
				StringBuilder sb = new StringBuilder();
				do {
					sb.appendCodePoint(ch);
				} while (!isCRLF(ch = br.read()));

				return sb.toString();
			} catch (IOException e) {
				throw new NoSuchElementException();
			}
		}
		
		int[] nextIntArray(int n) {
			int[] ret = new int[n];
			for (int i = 0; i < n; i++) {
				ret[i] = sc.nextInt();
			}
			
			return ret;
		}

		int[][] nextIntArrays(int m, int n) {
			int[][] ret = new int[m][n];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					ret[j][i] = sc.nextInt();
				}
			}
			
			return ret;
		}

		void close() {
			try {
				br.close();
			} catch (IOException e) {
//				throw new NoSuchElementException();
			}
		}
	}

	static class Printer extends PrintWriter {
		Printer(OutputStream out) {
			super(out);
		}
		
		void printInts(int... a) {
			StringBuilder sb = new StringBuilder(32);
			for (int i = 0, size = a.length; i < size; i++) {
				if (i > 0) {
					sb.append(' ');
				}
				sb.append(a[i]);
			}

			println(sb);
		}
		
		void printLongs(long... a) {
			StringBuilder sb = new StringBuilder(64);
			for (int i = 0, size = a.length; i < size; i++) {
				if (i > 0) {
					sb.append(' ');
				}
				sb.append(a[i]);
			}

			println(sb);
		}
		
		void printStrings(String... a) {
			StringBuilder sb = new StringBuilder(32);
			for (int i = 0, size = a.length; i < size; i++) {
				if (i > 0) {
					sb.append(' ');
				}
				sb.append(a[i]);
			}

			println(sb);
		}
	}
}
