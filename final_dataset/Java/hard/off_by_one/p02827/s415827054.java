import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.TreeSet;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] sa = br.readLine().split(" ");
		int n = Integer.parseInt(sa[0]);
		int m = Integer.parseInt(sa[1]);
		int t = Integer.parseInt(sa[2]);
		int[] x = new int[m];
		int[] y = new int[m];
		for (int i = 0; i < m; i++) {
			sa = br.readLine().split(" ");
			x[i] = Integer.parseInt(sa[0]) - 1;
			y[i] = Integer.parseInt(sa[1]) - 1;
		}
		br.close();

		if (t == 2) {
			throw new RuntimeException();
		}

		List<TreeSet<Integer>> list1 = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			list1.add(new TreeSet<>());
		}

		UnionFind uf = new UnionFind(n);
		boolean[] use = new boolean[m];
		for (int i = 0; i < m; i++) {
			if (!uf.same(x[i], y[i])) {
				uf.union(x[i], y[i]);
				list1.get(x[i]).add(i);
				list1.get(y[i]).add(i);
				use[i] = true;
			}
		}

		if (uf.size(0) != n) {
			System.out.println(-1);
			return;
		}

		char[] ans = new char[m];
		Arrays.fill(ans, ' ');
		for (int i = 0; i < m; i++) {
			if (use[i]) {
				Integer nx = list1.get(x[i]).higher(i);
				Integer ny = list1.get(y[i]).higher(i);
				if (nx == null) {
					if (ny == null) {
						System.out.println(-1);
						return;
					}
					ans[i] = 'v';
				} else {
					ans[i] = '^';
				}
			}
		}

		List<TreeSet<Integer>> list2 = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			list2.add(new TreeSet<>());
		}
		for (int i = 0; i < m; i++) {
			if (ans[i] == 'v') {
				list2.get(x[i]).add(i);
			}
			if (ans[i] == '^') {
				list2.get(y[i]).add(i);
			}
		}
		for (int i = 0; i < m; i++) {
			if (!use[i]) {
				Integer nx = list2.get(x[i]).higher(i);
				if (nx == null) {
					ans[i] = 'v';
				} else {
					ans[i] = '^';
				}
			}
		}

		StringBuilder sb = new StringBuilder();
		sb.append(ans);
		System.out.println(sb.toString());
	}

	static class UnionFind {
		int[] parent, size;

		UnionFind(int n) {
			parent = new int[n];
			size = new int[n];
			for (int i = 0; i < n; i++) {
				parent[i] = i;
				size[i] = 1;
			}
		}

		void union(int x, int y) {
			int px = find(x);
			int py = find(y);
			if (px != py) {
				parent[px] = py;
				size[py] += size[px];
			}
		}

		int find(int x) {
			if (parent[x] == x) {
				return x;
			}
			parent[x] = find(parent[x]);
			return parent[x];
		}

		boolean same(int x, int y) {
			return find(x) == find(y);
		}

		int size(int x) {
			return size[find(x)];
		}
	}
}
