	public static ArrayList<Integer>[] old;
	public static int[] preMap;

	public static ArrayList<Integer>[] tree;
	public static int[] children;
	public static int[] parent;
	public static int[][] ranges;
	public static int[] total;
	public static long[] ans;
	public static ArrayList<long[]>[] indices;
	public static void main(String[] args) {
		FastScanner sc = new FastScanner();
		PrintWriter pw = new PrintWriter(System.out);
		
		int N = sc.ni();
		int[] oldColors = new int[N];
		for (int i = 0; i < N; i++)
			oldColors[i] = sc.ni()-1;
		int[][] edges = new int[N-1][2];
		for (int i = 0; i < N-1; i++)
			edges[i] = new int[]{sc.ni()-1,sc.ni()-1};
		old = new ArrayList[N];
		for (int i = 0; i < N; i++)
			old[i] = new ArrayList<Integer>();
		for (int i = 0; i < N-1; i++) {
			old[edges[i][0]].add(edges[i][1]);
			old[edges[i][1]].add(edges[i][0]);
		}
		preMap = new int[N];
		Arrays.fill(preMap,-1);
		preOrder(0,0);
		int[] colors = new int[N];
		for (int i = 0; i < N; i++)
			colors[preMap[i]] = oldColors[i];
		tree = new ArrayList[N];
		for (int i = 0; i < N; i++)
			tree[i] = new ArrayList<Integer>();
		for (int i = 0; i < N-1; i++) {
			int e1 = preMap[edges[i][0]];
			int e2 = preMap[edges[i][1]];
			tree[Math.min(e1,e2)].add(Math.max(e1,e2));
		}
		for (int i = 0; i < N; i++) {
			Collections.sort(tree[i]);
		}
		
		parent = new int[N];
		children = new int[N];
		Arrays.fill(parent, -1);
		Arrays.fill(children, -1);
		children[0] = childDfs(0); //+ parents
		ranges = new int[N][2];
		for (int i = 0; i < N; i++) {
			ranges[i] = new int[]{i,i+children[i]-1};
		}
		
		//the nodes where color i appears at
		ArrayList<Integer>[] indices = new ArrayList[N];
		
		for (int i = 0; i < N; i++)
			indices[i] = new ArrayList<Integer>();
		for (int i = 0; i < N; i++) {
			indices[colors[i]].add(i);
		}
		HashMap<Integer,Integer> hm = new HashMap<Integer,Integer>();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < indices[i].size(); j++)
				hm.put(indices[i].get(j), j);
		}
		BinaryIndexedTree[] bits = new BinaryIndexedTree[N];
		for (int i = 0; i < N; i++) {
			int size = indices[i].size();
			if (size > 0)
				bits[i] = new BinaryIndexedTree(size);
		}
		
		int[] cnt = new int[N];
		
		ArrayDeque<Integer> bfs = new ArrayDeque<Integer>();
		for (int i = 0; i < N; i++) {
			if (tree[i].isEmpty())
				bfs.add(i);
		}
		
		long[] bad = new long[N];
		while (!bfs.isEmpty()) {
			int node = bfs.poll();
			int c = colors[node];
			long total = 1;
			
			for (int child: tree[node]) {
				if (colors[child] == c) continue;
				long size = (long)children[child];
				if (indices[c].get(indices[c].size()-1) >= child+1) {
					//leftmost bound.
					int low1 = 0;
					int high1 = indices[c].size()-1;
					while (low1 < high1) {
						int med = (low1+high1)/2;
						
						if (indices[c].get(med) >= child+1) {
							high1 = med;
						} else {
							low1 = med+1;
						}
					}
					
					//rightmost bound.
					int low2 = 0;
					int high2 = indices[c].size()-1;
					while (low2 < high2) {
						int med = (low2+high2+1)/2;
						
						if (indices[c].get(med) <= ranges[child][1]) {
							low2 = med;
						} else {
							high2 = med-1;
						}
					}
					
					
					if (low1 <= low2) {
						size -= bits[c].sum(low1, low2+1);
					}
				}
				bad[c] += (size)*(size+1)/2;
				total += size;
			}
			
			bits[c].add((int)total, hm.get(node));
			if (node > 0) {
				cnt[parent[node]] += 1;
				if (cnt[parent[node]] == tree[parent[node]].size())
					bfs.add(parent[node]);
			}
		}
		
		for (int i = 0; i < N; i++) {
			if (colors[0] != i && bits[i] != null) {
				long unpaired = 0L+N-bits[i].sum(0, bits[i].arr.length-1);
				bad[i] += unpaired*(unpaired+1)/2;
			}
		}
		
		long[] ans = new long[N];
		long all = (N+0L)*(N+1L)/2;
		for (int i = 0; i < N; i++) {
			ans[i] = all-bad[i];
			if (indices[i].isEmpty())
				ans[i] = 0L;
			pw.println(ans[i]);
		}
		
		pw.close();
	}
	
	//0 indexed
	static class BinaryIndexedTree {
		public int[] arr;

		public BinaryIndexedTree (int N) {
			arr = new int[N+1];
		}

		//add k to the i-th element.
		public void add(int k, int i) {
			int node = i+1;
			while (node < arr.length) {
				arr[node] += k;
				node += node & (-node);
			}
		}

		//sum up the elements from input[s_i] to input[e_i], from [s_i,e_i).
		public int sum(int s_i, int e_i) {
			return sum(e_i) - sum(s_i);
		}

		public int sum(int i) {
			int total = 0;
			int node = i;
			while (node > 0) {
				total += arr[node];
				node -= node & (-node);
			}
			return total;
		}
	}
	
	public static void preOrder(int node, int ind) {
		preMap[node] = ind;
		for (int child: old[node]) {
			if (preMap[child] == -1) {
				ind++;
				preOrder(child,ind);
			}
		}
	}
	
	public static int childDfs(int node) {
		int c = 1;
		children[node] = 0;
		for (int child: tree[node]) {
			if (children[child] == -1) {
				c += childDfs(child);
				parent[child] = node;
			}
		}
		children[node] = c;
		return c;
	}