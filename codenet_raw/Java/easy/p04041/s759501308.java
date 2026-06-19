import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.Arrays;
import java.util.StringTokenizer;
class Main{
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		int N=sc.nextInt();
		int X=sc.nextInt();
		int Y=sc.nextInt();
		int Z=sc.nextInt();
		long MOD=1_000_000_007L;
		int SUM=X+Y+Z;
		long ans=0;
		long tmp=0;
		long[] xs=new long[X+1];
		long[] ys=new long[Y+1];
		long[] zs=new long[Z+1];
		long[] tens=new long[42];
		tens[0]=1;
		for(int i=1; i<42; i++) {
			tens[i]=(tens[i-1]*10)%MOD;
		}
		Arrays.fill(xs,1);
		Arrays.fill(ys,1);
		Arrays.fill(zs,1);
		for(int i=1; i<X; i++) {
			xs[i]=Combi(X-1,i);
		}
		for(int i=1; i<Y; i++) {
			ys[i]=Combi(Y-1,i);
		}
		for(int i=1; i<Z; i++) {
			zs[i]=Combi(Z-1,i);
		}
		for(int i=3; i<=Math.min(SUM,N); i++) {	//計算の長さ
			for(int j=1; j<=X; j++) {
				for(int k=1; k<=Y; k++) {
					for(int l=1; l<=Z; l++) {
						if(j+k+l==i) {
							//pl(j+" "+k+" "+l);
							tmp=1;
							int yochi=N-i;	//1-10が入る余地
							if(yochi>=0) {
								long jun=((long)yochi)+1L;	//有効な範囲をずらす
								tmp=xs[j-1]*ys[k-1]*zs[l-1]%MOD;
								tmp=tmp*jun%MOD;
								tmp*=tens[yochi];
								tmp%=MOD;
								ans+=tmp;
								ans%=MOD;
								//pl(tmp);
							}
							else {
								continue;
							}
						}
					}
				}
			}
		}
		pl(ans);
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
	}
	public static void pl(Object o) {
		System.out.println(o);
	}
	public static void pl() {
		System.out.println();
	}
	public static void p(Object o) {
		System.out.print(o);
	}
	public static long Combi(int n,int r) {		// nCr
		if(r==0 || r==n) return 1L;
		if(r>n-r)r=n-r;
		int[] bunsi=new int[r];
		int[] bunbo=new int[r];
		for(int k=0; k<r; k++) {
			bunsi[k]=n-r+k+1;
			bunbo[k]=k+1;
		}
		for(int p=2; p<=r; p++) {
			int pivot=bunbo[p-1];
			if(pivot>1) {
				int offset=(n-r)%p;
				for(int k=p-1; k<r; k+=p) {
					bunsi[k-offset]/=pivot;
					bunbo[k]/=pivot;
				}
			}
		}
		long kotae=1;
		for(int k=0; k<r; k++) {
			if(bunsi[k]>1) {
				kotae*=bunsi[k];
			}
		}
		return kotae;
	}
}