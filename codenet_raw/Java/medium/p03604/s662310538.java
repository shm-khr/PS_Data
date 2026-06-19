import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

import org.omg.Messaging.SyncScopeHelper;

public class Main {
	public static void main(String[] args) {
		// long t = System.currentTimeMillis();
		new Main().run();
		// System.err.println(System.currentTimeMillis() - t);
	}

	final long MOD = 1_000_000_000 + 7;
	final int N = 100000;
	long[] fac = new long[2 * N];
	long[] invfac = new long[2 * N];
	long[] inv = new long[2 * N];
	{
		fac[0] = 1;
		invfac[0] = 1;
		inv[1] = 1;
		for (int i = 1; i < fac.length; ++i)
			fac[i] = fac[i - 1] * i % MOD;
		for (int i = 2; i < inv.length; ++i) {
			inv[i] = MOD - inv[(int) (MOD % i)] * (MOD / i) % MOD;
		}
		for (int i = 1; i < invfac.length; ++i) {
			invfac[i] = invfac[i - 1] * inv[i] % MOD;
		}
	}

	long c(int n, int k) {
		return fac[n] * invfac[k] % MOD * invfac[n - k] % MOD;
	}

	class DJSet {
		int[] upper;
		int[] e_sz;
		int n;

		public DJSet(int n_) {
			n = n_;
			upper = new int[n];
			e_sz = new int[n];
			Arrays.fill(upper, -1);
		}

		int root(int x) {
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}

		boolean equiv(int x, int y) {
			return root(x) == root(y);
		}

		void setUnion(int x, int y) {
			x = root(x);
			y = root(y);
			if (x == y) {
				++e_sz[x];
				return;
			}
			if (upper[x] < upper[y]) {
				x ^= y;
				y ^= x;
				x ^= y;
			}
			upper[y] += upper[x];
			upper[x] = y;
			e_sz[y] += e_sz[x] + 1;
			e_sz[x] = -1;
		}

		int sz(int x) {
			return -upper[root(x)];
		}
	}

	boolean check(int n, int[] x, int[] y) {
		DJSet ds = new DJSet(2 * n);
		for (int i = 0; i < 2 * n; ++i) {
			ds.setUnion(x[i], y[i] + n);
		}
		int[] ord = new int[2 * n];
		Arrays.fill(ord, -1);
		int p = 0;
		for (int i = 0; i < 2 * n; ++i) {
			int j = ds.root(i);
			if (ord[j] == -1) {
				ord[j] = p++;
			}
			if (ds.sz(j) != ds.e_sz[j]) {
				return false;
			}
		}
		return true;
	}

	void scc(ArrayList<Integer>[] g) {
		int n = g.length;
		col = new int[n];
		ord = new int[n];
		low = new int[n];
		col_sz = new int[n];
		Arrays.fill(col, -1);
		Arrays.fill(ord, -1);
		for (int i = 0; i < n; ++i) {
			if (col[i] == -1)
				scc_dfs(i, -1, g);
		}
		col_sz = Arrays.copyOf(col_sz, color);
	}

	void scc_dfs(int cur, int par, ArrayList<Integer>[] g) {
		scc_pend.addLast(cur);
		ord[cur] = order++;
		low[cur] = ord[cur];
		for (int dst : g[cur]) {
			if (dst == par || col[dst] != -1)
				continue;
			if (ord[dst] != -1) {
				low[cur] = Math.min(low[cur], low[dst]);
			} else {
				scc_dfs(dst, cur, g);
				low[cur] = Math.min(low[cur], low[dst]);
			}
		}
		if (ord[cur] == low[cur]) {
			int v = -1;
			while (v != cur) {
				v = scc_pend.pollLast();
				col[v] = color;
				col_sz[color]++;
			}
			++color;
		}
	}

	int[] col;
	int[] col_sz;
	int color;
	int[] ord;
	int[] low;
	int order;
	ArrayDeque<Integer> scc_pend = new ArrayDeque<>();

	long[] dfs2(int cur, ArrayList<Integer>[] g, boolean[] vis) {
		long pat = 1;
		int sz = 0;
		vis[cur] = true;
		ArrayList<Integer> szs = new ArrayList<>();
		for (int dst : g[cur]) {
			long[] q = dfs2(dst, g, vis);
			szs.add((int) q[1]);
			sz += q[1];
			pat = pat * q[0] % MOD * c(sz, (int) q[1]) % MOD;
		}
		sz += 1;
		return new long[] { pat, sz };
	}

	void dfs1(ArrayList<Integer>[] g, int cur, int par, ArrayList<Integer>[] forward, ArrayList<Integer>[] backward) {
		for (int v : g[cur]) {
			if (v == par)
				continue;
			forward[v].add(cur);
			backward[cur].add(v);
			if (backward[v].size() == 0)
				dfs1(g, v, cur, forward, backward);
		}
	}

	long f(ArrayList<Integer>[] g, ArrayList<Integer> v) {

		int n = g.length;
		ArrayList<Integer>[] g2 = new ArrayList[n];
		for (int i = 0; i < g2.length; ++i)
			g2[i] = new ArrayList<>();

		scc(g);

		long ret = 0;

		ArrayList<Integer>[] forward = new ArrayList[n];
		ArrayList<Integer>[] backward = new ArrayList[n];
		for (int i = 0; i < n; ++i) {
			forward[i] = new ArrayList<>();
			backward[i] = new ArrayList<>();
		}

		for (int i = 0; i < n; ++i) {
			if (col_sz[col[i]] > 1) {
				dfs1(g, i, -1, forward, backward);
				break;
			}
		}

		for (int t = 0; t < 2; ++t) {
			for (int i = 0; i < g2.length; ++i)
				g2[i].clear();

			int[] frm = new int[n];
			Arrays.fill(frm, -1);
			for (int i = 0; i < n; ++i) {
				for (int b : backward[i]) {
					for (int f : forward[i]) {
						if (v.get(b) < v.get(f)) {
							g2[i].add(b);
							frm[b] = i;
						}
					}
				}
			}
			int sz = 0;
			long ans = 1;
			boolean[] vis = new boolean[n];
			for (int i = 0; i < n; ++i) {
				if (vis[i])
					continue;
				int j = i;
				vis[j] = true;
				while (frm[j] != -1) {
					j = frm[j];
					vis[j] = true;
				}
				long[] q = dfs2(j, g2, vis);
				sz += q[1];
				ans = ans * q[0] % MOD * c((int) sz, (int) q[1]) % MOD;
			}
			ret = (ret + ans) % MOD;

			ArrayList<Integer>[] nf = new ArrayList[n];
			ArrayList<Integer>[] nb = new ArrayList[n];
			for (int i = 0; i < n; ++i) {
				nf[i] = new ArrayList<>();
				nb[i] = new ArrayList<>();
			}
			if (t == 0) {
				for (int i = 0; i < n; ++i) {
					for (int u : forward[i]) {
						if (col_sz[col[i]] == 1) {
							nf[i].add(u);
							nb[u].add(i);
						} else if (col_sz[col[i]] > 1 && col_sz[col[u]] > 1) {
							nf[u].add(i);
							nb[i].add(u);
						} else {
							throw new AssertionError();
						}
					}
				}
				backward = nb;
				forward = nf;
			}
		}
		return ret;

	}

	long solve(int n, int[] x, int[] y) {
		if (!check(n, x, y)) {
			return 0;
		}
		DJSet ds = new DJSet(2 * n);
		ArrayList<Integer>[] vv = new ArrayList[2 * n];
		ArrayList<Integer>[][] gg = new ArrayList[2 * n][];
		for (int i = 0; i < 2 * n; ++i) {
			vv[i] = new ArrayList<>();
		}
		for (int i = 0; i < 2 * n; ++i) {
			ds.setUnion(x[i], y[i] + n);
		}

		int[] id = new int[2 * n];
		for (int i = 0; i < 2 * n; ++i) {
			vv[ds.root(i)].add(i);
		}
		for (int i = 0; i < 2 * n; ++i) {
			Collections.sort(vv[i]);
			for (int v : vv[i])
				id[v] = Collections.binarySearch(vv[i], v);
			gg[i] = new ArrayList[vv[i].size()];
			for (int j = 0; j < gg[i].length; ++j)
				gg[i][j] = new ArrayList<>();
		}
		for (int i = 0; i < 2 * n; ++i) {
			int r = ds.root(x[i]);
			int u = id[x[i]];
			int v = id[y[i] + n];
			gg[r][u].add(v);
			gg[r][v].add(u);
		}
		long ans = 1;
		int tot = 0;
		for (int i = 0; i < gg.length; ++i) {
			if (gg[i].length == 0)
				continue;
			tot += gg[i].length;
			ans = ans * f(gg[i], vv[i]) % MOD * c(tot, gg[i].length) % MOD;
		}
		return ans;
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] x = new int[2 * n];
		int[] y = new int[2 * n];
		for (int i = 0; i < 2 * n; ++i) {
			x[i] = sc.nextInt();
			y[i] = sc.nextInt();
			--x[i];
			--y[i];
		}
		System.out.println(solve(n, x, y));
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}
