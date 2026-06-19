import java.io.BufferedReader;
import java.io.Closeable;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Map.Entry;

import java.util.PriorityQueue;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;


public class Main {
	
	public static void main(String[] args) throws IOException {	
		try(final Scanner sc = new Scanner(System.in)){
			final int N = sc.nextInt();
			final long K = sc.nextLong();
			
			long[] as = new long[N];
			for(int i = 0; i < N; i++) {
				as[i] = sc.nextLong() % K;
			}
			
			long[] ts = new long[N];
			for(int i = 0; i < N; i++) {
				ts[i] = as[i];
			}
			
			for(int i = 1; i < N; i++) {
				ts[i] += ts[i - 1];
				ts[i] %= K;
			}
			
			for(int i = 0; i < N; i++) {
				ts[i] = (ts[i] - ((i + 1) % K) + K) % K;
			}
			
			/*
			System.out.println(Arrays.toString(as));
			System.out.println(Arrays.toString(ss));
			System.out.println(Arrays.toString(ts));
			*/
			
			HashMap<Long, Integer> counts = new HashMap<Long, Integer>();
			for(int i = 0; i < Math.min(N, K - 1); i++) {
				if(!counts.containsKey(ts[i])) { counts.put(ts[i], 0); }
				counts.put(ts[i], counts.get(ts[i]) + 1);
			}
			
			long answer = 0;
			/*
			for(int i = 0; i < N; i++) {
				long sum = 0;
				for(int j = i; j < N; j++) {
					sum += as[j];
					if(sum % K == (j - i + 1)) {
						System.out.println(i + " " + j + " " + (j - i + 1));
					}
				}
			}
			*/
			
			long X = 0;
			for(int i = 0; i < N; i++) {
				//final long X = (i == 0 ? 0 : (K + (as[i - 1] % K) - (i + 1))) % K;
				X += (i == 0) ? 0 : ((K + as[i - 1] - 1) % K);
				X %= K;
				
				//System.out.println(X + " " + counts + " " + counts.get(X));
				if(counts.containsKey(X)) {
					answer += counts.get(X);
				}
				
				if(ts[i] < 0) {
					System.exit(0);
				}
				
				counts.put(ts[i], counts.get(ts[i]) - 1);

				if(i + (K - 1) < N) {
					final int index = (int)(i + (K - 1));
					if(!counts.containsKey(ts[index])) {
						counts.put(ts[index], 0);
					}
					
					counts.put(ts[index], counts.get(ts[index]) + 1);
				}
			}
			
			System.out.println(answer);
		}
	}

	public static class Scanner implements Closeable {
		private BufferedReader br;
		private StringTokenizer tok;

		public Scanner(InputStream is) throws IOException {
			br = new BufferedReader(new InputStreamReader(is));
		}

		private void getLine() throws IOException {
			while(!hasNext()){
				tok = new StringTokenizer(br.readLine());
			}
		}

		private boolean hasNext() {
			return tok != null && tok.hasMoreTokens();
		}

		public String next() throws IOException {
			getLine();
			return tok.nextToken();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}
		

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		public int[] nextIntArray(int n) throws IOException {
			final int[] ret = new int[n];
			for(int i = 0; i < n; i++){
				ret[i] = this.nextInt();
			}
			return ret;
		}

		public long[] nextLongArray(int n) throws IOException {
			final long[] ret = new long[n];
			for(int i = 0; i < n; i++){
				ret[i] = this.nextLong();
			}
			return ret;
		}

		public void close() throws IOException {
			br.close();
		}
	}
}
