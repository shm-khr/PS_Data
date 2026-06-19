import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) {
        FastScanner in = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        int n = in.nextInt();
        HashMap<Integer,Long> map = new HashMap<>();
        Integer arr[] = new Integer[n];
        for(int i=0;i<n;i++) {
        	int a = in.nextInt(), b = in.nextInt();
        	long c = hashInt(a, b);
        	int d = a + b;
        	map.put(d, c);
        	arr[i] = d;
        }
        Arrays.parallelSort(arr);
        long minx,miny,maxx,maxy;
        int a1 = arr[0], a2 = arr[n-1];
        minx = map.get(a1)/1_000_000_000;
        miny = map.get(a1)%1_000_000_000;
        maxx = map.get(a2)/1_000_000_000;
        maxy = map.get(a2)%1_000_000_000;
        out.println(Math.abs(maxx-minx)+Math.abs(maxy-miny));
        out.flush();
	}
	
	static class FastScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");
		
		String next() {
			while(!st.hasMoreTokens())
				try {
					st = new StringTokenizer(br.readLine());
				}catch(IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		
		long nextLong() {
			return Long.parseLong(next());
		}
		
		int[] readArray(int n) {
			int a[] = new int[n];
			for(int i=0;i<n;i++) a[i] = nextInt();
			return a;
		}
		
		Integer[] readArray(long n) {
		    Integer a[] = new Integer[(int)n];
			for(int i=0;i<n;i++) a[i] = nextInt();
			return a;
		}
		
		long[] readArray(int n,long x) {
			long a[] = new long[n];
			for(int i=0;i<n;i++) a[i] = nextLong();
			return a;
		}
		
	}
	
	static class Pair implements Comparable<Pair> {
		int x, y;
		Pair(int a, int b){ x = a; y = b; }
		int getKey() { return x; }
		int getVal() { return y; }
		@Override
		public int compareTo(Pair o) {
			if(o.getVal() - this.getVal()>0)
				return -1;
			else if(o.getVal() - this.getVal()<0)
				return 1;
			else 
				return 0;
		}
		
	}
	
	static boolean arrayEquals(char a[], char b[]) {
		int n = a.length;
		boolean verdict = true;
		for(int i=0;i<n;i++) {
			if(a[i]!=b[i]) {
				verdict = false;break;
			}
		}
		return verdict;
	}
	
	static long lcm(long a, long b) {
		return (a*b)/gcd(a,b);
	}
	
	static long gcd(long a, long b) {
		if(b==0) return a;
		else return gcd(b,a%b);
	}
	
	static long hashInt(int x,int y) {
		return x*(1_000_000_000L)+y;
	}
}
