import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;

class Main{
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		long L=sc.nextLong();
		int N=sc.nextInt();
		if(N>10000) {
			pl("BANANA");
			System.exit(0);
		}
		else {
			long[] hidari=new long[N+1];
			long[] migi=new long[N+1];
			long tmp=0;
			hidari[0]=0;
			migi[0]=0;
			for(int i=1; i<=N; i++) {
				tmp=sc.nextLong();
				migi[i]=tmp;
				hidari[N+1-i]=L-tmp;
			}
			long[][][] dp=new long[N+1][N+1][2];
			for(int i=0; i<=N; i++) {
				for(int j=0; j<=N; j++) {
					dp[i][j][0]=0L;
					dp[i][j][1]=0L;
				}
			}
			for(int i=0; i<=N; i++) {
				for(int j=0; j<=N; j++) {
					if(i<N) {
						dp[i+1][j][0]=Math.max(dp[i+1][j][0], dp[i][j][0]+hidari[i+1]-hidari[i]);
						dp[i+1][j][0]=Math.max(dp[i+1][j][0], dp[i][j][1]+hidari[i+1]+migi[j]);
					}
					if(j<N) {
						dp[i][j+1][1]=Math.max(dp[i][j+1][1], dp[i][j][1]+migi[j+1]-migi[j]);
						dp[i][j+1][1]=Math.max(dp[i][j+1][1], dp[i][j][0]+hidari[i]+migi[j+1]);
					}
				}
			}
			long ans=0;
			for(int i=0; i<=N; i++) {
				ans=Math.max(ans, dp[i][N-i][0]);
				ans=Math.max(ans, dp[i][N-i][1]);
			}
			pl(ans);
		}
	}
	public static void chmax(int a,int b) {
		a=Math.max(a, b);
	}
	static class SC {
		private BufferedReader reader = null;
		private StringTokenizer tokenizer = null;
		public SC(InputStream in) {
			reader = new BufferedReader(new InputStreamReader(in));
		}
		public String next() {
			if (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new UncheckedIOException(e);
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
		public String nextLine() {
			try {
				return reader.readLine();
			} catch (IOException e) {
				throw new UncheckedIOException(e);
			}
		}
	}
	public static void pl(Object o) {
		System.out.println(o);
	}
	public static void p(Object o) {
		System.out.print(o);
	}
}
