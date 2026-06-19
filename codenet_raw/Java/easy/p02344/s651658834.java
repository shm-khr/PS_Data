import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	private class DisjointSet {

		private int[] parent;
		private int[] rank;
		private int[] weight;
		
		public DisjointSet(int size) {
			parent = new int[size];
			rank = new int[size];
			weight = new int[size];
			for (int i = 0; i < size; i++) {
				makeSet(i);
			}
		}

		private void makeSet(int x) {
			parent[x] = x;
			rank[x] = 0;
			weight[x] = 0;
		}
		
		public boolean same(int x, int y) {
			return findSet(x) == findSet(y);
		}

		private int findSet(int x) {
			while (x != parent[x]) {
				x = parent[x];
			}
			return parent[x];
		}
		
		public void relate(int x, int y, int z) {
			link(findSet(x), findSet(y), z - weight[x] + weight[y]);
		}

		private void link(int x, int y, int cost) {
			if (rank[x] > rank[y]) {
				parent[y] = x;
				weight[y] -= cost;
			} else {
				parent[x] = y;
				weight[x] += cost;
				if (rank[x] == rank[y]) {
					rank[y]++;
				}
			}
		}

		public int sum(int x) {
			int sum = 0;
			int now = x;
			while (now != parent[now]) {
				sum += weight[now];
				now = parent[now];
			}
			return sum;
		}
	}
	
	public static void main(String[] args) throws IOException {
		new Main().run();
	}
	
	private void run() throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(reader.readLine());
		int n = Integer.parseInt(st.nextToken());
		DisjointSet ds = new DisjointSet(n);
		int q = Integer.parseInt(st.nextToken());
		for (int i = 0; i < q; i++) {
			st = new StringTokenizer(reader.readLine());
			int c, x, y, z;
			c = Integer.parseInt(st.nextToken());
			x = Integer.parseInt(st.nextToken());
			y = Integer.parseInt(st.nextToken());
			if (c == 0) {
				z = Integer.parseInt(st.nextToken());
				ds.relate(x, y, z);
			} else if (c == 1) {
				if (!ds.same(x, y)) {
					System.out.println("?");
				} else {
					System.out.println(ds.sum(x) - ds.sum(y));
				}
			}
		}
		reader.close();
	}
}

