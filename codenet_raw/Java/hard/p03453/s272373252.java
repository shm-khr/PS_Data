import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.PriorityQueue;

public class Main {

	static PrintWriter out;
	static InputReader ir;
	static boolean debug =false;
    static final long mod=(long)1e9+7;

	static void solve() {
        int n=ir.nextInt();
		int m=ir.nextInt();
        Graph[] g=new Graph[n];
        for(int i=0;i<n;i++){
            g[i]=new Graph();
        }
        int s=ir.nextInt()-1;
		int t=ir.nextInt()-1;
		for(int i=0;i<m;i++){
			int u=ir.nextInt()-1;
			int v=ir.nextInt()-1;
			int d=ir.nextInt();
			g[u].add(new long[]{v,d});
			g[v].add(new long[]{u,d});
		}
		long[] sd=dijkstra(s,g);
		long[] td=dijkstra(t,g);
		tr(sd);
		HashSet<Long> st=new HashSet<Long>();
		long[] sp=route(t,g,sd,st,1);
		long[] tp=route(s,g,td,st,0);
		tr(sp);
		long res=0;
		for(long x : st){
			int from=(int)(x/n);
			int to=(int)(x%n);
			res+=Math.pow((sp[from]*tp[to])%mod,2);
			res%=mod;
		}
		for(int i=0;i<n;i++){
			if(sd[i]*2==sd[t]){
				res+=Math.pow((sp[i]*tp[i])%mod,2);
				res%=mod;
			}
		}
		res=(sp[s]*tp[t])%mod-res;
		while(res<0)
			res+=mod;
		out.println(res%mod);
	}

    static class Graph extends ArrayList<long[]>{}

    static long[] dijkstra(int s,Graph[] g){
		int n=g.length;
        long[] res=new long[n];
		Arrays.fill(res,Long.MAX_VALUE/2);
		res[s]=0;
		PriorityQueue<long[]> pque=new PriorityQueue<long[]>(new Comparator<long[]>(){
			public int compare(long[] A,long[] B){
				return Long.compare(A[1],B[1]);
			}
		});
		pque.offer(new long[]{s,0});
		while(!pque.isEmpty()){
			long[] d=pque.poll();
			int from=(int)d[0];
			if(res[from]!=d[1])
				continue;
			for(int i=0;i<g[from].size();i++){
				int to=(int)g[from].get(i)[0];
				if(res[to]>res[from]+g[from].get(i)[1]){
					res[to]=res[from]+g[from].get(i)[1];
					pque.offer(new long[]{to,res[to]});
				}
			}
		}
		return res;
    }

	static long[] route(int s,Graph[] g,long[] d,HashSet<Long> st,int f){
		int n=g.length;
		long[] res=new long[n];
		boolean[] v=new boolean[n];
		res[s]=1;
		PriorityQueue<long[]> pque=new PriorityQueue<long[]>(new Comparator<long[]>(){
			public int compare(long[] A,long[] B){
				if(A[1]!=B[1]) return -Long.compare(A[1],B[1]);
				return Long.compare(A[0],B[0]);
			}
		});
		pque.offer(new long[]{s,d[s]});
		while(!pque.isEmpty()){
			long[] e=pque.poll();
			int from=(int)e[0];
			if(v[from])
				continue;
			v[from]=true;
			for(int i=0;i<g[from].size();i++){
				int to=(int)g[from].get(i)[0];
				if(d[to]==d[from]-g[from].get(i)[1]){
					res[to]+=res[from];
					res[to]%=mod;
					if(f==1&&2*d[from]>d[s]&&2*d[to]<d[s]){
						st.add((long)from*n+to);
					}
					pque.offer(new long[]{to,d[to]});
				}
			}
		}
		return res;
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
		if (debug)
			out.println(Arrays.deepToString(o));
	}
}
