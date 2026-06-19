import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner(System.in);
		final int n = sc.nextInt();
		final long[] a = new long[n];
		final long[] b = new long[n];
		for(int i=0; i<n; i++) {
			a[i] = sc.nextLong();
			b[i] = sc.nextLong();
		}
		long sum = 0;
		int m = 0;
		for(int i=0; i<n; i++) {
			if(a[i]<b[i]) {
				sum += a[i];
			} else {
				m++;
			}
		}
		if(m==0) {
			System.out.println(sum);
		} else if(m==1) {
			for(int i=0; i<n; i++) {
				if(a[i]>=b[i]) {
					sum += a[i]-b[i];
				}
			}
			System.out.println(sum);
		} else {
			Pair p = new Pair(Long.MAX_VALUE, 0);
			long add = 0;
			for(int i=0; i<n; i++) {
				if(a[i]>=b[i]) {
					if(p.fst>a[i]) {
						p = new Pair(a[i], b[i]);
					}
					add+= a[i];
				}
			}
			System.out.println(sum+add-p.fst+(p.fst-p.snd));
		}

	}
	
	static class Pair {
		long fst;
		long snd;
		Pair(long a, long b) {
			this.fst = a; this.snd = b;
		}
	}

	static class MyScanner
	{
		BufferedReader br;
		StringTokenizer st;
		public MyScanner(InputStream s)
		{
			br=new BufferedReader(new InputStreamReader(s));
		}
		public String nextLine() throws IOException
		{
			return br.readLine();
		}
		public String next() throws IOException
		{
			while(st==null || !st.hasMoreTokens())
				st=new StringTokenizer(br.readLine());
			return st.nextToken();
		}
		public int nextInt() throws IOException
		{
			return Integer.parseInt(next());
			
		}
		public double nextDouble() throws IOException
		{
			return Double.parseDouble(next());
		}
		public boolean ready() throws IOException
		{
			return br.ready();
		}
		public long nextLong() throws IOException
		{
			return Long.parseLong(next());
		}
	}
}
