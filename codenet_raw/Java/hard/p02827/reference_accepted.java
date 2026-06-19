import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.BitSet;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int T = sc.nextInt();
		int[] x = new int[M], y = new int[M];
		for (int i = 0; i < M; i++) {
			x[i] = sc.nextInt() - 1;
			y[i] = sc.nextInt() - 1;
		}
		if (T == 1) {
			BitSet[] set = new BitSet[N];
			for (int i = 0; i < N; i++) {
				set[i] = new BitSet(N);
				set[i].set(i);
			}
			int last = -1;
			for (int i = 0; i < M && last == -1; i++) {
				set[x[i]].or(set[y[i]]);
				set[y[i]].or(set[x[i]]);
				if (set[x[i]].cardinality() == N) {
					last = x[i];
				}
			}
			if (last == -1) {
				out.println(-1);
			} else {
				BitSet me = new BitSet();
				char[] ret = new char[M];
				me.set(last);
				for (int i = M - 1; i >= 0; i--) {
					if (me.get(x[i])) {
						ret[i] = '^';
						me.set(y[i]);
					} else {
						ret[i] = 'v';
						if (me.get(y[i])) {
							me.set(x[i]);
						}
					}
				}
				out.println(new String(ret));
			}
		}
		if (T == 2) {
			if (N == 2) {
				out.println(-1);
			} else {
				char[] ret = new char[M];
				int[] relevant = new int[M];
				int relSize = 0;
				
				for (int i = 0; i < M; i++) {
					if (y[i] < 3) {
						relevant[relSize++] = i;
					} else {
						ret[i] = '^';
					}
				}
				
				int mask = 7;
				for (int i = 0; i < relSize; i++) {
					int idx = relevant[i];
					int nextMask = 0;
					if (i + 1 < relSize) {
						nextMask = (1 << x[relevant[i+1]]) | (1 << y[relevant[i+1]]);
					}
					int upMask = mask & ~(1<<y[idx]) | (1<<x[idx]);
					if (upMask != nextMask) {
						ret[idx] = '^';
						mask = upMask;
					} else {
						ret[idx] = 'v';
						mask = mask & ~(1<<x[idx]) | (1<<y[idx]);
					}
				}
				
				out.println(new String(ret));
			}
		}
		
		out.flush();
	}
	
	static class MyScanner {
		private BufferedReader br;
		private StringTokenizer tokenizer;
		
		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		
		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(br.readLine());
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
	}
}
