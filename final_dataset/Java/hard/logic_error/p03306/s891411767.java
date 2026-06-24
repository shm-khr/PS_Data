/*input
4 3
1 2 6
3 4 5
2 3 7
*/
import java.util.Scanner;
import java.lang.*;
import java.util.Arrays;
import java.util.function.BinaryOperator;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;


public class Graph {
	private static final int N = (int)1e5 + 100;
	private static final long oo = (long) 1e18;
	public static class Pair {
		public int v;
		public long s;
		Pair(int v, long s) {
			this.v = v;
			this.s = s;
		}
	}

	private static long n, m, flag = 0;
	private static long[] a = new long[N];
	private static long[] step = new long[N];
	private static long[] res = new long[N];
	private static boolean[] visit = new boolean[N];

	public static ArrayList<ArrayList<Pair> > vi = new ArrayList< ArrayList <Pair> >();

	static void run() { System.out.print("0"); System.exit(0); }
	static void done() { System.out.print("1"); System.exit(0); }
	static boolean check(long x) {
		res[1] = x;
		for(int i = 1; i <= n; ++i) {
			if(step[i] % 2 == 0) {
				res[i] = a[i] + x;
			} else res[i] = a[i] - x;
		}
		for(int i = 1; i <= n; ++i) {
			for(Pair cur: vi.get(i))	{
				if(cur.s != (res[i] + res[cur.v])) return false;
			}
		}
		return true;
	}

	static void dfs(int u) {
		visit[u] = true;
		for(Pair cur: vi.get(u)) {
			if(!visit[cur.v]) {
				step[cur.v] = 1 - step[u];
				a[cur.v] = cur.s - a[u];
				dfs(cur.v);
			}
		}
	}

	public static void main(String[] args) {
		Scanner inp = new Scanner(System.in);

		n = inp.nextLong();
		m = inp.nextLong();
		
		for(int i = 1; i <= n + 1; ++i) {
			visit[i] = false;
			vi.add(new ArrayList<Pair>());
		}
		for(int i = 1; i <= m; ++i) {
			int u, v, s;
			u = inp.nextInt();
			v = inp.nextInt();
			s = inp.nextInt();
			vi.get(u).add(new Pair(v, s));
			vi.get(v).add(new Pair(u, s));
		} 
		step[1] = a[1] = 0;

		dfs(1);

		long minn = 1, maxn = oo;

		//for(int i = 1; i <= n; ++i) System.out.println(a[i] + " " + step[i]);

		for(int i = 1; i <= n; ++i ) {
			for(Pair cur: vi.get(i)) {
				if(1 - step[i] == step[cur.v]) {
					if(a[cur.v] != cur.s - a[i]) done();
				} else {
					long tmp = cur.s - a[i];
					if(step[i] % 2 == 0) {
						if(check((tmp - a[cur.v]) / 2)) done();
						else {
							//System.out.print(i + " ");
							//System.out.println(cur.v);
							run();
						}
					} else {
						if(check((a[cur.v] - tmp) / 2)) done();
						else {
							//System.out.print(i + " ");
							//System.out.println(cur.v);
							run();
						}	
					}
				}
			}
			if(step[i] == 0) minn = Math.max(minn, 1 - a[i]);
			else maxn = Math.min(maxn, a[i] - 1);
		}
			
		minn = Math.max(minn, 1);
		System.out.print(Math.max(maxn - minn + 1, 0L));
	}
}